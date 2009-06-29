/*--------------------------------------------------------------------*/
/*--- CatchConversions                           ca_callbacks.c    ---*/
/*--------------------------------------------------------------------*/

/*
   Copyright (C) 2006-07 Regents of the University of California
   Contact: dmolnar@eecs.berkeley.edu

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/

/* Callbacks for VG_(track_post_mem_write), track_post_reg_write, similar. */
/* Also includes callbacks for syscalls */ 


#include "pub_tool_basics.h"
#include "pub_tool_libcassert.h"
#include "pub_tool_tooliface.h"

#include "pub_tool_libcprint.h"
#include "pub_tool_debuginfo.h"
#include "pub_tool_libcbase.h"
#include "pub_tool_libcfile.h" 
#include "pub_tool_options.h"
#include "pub_tool_hashtable.h" 

#include "catchconv.h"
#include "ca_callbacks.h" 
#include "ca_interval.h"
#include "isIR.h" 
#include "ogIR.h" 
#include "cgIR.h"
#include "ca_settings.h" 


Bool isReadSyscall = 0; 
Bool isInputFile = 0; 
OffT fileOffset = 0; 

void ca_track_pre_mem_write (CorePart part, ThreadId tid, Char* info,
			     Addr a, SizeT size)
{
  Char * offset; 
  Char * fname;

  /* The info char * contains the file name and offset from a read, mmap,
     or mmap2 system call. This is an ugly way to pass information from 
     the core to the tool, but it is what we have now. */ 
  offset = VG_(strstr)(info, "offset"); 
  fname = VG_(strstr)(info, "fname");
  fname = fname + 5; 

  if (offset != NULL && fname != NULL)
  {
    if (ca_output_comment)
    {
      if (info != NULL)
      {
	VG_(printf)("XXX prememwrite info: %s \n", info); 
      }
      VG_(printf)("XXX read: fname %s size %d \n", fname, size);
      VG_(printf)("XXX inputfilename : %s \n", inputfilename); 
    }
  /* Now we have the file name, check if this is an input file. */
  /* Use file name from --input-file=<inputfilename>, set in ca_main.c */ 
  /* Set the isInputFile flag accordingly. */  
    if (inputfilename != NULL && (VG_(strstr)(fname, inputfilename) != NULL))
    {
      isInputFile = 1; 
      // change the global variable run_prefix_task to true 
      // first time (and every time) isInputFile is 1
      run_prefix_task = 1; 
      fileOffset = VG_(strtoll10)(offset+7, NULL); // strip off "offset" convert to int

     if (ca_output_comment) 
     {
       VG_(printf)("XXX fname %s matches inputfilename %s \n", fname, inputfilename);  
       VG_(printf)("XXX RUN PREFIX TASK = 1\n");
       VG_(printf)("XXX fileOffset : %d \n", fileOffset); 
     }
    }
    else
    {
      isInputFile = 0; 
      fileOffset = 0; 
    }
  }
}
		  
    

/*void VG_(track_post_mem_write)     (void(*f)(CorePart part, ThreadId tid,
  Addr a, SizeT size)); */
