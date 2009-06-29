/*--------------------------------------------------------------------*/
/*--- CatchConversions                   ca_interval.h             ---*/
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

/* Header file for interval data structure. */ 
/* Maps addresses to malloc'd chunk. */
/* Assumes chunks contiguous. */
/* If addr belongs to more than one chunk, returns the smallest chunk. */ 

typedef
struct __caChunkTy {
  struct __caChunkTy * next;
  HWord baseAddr; 
  SizeT size; 
  HWord regSize; 
  unsigned int n_instance; 
} caChunkTy; 

/* Typedef for vgHashTable based dumb implementation */ 

typedef struct _VgHashTable * caIntervalStruct; 

caIntervalStruct caIntervalTable; 

caChunkTy * caAddrToChunk(Addr a, caIntervalStruct table);
caChunkTy * caInsertInterval(Addr base, SizeT size, caIntervalStruct table); 
void caDeleteInterval(caChunkTy * interval, caIntervalStruct table); 
void caDeclareAllIntervals(caIntervalStruct table); 
void caDeclareChunk(caChunkTy * chunk); 
HWord caPickSize(SizeT n); 
