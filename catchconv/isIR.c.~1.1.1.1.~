/*--------------------------------------------------------------------*/
/*--- CatchConversions                           isIR.c            ---*/
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


/* Maintains the isSymbolic map from locations to bit */



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

#include "isIR.h" 
#include "ogIR.h" 
#include "catchconv.h"
#include "ca_settings.h"


void isSetKeyOrigin(HWord key, HWord offset)
{
  isIsSymbolicHashNode * isNode;

  isNode = VG_(HT_lookup)(isIsSymbolic, key);

  if (ca_output_comment)
  {
    VG_(printf)("XXX isSetKeyOrigin key: %x offset: %u \n", key, offset); 
  }


  // Check if key is already declared as origin
  if (isNode != NULL)
  {
    // Do not insert the node twice 
    isNode->isOrigin = 1; 
    return;
  }

    isNode = VG_(malloc)(sizeof(isIsSymbolicHashNode)); 
    isNode->key = key; 
    isNode->isOrigin = 1; 
    isNode->offset = offset; 

    VG_(HT_add_node)(isIsSymbolic,isNode); 

  return; 
}


void isSetKeySymbolic(HWord key)
{
  isIsSymbolicHashNode * isNode;
 
  if (!isKeySymbolicP(key))
  {
    if (ca_output_comment)
    {
      VG_(printf)("XXX isSetKeySymbolic new key: %x \n", key); 
    }
      isNode = VG_(malloc)(sizeof(isIsSymbolicHashNode)); 
      isNode->key = key; 
      isNode->isOrigin = 0; 
      VG_(HT_add_node)(isIsSymbolic,isNode); 
  }
  else
  {
    if (ca_output_comment)
    {
      VG_(printf)("XXX isSetKeySymbolic repeated key: %x \n", key); 
    }
  }

  return; 
}

void isSetJCSymbolic(HWord BB, HWord exec, HWord CC)
{
  
  isSetKeySymbolic(locToHashKeyJC(exec,BB,CC, JCLoc)); 
  return; 
}

void isSetKeyConcrete(HWord key)
{
  isIsSymbolicHashNode * isNode;

  if (ca_output_comment)
  {
    VG_(printf)("XXX isSetKeyConcrete key: %x \n", key); 
  }  

  isNode = VG_(HT_remove)(isIsSymbolic,key);
  if (isNode) VG_(free)(isNode); 
  return; 
}

void isSetRegConcrete(HWord offset)
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX is: set reg %x concrete \n",offset); 
  }
 isSetKeyConcrete(locToHashKey(offset,0,RegLoc));
}

void isSetMemConcrete(HWord addr, HWord numBytes)
{
  HWord offset; 
  HWord key; 

  if (ca_output_comment)
  {
    VG_(printf)("XXX is: set addr %x concrete %d bytes \n",addr, numBytes); 
  }

  for(offset = 0; offset < numBytes; offset++)
  {
    key = addr + offset; /* Memory is byte-addressed! */  
    isSetKeyConcrete(locToHashKey(key,0,MemLoc));
  }
}

void isFlowToMem(HWord srckey, HWord addr, HWord numBytes)
{
  HWord offset; 
  HWord key; 

  if (isKeySymbolicP(srckey))
  {
    if (ca_output_comment)
    {
    VG_(printf)("XXX isFlowToMem SYMBOLIC srckey: %x addr: %x numBytes: %d\n", srckey, addr, numBytes); 
    } 

    for (offset = 0; offset < numBytes; offset++)
    {
      key = addr + offset;  /* Memory is byte-addressable */  
      isSetKeySymbolic(locToHashKey(key,0,MemLoc)); 
    }
  }
  else
  {
    if (ca_output_comment)
    {
      VG_(printf)("XXX isFlowToMem CONCRETE srckey: %x addr: %x numBytes: %d\n", srckey, addr, numBytes); 
    } 
    for(offset = 0; offset < numBytes; offset++)
    {
      key = addr + offset ;  /* Memory is byte-addressable */ 
      isSetKeyConcrete(locToHashKey(key,0,MemLoc));
    }
  }
}

