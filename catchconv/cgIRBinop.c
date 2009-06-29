/*--------------------------------------------------------------------*/
/*--- CatchConversions                           cgIRBinop.c       ---*/
/*--------------------------------------------------------------------*/
/*
   Copyright (C) 2006-09 Regents of the University of California
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

/* _c_onstraint _g_eneration from Valgrind IR */ 
/*  contains code for handling binary operators */ 
/* Currently assumes a 32 bit guest architecture */ 

#include "libvex_basictypes.h"
#include "libvex_ir.h"
#include "libvex.h"
#include "limits.h"

#include "ca_vex_util.h"


#include "pub_tool_basics.h"
#include "pub_tool_libcassert.h"
#include "pub_tool_tooliface.h"
#include "pub_tool_vki.h" 

#include "pub_tool_libcprint.h"
#include "pub_tool_debuginfo.h" 
#include "pub_tool_libcbase.h"
#include "pub_tool_options.h"
#include "pub_tool_hashtable.h" 
#include "pub_tool_mallocfree.h"
#include "pub_tool_libcproc.h" 
#include "pub_tool_threadstate.h"

#include "ca_interval.h"
#include "isIR.h"
#include "ogIR.h" 
#include "ca_settings.h"
#include "trackmemIR.h" 
#include "cgIR.h" 
#include "ca_stats.h" 
#include "catchconv.h" 


/*---------------------------------------------------------------*/
/*--- Generate STP  from VEX IR for binary ops                ---*/
/*---------------------------------------------------------------*/

HWord numUnhandledBinops = 0; 

HWord cgIsSupportedBinop(IROp op)
{
  return (op == Iop_Add32 ||
	  op == Iop_Add16 ||
	  op == Iop_Add8  ||
	  op == Iop_Sub32 ||
	  op == Iop_Sub16 || 
	  op == Iop_Sub8  || 
	  op == Iop_Xor32 ||
	  op == Iop_And32 ||
	  op == Iop_Or32  ||
	  op == Iop_Shl32 ||
	  op == Iop_Shr32 ||
	  op == Iop_Sar32 ||
	  op == Iop_Shl64 ||
	  op == Iop_Shr64 || 
	  op == Iop_32HLto64 || 
	  op == Iop_CmpLT32S ||
	  op == Iop_CmpLT32U ||
	  op == Iop_CmpLE32S ||
	  op == Iop_CmpLE32U ||
	  op == Iop_CmpEQ32 ||
	  op == Iop_Mul32 || 
	  op == Iop_MullU32 ||
	  op == Iop_And16 ||
	  op == Iop_Or16 || 
	  op == Iop_And8 ||
	  op == Iop_Or8 ||
	  op == Iop_CmpNE32 ||
	  op == Iop_CmpEQ16 ||  
	  op == Iop_CmpEQ8 ||
	  op == Iop_CmpNE8); 
}