void ca_track_post_mem_write (CorePart part, ThreadId tid, Addr a, SizeT size)
{
  Addr index; 
  OffT curOff; 

  if (ca_output_comment)
  {
    VG_(printf)("XXX POSTMEMWRITE Addr %x ", a); 
    VG_(printf)("Size %u \n",size); 
  }
  curOff = fileOffset; 

  for (index = a; index < (a+size); index += 1)
  {
    cgEmitStoreInfoByte(index); 
    
      /* If this is a read, mark the memory as origin. Later 
	 reads from these addresses 
	 will then emit the proper declaration of new variable 
	 and symbolic updates. Note that in this case we do
	 not update the MemState array with the concrete value,
	 as we would just end up ignoring that value later. */ 

      /* isReadSyscall is global, set in pre- and post- syscall wrappers */
      /* Assumes single-threaded. Really should have an array of flags, */
      /* one for each thread, and look up the current running TID.  */ 

      /* isInputFile is global, set in pre-mem-write wrapper by looking */
      /* at the filename read and comparing against a list of input files */ 

    if (ca_output_comment)
    {
      VG_(printf)("XXX isReadSysCall %u isInputFile %u \n", isReadSyscall, isInputFile); 
    }

      if (isReadSyscall && isInputFile)
      {
	if (ca_output_comment)
	{
	  VG_(printf)("XXX Setting mem %x to origin at offset %d for  \
read syscall from input file.\n",index, curOff);
	}

	  isSetKeyOrigin(locToHashKey(index,0,MemLoc), curOff); 
	}
      /* If memory location is symbolic but not
	 an origin, then we need to eagerly
	 update the MemState value. Otherwise, we can be lazy and
	 wait for the later load to obtain the concrete value. */ 
      else if (isKeySymbolicP(locToHashKey(index,0,MemLoc)))
      {
	cgEmitStoreConstConcrete(index); 
      }
      curOff++; 
    }

  return; 
}

/* void VG_(track_post_reg_write)(void(*f)(CorePart part, ThreadId tid,
                                        OffT guest_state_offset,
                                        SizeT size)); */

void ca_track_post_reg_write (CorePart part, ThreadId tid, OffT offset,
			      SizeT size)
{
  IRType assignty; 

  switch (size)
    {
    case 1:
      assignty = Ity_I8;
      break; 
    case 2:
      assignty = Ity_I16;
      break;
    case 4:
      assignty = Ity_I32;
      break; 
    default:
      assignty = Ity_I32;

      if (ca_output_comment)
      {
	VG_(printf)("XXX Unhandled size-to-type in POSTREGWRITE \n");
      }
      break; 
    }
  if (ca_output_comment)
  {
    VG_(printf)("XXX POSTREGWRITE Offset %x ", offset); 
    VG_(printf)("Size %u \n",size); 
  }

  if (isKeySymbolicP(locToHashKey(offset,0,RegLoc)) || isReadSyscall  )
       cgEmitPutUnconstrained_32Bit(offset, assignty); 
  return; 
}


/* void VG_(track_post_reg_write_clientcall_return)(
   void(*f)(ThreadId tid, OffT guest_state_offset, SizeT size, Addr f)); */

void ca_track_post_reg_write_clientcall_return (ThreadId tid, OffT offset,
						SizeT size, Addr f)
{

  if (ca_output_comment)
  {
    VG_(printf)("XXX POSTREGWRITECLIENTCALL Offset %x ", offset); 
    VG_(printf)("Size %u ",size); 
    VG_(printf)("Addr %x \n", f); 
  }
  return; 
}


/* extern void VG_(needs_syscall_wrapper) (
   void (* pre_syscall)(ThreadId tid, UInt syscallno),
   void (*post_syscall)(ThreadId tid, UInt syscallno, SysRes res)
   ); */

void ca_pre_syscall (ThreadId tid, UInt syscallno)
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX PRESYSCALL ThreadId %u ", tid);
    VG_(printf)("SyscallNum %u ", syscallno);
    ca_print_syscall_name(syscallno);  
    VG_(printf)("\n"); 
  }

#define READSYSCALLNUM 3
#define MMAPSYSCALLNUM 90
#define MMAP2SYSCALLNUM 192
#define DARWINSYSCALLNUM 33554828
  if (syscallno == READSYSCALLNUM 
      || syscallno == MMAPSYSCALLNUM
      || syscallno == MMAP2SYSCALLNUM
      || syscallno == DARWINSYSCALLNUM 
      ) // is this a syscall that could be a taint source?
  {
    // if so, then set flag
    isReadSyscall = 1;       // XXX Will break in multi-threaded programs?
    if (ca_output_comment)
    {
      VG_(printf)("XXX Taint source syscall detected. Syscall number %d. \n", syscallno); 
    }
  }

  return; 
}

