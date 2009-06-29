/*--------------------------------------------------------------------*/
/*--- CatchConversions                           ogIR.c            ---*/
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

/*---------------------------------------------------------------*/
/*--- Generate integer mismatch constraints from VEX IR       ---*/
/*---------------------------------------------------------------*/




/* --- Globals --- */

static HWord counter = 0; 
static HWord curtyvar = 0; 
static IROp curJumpCond; 

/* --- Utility Functions --- */ 
 void setHelperAnns ( IRDirty* di ) {
   /*   di->nFxState = 2;
   di->fxState[0].fx     = Ifx_Read;
   di->fxState[0].offset = mce->layout->offset_SP;
   di->fxState[0].size   = mce->layout->sizeof_SP;
   di->fxState[1].fx     = Ifx_Read;
   di->fxState[1].offset = mce->layout->offset_IP;
   di->fxState[1].size   = mce->layout->sizeof_IP;
   */
   di->nFxState = 0; 
}


IntTyStateHint opToHint(IROp op)
{
  IntTyStateHint ret; 

  switch (op)
    {
    case (Iop_CmpLT32S):
    case (Iop_CmpLT64S):
    case (Iop_CmpLE32S):
    case (Iop_CmpLE64S):
      {
	ret = SignedHint;
	break;
      }
    case(Iop_CmpLT32U):
    case(Iop_CmpLT64U):
    case(Iop_CmpLE32U):
    case(Iop_CmpLE64U):
      {
	ret = UnsignedHint;
	break;
      }
    default:
      ret = HopelessHint; /* all our dreams are dying of overdoses */ 
      break; 
    }
  return ret; 
}

IntTyStateHint og86codeToHint(ogX86CondCode condcode)
{
  IntTyStateHint ret = HopelessHint; /* there's no use in trying */ 

  switch (condcode)
    {
    case (Xcc_B) : 
    case (Xcc_NB) :
    case (Xcc_BE) :
    case (Xcc_NBE) :
    case (Xcc_S) :
    case (Xcc_NS) :
      ret = SignedHint; 
      break; 
    case (Xcc_L) :
    case (Xcc_NL) :
    case (Xcc_LE) :
    case (Xcc_NLE) :
      ret = UnsignedHint; 
      break; 
    default:
      ret = HopelessHint; /* all our plans are lying in ten car road wrecks */
      break; 
    }

  return ret; 
}

ccOpHint ogccOpToHint(HWord op)
{
  /* TODO: add appropriate switch statement */ 
  ccOpHint ret = noRegs; 

  return ret;
}

/* Note: caller's responsibility to call locToHashKey */ 
int clearVarOf(HWord loc)
{
  OgVarOfHashNode * node; 

  node = VG_(HT_remove)(ogVarOf,loc);
  if (!node) 
  {
    return -1; 
  }
  else
  {
    VG_(free)(node); 
  }
  return 0; 
}

/* Note: caller's responsibility to call locToHashKey */ 
int setVarOf(HWord loc, HWord varname)
{
  OgVarOfHashNode * node;

  vassert(varname != -1); // if triggers, means we have an unchecked GetVarOf

  node = VG_(HT_lookup)(ogVarOf,loc);
  if (!node) 
    {
      /* allocate node for loc, since we are setting VarOf(loc) */ 
      node = (OgVarOfHashNode *)VG_(malloc)("ogNode", sizeof(OgVarOfHashNode));
      node->loc = loc; 
      VG_(HT_add_node)(ogVarOf,node); 
    }  
  vassert(node->loc == loc); 
  node->varname = varname;
  return 0; 
}

/* Note: caller's responsibility to call locToHashKey */ 
HWord getVarOf(HWord loc)
{
  HWord ret = -1; 
  OgVarOfHashNode * node;

  node = VG_(HT_lookup)(ogVarOf,loc);
  if (!node) return ret; // this isn't checked! 

  vassert(node->loc == loc);
  ret = node->varname;
  return ret; 
}

int setTypeOf(HWord varname, IntType type)
{
  OgTypeOfHashNode * node; 

  node = VG_(HT_lookup)(ogTypeOf,varname);
  if (!node)
    { 
      /* Allocate and add node for varname, since we are setting TypeOf()*/ 
      node = (OgTypeOfHashNode *)VG_(malloc)("ogNode", sizeof(OgTypeOfHashNode));
      node->varname = varname; 
      VG_(HT_add_node)(ogTypeOf,node);
    } 
  vassert(node->varname == varname); 
  node->type = type;

  /* Debugging only for now: */ 

  if (ca_output_comment)
  {
  switch (type)
    {
    case (Bot) : VG_(printf)("XXX Varname var.%u set to Bot. \n",varname); break;
    case (Top) : VG_(printf)("XXX Varname var.%u set to Top. \n",varname); break;
    case (SignedTy) : VG_(printf)("XXX Varname var.%u set to SIGNED. \n",varname); 
      break;
    case (UnsignedTy) : VG_(printf)("XXX Varname var.%u set to UNSIGNED. \n",varname); 
      break;
    case (BogusTy) : vpanic("Set variable to bogus type!\n");
    }
  }
  return 0; 
} 