void cgAddTmpBinopConstraints(IRSB * bb, IRStmt * s)
{
  IRExpr * rhs;
  IRExpr * arg1;
  IRExpr * arg2;
  IRDirty * d; 
  HWord lhstmp;
  HWord arg1tmp;
  HWord arg2tmp;
  HWord arg1val;
  HWord arg2val;
  IROp theOp; 
  IRType lhsty, arg1ty, arg2ty; 

  // extra arguments
  cgArgs_EmitTmpBinopConstConst *extra_args = NULL;
  cgArgs_EmitTmpBinopTmpConst *extra_args1 = NULL;
  cgArgs_EmitTmpBinopConstTmp *extra_args2 = NULL;
  cgArgs_EmitTmpBinopTmpTmp *extra_args3 = NULL;

  vassert(bb);
  vassert(s);
  vassert(s->tag == Ist_WrTmp); 
  rhs = s->Ist.WrTmp.data; 
  vassert(rhs->tag == Iex_Binop); 
  arg1 = rhs->Iex.Binop.arg1;
  arg2 = rhs->Iex.Binop.arg2; 
  lhstmp = (HWord) s->Ist.WrTmp.tmp;
  theOp = rhs->Iex.Binop.op; 


  /* We don't support all binops yet. Skip ones we don't, emit notice. */
  /* Later we can look at these notices, decide which binops to support. */  
  if (! cgIsSupportedBinop(theOp))
  {
    if (ca_output_comment)
    {
      VG_(printf)("XXX Unhandled binop: "); 
      ppIROp(theOp); 
      VG_(printf)("\n"); 
    }
    numUnhandledBinops++; 
    return; 
  } 

  lhsty = bb->tyenv->types[lhstmp]; 

  switch (arg1->tag)
    {

    case(Iex_RdTmp):

      arg1tmp = (HWord)arg1->Iex.RdTmp.tmp;
      
      arg1ty = bb->tyenv->types[arg1tmp]; 

      switch (arg2->tag)
	{
	case (Iex_RdTmp):
	  arg2tmp = (HWord)arg2->Iex.RdTmp.tmp; 
	  arg2ty = bb->tyenv->types[arg2tmp]; 
	 
	  extra_args3 = VG_(malloc)("extraArgs",sizeof(cgArgs_EmitTmpBinopTmpTmp));
	  

	  // getStructOf(bb, extra_args3); // store struct into hash table
	  extra_args3->theop = theOp;
	  extra_args3->tagVal = cgBBCounter;
	  extra_args3->lhsty = lhsty;
	  extra_args3->arg1ty = arg1ty;
	  extra_args3->arg2ty = arg2ty;
	  extra_args3->lhsname = lhstmp;
	  extra_args3->arg1name = arg1tmp;
	  extra_args3->arg2name = arg2tmp;

	  d = unsafeIRDirty_0_N(0,
				"cgEmitTmpBinopTmpTmp",
				&cgEmitTmpBinopTmpTmp,
				mkIRExprVec_3(
					      /*mkIRExpr_HWord(theOp),
					  mkIRExpr_HWord(cgBBCounter),
					  mkIRExpr_HWord(lhsty),
					  mkIRExpr_HWord(arg1ty),
					  mkIRExpr_HWord(arg2ty),
					  mkIRExpr_HWord(lhstmp),
					  mkIRExpr_HWord(arg1tmp),
					  mkIRExpr_HWord(arg2tmp),*/
					  mkIRExpr_HWord( (HWord)extra_args3),
					  IRExpr_RdTmp(arg1->Iex.RdTmp.tmp),
					  IRExpr_RdTmp(arg2->Iex.RdTmp.tmp) 
					  )
			    );
	  setHelperAnns(d);
	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 

	  break; 
	case (Iex_Const):
	  // CHANGING OVER TO STRUCT
	  arg2val = cgConstToHword(arg2); 
	  
	  // taking care of extra arguments                                                                                                    
	  extra_args1 = VG_(malloc)("extraArgs",sizeof(cgArgs_EmitTmpBinopTmpConst));
	    // getStructOf(bb, extra_args1); // store struct into hash table 
	    extra_args1->theop = theOp;
	    extra_args1->tagVal = cgBBCounter; // not tagVal
	    extra_args1->lhsty = lhsty;
	    extra_args1->arg1ty = arg1ty;
	    extra_args1->lhsname = lhstmp; // not lhsname
	    extra_args1->arg1name = arg1tmp; //not arg1name
	    extra_args1->arg2val = arg2val;
	    /*
	  d = unsafeIRDirty_0_N(0,
				"cgEmitTmpBinopTmpConst",
				&cgEmitTmpBinopTmpConst,
				mkIRExprVec_7(
					      mkIRExpr_HWord(theOp),
					      mkIRExpr_HWord(cgBBCounter),
					      mkIRExpr_HWord(lhsty), 
					      mkIRExpr_HWord(arg1ty),
					      mkIRExpr_HWord(lhstmp),
					      mkIRExpr_HWord(arg1tmp),
					      mkIRExpr_HWord(arg2val)
					  )
					  );*/
	    d = unsafeIRDirty_0_N(0,                                                                                       
				  "cgEmitTmpBinopTmpConst",                                                                
				  &cgEmitTmpBinopTmpConst,                                                                 
				  mkIRExprVec_1(
						mkIRExpr_HWord( (HWord)extra_args1)
						)
				  );
	  setHelperAnns(d);
	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 
	  break;
	default:
	  break; 
	}
      break; 


    case(Iex_Const):
      arg1val = cgConstToHword(arg1); 
      switch(arg2->tag)
	{
	case (Iex_RdTmp):
	  arg2tmp = (HWord) arg2->Iex.RdTmp.tmp; 
	  arg2ty = bb->tyenv->types[arg2tmp]; 
	  extra_args2 = VG_(malloc)("extraargs", sizeof(cgArgs_EmitTmpBinopConstTmp));
	  // getStructOf(bb, extra_args2); // store struct into hash table 
	  extra_args2->theop = theOp;
	  extra_args2->tagVal = cgBBCounter;
	  extra_args2->lhsty = lhsty;
	  extra_args2->arg2ty = arg2ty;
	  extra_args2->lhsname = lhstmp;
	  extra_args2->arg1val = arg1val;
	  extra_args2->arg2name = arg2tmp;

	  d = unsafeIRDirty_0_N(0,
				"cgEmitTmpBinopConstTmp",
				&cgEmitTmpBinopConstTmp,
				mkIRExprVec_1(
					      mkIRExpr_HWord((HWord) extra_args2)
					      /*    mkIRExpr_HWord(theOp),
					      mkIRExpr_HWord(cgBBCounter),
					      mkIRExpr_HWord(lhsty),
					      mkIRExpr_HWord(arg2ty),
					      mkIRExpr_HWord(lhstmp),
					      mkIRExpr_HWord(arg1val),
					      mkIRExpr_HWord(arg2tmp) */
					      )
				);
	  setHelperAnns(d);
	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 
	  break;

	case (Iex_Const):
	  arg2val = cgConstToHword(arg2); 

          // taking care of extra arguments                                                                                    
          extra_args = VG_(malloc)("extraArgs", sizeof(cgArgs_EmitTmpBinopConstConst));
          // getStructOf(bb, extra_args); // store struct into hash table 
	  extra_args->theop = theOp;
          extra_args->tagVal = cgBBCounter; // not tagVal
          extra_args->lhsty = lhsty;
          extra_args->lhsname = lhstmp; //not lhstmp

	  d = unsafeIRDirty_0_N(0,
				"cgEmitTmpBinopConstConst",
				&cgEmitTmpBinopConstConst,
				mkIRExprVec_3(mkIRExpr_HWord( (HWord)extra_args),
					      mkIRExpr_HWord(arg1val),
					      mkIRExpr_HWord(arg2val)
				      
					  )
			    );
	  setHelperAnns(d);
	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 
	  break; 

	default:
	  break; 

	}
      
      break; 
    default:

      if (ca_output_comment)
      {
	VG_(printf)("XXX Warning : unhandled binop arg type in ");
	ppIRStmt(s);
	VG_(printf)("\n"); 
      }
      break; 
    }

  return; 
}



// Ordering of Tmp and Const args is important because binop
// may depend on the order, e.g. Sub32
void cgEmitTmpBinopConstConst (
			       cgArgs_EmitTmpBinopConstConst *extra_args,
			       HWord arg1val, 
			       HWord arg2val
			       )
{

  HWord lhsSymP; 


  // extracting arguments from struct extra_args
  IROp theop = extra_args->theop;
  HWord tagVal = extra_args->tagVal;
  HWord lhsty = extra_args->lhsty;
  HWord lhsname = extra_args->lhsname;

  lhsSymP = isTmpSymbolicP(tagVal, lhsname); 
 
  if (! lhsSymP )
  {
    /* If LHS is not symbolic, do not emit constraint */
    return; 
  }

  cgDeclareTmpAtRunIfUndeclared(tagVal, lhsname, lhsty); 

  switch(theop)
  {
  case (Iop_32HLto64):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[63:32] = 0hex"); 
    cgPrintHWord(arg1val,8); 
    VG_(printf)(" );\n");
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[31:0] = 0hex");
    cgPrintHWord(arg2val,8);  
    VG_(printf)(" );\n");
    break; 

    case (Iop_Sub32):
    case (Iop_Add32):
    case (Iop_Add16):
    case (Iop_Add8):
    case (Iop_Sub16): 
    case (Iop_Sub8):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(32,0hex");
      cgPrintHWord(arg1val,8); 
      VG_(printf)(" ,0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 

    case (Iop_MullU32):
    case (Iop_Mul32):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)("[31:0]",lhsname);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(32,0hex");
      cgPrintHWord(arg1val,8); 
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 


    case (Iop_Xor32):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,8); 
      VG_(printf)(" ,0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 

    case (Iop_And32):
    case (Iop_Or32):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" ");  
      cgPrintOp(theop);  
      VG_(printf)(" 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 


      /* STP has a nasty quirk - it errors if we attempt to >> or << */
      /* by 0 positions. Need to explicitly check for this case, and */
      /* if we see it, output the identity instead.                  */
    case (Iop_Shl32):
    case (Iop_Shr32):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = ");
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,8);
      if (arg2val != 0)
      {
	VG_(printf)(" ");  
	cgPrintOp(theop); 
	VG_(printf)(" %x [31:0]));\n",arg2val);
      } 
      else
      {
	/* Can't << or >> by 0, emit identity instead. */ 
	VG_(printf)(");\n");
      }
      break; 

      /* STP has a nasty quirk - it errors if we attempt to >> or << */
      /* by 0 positions. Need to explicitly check for this case, and */
      /* if we see it, output the identity instead.                  */
    case (Iop_Shl64):
    case (Iop_Shr64):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = ");
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,16);
      if (arg2val != 0)
      {
	VG_(printf)(" ");  
	cgPrintOp(theop); 
	VG_(printf)(" %x [63:0]));\n",arg2val);
      } 
      else 
      {
	VG_(printf)(");\n");
      }
      break; 

      /* STP has a nasty quirk - it errors if we attempt to >> or << */
      /* by 0 positions. Need to explicitly check for this case, and */
      /* if we see it, output the identity instead.                  */
    case (Iop_Sar32):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = ");
      VG_(printf)("( (0hex");
      cgPrintHWord(arg1val,8);
      if (arg2val != 0)
      {
	VG_(printf)(" ");  
	cgPrintOp(theop); 
	VG_(printf)(" %x [31:0]) ",arg2val);
      } 
      else
      {
         VG_(printf)(") ");
      }
      
      /* If high bit is set in arg1, set high bit of result */ 
      if ((arg1val >> 31) == 1)
      {
	VG_(printf)(" | 0hex80000000 );\n"); 
      }
      else
      {
	VG_(printf)("); \n"); 
      }
      break; 

    case (Iop_CmpLT32S):
    case (Iop_CmpLT32U):
    case (Iop_CmpLE32S):
    case (Iop_CmpLE32U):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      cgPrintOp(theop); 
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,8); 
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break;

    case (Iop_CmpEQ32):
 
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" ");  
      cgPrintOp(theop);  
      VG_(printf)(" 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 
      

    default:
      if (ca_output_comment)
      {
	VG_(printf)("XXX Warning : Unhandled op ");
	ppIROp(theop);
	VG_(printf)(" in ConstConst binop.\n"); 
      }
      numUnhandledBinops++; 
      break; 
    }

  return; 
}