void isFlowToReg(HWord srckey, HWord regOffset , HWord numBytes)
{
  HWord offset; 
  HWord key; 
  
  if (isKeySymbolicP(srckey))
  {
    for (offset = 0; offset < numBytes; offset++)
    {
      key = regOffset + offset; /* Regs are byte-addressable */ 
      isSetKeySymbolic(locToHashKey(key,0,RegLoc)); 
    }
  }
  else
  {
    for(offset = 0; offset < numBytes; offset++)
    {
      key = regOffset + offset; 
      isSetRegConcrete(key);
    }
  }
}


HWord isKeySymbolicP(HWord key)
{
  isIsSymbolicHashNode * isNode;

  isNode = VG_(HT_lookup)(isIsSymbolic,key);

  return (isNode != 0); 
}

HWord isTmpSymbolicP(HWord BB, HWord tmpname)
{
  HWord ret = 0;

  ret = isKeySymbolicP(locToHashKey(tmpname,BB,TmpLoc));

  return ret; 
}

HWord isRegSymbolicP(HWord offset)
{

  HWord ret = 0;

  ret = isKeySymbolicP(locToHashKey(offset,0,RegLoc));

  return ret; 

}

HWord isJCSymbolicP(HWord BB, HWord exec, HWord CC)
{
  HWord ret = 0; 

  ret = isKeySymbolicP(locToHashKeyJC(exec,BB,CC, JCLoc)); 

  return ret; 
}


HWord isMemSymbolicP(HWord addr)
{

  HWord ret = 0;

  ret = isKeySymbolicP(locToHashKey(addr,0,MemLoc));

  return ret; 

}


HWord isKeyOriginP(HWord key, HWord * offset)
{
  isIsSymbolicHashNode * isNode;

  isNode = VG_(HT_lookup)(isIsSymbolic,key);
  if (isNode)
    {
      if (offset != NULL)
      {
	*offset = isNode->offset; 
      }
      return (isNode->isOrigin);
    }
  else
    return 0; 
}

HWord isTmpOriginP(HWord BB, HWord tmpname)
{
  HWord ret = 0;

  ret = isKeyOriginP(locToHashKey(tmpname,BB,TmpLoc), NULL);

  return ret; 
}

HWord isRegOriginP(HWord offset)
{

  HWord ret = 0;

  ret = isKeyOriginP(locToHashKey(offset,0,RegLoc), NULL);

  return ret; 

}

HWord isMemOriginP(HWord addr, HWord * offset)
{

  HWord ret = 0;

  ret = isKeyOriginP(locToHashKey(addr,0,MemLoc), offset);

  return ret; 

}

void isFlowMapByKey(HWord srcKey, HWord sinkKey)
{
  /* if isSymbolic(srcKey), then set isSymbolic(sinkKey) */  

  if (isKeySymbolicP(srcKey))
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX Flow from key %x",srcKey);
	VG_(printf)(" to key %x \n", sinkKey); 
      }
      isSetKeySymbolic(sinkKey);
    }

  /* Account for the case that a location is overwritten with a */
  /* non-symbolic value. In this case clear the symbolic-ness of location. */ 
  else if (! isKeySymbolicP(srcKey) &&  isKeySymbolicP(sinkKey) )
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX Anti-flow from key %x",srcKey);
	VG_(printf)(" to key %x \n", sinkKey); 
      }
      isSetKeyConcrete(sinkKey);
    }

  return; 
}