IntType getTypeOf(HWord varname)
{
  IntType ret = BogusTy; 
  OgTypeOfHashNode * node;

  node = VG_(HT_lookup)(ogTypeOf,varname);
  if (!node) return ret;

  vassert(node->varname == varname); 
  ret = node->type; 
  return ret; 
}

/* inserts pointer to an arg struct into hash table, key = address of the associated basic block */
int getStructOf (HWord basic_block, HWord struct_info)
{
  OgStructHashNode * node;
  int same_block = 0; // checks if the basic block has been seen before

  // vassert (varname != -1); // if triggers, means we have an unchecked GetVarOf

  node = VG_(HT_lookup)(argStructHashTable, node);
  if (!node)
    {
      /* allocate node for loc, since we are setting VarOf(loc) */
      node = (OgStructHashNode *)VG_(malloc)("ogNode", sizeof(OgStructHashNode));
      node->basic_block = basic_block;
      VG_(HT_add_node)(argStructHashTable, node);
      vassert(node->basic_block = basic_block);
      node->struct_info = struct_info;
      node->next = NULL;
    }
  else
    {
      /* chain the value to the previous occurence of the basic block */ 
      vassert(node->basic_block == basic_block);
      OgStructHashNode *new_node = (OgStructHashNode *)VG_(malloc)("ogHashNode", sizeof(OgStructHashNode));
      new_node->basic_block = basic_block;
      new_node->struct_info = struct_info;
      new_node->next = node->next; // NULL if only one in the chain, another node if not
      node->next = new_node;
    }
     return 0;
}

/* takes as input a basic block address. removes all nodes with that basic block from the hash table */
int removeStructOf (HWord basic_block)
{
  VG_(printf)("It actually starts freeing!\n");
  OgStructHashNode *node = VG_(HT_remove)(argStructHashTable, basic_block);
  if (node) 
      removeStructOfHelper (basic_block, node);
  return 0;
}

/* recursive function to delete all the nodes associated with a given basic block */
void removeStructOfHelper (HWord basic_block, OgStructHashNode *node)
{
  if (node->next == NULL)
    {
      /* remove the node's contents and free the node */
      vassert(node->basic_block = basic_block);
      VG_(free)(node->struct_info); // free the struct
      VG_(free)(node); // free the node itself
      return;
    }
  // else - more nodes with the same basic blocks
  removeStructOfHelper(basic_block, node->next);
  vassert(node->basic_block= basic_block);
  VG_(free)(node->struct_info); // free the struct                                                                         
  VG_(free)(node); // free the node itself
  return;
} 

/* Special case function for Top/Signed/Unsigned/Bot lattice */ 
IntType setTypeOfToMeet(HWord varname, IntType rhstype)
{
  IntType curType;
  
  curType = getTypeOf(varname); 

  switch (curType)
    { 
    case (BogusTy):
      setTypeOf(varname,rhstype); /* No current type, gets rhstype */
      return rhstype;
    case (Top):
      setTypeOf(varname,rhstype); 
      return rhstype;
      break;
    case (Bot):  
      setTypeOf(varname,Bot);
      return Bot; 
      break; 
    case (SignedTy):
      if ((rhstype == UnsignedTy)
	  || (rhstype == Bot))
	{
	  setTypeOf(varname,Bot);
	  return Bot; 
	}
      return SignedTy; 
      break; 
    case (UnsignedTy):
      if ((rhstype == SignedTy)
	  || (rhstype == Bot))
	{
	  setTypeOf(varname,Bot); 
	  return Bot;
	}
      return UnsignedTy; 
      break;
    default:
      /* Should never reach here */
      vpanic("Reached default in setTypeOfToMeet\n");
      break; 
    }
  /* Should never reach here */ 
  vpanic("Reached end of setTypeOfToMeet \n"); 
  return 0; 
 
}

/* Takes location to an HWord. */
/* Assumes that all memory addresses accessed > 60 decimal; this */
/* is realistic for Valgrind on Linux */ 
/* Call _before_ call to getVarOf or setVarOf */ 
HWord locToHashKey(HWord loc1, HWord loc2, LocType ltype)
{
  switch (ltype)
    {
    case (MemLoc): return loc1;
    case(RegLoc): return loc1;
    case(TmpLoc): return ( (loc1<<14) | loc2); 
    case(ErrorLoc): vpanic("ErrorLoc in locToHashKey.\n"); return 0;
    default: vpanic("Unknown ltype in locToHashKey.\n"); return 0; 
    }
  return 0; 
}


