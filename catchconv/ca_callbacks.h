/*--------------------------------------------------------------------*/
/*--- CatchConversions                       ca_callbacks.h        ---*/
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

/* Header file for memory update and syscall update callbacks. */ 

void ca_track_pre_mem_write (CorePart part, ThreadId tid, 
			     Char * info, Addr a, SizeT size);

void ca_track_post_mem_write (CorePart part, ThreadId tid, Addr a, SizeT size);

void ca_track_post_reg_write (CorePart part, ThreadId tid, OffT offset,
			      SizeT size);

void ca_track_post_reg_write_clientcall_return (ThreadId tid, OffT offset,
						SizeT size, Addr f);

void ca_pre_syscall (ThreadId tid, UInt syscallno);

void ca_post_syscall(ThreadId tid, UInt syscallno, SysRes res);

void ca_print_syscall_name(UInt syscallno);
