/*--------------------------------------------------------------------*/
/*--- CatchConversions                          ca_interval_dumb.c ---*/
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

/* Dumb O(n) implementation of interval data structure. */ 

#include "libvex_basictypes.h"
#include "libvex_ir.h"
#include "libvex.h"

#include "ca_vex_util.h"


#include "pub_tool_basics.h"
#include "pub_tool_libcassert.h"
#include "pub_tool_tooliface.h"

#include "pub_tool_libcprint.h"
#include "pub_tool_debuginfo.h"
#include "pub_tool_libcbase.h"
#include "pub_tool_options.h"
#include "pub_tool_hashtable.h"
#include "pub_tool_mallocfree.h"
#include "pub_tool_libcproc.h" 
#include "pub_tool_threadstate.h" 

#include "ca_interval.h" 
#include "cgIR.h" 
#include "isIR.h"
#include "ogIR.h"
#include "ca_settings.h"
#include "catchconv.h"



#define MAX_CHUNK_SIZE 4290000 

caChunkTy * caAddrToChunk(Addr a, caIntervalStruct table)
{

  caChunkTy * curChunk;
  caChunkTy * retChunk; 
  SizeT curRetChunkSize; 

  retChunk = NULL; 
  curChunk = NULL; 
  curRetChunkSize = MAX_CHUNK_SIZE; 

  VG_(HT_ResetIter)(table); 

 
    for (curChunk = VG_(HT_Next)(table); curChunk != NULL; curChunk = VG_(HT_Next)(table))
    {
      if (a >= curChunk->baseAddr && a <= (curChunk->baseAddr+curChunk->size))
	{

	  if (curChunk->size < curRetChunkSize)
	    {
	      retChunk = curChunk; 
	      curRetChunkSize = curChunk->size; 
	    }
	}
    }
  return retChunk;
}


caChunkTy * caInsertInterval(Addr base, SizeT size, caIntervalStruct table)
{
  caChunkTy * newChunk;

  newChunk = VG_(malloc)(sizeof(caChunkTy)); 

  newChunk->baseAddr = base; 
  newChunk->size = size; 
  newChunk->regSize = caPickSize(size); 
  newChunk->n_instance = 0; 

  VG_(HT_add_node(table,newChunk)); 

  return newChunk; 
}


void caDeleteInterval(caChunkTy * chunk, caIntervalStruct table)
{
  if (chunk)
    VG_(HT_remove)(table, chunk->baseAddr); 
  return; 
}

HWord caPickSize(SizeT n)
{

  if (n > (1<<28)) return 32; 
  if (n > (1<<24)) return 28; 
  if (n > (1<<20)) return 24;
  if (n > (1<<16)) return 20; 
  if (n > (1<<12)) return 16; 
  if (n > (1<<8)) return 12; 
  if (n > (1<<4)) return 8; 
  return 4; 

}


void caDeclareChunk(caChunkTy * chunk)
{
  // MemRegion$INSTANCEp$PIDth$TIDbase$BASEADDR : ARRAY () of BITVECTOR(32);

  HWord PID; 
  HWord TID; 
  vassert(chunk); 

  if (ca_mem_handling == CA_suppress_arrays)
  {
    /* We are suppressing array output, DO NOT declare a new chunk */
    return; 
  }

 
  PID = VG_(getpid)(); 
  TID = VG_(get_running_tid)(); 


  VG_(printf)("MemRegion%u", chunk->n_instance); 
  VG_(printf)("p%u", PID); 
  VG_(printf)("th%u",TID);
  VG_(printf)("base%x",chunk->baseAddr); 
  VG_(printf)(" : ARRAY BITVECTOR (%u) ",chunk->regSize);
  VG_(printf)(" OF BITVECTOR(32);\n"); 

  return;
}


void caDeclareAllIntervals(caIntervalStruct table)
{
  caChunkTy * curChunk; 
  
  VG_(HT_ResetIter)(table); 


  for (curChunk = VG_(HT_Next)(table); curChunk != NULL; curChunk = VG_(HT_Next)(table))
    { 
     
      caDeclareChunk(curChunk); 
    }

  return; 
}
