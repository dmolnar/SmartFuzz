/*--------------------------------------------------------------------*/
/*--- CatchConversions                    ca_malloc_wrappers.h     ---*/
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


/* Header file for catchconv malloc wrappers. */

#include "pub_tool_basics.h" 

#define CA_MALLOC_REDZONE_SZB 16 


typedef
struct __caMemRegionHashNode {
  struct __caMemRegionHashNode * next;
  HWord addr;
  HWord size;  
}
caMemRegionHashNode; 



/* --- Prototypes --- */ 

Bool bad_malloc_arg(SizeT n);
Bool bad_calloc_args(SizeT n1, SizeT n2);


void * CA_new_block(ThreadId tid,SizeT n);
void * CA_malloc(ThreadId tid, SizeT n);
void * CA__builtin_new(ThreadId tid, SizeT n);
void * CA__builtin_vec_new(ThreadId tid, SizeT n);
void * CA_memalign(ThreadId tid, SizeT n1, SizeT n2);
void * CA_calloc(ThreadId tid, SizeT n1, SizeT n2);
void CA_free(ThreadId tid, void * ptr);
void CA__builtin_delete(ThreadId tid, void * ptr);
void CA__builtin_vec_delete(ThreadId tid, void * ptr);
void * CA_realloc(ThreadId tid, void * ptr, SizeT n);

Int run_buffer_overflow_task;
