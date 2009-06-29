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



/* Given a triple (tmpName, transNum, execNum), return a pointer to a */
/* ufOgNode corresponding to the triple. Allocate the node if necessary. */ 
ufOgNode * tmpNametoNode(HWord tmpName, HWord transNum, HWord execNum)
{
  ufOgNode * ret;
  ufOgHashNode * hashret; 
  ufOgHashNode * hashretH;
  ufOgHashNode * hashretLive;
  HWord hashkey; 

  hashkey = locToHashKey(tmpName, execNum, TmpLoc); 

  hashret = VG_(HT_lookup)(ufOgHash, hashkey);
  //  VG_(printf)("XXX tmpNametoNode %u %u %u %x \n", tmpName, transNum, execNum, hashret); 
  if (hashret == NULL )
  {
    ret = ufSingleton(tmpName, transNum, execNum); 
    vassert(ret->parent == ret); 

    hashretH = VG_(malloc)(sizeof(ufOgHashNode)); 
    hashretLive = VG_(malloc)(sizeof(ufOgHashNode)); 
    //    VG_(printf)("XXX tmpNameToNode %u %u %u %x %x %x\n", tmpName, transNum, execNum, hashretH, hashretLive, ret); 
    hashretH->loc = hashkey; 
    hashretH->ufNode = ret; 
    hashretLive->loc = hashkey; 
    hashretLive->ufNode = ret; 
		       
    VG_(HT_add_node)(ufOgHash, hashretH);
    VG_(HT_add_node)(ufOgLiveTempVarNodes, hashretLive); 
  }
  else
  {
    ret = hashret->ufNode; 
    //    VG_(printf)("XXX tmpNameToNode %u %u %u %x \n", tmpName, transNum, execNum, hashret, ret); 
  }
  vassert(ret->parent != NULL); 
  return ret; 
}


void ufInstOgIRStmt (IRBB * bb,  IRStmt* s , ULong bb_counter)
{

  switch (s->tag)
  {
  case Ist_Store:
    ufInstOgIRStore(bb, s, bb_counter);
    break; 
  case Ist_Tmp:
    ufInstOgIRTemp(bb, s, bb_counter); 
    break;
  case Ist_Put:
    ufInstOgIRPut(bb, s, bb_counter); 
    break; 
  case Ist_Exit:
    ufInstOgIRExit(bb, s, bb_counter); 
  default:
    break; 
  }
}


void ufInstOgIRExit (IRBB * bb,  IRStmt* s , ULong bb_counter)
{
  IRDirty * d;
  
  d = unsafeIRDirty_0_N(0, 
			"ufCleanup",
			&ufCleanup, 
			mkIRExprVec_0()
			); 
  
    setHelperAnns(d); 
    addStmtToIRBB(bb, IRStmt_Dirty(d)); 			
}