HWord locToHashKeyJC(HWord loc1, HWord loc2, HWord loc3, LocType ltype)
{
  switch (ltype)
    {
    case (MemLoc): return loc1;
    case(RegLoc): return loc1;
    case(TmpLoc): return ( (loc1<<14) | loc2); 
    case(JCLoc): return ( (loc1<<18) | (loc2<<13) | loc3); 
    case(ErrorLoc): vpanic("ErrorLoc in locToHashKey.\n"); return 0;
    default: vpanic("Unknown ltype in locToHashKeyJC.\n"); return 0; 
    }
  return 0; 
}


/* --- Instrumentation Functions --- */ 

 



ULong ogTest(IRTemp foo)
{
  VG_(message)(Vg_DebugMsg,"Test %d\n"); 
  return 0; 
}

void ogEmitStackConstraints(Addr stackAddr, SizeT len)
{
  int i;

  if (ca_output_comment)
  {
    VG_(printf)("XXX New stack ptr: mem.%x  ",stackAddr);
    VG_(printf)("New len: %x \n", len); 
  }
   for (i = 0; i < len; i++)
     {
       if (ca_output_comment)
       {
	 VG_(printf)("XXX VarOf(mem.%x) := ",stackAddr+i);
	 VG_(printf)(" var%u; \n", curtyvar);
       }
       setVarOf(locToHashKey(stackAddr+i,0,MemLoc),curtyvar);  

       curtyvar++;
     }


  return; 
}


ULong ogEmitGuardConstraints (  ULong cc_op,
				ULong cc_dep1,
				ULong cc_dep2,
			      ULong cc_ndep)
{
  // pseudocode for later analysis: 
  // switch (jumptype )
  // case "neither signed nor unsigned" break;
  // case signed 
  //           switch (cc_op)
  //                    emit constraints on CurStates_i(loc36), etc.
  // case unsigned 
  //           switch (cc_op)
  //                    emit constraints on CurStates_i(loc36), etc. 
  // default:
  //    shouldn't happen, panic.
  IntTyStateHint int_hint = opToHint(curJumpCond); 
  ccOpHint cc_op_hint = ogccOpToHint(cc_op); 
  switch (int_hint)
    {
    case (SignedHint) : 
      switch(cc_op_hint)
	{
	default: return 0; 
	}

 case (UnsignedHint) :
   switch (cc_op)
     {
       default : return 0;
     }
    default: vpanic("Hint is neither SignedHint nor UnsignedHint\n"); return 0;

    }

}; 

void ogEmitRegConstraint(HWord reg, IntTyStateHint hint)
{
  IntType newty = 0;

  /* Check whether lhs has a tyvar */ 
  if (getVarOf(locToHashKey(reg,0,RegLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(reg,0,RegLoc),curtyvar);
      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(reg.%d :=",reg);
	VG_(printf)("var%u ; \n", curtyvar); 
      }

      curtyvar++;
    }

  newty = setTypeOfToMeet(getVarOf(locToHashKey(reg,0,RegLoc)),hint);

  if (ca_output_comment)
  {
  if (hint == SignedHint)
    {
      /* Something seems to be broken with giving VG_(printf) */
      /* more than one vararg. Workaround. */ 
    VG_(printf)("XXX TypeStateOf(VarOf(");
    VG_(printf)("reg.%d)) := ",reg); 
    VG_(printf)("TypeStateOf(VarOf(");
    VG_(printf)("reg.%d)) MEET SIGNED; \n\n", reg); 
   
    }
  else if (hint == UnsignedHint) 
    {

    VG_(printf)("XXX TypeStateOf(VarOf(");
    VG_(printf)("reg.%d)) := ",reg); 
    VG_(printf)("TypeStateOf(VarOf(");
    VG_(printf)("reg.%d)) MEET UNSIGNED; \n\n", reg); 

    }
  }

  return; 
} 

void ogEmitTmpConstraint(HWord tmp, IntTyStateHint hint, ULong TagVal)
{

  IntType newTy = 0; 

  /* Check whether lhs has a tyvar */ 
  if (getVarOf(locToHashKey(tmp,TagVal,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(tmp,TagVal,TmpLoc),curtyvar);
   
      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d",TagVal);
	VG_(printf)(".t%d ):=", tmp);  
	VG_(printf)("var%u ; \n", curtyvar); 
      }

      curtyvar++;
    }

  newTy = setTypeOfToMeet(getVarOf(locToHashKey(tmp,TagVal,TmpLoc)),hint); 

 
  if (ca_output_comment)
  {
  if (hint == SignedHint)
    {
      /* Something seems to be broken with giving VG_(printf) */
      /* more than one vararg. Workaround. */ 
    VG_(printf)("XXX TypeStateOf(VarOf(CV%d", TagVal);
    VG_(printf)(".t%d)) := ",tmp); 
    VG_(printf)("TypeStateOf(VarOf(CV%d.", TagVal);
    VG_(printf)("t%d)) MEET SIGNED; \n", tmp); 
    }
  else if (hint == UnsignedHint) 
    {

    VG_(printf)("XXX TypeStateOf(VarOf(CV%d", TagVal);
    VG_(printf)(".t%d)) := ",tmp); 
    VG_(printf)("TypeStateOf(VarOf(CV%d.", TagVal);
    VG_(printf)("t%d)) MEET UNSIGNED; \n", tmp); 
    }
  }

  if (newTy == Bot)
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX newTy = %d \n",newTy); 
      }
      cgEmitQueryBadRange(tmp,TagVal); 
    }
  

  return; 
} 


