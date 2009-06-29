
/*--------------------------------------------------------------------*/
/*--- CatchConversions                           findRepMov.c      ---*/
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
#include "ogIR.h" 
#include "cgIR.h" 
#include "ca_settings.h"
#include "findRepMov.h"
#include "ogIR.h"
#include "ufOgIR.h"

// Check to see whether the basic block looks like a rep mov statement.
// If so, add type constraints

findRepMovContext * createRepMovContext(int numTmpVars)
{
  findRepMovContext * newContext;

  newContext = (findRepMovContext *) VG_(malloc)("repMov",sizeof(findRepMovContext)); 
  newContext->subTmpVars = (int *) VG_(calloc)("repMov",numTmpVars,sizeof(int)); 
  newContext->cmpZeroTmpVars = (int *) VG_(calloc)("repMov",numTmpVars,sizeof(int)); 

  return newContext; 
}

void destroyRepMovContext(findRepMovContext * context)
{
  VG_(free)(context->subTmpVars); 
  VG_(free)(context->cmpZeroTmpVars); 
  VG_(free)(context); 
}

void emitFlaggedTmpRepMov(HWord tmpName, HWord tagVal)
{
  IntType newTy; 
  IntType oldTy; 
  ufOgNode * tmpNode;

  // find canonical representative corresponding to tmpName
  tmpNode = ufFind(tmpNametoNode(tmpName, tagVal, cgBBExecCounter)); 
  
  //  newTy = setTypeOfToMeet(getVarOf(locToHashKey(tmpName,tagVal,TmpLoc)),UnsignedTy);
  oldTy = tmpNode->tmpType; 

  switch (oldTy)
  {
  case UnsignedTy:
    //    VG_(printf)("XXX tmpName: %u  BB %u  was unsigned \n", tmpName, tagVal); 
    break; 
  case Top:
    //    VG_(printf)("XXX tmpName: %u %u BB %u was Top \n", tmpName, tmpNode->tmpName, tagVal); 
    break; 
  case SignedTy:
    //    VG_(printf)("XXX tmpName: %u BB %u was signed \n", tmpName, tagVal); 
    break; 
  case Bot:
    //    VG_(printf)("XXX tmpName: %u BB %u was Bot \n", tmpName, tagVal); 
    break; 
  }

  newTy = ufMeet(UnsignedTy, tmpNode->tmpType); 
  tmpNode->tmpType = newTy; 

  switch (newTy)
  {
  case UnsignedTy:
    //    VG_(printf)("XXX tmpName: %u BB %u now unsigned \n", tmpName, tagVal); 
    break;
  case Bot:
    //    VG_(printf)("XXX tmpName: %u BB %u now Bot \n", tmpName, tagVal);
    cgEmitQueryBadRange(tmpName, tagVal);
    break;
  default:
    break;
  }
}



UInt checkTmpRepMov(UInt tmpName, findRepMovContext * context)
{
  if (context->subTmpVars[tmpName] == 1 && context->cmpZeroTmpVars[tmpName] == 1)
  {
    return 1; 
  }
  else
  {
    return 0;
  }
}

void findRepMovIRStmt(IRSB * bb, IRStmt * s, findRepMovContext * context, UInt tagVal)
{
  vassert(context != NULL); 
  switch (s->tag)
  {
  case Ist_WrTmp:
    findRepMovIRExpr(bb, s, context, tagVal); 
  default:
    break; 
  }

  return; 
} 

void findRepMovIRExpr(IRSB * bb, IRStmt * s, findRepMovContext * context, UInt tagVal)
{
  IROp theOp; 
  IRExpr * expr; 
  IRExpr * arg1;
  IRExpr * arg2; 
  UInt tmpName; 
  IRDirty * d; 

  expr = s->Ist.WrTmp.data; 
  
  switch (expr->tag)
  {
  case Iex_Binop:
    theOp = expr->Iex.Binop.op;
    arg1 = expr->Iex.Binop.arg1;
    arg2 = expr->Iex.Binop.arg2; 

    switch(theOp)
    {
    case Iop_Sub32:
    case Iop_Sub16:
    case Iop_Sub8:
      if (arg2->tag == Iex_Const && arg1->tag == Iex_RdTmp)
      {
	tmpName = (UInt) arg1->Iex.RdTmp.tmp; 
	context->subTmpVars[tmpName] = 1; 

	if (checkTmpRepMov(tmpName, context) == 1)
	{
	  //	  VG_(printf)("XXX tmpName: %u BB %u flagged by checkTmpRepMov! \n", tmpName, tagVal);

	  d = unsafeIRDirty_0_N(0,
				"emitFlaggedTmpRepMov",
				&emitFlaggedTmpRepMov,
				mkIRExprVec_2(
					      mkIRExpr_HWord(tmpName),
					      mkIRExpr_HWord(tagVal)
					      )
				);
	  setHelperAnns(d); 
	  addStmtToIRSB(bb, IRStmt_Dirty(d)); 
	}
      }
      break; 

    case Iop_CmpEQ32:
    case Iop_CmpEQ16:
    case Iop_CmpEQ8:
      if (arg2->tag == Iex_Const && arg1->tag == Iex_RdTmp)
	{
	  tmpName = (UInt) arg1->Iex.RdTmp.tmp; 
	  if (arg2->Iex.Const.con->Ico.U32 == 0)
	  {
	    context->cmpZeroTmpVars[tmpName] = 1; 

	    if (checkTmpRepMov(tmpName, context) == 1)
	    {
	      //	      VG_(printf)("XXX tmpName: %u BB %u flagged by checkTmpRepMov! \n", tmpName, tagVal);
	      d = unsafeIRDirty_0_N(0,
				    "emitFlaggedTmpRepMov",
				    &emitFlaggedTmpRepMov,
				    mkIRExprVec_2(
						  mkIRExpr_HWord(tmpName),
						  mkIRExpr_HWord(tagVal)
						  )
				    );
	      setHelperAnns(d); 
	      addStmtToIRSB(bb, IRStmt_Dirty(d)); 
	    }
	  }
      }
      break; 

    default:
      break; 
    }
  default:
    break; 
  }
  return; 
}