void ufInstOgIRStore (IRBB * bb,  IRStmt* s , ULong bb_counter)
{
  IRDirty * d; 
  IRExpr * addrExpr; 
  IRExpr * dataExpr; 
  IRExpr ** args; 
  HWord dataTmpName; 
  HWord storeAddr; 

  addrExpr = s->Ist.Store.addr; 
  dataExpr = s->Ist.Store.data; 
 
  switch(addrExpr->tag)
  {
  case Iex_Tmp:

    if (dataExpr->tag == Iex_Tmp)
    {
      dataTmpName = (HWord)dataExpr->Iex.Tmp.tmp; 

      args = mkIRExprVec_3(addrExpr,
			   mkIRExpr_HWord(dataTmpName),
			   mkIRExpr_HWord(bb_counter)
			   ); 

    d = unsafeIRDirty_0_N(0, 
			  "ufHandleStore",
			  &ufHandleStore, 
			  args
			  );
		       
    }
    else if (dataExpr->tag == Iex_Const)
    {

      args = mkIRExprVec_2(addrExpr,
			   mkIRExpr_HWord(bb_counter)
			   ); 

    d = unsafeIRDirty_0_N(0, 
			  "ufHandleStoreConstant",
			  &ufHandleStoreConstant, 
			  args
			  );

      

    }

    setHelperAnns(d); 
    addStmtToIRBB(bb, IRStmt_Dirty(d)); 			
    break; 

  case Iex_Const:
    storeAddr = addrExpr->Iex.Const.con->Ico.U32; 

    if (dataExpr->tag == Iex_Tmp)
    {
      dataTmpName = dataExpr->Iex.Tmp.tmp; 

      d = unsafeIRDirty_0_N(0, 
			    "ufHandleStore",
			    &ufHandleStore, 
			    mkIRExprVec_3(mkIRExpr_HWord(storeAddr),
					  mkIRExpr_HWord(dataTmpName),
					  mkIRExpr_HWord(bb_counter)
					  )
			    ); 
    }
    else if (dataExpr->tag == Iex_Const)
    {
      storeAddr = addrExpr->Iex.Const.con->Ico.U32; 
      d = unsafeIRDirty_0_N(0, 
			    "ufHandleStoreConstant",
			    &ufHandleStoreConstant, 
			    mkIRExprVec_2(mkIRExpr_HWord(storeAddr),
					  mkIRExpr_HWord(bb_counter)
					  )
			    ); 
    }
    else 
    {
      vpanic("dataExpr is neither constant nor temp!\n"); 
    }
      
    setHelperAnns(d); 
    addStmtToIRBB(bb, IRStmt_Dirty(d)); 			
    break; 

  default:
    break; 
  }
}

void ufInstOgIRPut (IRBB * bb,  IRStmt* s , ULong bb_counter)
{
  IRDirty * d; 
  IRExpr * dataExpr; 
  HWord offset; 
  HWord dataTmpName; 

  dataExpr = s->Ist.Put.data; 
  offset = s->Ist.Put.offset;  // offset is constant for PUT, tmp for PUTI
  d = NULL; 

  switch(dataExpr->tag)
  {
  case Iex_Tmp:
    dataTmpName = dataExpr->Iex.Tmp.tmp; 
    d = unsafeIRDirty_0_N(0, 
			  "ufHandleStore",
			  &ufHandleStore, 
			  mkIRExprVec_3(
					mkIRExpr_HWord(offset),
					mkIRExpr_HWord(dataTmpName),
					mkIRExpr_HWord(bb_counter)
					)
			  ); 
    
    setHelperAnns(d); 
    addStmtToIRBB(bb, IRStmt_Dirty(d));     
    break; 

      // if the data is constant, need to decrement memRefCount 
  case Iex_Const:
      d = unsafeIRDirty_0_N(0, 
			    "ufHandleStoreConstant",
			    &ufHandleStoreConstant, 
			    mkIRExprVec_2(
					  mkIRExpr_HWord(offset),
					  mkIRExpr_HWord(bb_counter)
					  )
			    ); 

      setHelperAnns(d); 
      addStmtToIRBB(bb, IRStmt_Dirty(d));     
      break; 
  default:
    break; 
  }
}


UInt isCompare(IROp op)
{
  UInt ret;
  
  ret = 0; 

  switch (op)
  {
  case (Iop_CmpLT32S):
  case (Iop_CmpLT64S):
  case (Iop_CmpLE32S):
  case (Iop_CmpLE64S):
  case(Iop_CmpLT32U):
  case(Iop_CmpLT64U):
  case(Iop_CmpLE32U):
  case(Iop_CmpLE64U):
  case(Iop_CmpEQ32):
  case(Iop_CmpEQ64):
    ret = 1;
       break;
  default:
    ret = 0; 
  }
  return ret; 
}