void ogAddOpRhsTypeConstraints(IRSB * bb, IRExpr * arg, IntTyStateHint hint)
{
  IRDirty * d; 
  HWord TmpName; 

  switch (arg->tag)
    {
    case(Iex_RdTmp):
      TmpName = (HWord)arg->Iex.RdTmp.tmp; 

      d = unsafeIRDirty_0_N(0, "ogEmitTmpConstraint", 
			 &ogEmitTmpConstraint,
			   mkIRExprVec_3(
					 mkIRExpr_HWord(TmpName),
					 mkIRExpr_HWord(hint),
					 mkIRExpr_HWord(counter))
			);
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d)); 
      break;

    default: 
      break; 
    }
  return; 
}



void ogTmp2TmpAliasHelper(HWord lhs, HWord rhs, HWord eip) 
{
  /* Handle IR instruction of form t.lhs = t.rhs. */
  /* updates such that VarOf(t.lhs) := VarOf(t.rhs) */

  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(CV%d.",eip); 
    VG_(printf)("t%d) := ",lhs);
    VG_(printf)("VarOf(CV%d.",eip);
    VG_(printf)("t%d);\n",rhs);
  }

  /* Check whether rhs has a tyvar */ 
  if (getVarOf(locToHashKey(rhs,eip,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(rhs,eip,TmpLoc),curtyvar);

      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d",eip);
	VG_(printf)(".t%d ):=", rhs);  
	VG_(printf)("var%u ; \n", curtyvar); 
      }
      curtyvar++;
    }

  setVarOf(locToHashKey(lhs,eip,TmpLoc),
	   getVarOf(locToHashKey(rhs,eip,TmpLoc)));

  return; 
}



void ogAddTmp2TmpAliasHelper(IRSB * bb, IRTemp lhs, IRTemp rhs)
{
  IRDirty * d; 
  ULong lhs_int, rhs_int;
  
  lhs_int = (HWord)lhs;
  rhs_int = (HWord)rhs; 

      d = unsafeIRDirty_0_N(0, "ogTmp2TmpAliasHelper", 
			 &ogTmp2TmpAliasHelper,
			   mkIRExprVec_3(
					 mkIRExpr_HWord(lhs_int),
					 mkIRExpr_HWord(rhs_int),
					 mkIRExpr_HWord(counter)
					 )
			);
  setHelperAnns(d);
  addStmtToIRSB(bb,IRStmt_Dirty(d)); 

  return;
}


void ogTmp2GetAliasHelper(HWord templhs, HWord offset, HWord eip)
{

  /* Handle IR instruction of form t.lhs = GET(offset). */
  /* updates such that VarOf(t.lhs) := VarOf(reg.rhs) */
  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(CV%d.",eip); 
    VG_(printf)("t%d) := ",templhs);
    VG_(printf)("VarOf(");
    VG_(printf)("reg.%d);\n",offset);
  }

  /* Check whether reg has a tyvar */ 
  if (getVarOf(locToHashKey(offset,0,RegLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(offset,0,RegLoc),curtyvar);

      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(reg.%d) := ",offset);
	VG_(printf)("var%u ; \n", curtyvar); 
      }

      curtyvar++;
    }

  setVarOf(locToHashKey(templhs,eip,TmpLoc),
	   getVarOf(locToHashKey(offset,0,RegLoc)));
  return; 


}

void ogAddTmp2GetAliasHelper(IRSB * bb, IRTemp lhs, IRExpr * rhs)
{

  ULong lhs_int = (HWord)lhs;
  ULong offset = 0;
  IRDirty * d; 

  offset = (HWord)rhs->Iex.Get.offset; 

      d = unsafeIRDirty_0_N(0, "ogTmp2GetAliasHelper", 
			 &ogTmp2GetAliasHelper,
			   mkIRExprVec_3(
					 mkIRExpr_HWord(lhs_int),
					 mkIRExpr_HWord(offset),
					 mkIRExpr_HWord(counter)
					 )
			);
  setHelperAnns(d);
  addStmtToIRSB(bb,IRStmt_Dirty(d));   

  return; 
}