void isFlowMapByKeyBinary(HWord srcKey1, HWord srcKey2, HWord sinkKey)
{
   /* if isSymbolic(srcKey), then set isSymbolic(sinkKey) */  

   if (ca_output_comment)
   {
      VG_(printf)("XXX Flow srcKey=(0x%x, 0x%x) sinkKey=0x%x: ", srcKey1, srcKey2, sinkKey);
   }
   if (isKeySymbolicP(srcKey1) || isKeySymbolicP(srcKey2))
   {
      if (ca_output_comment)
      {
         VG_(printf)("FLOW "); 
      }
      isSetKeySymbolic(sinkKey);
   } else {
      /* Account for the case that a location is overwritten with a */
      /* non-symbolic value. In this case clear the symbolic-ness of location. */ 

      if (isKeySymbolicP(sinkKey) )
      {
         if (ca_output_comment)
         {
            VG_(printf)("ANTI-FLOW"); 
         }
         isSetKeyConcrete(sinkKey);
      }
   }

   if (ca_output_comment)
   {
      VG_(printf)("\n"); 
   }
}

void isFlowMapByKeyTrinary(HWord srcKey1, 
			   HWord srcKey2, 
			   HWord srcKey3,
			   HWord sinkKey)
{

   if (ca_output_comment)
   {
      VG_(printf)("XXX Flow srcKey=(0x%x, 0x%x, 0x%x) sinkKey=0x%x: ", srcKey1, srcKey2, srcKey3, sinkKey);
   }

   if ( ((srcKey1 != -1) && isKeySymbolicP(srcKey1))  || 
	((srcKey2 != -1) && isKeySymbolicP(srcKey2))  ||
	((srcKey3 != -1) && isKeySymbolicP(srcKey3)))
   {
      if (ca_output_comment)
      {
         VG_(printf)("FLOW "); 
      }
      isSetKeySymbolic(sinkKey);
   } else {
      /* Account for the case that a location is overwritten with a */
      /* non-symbolic value. In this case mark LHS concrete.*/
      if (isKeySymbolicP(sinkKey) )
      {
         if (ca_output_comment)
         {
            VG_(printf)("ANTI-FLOW"); 
         }
         isSetKeyConcrete(sinkKey);
      }
   }

   if (ca_output_comment)
   {
      VG_(printf)("\n"); 
   }
}


void isIRTmpUnop(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * rhs; 
  IRExpr * arg; 
  IRDirty * d; 
  HWord lhsname; 
  HWord rhsname; 

  HWord lhskey;
  HWord rhskey; 

  vassert(s->tag == Ist_Tmp); 
  rhs = s->Ist.Tmp.data;
  vassert(rhs->tag == Iex_Unop); 

  lhsname = (HWord) s->Ist.Tmp.tmp; 

  arg = rhs->Iex.Unop.arg; 

  switch (arg->tag)
    {
    case (Iex_Const):

      break; 
      
    case (Iex_Tmp):
      rhsname = (HWord) arg->Iex.Tmp.tmp; 
      lhskey = locToHashKey(lhsname, BBCounter,TmpLoc); 
      rhskey = locToHashKey(rhsname, BBCounter,TmpLoc); 
      
      d = unsafeIRDirty_0_N(0,
			    "isFlowMapByKey",
			    &isFlowMapByKey,
			    mkIRExprVec_2(mkIRExpr_HWord(rhskey),
					  mkIRExpr_HWord(lhskey)
					  )
			    );
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d));  
      break; 
   if (ca_output_comment)
   {
      VG_(printf)("\n"); 
   }




    default:
      if (ca_output_comment)
      {
	VG_(printf)("XXX Unhandled unop arg in stmt");
	ppIRStmt(s); 
	VG_(printf)("\n"); 
      }
      break; 

    }


}