// Ordering of Tmp and Const args is important because binop
// may depend on the order, e.g. Sub32
/*void cgEmitTmpBinopTmpConst (
			     IROp theop, 
			     HWord tagVal,
			     IRType lhsty,
			     IRType arg1ty,
			     HWord lhsname,
			     HWord arg1name, 
			     HWord arg2val
			     )
{*/
// TROUBLESOME METHOD
// XXX dmolnar: what does "Troublesome Method" mean? need to ask sushant
void cgEmitTmpBinopTmpConst (
			     cgArgs_EmitTmpBinopTmpConst *extra_args
			     )
{

  HWord lhsSymP; 
  HWord arg1SymP; 
  HWord uintMin = 0; 
  HWord intMin = INT_MIN; 
  HWord intMax = INT_MAX;
  HWord uintMax = UINT_MAX; 

  // extracting arguments out of struct
  // we use a struct because VEX doesn't pass > 5 args on amd64
  IROp theop = extra_args->theop;
  HWord tagVal = extra_args->tagVal;
  IRType lhsty = extra_args->lhsty;
  IRType arg1ty = extra_args->arg1ty;
  HWord lhsname = extra_args->lhsname;
  HWord arg1name = extra_args->arg1name;
  HWord arg2val = extra_args->arg2val;

  lhsSymP = isTmpSymbolicP(tagVal, lhsname); 
  arg1SymP = isTmpSymbolicP(tagVal, arg1name); 

  if (! lhsSymP && ! arg1SymP )
  {
    /* If neither LHS nor arguments are symbolic, do not emit constraint */
    return; 
  }


  /* Check to see if arg1 is actually tainted. */ 
  if (! arg1SymP)
  {

    /* Can't use cgEmitTmpBinopConstConst b/c don't have arg1val */
    /* So just error out now. 
    cgEmitTmpBinopConstConst(
			     theop,
			     tagVal,
			     lhsty,
			     lhsname,
			     arg1val,
			     arg2val
			     ); 
    */
    vassert(arg1SymP); 
  }

  cgDeclareTmpAtRunIfUndeclared(tagVal, lhsname, lhsty);
  cgDeclareTmpAtRunIfUndeclared(tagVal, arg1name, arg1ty);  

  switch(theop)
    {

    case (Iop_32HLto64):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[63:32] = "); 
    cgPrintTmpName(arg1name,tagVal); 
    VG_(printf)(" );\n");
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[31:0] = ");
    cgPrintHWord(arg2val,8);  
    VG_(printf)(" );\n");
    break; 
 

    case (Iop_Sub32):
    case (Iop_Sub16):
    case (Iop_Sub8):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(32,");
      cgPrintTmpName(arg1name,tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 

      // Emit integer signed underflow query 
      VG_(printf)("XXX QUERY( BVSGT("); 
      cgPrintTmpName(lhsname, tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(intMin, 8); 
      VG_(printf)(")); %% TYPE IntUnderflowSigned \n");   
      break; 



    case (Iop_Add16):
      intMax = 32767;             // Max for 16 bit signed integer
    case (Iop_Add8): 
      if (intMax == INT_MAX)
      {
	intMax = 127;             // Max for 8 bit signed integer 
      }
    case (Iop_Add32):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(32,");
      cgPrintTmpName(arg1name,tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 

      // Emit signed integer overflow query 
      VG_(printf)("XXX QUERY( BVSLE("); 
      cgPrintTmpName(lhsname, tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(intMax, 8); 
      VG_(printf)(")); %% TYPE IntOverflowSigned \n");  


      // Emit unsigned integer overflow query 

      /* Pattern:

	 Original statement: 
	 Z = X +Y

	 Recompute at 64 bit precision: 

	 ASSERT( XW[31:0] = X);
	 ASSERT( XW[63:32] = 0hex00000000);  
	 ASSERT( YW[31:0] = Y);  
	 ASSERT( YW[63:32] = 0hex00000000); 
	 ASSERT( W = BVPLUS(64, XW, YW));

	 Query if 64 bit result is always less than 32(or 16 or 8) INT_MAX: 
	 QUERY(BVLE(W, 0hex00000000ffffffff));  
      */      

      cgDeclareTmpWideIfUndeclared(tagVal, lhsname);
      cgDeclareTmpWideIfUndeclared(tagVal, arg1name); 
      // arg2 is a constant, do not need to declare

      VG_(printf)("ASSERT("); 
      cgPrintTmpNameWide(arg1name, tagVal); 
      VG_(printf)("[63:32] = 0hex00000000);\n"); 

      VG_(printf)("ASSERT("); 
      cgPrintTmpNameWide(arg1name, tagVal); 
      VG_(printf)("[31:0] = "); 
      cgPrintTmpName(arg1name, tagVal); 
      VG_(printf)(" );\n");

      VG_(printf)("ASSERT( "); 
      cgPrintTmpNameWide(lhsname, tagVal); 
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(64,");
      cgPrintTmpNameWide(arg1name, tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,16); 
      VG_(printf)("));\n"); 


      // Now finally emit integer unsigned overflow query
      VG_(printf)("XXX QUERY( BVLE("); 
      cgPrintTmpNameWide(lhsname, tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(uintMax, 16); 
      VG_(printf)(")); %% TYPE IntOverflowUnsigned \n");  
      break; 

    case (Iop_Mul32):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)("[31:0]",lhsname);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(32, ");
      cgPrintTmpName(arg1name,tagVal);
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 

      // Emit signed integer overflow query 
      VG_(printf)("XXX QUERY( BVSLE("); 
      cgPrintTmpName(lhsname, tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(intMax, 8); 
      VG_(printf)(")); %% TYPE IntOverflowSigned \n");  
      break; 

    case (Iop_MullU32):

      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)("[31:0]",lhsname);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(32, ");
      cgPrintTmpName(arg1name,tagVal);
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 

      // Emit signed integer overflow query 
      VG_(printf)("XXX QUERY( BVLE("); 
      cgPrintTmpName(lhsname, tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(intMax, 8); 
      VG_(printf)(")); %% TYPE IntOverflowSigned \n");  
      break; 

    case (Iop_Xor32):

      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 

    
    case (Iop_And32):
    case (Iop_Or32):


      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal);
     
      cgPrintOp(theop); 
      VG_(printf)(" 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 

      break; 

    case (Iop_And16):
    case (Iop_Or16):

      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)("[15:0]",lhsname);
      VG_(printf)(" = "); 
      
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal);
      VG_(printf)("[15:0] ",arg1name); 
      cgPrintOp(theop); 
      VG_(printf)(" 0hex");
      cgPrintHWord(arg2val,4); 
      VG_(printf)("));\n"); 
      break; 

    case (Iop_And8):
    case (Iop_Or8):

      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)("[7:0]",lhsname);
      VG_(printf)(" = "); 
      
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal);
      VG_(printf)("[7:0] ",arg1name); 
      cgPrintOp(theop); 
      VG_(printf)(" 0hex");
      cgPrintHWord(arg2val,2); 
      VG_(printf)("));\n"); 

      break; 

      /* STP has a nasty quirk - it errors if we attempt to >> or << */
      /* by 0 positions. Need to explicitly check for this case, and */
      /* if we see it, output the identity instead.                  */
    case (Iop_Shl64):
    case (Iop_Shr64):

      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal);

      if (arg2val != 0)
      {
	cgPrintOp(theop); 
	VG_(printf)(" %u [63:0]));\n",arg2val); 
      }
      else
      {
	VG_(printf)(" ));\n"); 
      }
      break; 


      /* STP has a nasty quirk - it errors if we attempt to >> or << */
      /* by 0 positions. Need to explicitly check for this case, and */
      /* if we see it, output the identity instead.                  */
    case (Iop_Shl32):
    case (Iop_Shr32):

      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal);

      if (arg2val != 0) 
      {
	cgPrintOp(theop); 
	VG_(printf)(" %u [31:0]));\n",arg2val);  
      }
      else
      {
	VG_(printf)(" ));\n"); 
      }
      break; 


      /* STP has a nasty quirk - it errors if we attempt to >> or << */
      /* by 0 positions. Need to explicitly check for this case, and */
      /* if we see it, output the identity instead.                  */
    case (Iop_Sar32):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal);

      if (arg2val != 0)
      {
	cgPrintOp(theop); 
	VG_(printf)(" %u [31:0])",arg2val);  
	VG_(printf)(" | "); 
	cgPrintTmpName(arg1name,tagVal);
	VG_(printf)("[31:31] << 31);\n"); 
      }
      else
      {
	VG_(printf)("));\n");
      }
      break; 

    case (Iop_CmpLT32S):
    case (Iop_CmpLT32U):
    case (Iop_CmpLE32S):
    case (Iop_CmpLE32U):

      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      cgPrintOp(theop); 
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal);
      VG_(printf)(", 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 

      break; 

    case (Iop_CmpEQ32):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("( ");
      cgPrintTmpName(arg1name,tagVal); 
      cgPrintOp(theop); 
      VG_(printf)(" 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 

    case (Iop_CmpEQ16):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("( "); 
      cgPrintTmpName(arg1name,tagVal);
      VG_(printf)("[15:0] "); 
      cgPrintOp(theop); 
      VG_(printf)(" "); 
      VG_(printf)("0hex"); 
      cgPrintHWord(arg2val,4);
      VG_(printf)("));\n"); 
      break; 

    case (Iop_CmpEQ8):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("( "); 
      cgPrintTmpName(arg1name,tagVal);
      VG_(printf)("[7:0] "); 
      cgPrintOp(theop); 
      VG_(printf)(" "); 
      VG_(printf)("0hex"); 
      cgPrintHWord(arg2val,2);
      VG_(printf)("));\n"); 
      break; 


    case (Iop_CmpNE32):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("(NOT ");
      cgPrintTmpName(arg1name,tagVal); 
      cgPrintOp(theop); 
      VG_(printf)(" 0hex");
      cgPrintHWord(arg2val,8); 
      VG_(printf)("));\n"); 
      break; 

    default:

      if (ca_output_comment)
      {

	VG_(printf)("XXX Warning : Unhandled op " ); 
	ppIROp(theop); 
	VG_(printf)(" in TmpConst binop. \n"); 
      }
      numUnhandledBinops++; 
      break; 
    }

  return; 
}

void cgEmitTmpBinopConstTmp (/*
			     IROp theop,
			     HWord tagVal,
			     IRType lhsty,
			     IRType arg2ty,
			     HWord lhsname, 
			     HWord arg1val, 
			     HWord arg2name*/
			     cgArgs_EmitTmpBinopConstTmp *extra_args
			     )
{

  HWord lhsSymP; 
  HWord arg2SymP; 
  HWord shiftVal = 1;  
  HWord uintMin = 0;
  HWord intMin = INT_MIN;
  HWord intMax = INT_MAX;
  HWord uintMax = UINT_MAX;

  // extracting extra_args's arguments
  IROp theop = extra_args->theop;
  HWord tagVal = extra_args->tagVal;
  IRType lhsty = extra_args->lhsty;
  IRType arg2ty = extra_args->arg2ty;
  HWord lhsname = extra_args->lhsname;
  HWord arg1val = extra_args->arg1val;
  HWord arg2name = extra_args->arg2name;

  lhsSymP = isTmpSymbolicP(tagVal, lhsname); 
  arg2SymP = isTmpSymbolicP(tagVal, arg2name); 

  if (! lhsSymP && ! arg2SymP )
  {
    /* If neither LHS nor arguments are symbolic, do not emit constraint */
    return; 
  }  

  /* Check that argument is symbolic. */ 
  if (! arg2SymP )
  {
    /* Can't use cgEmitTmpBinopConstConst b/c don't have arg2val ! */

    /*    cgEmitTmpBinopConstConst(
			     theop,
			     tagVal,
			     lhsty,
			     lhsname,
			     arg1val,
			     arg2val
			     ); 
    */ 

    /* Intentional fail assert */ 
    vassert(arg2SymP); 
  }

  vassert (lhsSymP && arg2SymP); 

  cgDeclareTmpAtRunIfUndeclared(tagVal, lhsname, lhsty); 
  cgDeclareTmpAtRunIfUndeclared(tagVal, arg2name, arg2ty); 


  switch(theop)
  {
    case (Iop_32HLto64):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[63:32] = 0hex"); 
    cgPrintHWord(arg1val,8); 
    VG_(printf)(" );\n");
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[31:0] = ");
    cgPrintTmpName(arg2name,tagVal);  
    VG_(printf)(" );\n");
    break; 



    case (Iop_Sub32):
    case (Iop_Sub16): 
    case (Iop_Sub8):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname, tagVal);
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(32, 0hex");
      cgPrintHWord(arg1val,8); 
      VG_(printf)(", ");
      cgPrintTmpName(arg2name, tagVal);
      VG_(printf)(")); \n"); 

      VG_(printf)("XXX QUERY( BVSGT(");
      cgPrintTmpName(lhsname, tagVal);
      VG_(printf)(", 0hex");
      cgPrintHWord(intMin, 8);
      VG_(printf)(")); %% TYPE IntUnderflowSigned \n");
      break; 

  case (Iop_Add16):
      intMax = 32767;             // Max for 16 bit signed integer
  case (Iop_Add8):
      if (intMax == INT_MAX)
      {
	intMax = 127;             // Max for 8 bit signed integer
      }
  case (Iop_Add32):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" = "); 
    cgPrintOp(theop); 
    VG_(printf)("(32, 0hex");
    cgPrintHWord(arg1val,8); 
    VG_(printf)(", ");
    cgPrintTmpName(arg2name, tagVal);
    VG_(printf)("));\n"); 
    
    // Emit signed integer overflow query
    VG_(printf)("XXX QUERY( BVSLE(");
    cgPrintTmpName(lhsname, tagVal);
    VG_(printf)(", 0hex");
    cgPrintHWord(intMax, 8);
    VG_(printf)(")); %% TYPE IntOverflowSigned \n");      
    
    // Emit unsigned integer overflow query
    /* Pattern:
	 
    Original statement:
    Z = X +Y

    Recompute at 64 bit precision:
    
    ASSERT( XW[31:0] = X);
    ASSERT( XW[63:32] = 0hex00000000);
    ASSERT( YW[31:0] = Y);
    ASSERT( YW[63:32] = 0hex00000000);
    ASSERT( W = BVPLUS(64, XW, YW));
    
    Query if 64 bit result is always less than 32(or 16 or 8) INT_MAX:
    QUERY(BVLE(W, 0hex00000000ffffffff));
    */

    cgDeclareTmpWideIfUndeclared(tagVal, lhsname);
    cgDeclareTmpWideIfUndeclared(tagVal, arg2name);
    // arg1 is a constant, do not need to declare
    VG_(printf)("ASSERT(");
    cgPrintTmpNameWide(arg2name, tagVal);
    VG_(printf)("[63:32] = 0hex00000000);\n");
    VG_(printf)("ASSERT(");
    cgPrintTmpNameWide(arg2name, tagVal);
    VG_(printf)("[31:0] = "); 
    cgPrintTmpName(arg2name, tagVal);
    VG_(printf)(");\n");
    
    VG_(printf)("ASSERT( ");
    cgPrintTmpNameWide(lhsname, tagVal);
    VG_(printf)(" = ");
    cgPrintOp(theop);
    VG_(printf)("(64,0hex");
    cgPrintHWord(arg1val, 16);
    VG_(printf)(", ");
    cgPrintTmpNameWide(arg2name, tagVal);
    VG_(printf)("));\n");
    
    // Now finally emit integer unsigned overflow query
    VG_(printf)("XXX QUERY( BVLE(");
    cgPrintTmpNameWide(lhsname, tagVal);
    VG_(printf)(", 0hex");
    cgPrintHWord(uintMax, 16);
    VG_(printf)(")); %% TYPE IntOverflowUnsigned \n");
    break; 
    
  case (Iop_MullU32):
  case (Iop_Mul32):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[31:0]",lhsname);
    VG_(printf)(" = "); 
    cgPrintOp(theop); 
    VG_(printf)("(32, 0hex");
    cgPrintHWord(arg1val,8); 
    VG_(printf)(", ");
    cgPrintTmpName(arg2name, tagVal);  
    VG_(printf)("));\n"); 
    break; 

  case (Iop_Xor32):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" = "); 
    cgPrintOp(theop); 
    VG_(printf)("(0hex");
    cgPrintHWord(arg1val,8); 
    VG_(printf)(", "); 
    cgPrintTmpName(arg2name,tagVal); 
    VG_(printf)("));\n"); 
    break; 
    
  case (Iop_And32):
  case (Iop_Or32):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" = "); 
    VG_(printf)("(0hex");
    cgPrintHWord(arg1val,8);
    VG_(printf)(" "); 
    cgPrintOp(theop); 
    VG_(printf)(" "); 
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)("));\n"); 
    break; 


  case (Iop_And16):
  case (Iop_Or16):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[15:0]",lhsname);
    VG_(printf)(" = "); 
    VG_(printf)("( 0hex");
    cgPrintHWord(arg1val,4);
    cgPrintOp(theop); 
    VG_(printf)(" ");
    cgPrintTmpName(arg2name,tagVal); 
    VG_(printf)("[15:0] "); 
    VG_(printf)("));\n"); 
    break;

  case (Iop_And8):
  case (Iop_Or8): 
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[7:0]",lhsname);
    VG_(printf)(" = "); 
    VG_(printf)("(0hex");
    cgPrintHWord(arg1val,2);
      cgPrintOp(theop); 
      VG_(printf)(" ");
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)("[7:0] "); 
      VG_(printf)("));\n"); 
      break;



    case (Iop_CmpLT32S):
    case (Iop_CmpLT32U):
    case (Iop_CmpLE32S):
    case (Iop_CmpLE32U):
      VG_(printf)("ASSERT( ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      cgPrintOp(theop); 
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,8); 
      VG_(printf)(", "); 
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)("));\n"); 
      break; 
  
    case (Iop_CmpEQ32):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("(0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" "); 
      cgPrintOp(theop); 
      VG_(printf)(" "); 
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)("));\n"); 
      break; 


    case (Iop_CmpEQ16):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("( "); 
      VG_(printf)("0hex"); 
      cgPrintHWord(arg1val,4);
      VG_(printf)(" "); 
      cgPrintOp(theop); 
      VG_(printf)(" "); 
      cgPrintTmpName(arg2name,tagVal);
      VG_(printf)("[15:0]"); 
      VG_(printf)("));\n"); 
      break; 

    case (Iop_CmpEQ8):
      VG_(printf)("ASSERT( "); 
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" <=> "); 
      VG_(printf)("( "); 
      VG_(printf)("0hex"); 
      cgPrintHWord(arg1val,2);
      VG_(printf)(" "); 
      cgPrintOp(theop); 
      VG_(printf)(" "); 
      cgPrintTmpName(arg2name,tagVal);
      VG_(printf)("[7:0]"); 
      VG_(printf)("));\n"); 
      break; 


    case (Iop_Shl32):

      VG_(printf)("ASSERT(IF ");
      VG_(printf)(" ( ");
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)( " = 0hex" );
      cgPrintHWord(0,8);
      VG_(printf)(")");
      VG_(printf)(" THEN ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      VG_(printf)("0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" ELSE TRUE "); 
      VG_(printf)(" ENDIF);\n");  
     
      for (shiftVal = 1; shiftVal < 32; shiftVal++)
	{
	  VG_(printf)("ASSERT(IF ");
	  VG_(printf)(" ( "); 
	  cgPrintTmpName(arg2name,tagVal); 
	  VG_(printf)( " = 0hex" );
	  cgPrintHWord(shiftVal,8);
	  VG_(printf)(")");
	  VG_(printf)(" THEN ");
	  cgPrintTmpName(lhsname,tagVal);
	  VG_(printf)(" = "); 
	  VG_(printf)("(0hex");
	  cgPrintHWord(arg1val,8);
	  VG_(printf)(" <<%u )[31:0]",shiftVal);
	  VG_(printf)(" ELSE TRUE "); 
	  VG_(printf)(" ENDIF);\n"); 
	}
      break; 

    case (Iop_Shl64):

      VG_(printf)("ASSERT(IF ");
      VG_(printf)(" ( ");
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)( " = 0hex" );
      cgPrintHWord(0,8);
      VG_(printf)(")");
      VG_(printf)(" THEN ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      VG_(printf)("0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" ELSE TRUE "); 
      VG_(printf)(" ENDIF);\n");  
     
      for (shiftVal = 1; shiftVal < 64; shiftVal++)
      {
	VG_(printf)("ASSERT(IF ");
	VG_(printf)(" ( "); 
	cgPrintTmpName(arg2name,tagVal); 
	VG_(printf)( " = 0hex" );
	cgPrintHWord(shiftVal,8);
	VG_(printf)(")");
	VG_(printf)(" THEN ");
	cgPrintTmpName(lhsname,tagVal);
	VG_(printf)(" = "); 
	VG_(printf)("(0hex");
	cgPrintHWord(arg1val,8);
	VG_(printf)(" <<%u )[31:0]",shiftVal);
	VG_(printf)(" ELSE TRUE "); 
	VG_(printf)(" ENDIF);\n"); 
      }
      break; 

    case (Iop_Shr32):
      VG_(printf)("ASSERT(IF ");
      VG_(printf)(" ( ");
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)( " = 0hex" );
      cgPrintHWord(0,8);
      VG_(printf)(")");
      VG_(printf)(" THEN ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      VG_(printf)("0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" ELSE TRUE "); 
      VG_(printf)(" ENDIF);\n");  
     
      for (shiftVal = 1; shiftVal < 32; shiftVal++)
	{
	  VG_(printf)("ASSERT(IF ");
	  VG_(printf)(" ( "); 
	  cgPrintTmpName(arg2name,tagVal); 
	  VG_(printf)( " = 0hex" );
	  cgPrintHWord(shiftVal,8);
	  VG_(printf)(")");
	  VG_(printf)(" THEN ");
	  cgPrintTmpName(lhsname,tagVal);
	  VG_(printf)(" = "); 
	  VG_(printf)("(0hex");
	  cgPrintHWord(arg1val,8);
	  VG_(printf)(" >>%u )[31:0]",shiftVal);
	  VG_(printf)(" ELSE TRUE "); 
	  VG_(printf)(" ENDIF);\n"); 
	}
      break; 


    case (Iop_Shr64):
      VG_(printf)("ASSERT(IF ");
      VG_(printf)(" ( ");
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)( " = 0hex" );
      cgPrintHWord(0,8);
      VG_(printf)(")");
      VG_(printf)(" THEN ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      VG_(printf)("0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" ELSE TRUE "); 
      VG_(printf)(" ENDIF);\n");  
     
      for (shiftVal = 1; shiftVal < 64; shiftVal++)
      {
	VG_(printf)("ASSERT(IF ");
	VG_(printf)(" ( "); 
	cgPrintTmpName(arg2name,tagVal); 
	VG_(printf)( " = 0hex" );
	cgPrintHWord(shiftVal,8);
	VG_(printf)(")");
	VG_(printf)(" THEN ");
	cgPrintTmpName(lhsname,tagVal);
	VG_(printf)(" = "); 
	VG_(printf)("(0hex");
	cgPrintHWord(arg1val,8);
	VG_(printf)(" >>%u )[63:0]",shiftVal);
	VG_(printf)(" ELSE TRUE "); 
	VG_(printf)(" ENDIF);\n"); 
      }
      break; 


    case (Iop_Sar32):
      VG_(printf)("ASSERT(IF ");
      VG_(printf)(" ( ");
      cgPrintTmpName(arg2name,tagVal); 
      VG_(printf)( " = 0hex" );
      cgPrintHWord(0,8);
      VG_(printf)(")");
      VG_(printf)(" THEN ");
      cgPrintTmpName(lhsname,tagVal);
      VG_(printf)(" = "); 
      VG_(printf)("0hex");
      cgPrintHWord(arg1val,8);
      VG_(printf)(" ELSE TRUE "); 
      VG_(printf)(" ENDIF);\n");  
     
      for (shiftVal = 1; shiftVal < 32; shiftVal++)
      {
	VG_(printf)("ASSERT(IF ");
	VG_(printf)(" ( "); 
	cgPrintTmpName(arg2name,tagVal); 
	VG_(printf)( " = 0hex" );
	cgPrintHWord(shiftVal,8);
	VG_(printf)(")");
	VG_(printf)(" THEN ");
	cgPrintTmpName(lhsname,tagVal);
	VG_(printf)(" = "); 
	VG_(printf)("(0hex");
	cgPrintHWord(arg1val,8);
	VG_(printf)(" >>%u )[31:0]",shiftVal);

	if (arg1val >> 31 == 1)
	{
	  VG_(printf)(" | 0hexf0000000 "); 
	}
	VG_(printf)(" ELSE TRUE "); 
	VG_(printf)(" ENDIF);\n"); 
      }
      break; 

    default:

      if (ca_output_comment)
      {
	  VG_(printf)("XXX Warning : Unhandled op ");
	  ppIROp(theop);
	  VG_(printf)(" in ConstTmp binop.\n"); 
      }
      numUnhandledBinops++; 
      break; 
    }


  return; 
}