void ogTmp2LoadAliasHelper(HWord lhs, HWord addr, HWord eip )
{
  /* Handle IR instruction of form t.lhs = LOAD(addr). */
  /* updates such that VarOf(t.lhs) := VarOf(mem.addr) */

  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(CV%d.",eip); 
    VG_(printf)("t%d) := ",lhs);
    VG_(printf)("VarOf(");
    VG_(printf)("mem.%x);\n",addr);
  }

  /* Check first whether addr has a tyvar */ 
  if (getVarOf(locToHashKey(addr,0,MemLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(addr,0,MemLoc),curtyvar);

      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(mem.%x) := ",addr);
	VG_(printf)("var%u ; \n", curtyvar); 
      }
      curtyvar++;
    }

  /* Now we know Varof(mem.addr) has a tyvar */ 
  setVarOf(locToHashKey(lhs,eip,TmpLoc),
	   getVarOf(locToHashKey(addr,0,MemLoc))); 

  return; 
} 

void ogAddTmp2LoadAliasHelper(IRSB * bb, IRTemp lhs, IRExpr * addr)
{
  IRDirty * d; 
  ULong lhs_int = (HWord)lhs; 

  d = unsafeIRDirty_0_N(0,"ogTmp2LoadAliasHelper", 
			&ogTmp2LoadAliasHelper, 
			mkIRExprVec_3(
				      mkIRExpr_HWord(lhs_int),
				      addr,
				      mkIRExpr_HWord(counter)
				      )
			); 
  setHelperAnns(d); 
  addStmtToIRSB(bb,IRStmt_Dirty(d));   

  return;
}

void ogEmitCalcCondConstraints(HWord cond, HWord cc_op, HWord eip)
{

  /* Emit type constraints from condition calculation. */
  /* cond tells us which condition was calculated, */
  /* cc_op tells us which of reg.36, reg.40, and reg.44 */
  /* are involved in the constraints. */

  /* TODO: emit constraints */ 

  IntTyStateHint int_hint = opToHint(cond); 
  ccOpHint cc_op_hint = ogccOpToHint(cc_op); 
  
  switch (cc_op_hint)
    {
    case (oneReg):
      /* emit constraint on loc36 of type int_hint */ 
      ogEmitRegConstraint(36,int_hint); 
      break;
    case (twoRegs):
      /* emit constraints on loc36 and loc40 of type int_hint */
      ogEmitRegConstraint(36,int_hint); 
      ogEmitRegConstraint(40,int_hint); 
      break; 
    default:
      break;
    }  

  return; 
}

void ogAddCCallConstraints(IRSB * bb, IRTemp rst, IRExpr * call)
{
  IRCallee * callee = call->Iex.CCall.cee;
  IRExpr ** callee_args = call->Iex.CCall.args; 
  IRDirty * d; 


  /* Don't add instrumentation unless the call will lead to */
  /* new constraints or aliasing. */
  
  /* Right now, only care about x86g_calculate_condition. */ 
  if (!VG_(strncmp)(callee->name, "x86g_calculate_condition",24))
    {


      d = unsafeIRDirty_0_N(0,
			    "ogEmitCalcCondConstraints",
			    &ogEmitCalcCondConstraints,
			    mkIRExprVec_3(callee_args[0],
					  callee_args[1],
					  mkIRExpr_HWord(counter)
					  )
			    );
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d)); 
    }

  return; 
}

void ogEmitNewTmpTyvar(HWord tmpname, HWord TagValue)
{

  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(CV%d",TagValue); 
    VG_(printf)(".t%d) := ",tmpname);
    VG_(printf)(" var%u;\n",curtyvar); 
  }

  setVarOf(locToHashKey(tmpname,TagValue,TmpLoc),curtyvar); 

  curtyvar++;
  return; 
}

IntType ogBinopTypeStateFunc(HWord opcode, IntType arg1, IntType arg2)
{
  IntType ret = Top; 

  return ret; 
}


void ogEmitBinopTmpTmpTypeCons(HWord lhs, HWord opcode, 
			       HWord tmp1, HWord tmp2, 
			       HWord TagVal)
{
  IntType lhsType = Top; 
  IntType arg1type = Top;
  IntType arg2type = Top; 

  if (ca_output_comment)
  {
    VG_(printf)("XXX TypeStateOf(VarOf(CV%d",TagVal);
    VG_(printf)(".t%d)) := ",lhs);
    VG_(printf)(" BinopTypeStateFunc(%x,",opcode);
    VG_(printf)("TypeStateof(VarOf(CV%d",TagVal);
    VG_(printf)(".t%d)),",tmp1);
    VG_(printf)("TypeStateOf(VarOf(CV%d",TagVal);
    VG_(printf)(".t%d)) )\n",tmp2);
  }

  /* Check first whether tmp1 has a tyvar */ 
  if (getVarOf(locToHashKey(tmp1,TagVal,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(tmp1,TagVal,TmpLoc),curtyvar);

      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d.",TagVal);
	VG_(printf)("t%d := ",tmp1); 
	VG_(printf)("var%u ; \n", curtyvar); 
      }

      curtyvar++;
    }

  /* Check first whether tmp2 has a tyvar */ 
  if (getVarOf(locToHashKey(tmp2,TagVal,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(tmp2,TagVal,TmpLoc),curtyvar);

      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d.",TagVal);
	VG_(printf)("t%d := ",tmp2); 
	VG_(printf)("var%u ; \n", curtyvar); 
      }
      curtyvar++;
    }

  arg1type = getTypeOf(getVarOf(locToHashKey(tmp1,TagVal,TmpLoc)));
  arg2type = getTypeOf(getVarOf(locToHashKey(tmp2,TagVal,TmpLoc)));

  lhsType = ogBinopTypeStateFunc(opcode, arg1type, arg2type); 

  /* Check whether lhs has a tyvar */ 
  if (getVarOf(locToHashKey(lhs,TagVal,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(lhs,TagVal,MemLoc),curtyvar);

      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d.",TagVal);
	VG_(printf)("t%d := ",lhs); 
	VG_(printf)("var%u ; \n", curtyvar); 
      }
      curtyvar++;
    }


  setTypeOf(getVarOf(locToHashKey(lhs,TagVal,TmpLoc)),lhsType); 

  return; 
}