void isIRTmpBinop(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * rhs; 
  IRExpr * arg1;
  IRExpr * arg2; 
  IRDirty * d1;
  IRDirty * d2;

  HWord lhsname;
  HWord arg1name; 
  HWord arg2name; 

  HWord lhskey;
  HWord arg1key; 
  HWord arg2key;

  vassert(s->tag == Ist_Tmp); 
  rhs = s->Ist.Tmp.data;
  vassert(rhs->tag == Iex_Binop); 

  lhsname = (HWord) s->Ist.Tmp.tmp; 
  lhskey = locToHashKey(lhsname,BBCounter, TmpLoc); 

  arg1 = rhs->Iex.Binop.arg1; 
  arg2 = rhs->Iex.Binop.arg2; 

   if (arg1->tag == Iex_Tmp && arg2->tag == Iex_Tmp) {
      arg1name = (HWord)arg1->Iex.Tmp.tmp; 
      arg1key = locToHashKey(arg1name,BBCounter,TmpLoc); 
      arg2name = (HWord)arg2->Iex.Tmp.tmp; 
      arg2key = locToHashKey(arg2name,BBCounter,TmpLoc); 

      d1 = unsafeIRDirty_0_N(0,
            "isFlowMapByKeyBinary",
            &isFlowMapByKeyBinary,
            mkIRExprVec_3(
               mkIRExpr_HWord(arg1key),
               mkIRExpr_HWord(arg2key),
               mkIRExpr_HWord(lhskey)
               )
            );
      setHelperAnns(d1); 
      addStmtToIRSB(bb,IRStmt_Dirty(d1));  

   } else {
      if (arg1->tag == Iex_Tmp || arg2->tag == Iex_Tmp) {
         if (arg1->tag == Iex_Tmp) {
      arg1name = (HWord)arg1->Iex.Tmp.tmp; 
      arg1key = locToHashKey(arg1name,BBCounter,TmpLoc); 

      d1 = unsafeIRDirty_0_N(0,
			    "isFlowMapByKey",
			    &isFlowMapByKey,
			    mkIRExprVec_2(mkIRExpr_HWord(arg1key),
					  mkIRExpr_HWord(lhskey)
					  )
			    );
      setHelperAnns(d1); 
      addStmtToIRSB(bb,IRStmt_Dirty(d1));  
    }

         if (arg2->tag == Iex_Tmp) {
      arg2name = (HWord)arg2->Iex.Tmp.tmp; 
      arg2key = locToHashKey(arg2name,BBCounter,TmpLoc); 

      d2 = unsafeIRDirty_0_N(0,
			    "isFlowMapByKey",
			    &isFlowMapByKey,
			    mkIRExprVec_2(mkIRExpr_HWord(arg2key),
					  mkIRExpr_HWord(lhskey)
					  )
			    );
      setHelperAnns(d2); 
      addStmtToIRSB(bb,IRStmt_Dirty(d2));  
      }
      } else {
         /* If both operands are constant, then make the sink concrete. */

	d2 = unsafeIRDirty_0_N(0,
			       "isSetKeyConcrete",
			       &isSetKeyConcrete,
			       mkIRExprVec_1(
					     mkIRExpr_HWord(lhskey)
					     )
			       ); 

      }
    }

  return; 
}

void isIRTmpTmp(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * rhs; 
  IRDirty * d; 
  HWord lhskey;
  HWord rhskey;


  vassert(s->tag == Ist_Tmp);
  rhs = s->Ist.Tmp.data; 
  vassert(rhs->tag == Iex_Tmp); 
  

  lhskey = locToHashKey(s->Ist.Tmp.tmp,BBCounter,TmpLoc); 
  rhskey = locToHashKey(rhs->Iex.Tmp.tmp,BBCounter,TmpLoc); 
  
      d = unsafeIRDirty_0_N(0,
			    "isFlowMapByKey",
			    &isFlowMapByKey,
			    mkIRExprVec_2(mkIRExpr_HWord(rhskey),
					  mkIRExpr_HWord(lhskey)
					  )
			    );
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d));  


      return; 

}