IntType opToType(IROp op)
{
  IntType ret;

  switch (op)
  {
  case (Iop_CmpLT32S):
  case (Iop_CmpLT64S):
  case (Iop_CmpLE32S):
  case (Iop_CmpLE64S):
  {
      ret = SignedTy;
      break;
  }
  case(Iop_CmpLT32U):
  case(Iop_CmpLT64U):
  case(Iop_CmpLE32U):
  case(Iop_CmpLE64U):
  {
    ret = UnsignedTy;
       break;
  }

  case (Iop_CmpEQ32):
  case (Iop_CmpEQ64):
    ret = Top; 
    break; 

  default:
    ret = Top;
    break;
  }
  return ret;
}


void ufInstOgIRTemp (IRBB * bb,  IRStmt* s , ULong bb_counter)
{
  IRDirty * d; 
  IRExpr * rhs; 
  IRExpr * argX;
  IRExpr * argY; 
  HWord lhsTmpName; 
  HWord rhsTmpName; 
  HWord argXTmpName;
  HWord argYTmpName; 
  HWord offset; 
  HWord addr; 
  IRExpr * addrExpr; 
  IntType compareType; 

  rhs = s->Ist.Tmp.data;
  lhsTmpName = (HWord)s->Ist.Tmp.tmp; 

  d = NULL; 

  switch(rhs->tag)
  {
  case (Iex_Load):
    addrExpr = rhs->Iex.Load.addr; 
    if (addrExpr->tag == Iex_Tmp)
    {
    
    d = unsafeIRDirty_0_N(0, "ufHandleLoad",
			  &ufHandleLoad,
			  mkIRExprVec_3( addrExpr,
					 mkIRExpr_HWord(lhsTmpName),
					 mkIRExpr_HWord(bb_counter)
					 )
			  ); 
    }
    else if (addrExpr->tag == Iex_Const)
    {
      addr = addrExpr->Iex.Const.con->Ico.U32;
      d = unsafeIRDirty_0_N(0, "ufHandleLoad",
			    &ufHandleLoad,
			    mkIRExprVec_3( addrExpr,
					   mkIRExpr_HWord(lhsTmpName),
					   mkIRExpr_HWord(bb_counter)
					   )
			    );
    }
    
    if (d != NULL)
    {
      setHelperAnns(d); 
      addStmtToIRBB(bb, IRStmt_Dirty(d)); 		  
    }
    break; 


  case (Iex_Get):
    offset = rhs->Iex.Get.offset; 
    d = unsafeIRDirty_0_N(0, "ufHandleLoad",
			  &ufHandleLoad,
			  mkIRExprVec_3( mkIRExpr_HWord(offset),
					 mkIRExpr_HWord(lhsTmpName),
					 mkIRExpr_HWord(bb_counter)
					 )
			  ); 
    setHelperAnns(d); 
    addStmtToIRBB(bb, IRStmt_Dirty(d)); 		  
    break; 

  case (Iex_Tmp):
    rhsTmpName = (HWord)(s->Ist.Tmp.data->Iex.Tmp.tmp); 
    d = unsafeIRDirty_0_N(0, "ufHandleAssignment",
			  &ufHandleAssignment, 
			  mkIRExprVec_3( mkIRExpr_HWord(lhsTmpName), 
					 mkIRExpr_HWord(rhsTmpName),
					 mkIRExpr_HWord(bb_counter)
					 )
			  ); 
    setHelperAnns(d); 
    addStmtToIRBB(bb, IRStmt_Dirty(d)); 		  
    break; 

  case (Iex_Unop):
    // Only go forward if argument is a temporary variable
    if(rhs->Iex.Unop.arg->tag == Iex_Tmp)
    { 
      rhsTmpName = (HWord)rhs->Iex.Unop.arg->Iex.Tmp.tmp;
      d = unsafeIRDirty_0_N(0, "ufHandleUnop",
			    &ufHandleUnop,
			    mkIRExprVec_3(
					  mkIRExpr_HWord(lhsTmpName),
					  mkIRExpr_HWord(rhsTmpName),
					  mkIRExpr_HWord(bb_counter)
					  )
	); 
    
    setHelperAnns(d); 
    addStmtToIRBB(bb, IRStmt_Dirty(d)); 
    }
    break; 

  case (Iex_Binop):
    argXTmpName = NONTEMP; 
    argYTmpName = NONTEMP;  
    argX = rhs->Iex.Binop.arg1;
    argY = rhs->Iex.Binop.arg2; 

    if (argX->tag == Iex_Tmp)
    {
      argXTmpName = (HWord)argX->Iex.Tmp.tmp;
    }

    if (argY->tag == Iex_Tmp)
    {
      argYTmpName = (HWord)argY->Iex.Tmp.tmp; 
    }
    
    // check if compare or if regular binop 
    if (isCompare(rhs->Iex.Binop.op))
    {
      compareType = opToType(rhs->Iex.Binop.op); 
      d = unsafeIRDirty_0_N(0, 
			    "ufHandleCompare",
			    &ufHandleCompare, 
			    mkIRExprVec_4 ( 
					   mkIRExpr_HWord(argXTmpName),
					   mkIRExpr_HWord(argYTmpName),
					   mkIRExpr_HWord(bb_counter), 
					   mkIRExpr_HWord(compareType)
					   )
			    ); 
					    
    }
    else
    {
      d = unsafeIRDirty_0_N(0, 
			    "ufHandleBinop",
			    &ufHandleBinop, 
			    mkIRExprVec_4( 
					  mkIRExpr_HWord(lhsTmpName), 
					  mkIRExpr_HWord(argXTmpName),
					  mkIRExpr_HWord(argYTmpName),
					  mkIRExpr_HWord(bb_counter)
					  )
			    ); 
    }


    if (d != NULL)
    {
      setHelperAnns(d); 
      addStmtToIRBB(bb, IRStmt_Dirty(d)); 
    }
    break; 

  default:
    break; 
  }
}