void ogEmitBinopTmpConstTypeCons(HWord lhs, HWord opcode, 
				 HWord tmp, HWord TagVal)
{
  IntType lhsType = Top; 
  IntType arg1type = Top;
  IntType consttype = Top; 


  if (ca_output_comment)
  {
    VG_(printf)("XXX TypeStateOf(VarOf(CV%d",TagVal);
    VG_(printf)(".t%d)) := ",lhs);
    VG_(printf)(" BinopTypeStateFunc(%x,",opcode);
    VG_(printf)("TypeStateOf(VarOf(CV%d",TagVal);
    VG_(printf)(".t%d)),",tmp);
    VG_(printf)("CONST)\n");
  }

  /* Check whether tmp has a tyvar */ 
  if (getVarOf(locToHashKey(tmp,TagVal,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(tmp,TagVal,TmpLoc),curtyvar);
      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d.",TagVal);
	VG_(printf)("t%d := ",tmp); 
	VG_(printf)("var%u ; \n", curtyvar);
      } 
      curtyvar++;
    }

  /* Check whether lhs has a tyvar */ 
  if (getVarOf(locToHashKey(lhs,TagVal,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(lhs,TagVal,TmpLoc),curtyvar);
      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d.",TagVal);
	VG_(printf)("t%d := ",lhs); 
	VG_(printf)("var%u ; \n", curtyvar); 
      }
      curtyvar++;
    }

  arg1type = getTypeOf(getVarOf(locToHashKey(tmp,TagVal,TmpLoc)));

  lhsType = ogBinopTypeStateFunc(opcode, arg1type, consttype); 
  setTypeOf(getVarOf(locToHashKey(lhs,TagVal,TmpLoc)),lhsType); 

  return; 
}

void ogAddBinopAliasAndTypeConstraints(IRSB * bb, IRStmt * st)
{

  IROp the_op; 
  IRExpr * arg1;
  IRExpr * arg2;

  HWord cur_ctr; 
  HWord lhs; 
  HWord tmpname; 
  IRDirty * d1;
  IRDirty * d2; 

  vassert(st->tag = Ist_WrTmp); 
  the_op = (HWord)st->Ist.WrTmp.data->Iex.Binop.op;
  arg1 = st->Ist.WrTmp.data->Iex.Binop.arg1;
  arg2 = st->Ist.WrTmp.data->Iex.Binop.arg2; 
  cur_ctr = (HWord)(counter);

  /* Emit new type variable for lhs */
  lhs = (HWord)st->Ist.WrTmp.tmp;
  d1 = unsafeIRDirty_0_N(0,
			"ogEmitNewTmpTyvar",
		      &ogEmitNewTmpTyvar, 
		      mkIRExprVec_2(mkIRExpr_HWord(lhs),
				    mkIRExpr_HWord(cur_ctr)
				    )
		      ); 
  
  setHelperAnns(d1);
  addStmtToIRSB(bb,IRStmt_Dirty(d1)); 

  /* Emit constraints on lhs type variable */ 
  /* handle only case where arg1 and arg2 are tmps or consts for now */ 

  /* Both args are tmps */
  if (arg1->tag== Iex_RdTmp && arg2->tag == Iex_RdTmp)
    {
      d2 = unsafeIRDirty_0_N(0,
			     "ogEmitBinopTmpTmpTypeCons",
			     &ogEmitBinopTmpTmpTypeCons,
			     mkIRExprVec_5(mkIRExpr_HWord(lhs),
					   mkIRExpr_HWord(the_op),
					   mkIRExpr_HWord((HWord)
							  arg1->Iex.RdTmp.tmp),
					   mkIRExpr_HWord((HWord)
							  arg2->Iex.RdTmp.tmp),
					   mkIRExpr_HWord(cur_ctr)
					   )
			     );
      setHelperAnns(d2);
      addStmtToIRSB(bb,IRStmt_Dirty(d2));
    }

  /* One arg is a tmp, one is a const */ 
  if ((arg1->tag == Iex_RdTmp && arg2->tag == Iex_Const) 
      || (arg1->tag == Iex_Const && arg2->tag == Iex_RdTmp))
    {
      if (arg1->tag == Iex_RdTmp) tmpname = (HWord)arg1->Iex.RdTmp.tmp;
      else if (arg2->tag == Iex_RdTmp) tmpname = (HWord)arg2->Iex.RdTmp.tmp;
      else vpanic("Neither arg1 nor arg2 is a tmp! \n"); 

      d2 = unsafeIRDirty_0_N(0,
			     "ogEmitBinopTmpConstTypeCons",
			     &ogEmitBinopTmpConstTypeCons,
			     mkIRExprVec_4(mkIRExpr_HWord(lhs),
					   mkIRExpr_HWord(the_op),
					   mkIRExpr_HWord(tmpname), 
					   mkIRExpr_HWord(cur_ctr)
					   )
			     );

      setHelperAnns(d2);
      addStmtToIRSB(bb,IRStmt_Dirty(d2)); 
    }
						       

  return; 
}

