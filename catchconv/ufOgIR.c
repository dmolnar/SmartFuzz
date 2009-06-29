/*--------------------------------------------------------------------*/
/*--- CatchConversions                           ufOgIR.c          ---*/
/*--------------------------------------------------------------------*/
/*
   Copyright (C) 2006-08 Regents of the University of California
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

#include "ca_interval.h" 
#include "cgIR.h" 
#include "ca_settings.h"
#include "ogIR.h"
#include "ufOgIR.h" 

IntType ufMeet(IntType x, IntType y)
{
  if (x == Bot || y == Bot)
  {
    return Bot; 
  }

  if (x == Top)
  {
    return y; 
  }

  if (y == Top)
  {
    return x; 
  }

  if (x == UnsignedTy)
  {
    if (y == SignedTy)
    {
      return Bot; 
    }
    else
    {
      return UnsignedTy;
    }
  }

  if (x == SignedTy)
  {
    if (y == UnsignedTy)
    {
      return Bot;
    }
    else
    {
      return SignedTy; 
    }
  }

  vpanic("Reached end of ufMeet!\n"); 
  return Top; 
}

ufOgNode * ufSingleton(HWord tmpName, HWord transNum, HWord execNum)
{
  ufOgNode * ret; 
  ret = VG_(malloc)("ufOgIR", sizeof(ufOgNode)); 
  ret->tmpName = tmpName; 
  ret->bbTransNum = transNum; 
  ret->bbExecNum = execNum; 
  ret->tmpType = Top; 
  ret->memRefCount = 0; 
  ret->childRefCount = 0; 
  ret->rank = 0; 
  ret->parent = ret;  
  return ret; 
}

ufOgNode * ufFind(ufOgNode * x)
{
  ufOgNode * y;
  ufOgNode * z; 

  if (x->parent == x)
  { 
    return x;
  }
  else
  {
    y = x->parent; 
    z = ufFind(y); 
    y->childRefCount--; 
    z->childRefCount++; 
    x->parent = z; 
    ufCheck(y, FALSE); 
    return z; 
  }
}

ufOgNode * ufUnion(ufOgNode * x, ufOgNode * y)
{
  ufOgNode * xRoot;
  ufOgNode * yRoot; 


  //  VG_(printf)("XXX ufUnion x: %x y: %x \n", x, y);  
  vassert(x != NULL); 
  vassert(y != NULL); 
  vassert(x->parent != NULL); 
  vassert(y->parent != NULL); 

  xRoot = ufFind(x);
  yRoot = ufFind(y); 

  //  VG_(printf)("XXX ufUnion xRoot: %x yRoot: %x \n", xRoot, yRoot);  

  vassert(xRoot != NULL); 
  vassert(yRoot != NULL);
  vassert(xRoot->parent != NULL); 
  vassert(yRoot->parent != NULL); 

  // VG_(printf)("XXX ufUnion xRoot rank: %u yRoot rank: %u \n", xRoot->rank, yRoot->rank);  
  
  if (xRoot->rank > yRoot->rank)
  {
    yRoot->parent = xRoot; 
    xRoot->tmpType = ufMeet(xRoot->tmpType, yRoot->tmpType);
    xRoot->childRefCount++;
    return xRoot; 
  }
  else if (xRoot->rank < yRoot->rank)
  {
    xRoot->parent = yRoot; 
    yRoot->tmpType = ufMeet(xRoot->tmpType, yRoot->tmpType); 
    yRoot->childRefCount++; 
    return yRoot; 
  }
  else if (xRoot != yRoot)
  {
    yRoot->parent = xRoot; 
    xRoot->rank++;
    xRoot->tmpType = ufMeet(xRoot->tmpType, yRoot->tmpType);
    xRoot->childRefCount++; 
    return xRoot; 
  }
  else if (xRoot == yRoot)
  {
    return xRoot; // is equal to yRoot
  }

  vpanic("Reached end of ufUnion! \n"); // Should not happen!
  return xRoot; 
}
UInt ufCheck(ufOgNode * x, UInt cleanupP)
{
  //  VG_(printf)("XXX ufCheck %u %u %u %u %u \n", x->tmpName, x->bbExecNum, cgBBExecCounter, x->memRefCount, x->childRefCount); 

  if (x->memRefCount == 0 && x->childRefCount == 0)
  {
    if (x->bbExecNum != cgBBExecCounter || (cleanupP == 1) )
    {
      if (x->parent != NULL)
      {
	if (x != x->parent)
	{
	  x->parent->childRefCount--;
	  ufCheck(x->parent, cleanupP);
	}
      }

      ufDestroy(x);
      return 1;      // return code of 1 means we deleted it
    }
  }
  else
  {
    return 0;
  }
  return 0; 
}
 
void ufDestroy(ufOgNode * element)
{
  HWord hashkey; 
  ufOgHashNode * delHashNode; 
  vassert(element != NULL); 
  vassert(element != NULL); 

  //  VG_(printf)("XXX ufDestroy %u %u \n", element->tmpName, element->bbExecNum); 
  hashkey = locToHashKey(element->tmpName, element->bbExecNum, TmpLoc);

  // delete x from H 
  delHashNode = VG_(HT_remove)(ufOgHash, hashkey); 
  if (delHashNode)
  {
    VG_(free)(delHashNode); 
  }

  // delete x from LiveTempVarNodes
  //  delHashNode = VG_(HT_remove)(ufOgLiveTempVarNodes, hashkey); 
  // if (delHashNode)
  //{
  //  VG_(free)(delHashNode); 
  //}
  // free x itself
  VG_(free)(element); 
}