void ca_post_syscall(ThreadId tid, UInt syscallno, SysRes res)
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX POSTSYSCALL ThreadId %u ", tid);
    VG_(printf)("SyscallNum %u ", syscallno); 
    ca_print_syscall_name(syscallno);  
    VG_(printf)(" Result %x \n", sr_Res(res)); 
  }

  isReadSyscall = 0; // Syscall is over, no matter what it was
                     // XXX This will break in multi-threaded programs?

  return; 
}

void ca_print_syscall_name(UInt syscallno)
{

  switch(syscallno)
    {

    case 0:
      VG_(printf)("restart_syscall"); 
      break; 
    case 1:
      VG_(printf)("sys_exit"); 
      break; 
    case 2:
      VG_(printf)("sys_fork"); 
      break;
    case 3:
      VG_(printf)("sys_read"); 
      break;
    case 4:
      VG_(printf)("sys_write"); 
      break; 
    case 5:
      VG_(printf)("sys_open"); 
      break;
    case 6:
      VG_(printf)("sys_close");
      break;
    case 7:
      VG_(printf)("sys_waitpid");
      break;
    case 8:
      VG_(printf)("sys_creat");
      break;
    case 9:
      VG_(printf)("sys_link"); 
      break;
    case 10:
      VG_(printf)("sys_unlink"); 
      break;
    case 11:
      VG_(printf)("sys_execve"); 
      break;
    case 12:
      VG_(printf)("sys_chdir"); 
      break;
    case 13:
      VG_(printf)("sys_time"); 
      break;
    case 14:
      VG_(printf)("sys_mknod"); 
      break;
    case 15:
      VG_(printf)("sys_chmod");
      break;
    case 16:
      VG_(printf)("sys_lchown16"); 
      break;
    case 17:
      VG_(printf)("sys_ni_syscall");
      break;
    case 18:
      VG_(printf)("sys_stat"); 
      break; 
    case 19:
      VG_(printf)("sys_lseek"); 
      break; 
    case 20:
      VG_(printf)("sys_getpid"); 
      break; 
    case 21:
      VG_(printf)("sys_mount");
      break;
    case 22:
      VG_(printf)("sys_oldumount"); 
      break;
    case 23:
      VG_(printf)("sys_setuid16"); 
      break;
    case 24:
      VG_(printf)("sys_getuid16"); 
      break; 
    case 25:
      VG_(printf)("sys_stime"); 
      break;
    case 26:
      VG_(printf)("sys_ptrace"); 
      break;
    case 27:
      VG_(printf)("sys_alarm"); 
      break; 
    case 28:
      VG_(printf)("sys_oldfstat"); 
      break; 
    case 29:
      VG_(printf)("sys_pause"); 
      break; 
    case 30:
      VG_(printf)("sys_utime"); 
      break; 
    case 31:
      VG_(printf)("sys_stty"); 
      break; 
    case 32:
      VG_(printf)("sys_gtty"); 
      break; 
    case 33:
      VG_(printf)("sys_access"); 
      break; 
    case 34:
      VG_(printf)("sys_nice"); 
      break; 
    case 35:
      VG_(printf)("sys_ftime"); 
      break; 
    case 36:
      VG_(printf)("sys_sync"); 
      break; 
    case 37:
      VG_(printf)("sys_kill"); 
      break; 
    case 38:
      VG_(printf)("sys_rename"); 
      break; 
    case 39:
      VG_(printf)("sys_mkdir"); 
      break; 
    case 40:
      VG_(printf)("sys_rmdir"); 
      break; 
    case 41:
      VG_(printf)("sys_dup"); 
      break; 
    case 42:
      VG_(printf)("sys_pipe"); 
      break; 
    case 43:
      VG_(printf)("sys_times"); 
      break; 
    case 44:
      VG_(printf)("sys_prof"); 
      break; 
    case 45:
      VG_(printf)("sys_brk"); 
      break;    
    case 46:
      VG_(printf)("sys_setgid16"); 
      break; 
    case 47:
      VG_(printf)("sys_getgid16"); 
      break; 
    case 48:
      VG_(printf)("sys_signal"); 
      break; 
    case 49:
      VG_(printf)("sys_geteuid16"); 
      break; 
    case 50:
      VG_(printf)("sys_getegid16"); 
      break; 
    case 51:
      VG_(printf)("sys_acct"); 
      break; 
    case 52:
      VG_(printf)("sys_umount"); 
      break; 
    case 53:
      VG_(printf)("sys_lock"); 
      break; 
    case 54:
      VG_(printf)("sys_ioctl"); 
      break; 
    case 55:
      VG_(printf)("sys_fnctl"); 
      break; 
    case 56:
      VG_(printf)("sys_mpx"); 
      break; 
    case 57:
      VG_(printf)("sys_setpgid"); 
      break; 
    case 58:
      VG_(printf)("sys_ulimit"); 
      break; 
    case 59:
      VG_(printf)("sys_olduname"); 
      break; 
    case 60:
      VG_(printf)("sys_umask"); 
      break; 
    case 61:
      VG_(printf)("sys_chroot"); 
      break; 
    case 62:
      VG_(printf)("sys_ustat"); 
      break; 
    case 63:
      VG_(printf)("sys_dup2"); 
      break; 
    case 64:
      VG_(printf)("sys_getppid"); 
      break; 
    case 65:
      VG_(printf)("sys_getpgrp"); 
      break; 
    case 66:
      VG_(printf)("sys_setsid"); 
      break; 
    case 67:
      VG_(printf)("sys_sigaction"); 
      break; 
    case 68:
      VG_(printf)("sys_sgetmask"); 
      break; 
    case 69:
      VG_(printf)("sys_ssetmask"); 
      break; 
    case 70:
      VG_(printf)("sys_setreuid16"); 
      break; 
    case 71:
      VG_(printf)("sys_setregid16"); 
      break; 
    case 72:
      VG_(printf)("sys_sigsuspend"); 
      break; 
    case 73:
      VG_(printf)("sys_sigpending"); 
      break; 
    case 74:
      VG_(printf)("sys_sethostname"); 
      break; 
    case 75:
      VG_(printf)("sys_setrlimit"); 
      break; 
    case 76:
      VG_(printf)("sys_old_getrlimit"); 
      break; 
    case 77:
      VG_(printf)("sys_getrusage"); 
      break; 
    case 78:
      VG_(printf)("sys_gettimeofday"); 
      break; 
    case 79:
      VG_(printf)("sys_settimeofday"); 
      break; 
    case 80:
      VG_(printf)("sys_getgroups16"); 
      break; 
    case 81:
      VG_(printf)("sys_setgroups16"); 
      break; 
    case 83:
      VG_(printf)("sys_symlink"); 
      break; 
    case 84:
      VG_(printf)("sys_oldlstat"); 
      break; 
    case 85:
      VG_(printf)("sys_readlink"); 
      break; 
    case 86:
      VG_(printf)("sys_uselib"); 
      break; 
    case 87:
      VG_(printf)("sys_swapon"); 
      break; 
    case 88:
      VG_(printf)("sys_reboot"); 
      break; 
    case 89:
      VG_(printf)("old_readdir");
      break; 
    case 90:
      VG_(printf)("old_mmap");
      break; 
    case 91:
      VG_(printf)("sys_munmap"); 
      break; 
    case 92:
      VG_(printf)("sys_truncate"); 
      break; 
    case 93:
      VG_(printf)("sys_ftruncate"); 
      break; 
    case 94:
      VG_(printf)("sys_fchmod"); 
      break; 
    case 95:
      VG_(printf)("sys_fchown16"); 
      break; 
    case 96:
      VG_(printf)("sys_getpriority"); 
      break; 
    case 97:
      VG_(printf)("sys_setpriority"); 
      break; 
    case 98:
      VG_(printf)("sys_profil"); 
      break; 
    case 99:
      VG_(printf)("sys_statfs"); 
      break; 
    case 100:
      VG_(printf)("sys_fstatfs"); 
      break; 
    case 101:
      VG_(printf)("sys_ioperm"); 
      break; 
    case 102:
      VG_(printf)("sys_socketcall"); 
      break; 
    case 103:
      VG_(printf)("sys_syslog"); 
      break; 
    case 104:
      VG_(printf)("sys_setitimer"); 
      break; 
    case 105:
      VG_(printf)("sys_getitimer"); 
      break; 
    case 106:
      VG_(printf)("sys_newstat"); 
      break; 
    case 107:
      VG_(printf)("sys_newlstat"); 
      break; 
    case 108:
      VG_(printf)("sys_newfstat"); 
      break; 
    case 109:
      VG_(printf)("sys_olduname"); 
      break; 
    case 110:
      VG_(printf)("sys_iopl"); 
      break; 
    case 111:
      VG_(printf)("sys_vhangup"); 
      break; 
    case 112:
      VG_(printf)("sys_idle"); 
      break; 
    case 113:
      VG_(printf)("sys_vm86old"); 
      break; 
    case 114:
      VG_(printf)("sys_wait4"); 
      break; 
    case 115:
      VG_(printf)("sys_swapoff"); 
      break; 
    case 116:
      VG_(printf)("sys_sysinfo"); 
      break; 
    case 117:
      VG_(printf)("sys_ipc"); 
      break; 
    case 118:
      VG_(printf)("sys_fsync"); 
      break; 
    case 119:
      VG_(printf)("sys_sigreturn"); 
      break; 
    case 120:
      VG_(printf)("sys_clone"); 
      break; 
    case 121:
      VG_(printf)("sys_setdomainname"); 
      break; 
    case 122:
      VG_(printf)("sys_newuname"); 
      break; 
    case 123:
      VG_(printf)("sys_modify_ldt"); 
      break; 
    case 124:
      VG_(printf)("sys_adjtimex"); 
      break; 
    case 125:
      VG_(printf)("sys_mprotect"); 
      break; 
    case 126:
      VG_(printf)("sys_sigprocmask"); 
      break; 
    case 127:
      VG_(printf)("sys_create_module"); 
      break; 
    case 128:
      VG_(printf)("sys_init_module"); 
      break; 
    case 129:
      VG_(printf)("sys_delete_module"); 
      break; 
    case 130:
      VG_(printf)("sys_get_kernel_syms"); 
      break; 
    case 131:
      VG_(printf)("sys_quotactl"); 
      break; 
    case 132:
      VG_(printf)("sys_getpgid"); 
      break; 
    case 133:
      VG_(printf)("sys_fchdir"); 
      break; 
    case 134:
      VG_(printf)("sys_bdflush"); 
      break; 
    case 135:
      VG_(printf)("sys_sysfs"); 
      break; 
    case 136:
      VG_(printf)("sys_personality"); 
      break; 
    case 137:
      VG_(printf)("sys_afs_syscall"); 
      break; 
    case 138:
      VG_(printf)("sys_setfsuid16"); 
      break; 
    case 139:
      VG_(printf)("sys_setfsgid16"); 
      break; 
    case 140:
      VG_(printf)("sys_llseek"); 
      break; 
    case 141:
      VG_(printf)("sys_getdents"); 
      break; 
    case 142:
      VG_(printf)("sys_select"); 
      break; 
    case 143:
      VG_(printf)("sys_flock"); 
      break; 
    case 144:
      VG_(printf)("sys_msync"); 
      break; 
    case 145:
      VG_(printf)("sys_readv"); 
      break; 
    case 146:
      VG_(printf)("sys_writev"); 
      break; 
    case 147:
      VG_(printf)("sys_getsid"); 
      break; 
    case 148:
      VG_(printf)("sys_fdatasync"); 
      break; 
    case 149:
      VG_(printf)("sys_sysctl"); 
      break; 
    case 150:
      VG_(printf)("sys_mlock"); 
      break; 
    case 151:
      VG_(printf)("sys_munlock"); 
      break; 
    case 152:
      VG_(printf)("sys_mlockall"); 
      break; 
    case 153:
      VG_(printf)("sys_munlockall"); 
      break; 
    case 154:
      VG_(printf)("sys_sched_setparam"); 
      break; 
    case 155:
      VG_(printf)("sys_sched_getparam"); 
      break; 
    case 156:
      VG_(printf)("sys_sched_setscheduler"); 
      break; 
    case 157:
      VG_(printf)("sys_sched_getscheduler"); 
      break; 
    case 158:
      VG_(printf)("sys_sched_yield"); 
      break; 
    case 159:
      VG_(printf)("sys_sched_get_priority_max"); 
      break; 
    case 160:
      VG_(printf)("sys_sched_get_priority_min"); 
      break; 
    case 161:
      VG_(printf)("sys_sched_rr_get_interval"); 
      break; 
    case 162:
      VG_(printf)("sys_nanosleep"); 
      break; 
    case 163:
      VG_(printf)("sys_mremap"); 
      break; 
    case 164:
      VG_(printf)("sys_setresuid16"); 
      break; 
    case 165:
      VG_(printf)("sys_getresuid16"); 
      break; 
    case 166:
      VG_(printf)("sys_vm86"); 
      break; 
    case 167:
      VG_(printf)("sys_query_module"); 
      break; 
    case 168:
      VG_(printf)("sys_poll"); 
      break; 
    case 169:
      VG_(printf)("sys_nfsservctl"); 
      break; 
    case 170:
      VG_(printf)("sys_setresgid16"); 
      break; 
    case 171:
      VG_(printf)("sys_getresgid16"); 
      break; 
    case 172:
      VG_(printf)("sys_prctl"); 
      break; 
    case 173:
      VG_(printf)("sys_rt_sigreturn"); 
      break; 
    case 174:
      VG_(printf)("sys_rt_sigaction"); 
      break; 
    case 175:
      VG_(printf)("sys_rt_sigprocmask"); 
      break; 
    case 176:
      VG_(printf)("sys_rt_sigpending"); 
      break; 
    case 177:
      VG_(printf)("sys_rt_sigtimedwait"); 
      break; 
    case 178:
      VG_(printf)("sys_rt_sigqueueinfo"); 
      break; 
    case 179:
      VG_(printf)("sys_rt_sigsuspend"); 
      break; 
    case 180:
      VG_(printf)("sys_pread64"); 
      break; 
    case 181:
      VG_(printf)("sys_pwrite64"); 
      break; 
    case 182:
      VG_(printf)("sys_chown16"); 
      break; 
    case 183:
      VG_(printf)("sys_getcwd"); 
      break; 
    case 184:
      VG_(printf)("sys_capget"); 
      break; 
    case 185:
      VG_(printf)("sys_capset"); 
      break; 
    case 186:
      VG_(printf)("sys_signalstack"); 
      break; 
    case 187:
      VG_(printf)("sys_sendfile"); 
      break; 
    case 188:
      VG_(printf)("sys_getpmsg"); 
      break; 
    case 189:
      VG_(printf)("sys_putpmsg"); 
      break; 
    case 190:
      VG_(printf)("sys_fork"); 
      break; 
    case 191:
      VG_(printf)("sys_getrlimit"); 
      break; 
    case 192:
      VG_(printf)("sys_mmap2"); 
      break; 
    case 193:
      VG_(printf)("sys_truncate64"); 
      break; 
    case 194:
      VG_(printf)("sys_ftruncate64"); 
      break; 
    case 195:
      VG_(printf)("sys_stat64"); 
      break; 
    case 196:
      VG_(printf)("sys_lstat64"); 
      break; 
    case 197:
      VG_(printf)("sys_fstat64"); 
      break; 
    case 198:
      VG_(printf)("sys_lchown"); 
      break; 
    case 199:
      VG_(printf)("sys_getuid"); 
      break; 



    case 243:
      VG_(printf)("sys_set_thread_area"); 
      break; 

    case 252:
      VG_(printf)("sys_exit_group");
      break; 


    default:
      VG_(printf)("Uhandled syscallno: %d", syscallno); 
     
    }

}