void ufHandleAssignment(HWord tmpLHS, HWord tmpRHS, HWord bbTransNum)
{
  ufOgNode * tLHS;
  ufOgNode * tRHS;

  //  VG_(printf)("XXX ufHandleAssignment \n"); 

  tLHS = ufFind(tmpNametoNode(tmpLHS, bbTransNum, cgBBExecCounter));
  tRHS = ufFind(tmpNametoNode(tmpRHS, bbTransNum, cgBBExecCounter)); 
  ufUnion(tLHS, tRHS); 
}

void ufHandleUnop(HWord tmpLHS, HWord tmpRHS, HWord bbTransNum)
{
  ufOgNode * tLHS;
  ufOgNode * tRHS;

  //  VG_(printf)("XXX ufHandleUnop %u %u %u \n", tmpLHS, tmpRHS, bbTransNum); 

  tLHS = ufFind(tmpNametoNode(tmpLHS, bbTransNum, cgBBExecCounter)); 
  tRHS = ufFind(tmpNametoNode(tmpRHS, bbTransNum, cgBBExecCounter)); 
  ufUnion(tLHS, tRHS); 

}


void ufHandleBinop(HWord tmpZ, HWord tmpX, HWord tmpY, HWord bbTransNum)
{
  ufOgNode * tZ;
  ufOgNode * tX;
  ufOgNode * tY;

  // VG_(printf)("XXX ufHandleBinop %u %u %u %u \n", tmpZ, tmpX, tmpY, bbTransNum); 
  tZ = ufFind(tmpNametoNode(tmpZ, bbTransNum, cgBBExecCounter));

  //  VG_(printf)("XXX ufHandleBinop past first tmpNametoNode\n"); 
  if (tmpX != NONTEMP)
  {
    //    VG_(printf)("XXX ufHandleBinop before tX tmpNametoNode\n"); 
    tX = ufFind(tmpNametoNode(tmpX, bbTransNum, cgBBExecCounter)); 
    //    VG_(printf)("XXX ufHandleBinop past tX tmpNametoNode\n"); 
    ufUnion(tZ, tX); 
    //    VG_(printf)("XXX ufHandleBinop past tX ufUnion\n"); 
  }

  if (tmpY != NONTEMP)
  {
    //    VG_(printf)("XXX ufHandleBinop before tX tmpNametoNode\n"); 
    tY = ufFind(tmpNametoNode(tmpY, bbTransNum, cgBBExecCounter)); 
    //    VG_(printf)("XXX ufHandleBinop past tX tmpNametoNode\n"); 
    ufUnion(tZ, tY); 
    //    VG_(printf)("XXX ufHandleBinop past tX ufUnion\n"); 
  }
}

