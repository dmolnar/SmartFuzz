/*--------------------------------------------------------------------*/
/*--- CatchConversions                        ca_malloc_wrappers.c ---*/
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


/* Wrappers for malloc() and friends. Check for bogus args, then manage */
/* constraints for region-based memory allocation. */ 

#include "pub_tool_basics.h"
#include "pub_tool_errormgr.h"     
#include "pub_tool_execontext.h"   
#include "pub_tool_hashtable.h"    
#include "pub_tool_libcbase.h"
#include "pub_tool_libcassert.h"
#include "pub_tool_libcprint.h"
#include "pub_tool_mallocfree.h"
#include "pub_tool_options.h"
#include "pub_tool_replacemalloc.h"
#include "pub_tool_threadstate.h"
#include "ca_malloc_wrappers.h" 
#include "ca_interval.h" 
#include "ca_settings.h"

void * CA_new_block(ThreadId tid, SizeT n)
{
  Addr p; 
  SizeT align;
  caChunkTy * newChunk; 

  align = VG_(clo_alignment); 
  
  p = (Addr)VG_(cli_malloc)(align, n); 

  if (ca_output_comment)
  {
    VG_(printf)("XXX MALLOC_NEW_BLOCK tid %ld ", tid); 
    VG_(printf)("base %x ", p); 
    VG_(printf)("size %u \n", n); 
  }

  if (p)
    {
    	// was deleted for MEMORY
      if (run_buffer_overflow_task == 1) {	
      	newChunk = caInsertInterval(p,n,caIntervalTable); 
      	caDeclareChunk(newChunk); 
      }
    }

  return (void *)p; 

}

Bool bad_malloc_arg(SizeT n)
{

  /* Check to see if malloc arg is negative. If so, we have a bug. */ 

  return ((SSizeT)n < 0); 
}

Bool bad_calloc_args(SizeT n1, SizeT n2)
{
  /* Check to see if either  arg is negative. If so, we have a bug. */ 
  return ( ((SSizeT)n1 < 0 || (SSizeT)n2 < 0)); 


}



void * CA_malloc(ThreadId tid, SizeT n)
{

  if (bad_malloc_arg(n))
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX EVIL malloc arg %d \n", (SSizeT)n); 
      }
      return NULL;
    }
  else 
    {
      return CA_new_block(tid, n);
    }
}
 
void * CA__builtin_new(ThreadId tid, SizeT n)
{

 if (bad_malloc_arg(n))
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX EVIL __builtin_new arg %ld \n", (SSizeT)n); 
      }
      return NULL;
    }
  else 
    {
      return CA_new_block(tid, n);
    }

}

void * CA__builtin_vec_new(ThreadId tid, SizeT n) 
{

 if (bad_malloc_arg(n))
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX EVIL __builtin_vec_new arg %ld \n", (SSizeT)n); 
      }
      return NULL;
    }
  else 
    {
      return CA_new_block(tid, n);
    }

}

void * CA_memalign(ThreadId tid, SizeT align, SizeT n) 
{
 if (bad_calloc_args(align,n))
    {

      if (ca_output_comment)
      {
	VG_(printf)("XXX EVIL memalign args %ld", align);
	VG_(printf)(" %ld \n", n); 
      }
      return NULL;
    }
  else 
    {
      return CA_new_block(tid, n);
    }
}

void * CA_calloc(ThreadId tid, SizeT n1, SizeT n2) 
{
  if (bad_calloc_args(n1,n2))
  {
    if (ca_output_comment)
    {
      VG_(printf)("XXX EVIL calloc args %ld ",n1); 
      VG_(printf)(" %ld \n", n2);
    } 
    return NULL; 
  }
      else
  {
    return CA_new_block(tid, n1*n2);
  }
      
}

void CA_free(ThreadId tid, void * ptr) 
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX FREE %x \n", ptr); 
  }
  //  VG_(free)(ptr); 
}

void CA__builtin_delete(ThreadId tid, void * ptr) 
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX FREE %x \n", ptr); 
  }
  // VG_(free)(ptr); 
}

void CA__builtin_vec_delete(ThreadId tid, void * ptr) 
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX FREE %x \n", ptr); 
  }
  // VG_(free)(ptr); 
}

void * CA_realloc(ThreadId tid, void * ptr, SizeT n) 
{

  Addr p; 

  /* Temporarily bypass CA_realloc due to problem in imageMagick */ 
  /* VG_AR_CLIENT = 3, see pub_core_mallocfree.h                 */
  return (void *)VG_(arena_realloc)(3, ptr, n); 

  if (bad_malloc_arg(n))
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX EVIL realloc arg %d", (SSizeT)n); 
      }
      return NULL;
    }
  else 
    {

      p = (Addr) CA_new_block(tid, n);
      if (p)
	{
	  VG_(memcpy)( (void *) p, ptr, n);  // this isn't right
	                                     // since n should be old_size
	  CA_free(tid, ptr); 
	}

      return (void *)p; 
    }

 
}