void ogAddTmpConstraints(IRSB * bb, IRStmt * st, IRExpr * rhs) 
{
  IntTyStateHint hint; 
  vassert(st);
  vassert(rhs); 
  
  switch (rhs->tag)
    {
    case (Iex_RdTmp) :
 
      ogAddTmp2TmpAliasHelper(bb,st->Ist.WrTmp.tmp,rhs->Iex.RdTmp.tmp); 
      break;
    case (Iex_Get) :
      ogAddTmp2GetAliasHelper(bb,st->Ist.WrTmp.tmp, rhs); 
      break;
    case(Iex_Load):
      ogAddTmp2LoadAliasHelper(bb,st->Ist.WrTmp.tmp,rhs->Iex.Load.addr);
      break;
    case (Iex_CCall):
      ogAddCCallConstraints(bb, st->Ist.WrTmp.tmp,rhs);
      break; 
    case (Iex_Binop) :
      {

	/* Check for signed/unsigned constraint emission to args*/ 
	hint = opToHint(rhs->Iex.Binop.op); 
	if (hint != HopelessHint) 
	  {
	    ogAddOpRhsTypeConstraints(bb,rhs->Iex.Binop.arg1,hint); 
	    ogAddOpRhsTypeConstraints(bb,rhs->Iex.Binop.arg2,hint); 
	  }

	// Propagate aliasing and type constraints from args to result
	ogAddBinopAliasAndTypeConstraints(bb,st);

	// Output CVCL presentation language constraints
	// cgAddBinopPropConstraints 

	// Check whether type of lhs, arg1, or arg2 set to Bot
	// and if so, emit the appropriate query
	// cgCheckBotEmitQuery(bb, st); 
      }
    case (Iex_Unop):
   
	hint = opToHint(rhs->Iex.Unop.op); 
	if (hint != HopelessHint)
	  {
	    ogAddOpRhsTypeConstraints(bb,rhs->Iex.Unop.arg,hint);
	  }

	// TODO: ogAddUnopAliasAndTypeConstrains(bb,s); 

    default: break; 
    }
  return; 
}

void ogEmitPutConstConstraints(HWord offset, HWord eip)
{

  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(reg.%d) := ERASE_CONST;\n",offset);  
  }
  clearVarOf(locToHashKey(offset,0,RegLoc)); 

  return; 
}

void ogEmitPutTmpConstraints(HWord offset, HWord tmpname, HWord eip) 
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(reg.%d) := ", offset);
    VG_(printf)("VarOf(CV%d.",eip);
    VG_(printf)("t%d);\n",tmpname);
  }

  /* Check whether tmpname has a tyvar */ 
  if (getVarOf(locToHashKey(tmpname,eip,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(tmpname,eip,TmpLoc),curtyvar);

      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d.",eip);
	VG_(printf)("t%d := ",tmpname); 
	VG_(printf)("var%u ; \n", curtyvar);
      } 
      curtyvar++;
    }

  setVarOf( locToHashKey(offset,0,RegLoc),
	    getVarOf(locToHashKey(tmpname,eip,TmpLoc))); 

  return;
}

void ogAddPutConstraints(IRSB * bb, Int offset, IRExpr * data)
{
  IRDirty * d;  
  HWord h_offset = (HWord)(offset);  
  HWord lhs_name;  

  switch (data->tag)
    {
      

    case(Iex_Const):
     
      d = unsafeIRDirty_0_N(0, "ogEmitPutConstConstraints",
			    &ogEmitPutConstConstraints,
			    mkIRExprVec_2(mkIRExpr_HWord(h_offset),
					  mkIRExpr_HWord(counter)
					  )
			    );
      setHelperAnns(d);
      addStmtToIRSB(bb, IRStmt_Dirty(d)); 
      break;
      
    case(Iex_RdTmp):

     
      lhs_name = (HWord)data->Iex.RdTmp.tmp; 

      d = unsafeIRDirty_0_N(0, "ogEmitPutTmpConstraints",
			    &ogEmitPutTmpConstraints,
			    mkIRExprVec_3(mkIRExpr_HWord(h_offset),
					  mkIRExpr_HWord(lhs_name),
					  mkIRExpr_HWord(counter)
					  )
			    );
      setHelperAnns(d);
      addStmtToIRSB(bb, IRStmt_Dirty(d)); 
      break;
      
    default: 
      break; 
    }

  return; 
}