void ufHandleCompare(HWord tmpX, HWord tmpY, HWord bbTransNum, IntType CompareType)
{
  ufOgNode * tX;
  ufOgNode * tY;
  ufOgNode * repX;
  ufOgNode * repY;

  //  VG_(printf)("XXX ufHandleCompare %u %u %u %u \n", tmpX, tmpY, bbTransNum, cgBBExecCounter); 

  if (tmpX != NONTEMP)
  {
    tX = tmpNametoNode(tmpX, bbTransNum, cgBBExecCounter); 
    repX = ufFind(tX);
    repX->tmpType = ufMeet(repX->tmpType, CompareType);

    //    VG_(printf)("XXX %u %u %u MEET ", repX->tmpName, bbTransNum, cgBBExecCounter); 

    if (CompareType == SignedTy)
    {
      //      VG_(printf)( "SIGNED"); 
    }
    if (CompareType == UnsignedTy)
    {
      //  VG_(printf)( "UNSIGNED"); 
    }

    if (CompareType == Top)
    {
      // VG_(printf)( "TOP"); 
    }

    //  VG_(printf)("\n"); 

    if (repX->tmpType == Bot)
    {
      cgEmitQueryBadRange(tmpX, bbTransNum); 
     } 
  }

  if (tmpY != NONTEMP)
  {
    tY = tmpNametoNode(tmpY, bbTransNum, cgBBExecCounter); 
    repY = ufFind(tY); 
    repY->tmpType = ufMeet(repY->tmpType, CompareType);

    //  VG_(printf)("XXX %u %u %u MEET ", repY->tmpName, bbTransNum, cgBBExecCounter); 

    if (CompareType == SignedTy)
    {
      //  VG_(printf)( "SIGNED"); 
    }
    if (CompareType == UnsignedTy)
    {
      //  VG_(printf)( "UNSIGNED"); 
    }

    if (CompareType == Top)
    {
      //  VG_(printf)( "TOP"); 
    }

    // VG_(printf)("\n"); 

    if (repY->tmpType == Bot)
    {
      cgEmitQueryBadRange(tmpY, bbTransNum); 
    }
  } 
}


void ufHandleLoad(HWord addr, HWord LHSTmpName, HWord bbTransNum)
{
  TmTypeOfHashNode * addrTmNode; 
  TmpVarTy addrTmp;
  ufOgNode * lhsNode;
  ufOgNode * memNode; 

  //  VG_(printf)("XXX ufHandleLoad addr %x LHSTmp %u bbTransNum %u \n", addr, LHSTmpName, bbTransNum); 

  addrTmNode = VG_(HT_lookup)(tmAddrToVar, addr);
  if (addrTmNode)
  {
    addrTmp = addrTmNode->var; 
    //    VG_(printf)("XXX ufHandleLoad addr %x -> t %u CV %u e %u \n", addr, addrTmp.t, addrTmp.CV, addrTmp.e); 
    memNode = tmpNametoNode(addrTmp.t, addrTmp.CV, addrTmp.e);
    lhsNode = tmpNametoNode(LHSTmpName, bbTransNum, cgBBExecCounter); 
    vassert(memNode != NULL); 
    vassert(lhsNode != NULL); 
    ufUnion(lhsNode, memNode); 
  }
}