void cgEmitTmpBinopTmpTmp (
			   /*
			   IROp theop, 
			   HWord tagVal,
			   IRType lhsty,
			   IRType arg1ty,
			   IRType arg2ty,
			   HWord lhsname, 
			   HWord arg1name, 
			   HWord arg2name,*/
			   cgArgs_EmitTmpBinopTmpTmp *extra_args,
			   HWord arg1val,
			   HWord arg2val
			   )
{

  HWord lhsSymP; 
  HWord arg1SymP; 
  HWord arg2SymP;
  HWord uintMin = 0; 
  HWord intMin = INT_MIN; 
  HWord intMax = INT_MAX;
  HWord uintMax = UINT_MAX; 
 
  // extracting the arguments from the struct
  IROp theop = extra_args->theop;
  HWord tagVal = extra_args->tagVal;
  IRType lhsty = extra_args->lhsty;
  IRType arg1ty = extra_args->arg1ty;
  IRType arg2ty = extra_args->arg2ty;
  HWord lhsname = extra_args->lhsname;
  HWord arg1name = extra_args->arg1name;
  HWord arg2name = extra_args->arg2name;

  lhsSymP = isTmpSymbolicP(tagVal, lhsname); 
  arg1SymP = isTmpSymbolicP(tagVal, arg1name); 
  arg2SymP = isTmpSymbolicP(tagVal, arg2name); 


  if (! lhsSymP && ! arg1SymP && ! arg2SymP )
  {
    /* If neither LHS nor arguments are symbolic, do not emit constraint */
    return; 
  }


  /* Check to see if args are untainted! */ 

  if (! arg1SymP && arg2SymP )
  {
    /*cgEmitTmpBinopConstTmp(
			   theop, 
			   tagVal,
			   lhsty,
			   arg2ty,
			   lhsname,
			   arg1val, 
			   arg2name
			   );*/
    cgArgs_EmitTmpBinopConstTmp *extra_args1 = VG_(malloc)("extraargs",sizeof(cgArgs_EmitTmpBinopConstTmp));
    extra_args1->theop = theop;
    extra_args1->tagVal = tagVal;
    extra_args1->lhsty = lhsty;
    extra_args1->arg2ty = arg2ty;
    extra_args1->lhsname = lhsname;
    extra_args1->arg1val = arg1val;
    extra_args1->arg2name = arg2name;

    cgEmitTmpBinopConstTmp (extra_args1);

    return; /* Done emitting constraints for this statement. */ 
  }

  if ( arg1SymP && ! arg2SymP )
  {
    cgArgs_EmitTmpBinopTmpConst *extra_args1 = VG_(malloc)("extraargs", sizeof(cgArgs_EmitTmpBinopTmpConst));
    extra_args1->theop = theop;
    extra_args1->tagVal = tagVal;
    extra_args1->lhsty = lhsty;
    extra_args1->arg1ty = arg1ty;
    extra_args1->lhsname = lhsname;
    extra_args1->arg1name = arg1name;
    extra_args1->arg2val = arg2val;


    cgEmitTmpBinopTmpConst(
			   extra_args1
			   ); 
    return; /* Done emitting constraints for this statement. */ 
  }

  

  /* Both args should be symbolic! */ 
  vassert(arg1SymP && arg2SymP); 

  cgDeclareTmpAtRunIfUndeclared(tagVal, lhsname, lhsty); 
  cgDeclareTmpAtRunIfUndeclared(tagVal, arg1name, arg1ty); 
  cgDeclareTmpAtRunIfUndeclared(tagVal, arg2name, arg2ty); 

  switch(theop)
  {

  case (Iop_32HLto64):

    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[63:32] = "); 
    cgPrintTmpName(arg1name,tagVal); 
    VG_(printf)(" );\n");

    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[31:0] = "); 
    cgPrintTmpName(arg2name,tagVal); 
    VG_(printf)(" );\n");
    break; 
    

  case (Iop_Sub32):
  case (Iop_Sub16):
  case (Iop_Sub8):
  VG_(printf)("ASSERT( ");
  cgPrintTmpName(lhsname, tagVal);
  VG_(printf)(" = "); 
  cgPrintOp(theop); 
  VG_(printf)("(32, ");
  cgPrintTmpName(arg1name, tagVal); 
  VG_(printf)(", ");
  cgPrintTmpName(arg2name, tagVal); 
  VG_(printf)("));\n"); 

  // Emit integer signed underflow query 
  VG_(printf)("XXX QUERY( BVSGT("); 
  cgPrintTmpName(lhsname, tagVal); 
  VG_(printf)(", 0hex");
  cgPrintHWord(intMin, 8); 
  VG_(printf)(")); %% TYPE IntUnderflowSigned \n");   
  break; 


  case (Iop_Add16):
    intMax = 32767;             // Max for 16 bit signed integer
  case (Iop_Add8): 
    if (intMax == INT_MAX)
    {
      intMax = 127;             // Max for 8 bit signed integer 
    }

 
  case (Iop_Add32):

  VG_(printf)("ASSERT( ");
  cgPrintTmpName(lhsname,tagVal);
  VG_(printf)(" = "); 
  cgPrintOp(theop); 
  VG_(printf)("(32, ");
  cgPrintTmpName(arg1name,tagVal); 
  VG_(printf)(", ",tagVal);
  cgPrintTmpName(arg2name,tagVal); 
  VG_(printf)("));\n"); 

  // Emit signed integer overflow query 
  VG_(printf)("XXX QUERY( BVSLE("); 
  cgPrintTmpName(lhsname, tagVal); 
  VG_(printf)(", 0hex");
  cgPrintHWord(intMax, 8); 
  VG_(printf)(")); %% TYPE IntOverflowSigned \n");  

      // Emit unsigned integer overflow query 

      /* Pattern:

         Original statement: 
         Z = X +Y

         Recompute at 64 bit precision: 

         ASSERT( XW[31:0] = X);
         ASSERT( XW[63:32] = 0hex00000000);  
         ASSERT( YW[31:0] = Y);  
         ASSERT( YW[63:32] = 0hex00000000); 
         ASSERT( W = BVPLUS(64, XW, YW));

         Query if 64 bit result is always less than 32(or 16 or 8) INT_MAX: 
         QUERY(BVLE(W, 0hex00000000ffffffff));  
      */      

      cgDeclareTmpWideIfUndeclared(tagVal, lhsname);
      cgDeclareTmpWideIfUndeclared(tagVal, arg1name); 
      cgDeclareTmpWideIfUndeclared(tagVal, arg2name); 

      VG_(printf)("ASSERT("); 
      cgPrintTmpNameWide(arg1name, tagVal); 
      VG_(printf)("[63:32] = 0hex00000000);\n"); 

      VG_(printf)("ASSERT("); 
      cgPrintTmpNameWide(arg2name, tagVal); 
      VG_(printf)("[63:32] = 0hex00000000);\n"); 

      VG_(printf)("ASSERT("); 
      cgPrintTmpNameWide(arg1name, tagVal); 
      VG_(printf)("[31:0] = "); 
      cgPrintTmpName(arg1name, tagVal); 
      VG_(printf)(" );\n");

      VG_(printf)("ASSERT("); 
      cgPrintTmpNameWide(arg2name, tagVal); 
      VG_(printf)("[31:0] = "); 
      cgPrintTmpName(arg2name, tagVal); 
      VG_(printf)(" );\n");


      VG_(printf)("ASSERT( "); 
      cgPrintTmpNameWide(lhsname, tagVal); 
      VG_(printf)(" = "); 
      cgPrintOp(theop); 
      VG_(printf)("(64,");
      cgPrintTmpNameWide(arg1name, tagVal); 
      VG_(printf)(", ");
      cgPrintTmpNameWide(arg2name, tagVal); 
      VG_(printf)("));\n"); 


      // Now finally emit integer unsigned overflow query
      VG_(printf)("XXX QUERY( BVLE("); 
      cgPrintTmpNameWide(lhsname, tagVal); 
      VG_(printf)(", 0hex");
      cgPrintHWord(uintMax, 16); 
      VG_(printf)(")); %% TYPE IntOverflowUnsigned \n");  
      break; 

  case (Iop_MullU32):
  case (Iop_Mul32):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[31:0]",lhsname);
    VG_(printf)(" = "); 
    cgPrintOp(theop); 
    VG_(printf)("(32, ");
    cgPrintTmpName(arg1name, tagVal); 
    VG_(printf)(" , ");
    cgPrintTmpName(arg2name, tagVal);  
    VG_(printf)("));\n"); 
    break; 


  case (Iop_Xor32):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" = "); 
    cgPrintOp(theop); 
    VG_(printf)("( ");
    cgPrintTmpName(arg1name,tagVal);
    VG_(printf)(", "); 
    cgPrintTmpName(arg2name,tagVal); 
    VG_(printf)("));\n"); 
    break; 


  case (Iop_And32):
  case (Iop_Or32):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" = "); 
    VG_(printf)(" ( "); 
    cgPrintTmpName(arg1name,tagVal);
    cgPrintOp(theop); 
    VG_(printf)(" "); 
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)("));\n"); 
    break; 

  case (Iop_And16):
  case (Iop_Or16):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[15:0]",lhsname);
    VG_(printf)(" = "); 
    VG_(printf)("( ");
    cgPrintTmpName(arg1name,tagVal);
    VG_(printf)("[15:0]",lhsname);
    cgPrintOp(theop); 
    VG_(printf)(" ");
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)("[15:0]",lhsname); 
    VG_(printf)(" ));\n"); 
    break;

  case (Iop_And8):
  case (Iop_Or8):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)("[7:0]",lhsname);
    VG_(printf)(" = "); 
    VG_(printf)("( ");
    cgPrintTmpName(arg1name,tagVal);
    VG_(printf)("[7:0] "); 
    cgPrintOp(theop); 
    VG_(printf)(" ");
    cgPrintTmpName(arg2name,tagVal); 
    VG_(printf)("[7:0] "); 
    VG_(printf)("));\n"); 
    break; 

  case (Iop_CmpLT32S):
  case (Iop_CmpLT32U):
  case (Iop_CmpLE32S):
  case (Iop_CmpLE32U):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" <=> "); 
    cgPrintOp(theop); 
    VG_(printf)("( "); 
    cgPrintTmpName(arg1name,tagVal);
    VG_(printf)(", ");
    cgPrintTmpName(arg2name,tagVal); 
    VG_(printf)("));\n"); 
    break; 

  case (Iop_CmpEQ32):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" <=> "); 
    VG_(printf)("( ");
    cgPrintTmpName(arg1name,tagVal);
    cgPrintOp(theop); 
    VG_(printf)(" ");   
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)("));\n"); 
    break; 

  case (Iop_CmpEQ16):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" <=> "); 
    VG_(printf)("( "); 
    cgPrintTmpName(arg1name,tagVal);
    VG_(printf)("[15:0] ",arg1name); 
    cgPrintOp(theop); 
    VG_(printf)(" "); 
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)("[15:0]"); 
    VG_(printf)("));\n"); 
    break; 

  case (Iop_CmpEQ8):
    VG_(printf)("ASSERT( ");
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" <=> "); 
    VG_(printf)("( "); 
    cgPrintTmpName(arg1name,tagVal);
    VG_(printf)("[7:0] "); 
    cgPrintOp(theop); 
    VG_(printf)(" "); 
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)("[7:0]"); 
    VG_(printf)("));\n"); 
    break; 

  case (Iop_CmpNE32):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" <=> "); 
    VG_(printf)("(NOT ( ");
    cgPrintTmpName(arg1name,tagVal);
    cgPrintOp(theop); 
    VG_(printf)(" "); 
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)(")));\n"); 
    break; 

  case (Iop_CmpNE8):
    VG_(printf)("ASSERT( "); 
    cgPrintTmpName(lhsname,tagVal);
    VG_(printf)(" <=> "); 
    VG_(printf)("(NOT ( "); 
    cgPrintTmpName(arg1name,tagVal);
    VG_(printf)("[7:0] "); 
    cgPrintOp(theop); 
    VG_(printf)(" ");
    cgPrintTmpName(arg2name,tagVal);
    VG_(printf)("[7:0]"); 
    VG_(printf)(")));\n"); 
    break; 

  default:
    if (ca_output_comment)
    {
      VG_(printf)("XXX Warning : Unhandled op ");
      ppIROp(theop); 
      VG_(printf)(" in TmpTmp binop.\n"); 
    }
    numUnhandledBinops++; 
    break; 
  }
  return; 
}