void isIRTmpGet(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * rhs; 
  IRDirty * d;
  HWord lhskey; 
  HWord rhskey; 

  vassert(s->tag == Ist_Tmp);
  rhs = s->Ist.Tmp.data; 
  vassert(rhs->tag == Iex_Get); 

  lhskey = locToHashKey(s->Ist.Tmp.tmp,BBCounter,TmpLoc); 
  rhskey = locToHashKey(rhs->Iex.Get.offset,0,RegLoc); 

  d = unsafeIRDirty_0_N(0,
			"isFlowMapByKey",
			&isFlowMapByKey,
			mkIRExprVec_2(mkIRExpr_HWord(rhskey),
				      mkIRExpr_HWord(lhskey)
				      )
			);
  setHelperAnns(d); 
  addStmtToIRSB(bb,IRStmt_Dirty(d));  
  return; 
}


void isIRTmpLoad(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * rhs; 
  IRExpr * addrExpr; 
  IRDirty * d; 
  HWord lhskey; 

  vassert(s->tag == Ist_Tmp);
  rhs = s->Ist.Tmp.data;
  vassert(rhs->tag == Iex_Load); 
  addrExpr = rhs->Iex.Load.addr; 

  lhskey = locToHashKey(s->Ist.Tmp.tmp,BBCounter,TmpLoc); 

  /* Note that locToHashKey of a memory location is the identity function. */
  /* Therefore can simply pass in addrExpr to update isSymbolic map. */ 


  d = unsafeIRDirty_0_N(0,
			"isFlowMapByKey",
			&isFlowMapByKey,
			mkIRExprVec_2(addrExpr,
				      mkIRExpr_HWord(lhskey)
				      )
			);
  setHelperAnns(d); 
  addStmtToIRSB(bb,IRStmt_Dirty(d));  

}

/* Set up the flow for an x86g_calc_condition call */ 
void isIRTmpCCallCalcConditionAdd(IRSB * bb, IRStmt * s, HWord BBCounter)
{

  //  IRTemp lhs; 
  IRExpr * call; 
  IRCallee * callee;
  IRExpr** callee_args; 

  call = s->Ist.Tmp.data; 
  vassert(call->tag == Iex_CCall); 
  callee = call->Iex.CCall.cee;
  callee_args = call->Iex.CCall.args;  

}

void isIRTmpCCall(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * call; 
  IRCallee * callee;
 
  call = s->Ist.Tmp.data; 
  vassert(call->tag == Iex_CCall); 
  callee = call->Iex.CCall.cee;

  if (! VG_(strncmp)(callee->name, "x86g_calculate_condition",24))
  {
    isIRTmpCCallCalcConditionAdd(bb, s, BBCounter); 
  }
  else if (! VG_(strncmp)(callee->name, "x86g_use_seg_selector",32))
  {
    if (ca_output_comment)
    {
      VG_(printf)("Unhandled isIR x86g_use_seg_selector ");
      VG_(printf)("\n"); 
    }
  }
  else
  {
    if (ca_output_comment)
    {
      VG_(printf)("Unhandled isIRTmp CCall : "); 
      ppIRStmt(s); 
      VG_(printf)("\n"); 
    }
    return; 
  }
}

/* Add instrumentation for statement of form tX = Mux0X(tA,tB,tZ) */
/* Complication here is that tA, tB, tZ could be constants.       */
/*                                                                */
/* Strict interpretation:                                         */
/* tX should be tainted if tA is true and tB is tainted OR tA     */
/* is false and tZ is tainted.                                    */
/* Loose interpretation:                                          */
/* tX should be tainted if any one of tA, tB, tZ is tainted.      */
/* isIRTmpMux0X implements the loose interpretation.              */