// When storing a constant, need to decrement memRefCount! 
void ufHandleStoreConstant(HWord addr, HWord bbTransNum)
{
  TmTypeOfHashNode * addrTmNode; 
  TmpVarTy addrTmp; 
  ufOgNode * nodeOld;
  
  //  VG_(printf)("XXX ufHandleStoreConstant addr %x \n", addr);  
  addrTmNode = VG_(HT_lookup)(tmAddrToVar, addr);
  if (addrTmNode)
  {
    addrTmp = addrTmNode->var; 
    //    VG_(printf)("XXX ufHandleStore addr %x was t %u CV %u e %u \n", addr, addrTmp.t, addrTmp.CV, addrTmp.e); 
    // VG_(printf)("XXX ufHandleStore addr %x now constant \n"); 
    
    nodeOld = tmpNametoNode(addrTmp.t, addrTmp.CV, addrTmp.e);
    vassert(nodeOld != NULL); 
    nodeOld->memRefCount--; 
    // VG_(printf)("XXX ufHandleStore %u %u %u %u after --\n", addrTmp.t, addrTmp.CV, addrTmp.e, nodeOld->memRefCount); 
    ufCheck(nodeOld, FALSE);
  }
}

void ufHandleStore(HWord addr, HWord tmpName, HWord bbTransNum)
{
  TmTypeOfHashNode * addrTmNode; 
  TmpVarTy addrTmp; 
  ufOgNode * nodeOld;
  ufOgNode * nodeNew; 
  
  // VG_(printf)("XXX ufHandleStore addr %x tmpName %u CV %u \n", addr, tmpName, bbTransNum);  
  //   VG_(printf)("XXX ufHandleStore addr %x now t %u CV %u e %u \n", addr, tmpName, bbTransNum, cgBBExecCounter); 
  nodeNew = tmpNametoNode(tmpName, bbTransNum, cgBBExecCounter); 
  vassert(nodeNew != NULL); 
  nodeNew->memRefCount++;
  // VG_(printf)("XXX ufHandleStore %u %u %u %u after ++\n", tmpName, bbTransNum, cgBBExecCounter, nodeNew->memRefCount); 
  
  addrTmNode = VG_(HT_lookup)(tmAddrToVar, addr);
  if (addrTmNode)
  {
    addrTmp = addrTmNode->var; 
    //  VG_(printf)("XXX ufHandleStore addr %x was t %u CV %u e %u \n", addr, addrTmp.t, addrTmp.CV, addrTmp.e); 
    nodeOld = tmpNametoNode(addrTmp.t, addrTmp.CV, addrTmp.e);
    vassert(nodeOld != NULL); 
    nodeOld->memRefCount--; 
    //  VG_(printf)("XXX ufHandleStore %u %u %u %u after --\n", addrTmp.t, addrTmp.CV, addrTmp.e, nodeOld->memRefCount); 

    ufCheck(nodeOld, FALSE);
  }
}

void ufCleanup(void)
{
  UInt numNodesPre; 
  UInt numNodesPost; 
  ufOgHashNode * curNode; 
  ufOgHashNode * delHashNode;
  UInt counter; 

  counter = 0; 
  numNodesPre = VG_(HT_count_nodes)(ufOgHash); 
  //  VG_(printf)("XXX ufCleanup H Pre: %u \n", numNodesPre); 
  VG_(HT_ResetIter)(ufOgLiveTempVarNodes);

  curNode = VG_(HT_Next)(ufOgLiveTempVarNodes); 
  while(curNode)
  {
    ufCheck(curNode->ufNode, TRUE);

    // Remove it once checked 
    delHashNode = VG_(HT_remove)(ufOgLiveTempVarNodes,curNode->loc); 
    VG_(free)(delHashNode); 
  
    VG_(HT_ResetIter)(ufOgLiveTempVarNodes);
    curNode = VG_(HT_Next)(ufOgLiveTempVarNodes); 
    counter++; 
  }

  numNodesPost = VG_(HT_count_nodes)(ufOgHash); 
  //  VG_(printf)("XXX ufCleanup H Post: %u \n", numNodesPost); 
  // VG_(printf)("XXX ufCleanup counter: %u \n", counter);
}