void ogEmitStoreTmp2TmpConstraints(HWord addr, HWord tmpname, HWord eip)
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(mem.%x) := ", addr);
    VG_(printf)("VarOf(CV%d", eip);
    VG_(printf)(".t%d);\n",tmpname); 
  }

  /* Check whether tmp has a tyvar */ 
  if (getVarOf(locToHashKey(tmpname,eip,TmpLoc)) == -1)
    {
      /* No, so add one */ 
      setVarOf(locToHashKey(tmpname,eip,TmpLoc),curtyvar);
      if (ca_output_comment)
      {
	VG_(printf)("XXX VarOf(CV%d.",eip);
	VG_(printf)("t%d ) := ",tmpname); 
	VG_(printf)("var%u ; \n", curtyvar); 
      }
      curtyvar++;
    }

  setVarOf( locToHashKey(addr,0,MemLoc),
	    getVarOf(locToHashKey(tmpname,eip,TmpLoc))); 
  

  return;
}


void  ogEmitStoreTmp2ConstConstraints (HWord addr)
{
  /* Being assigned a constant means we need a new type variable */ 
  if (ca_output_comment)
  {
    VG_(printf)("XXX VarOf(mem,%x) := ", addr);
    VG_(printf)(" var%u; \n", curtyvar); 
  }

  setVarOf(locToHashKey(addr,0,MemLoc),curtyvar);

  curtyvar++;
  return; 
}
void ogAddStoreConstraints(IRSB * bb, IRExpr * addr, IRExpr * data)
{
  IRDirty * d;
  HWord tmpname;
 

  switch (addr->tag) 
    {
    case (Iex_RdTmp):
      switch (data->tag)
	{
	case (Iex_RdTmp):
	  tmpname = (HWord) data->Iex.RdTmp.tmp; 
	

	  d = unsafeIRDirty_0_N(0,
			    "ogEmitStoreTmp2TmpConstraints",
			    &ogEmitStoreTmp2TmpConstraints,
			    mkIRExprVec_3(addr,
					  mkIRExpr_HWord(tmpname),
					  mkIRExpr_HWord(counter)
					  )
			    );
	  setHelperAnns(d);
	  addStmtToIRSB(bb, IRStmt_Dirty(d)); 
	  break; 
	case (Iex_Const):
	  /* TODO: add code to emit new ty var for memory address */ 
	  d = unsafeIRDirty_0_N(0,
				"ogEmitStoreTmp2ConstConstraints",
				&ogEmitStoreTmp2ConstConstraints,
				mkIRExprVec_1(addr
					      )
				);
	  setHelperAnns(d);
	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 
	  break;
	default:
	  /* Should not reach here. */
	     ppIRExpr(data); 
	   vpanic("Bad store address!\n"); 
	  break; 
	}
      break; 
    default:
      break; 
    }

  return; 
}

void ogIRStmt (IRSB * bb,  IRStmt* s , ULong bb_counter)
{
  //  unsigned long n_old_typestates_state_instance = 0; 
  IRExpr * rhs;

  counter = bb_counter; 
   if (!s) {
     if (ca_output_comment)
     {
       vex_printf("XXX !!! IRStmt* which is NULL !!!");
     }
      return;
   }
   switch (s->tag) {
      case Ist_NoOp:
	break; /* Nothing to emit. */
      case Ist_IMark:
	break; /* Nothing to emit. */ 
      case Ist_AbiHint:
	break; /* Nothing to emit. */ 

      case Ist_Put:
	/* TODO: update map of names -> typestate vars */ 
	/* PUT(30) = t32 --> VarOf(reg.30) := VarOf(eipX.t32) */ 
	/* PUT(30) = const --> VarOf(reg.30) := NONE */ 
	rhs = s->Ist.Put.data;
	ogAddPutConstraints(bb, s->Ist.Put.offset,rhs);
         break;

      case Ist_PutI:
	/* TODO: update map of names -> typestate vars */ 
         break;

      case Ist_WrTmp:
	rhs = s->Ist.WrTmp.data; 
	ogAddTmpConstraints(bb,s, rhs); 

         break;
      case Ist_Store:
	/* TODO: update map of names -> typestate vars */ 
	ogAddStoreConstraints(bb,s->Ist.Store.addr,s->Ist.Store.data); 
        break;
      case Ist_Dirty:
	/* TODO: handle common dirty helpers here */ 
         break;
      case Ist_Exit:
	/* No need to emit constraints here; catch earlier at CMP or */
	/* at x86g_calc_condition. Do nothing. */ 
         break;
      default: 
	return; 
   }
}