void isIRTmpMux0X(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRDirty * d;
  IRExpr * rhs; 
  IRExpr * condexpr; 
  IRExpr * truexpr; 
  IRExpr * falsexpr; 

  HWord condName, condKey; 
  HWord falseName, falseKey; 
  HWord trueName, trueKey; 
  HWord lhsName, lhsKey; 

  rhs = s->Ist.Tmp.data; 
  vassert(rhs->tag == Iex_Mux0X); 
  condexpr = rhs->Iex.Mux0X.cond; 
  truexpr = rhs->Iex.Mux0X.expr0; 
  falsexpr = rhs->Iex.Mux0X.exprX; 

  vassert(condexpr->tag == Iex_Tmp || condexpr->tag == Iex_Const); 
  vassert(truexpr->tag == Iex_Tmp || truexpr->tag == Iex_Const); 
  vassert(falsexpr->tag == Iex_Tmp || falsexpr->tag == Iex_Const); 


  lhsName = (HWord)s->Ist.Tmp.tmp; 
  lhsKey = locToHashKey(lhsName, BBCounter, TmpLoc); 

  if (condexpr->tag == Iex_Tmp)
  {
    condName = (HWord)condexpr->Iex.Tmp.tmp; 
    condKey = locToHashKey(condName, BBCounter, TmpLoc);
  }
  else
  { 
    condKey = -1; 
  }

  if (truexpr->tag == Iex_Tmp)
  {
    trueName = (HWord)truexpr->Iex.Tmp.tmp;
    trueKey = locToHashKey(trueName, BBCounter, TmpLoc); 
  }
  else 
  {
    trueKey = -1;
  }

  if (falsexpr->tag == Iex_Tmp)
  {
    falseName = (HWord)falsexpr->Iex.Tmp.tmp; 
    falseKey = locToHashKey(falseName, BBCounter, TmpLoc); 
  }
  else
  {
    falseKey = -1; 
  }

  d = unsafeIRDirty_0_N(0,
			"isFlowMapByKeyTrinary", 
			&isFlowMapByKeyTrinary,
			mkIRExprVec_4(
				      mkIRExpr_HWord(condKey),
				      mkIRExpr_HWord(trueKey), 
				      mkIRExpr_HWord(falseKey),
				      mkIRExpr_HWord(lhsKey)
				      )
			); 

  setHelperAnns(d); 
  addStmtToIRSB(bb, IRStmt_Dirty(d)); 
}

void isIRTmp(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * rhs; 

  vassert(s->tag == Ist_Tmp);
  rhs = s->Ist.Tmp.data; 


  switch (rhs->tag)
    {
      
    case (Iex_Const):
      break; 

    case (Iex_Get):
      isIRTmpGet(bb,s,BBCounter); 
      break; 
   
    case (Iex_Load):
      isIRTmpLoad(bb,s,BBCounter); 
      break; 
    case (Iex_Tmp):
      isIRTmpTmp(bb,s,BBCounter); 
      break; 
    case(Iex_Binop):
      isIRTmpBinop(bb,s,BBCounter); 
      break;
    case(Iex_Unop):
      isIRTmpUnop(bb,s,BBCounter); 
      break; 
    case (Iex_CCall):
      isIRTmpCCall(bb,s,BBCounter); 
      break; 
    case (Iex_Mux0X):
      isIRTmpMux0X(bb,s,BBCounter); 
      break; 

    case (Iex_GetI):
    default:
      if (ca_output_comment)
      {
	VG_(printf)("XXX Unhandled IRExpr in isIRTmp:");
	ppIRExpr(rhs); 
	VG_(printf)("\n"); 
      }
    }

  return; 
} 




void isIRPut(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRDirty * d; 
  IRExpr * data;
  HWord lhskey; 
  HWord rhskey; 
  HWord numBytes = 4; 

  lhskey = s->Ist.Put.offset; 
  data = s->Ist.Put.data; 

  switch(data->tag)
  {
    case (Iex_Const):
      numBytes = numBytesOfConst(data->Iex.Const.con);
      /* Cannot have symbolic reg from a constant storage */
      /* So clear the isSymbolic bit in this case */ 
      d = unsafeIRDirty_0_N(0,
			    "isSetRegConcrete",
			    &isSetRegConcrete,
			    mkIRExprVec_1(mkIRExpr_HWord(lhskey))
			    );

      
	 
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d)); 
      return; /* Do not want to fall through to isFlowToReg */ 

      break; 

    case (Iex_Tmp):

      numBytes = numBytesOfTmpvar(bb, data->Iex.Tmp.tmp); 
      rhskey = locToHashKey(data->Iex.Tmp.tmp,BBCounter,TmpLoc);
      d = unsafeIRDirty_0_N(0,
			    "isFlowToReg",
			    &isFlowToReg,
			    mkIRExprVec_3(
					  mkIRExpr_HWord(rhskey),
					  mkIRExpr_HWord(lhskey),
					  mkIRExpr_HWord(numBytes)
					  )
			    );
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d));  
      break; 

    default:
      /* Should not be reached. */ 
      if (ca_output_comment)
      {
	VG_(printf)("XXX Unhandled put arg in stmt"); 
	ppIRStmt(s); 
	VG_(printf)("\n"); 
      }
      break; 
    }
  return; 
}

void isIRStore(IRSB * bb, IRStmt * s, HWord BBCounter)
{
  IRExpr * addrExpr; 
  IRExpr * dataExpr;
  IRDirty * d; 
  HWord rhskey;
  HWord numBytes = 0; 

  vassert(s->tag == Ist_Store); 
  addrExpr = s->Ist.Store.addr; 
  dataExpr = s->Ist.Store.data; 

  switch (dataExpr->tag)
    {
    case (Iex_Const):
      numBytes = numBytesOfConst(dataExpr->Iex.Const.con);
      /* Cannot have symbolic addr from a constant storage */
      /* So clear the isSymbolic bit in this case */ 
      d = unsafeIRDirty_0_N(0,
			    "isSetMemConcrete",
			    &isSetMemConcrete,
			    mkIRExprVec_2(
					  addrExpr,
					  mkIRExpr_HWord(numBytes)
					  )
			    );

      
	 
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d)); 
      return; /* Do not want to fall through to isFlowMapByKey */ 
      break; 
 
    case (Iex_Tmp):
      numBytes = numBytesOfTmpvar( bb, dataExpr->Iex.Tmp.tmp);
      rhskey = locToHashKey(dataExpr->Iex.Tmp.tmp,BBCounter,TmpLoc); 
      break; 
      
    default:
      if (ca_output_comment)
      {
	VG_(printf)("XXX Unhandled store arg in isIRStore");
	ppIRStmt(s);
	VG_(printf)("\n"); 
      }
      return; 
    }


  d = unsafeIRDirty_0_N(0,
			"isFlowToMem",
			&isFlowToMem,
			mkIRExprVec_3(
				      mkIRExpr_HWord(rhskey),
			 	      addrExpr,
				      mkIRExpr_HWord(numBytes)
				      )
			); 
  setHelperAnns(d); 
  addStmtToIRSB(bb,IRStmt_Dirty(d));  

  return; 
}

void isIRStmt(IRSB * bb, IRStmt * s, HWord BBCounter)
{

  switch (s->tag)
    {

      case Ist_NoOp:
         break;
      case Ist_IMark:
         break;
      case Ist_AbiHint:
         break;
      case Ist_Put:
	isIRPut(bb,s,BBCounter); 
         break;
      case Ist_PutI:
	if (ca_output_comment)
	{
	  VG_(printf)("XXX Unhandled PutI in stmt"); 
	  ppIRStmt(s); 
	  VG_(printf)("\n"); 
	}
	break;
      case Ist_Tmp:
	isIRTmp(bb,s,BBCounter); 
	break;
      case Ist_Store:
	isIRStore(bb,s,BBCounter); 
        break;
      case Ist_Dirty:
	if (ca_output_comment)
	{
	  VG_(printf)("XXX Unhandled Dirty in stmt"); 
	  ppIRStmt(s); 
	  VG_(printf)("\n"); 
	}
         break;
      case Ist_MFence:
         break;
      case Ist_Exit:
         break;

    default:
      if (ca_output_comment)
      {
	VG_(printf)("XXX Unhandled statement in isIRStmt :"); 
	ppIRStmt(s);
	VG_(printf)("\n"); 
      }
    }

  return; 
}
