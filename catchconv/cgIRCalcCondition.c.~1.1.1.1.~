/*--------------------------------------------------------------------*/
/*--- CatchConversions                         cgIRCalcCondition.c ---*/
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

   Code for translating x86_calc_condition_g to STP constraints.
   Based on code contributed by Gautam Altekar 

*/

#include "libvex_basictypes.h"
#include "libvex_ir.h"
#include "libvex.h"
#include "vex-gdefs.h"

#include "ca_vex_util.h"


#include "pub_tool_basics.h"
#include "pub_tool_libcassert.h"
#include "pub_tool_tooliface.h"

#include "pub_tool_machine.h" 

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
#include "catchconv.h" 
#include "macros.h"

void CgenOut(const char *fmt, ...);

void CgenOut(const char *fmt, ...)
{
        va_list args;

        va_start(args, fmt);
        VG_(printf)(fmt, args);
        va_end(args);
}


static const int wantsComments = 1;

struct CalcStruct {
   HWord dep1Tmp, dep2Tmp, ndepTmp;
   HWord opVal, dep1Val, dep2Val, ndepVal;
};

/* Returns a bitmask of eflags fields used for a given operation */
static int
cgMaskFromCond(HWord condVal) 
{
   switch (condVal) {
   case X86CondNO:
   case X86CondO: /* OF == 1 */
      return X86G_CC_MASK_O;
      break;
   case X86CondNZ:
   case X86CondZ: /* ZF == 1 */
      return X86G_CC_MASK_Z;
      break;
   case X86CondNB:
   case X86CondB: /* CF == 1 */
      return X86G_CC_MASK_C;
      break;
   case X86CondNBE:
   case X86CondBE: /* (CF or ZF) == 1 */
      return (X86G_CC_MASK_C | X86G_CC_MASK_Z);
      break;
   case X86CondNS:
   case X86CondS: /* SF == 1 */
      return X86G_CC_MASK_S;
      break;
   case X86CondNP:
   case X86CondP: /* PF == 1 */
      return X86G_CC_MASK_P;
      break;
   case X86CondNL:
   case X86CondL: /* (SF xor OF) == 1 */
      return (X86G_CC_MASK_S | X86G_CC_MASK_O);
      break;
   case X86CondNLE:
   case X86CondLE: /* ((SF xor OF) or ZF)  == 1 */
      return (X86G_CC_MASK_S | X86G_CC_MASK_O | X86G_CC_MASK_Z);
      break;
   default:
     //      ASSERT_UNIMPLEMENTED(0);
     vpanic("Unimplemented condition code!\n"); 
      break;
   }

   //   NOTREACHED();
   vpanic("Should not be reached. \n"); 
}

static void cgDoParityFlag(void);

static void
cgDoParityFlag(void)
{
   /* XXX: PF -- This flag is unlikely to be used in modern software
    * (it's Intel legacy from the 8080 and used mostly in old drivers for
    * hardware that can't do hardware parity checking (e.g., old modems)), 
    * so it probably isn't worth implementing. If we wanted to implement it, 
    * we could use a parity table similar to that used in LibVEX. */
  //   ASSERT_UNIMPLEMENTED(0);
   vpanic("cgDoParityFlag\n"); 
}

/* Number of right shifts required to move most-significant-bit 
 * of given type to the least-significant-bit. */
#define MSB_POS(ty) IRTYPE2BITS(ty) - 1

#define WANTS(f) (mask & X86G_CC_MASK_##f)

static void
cgCalculateCondition_SUB(HWord depIrTy, struct CalcStruct *cp, unsigned int mask)
{
   CG_NEW_VAR(Ity_I32, CG_LSCOPE("argL"));
   if (isTmpSymbolicP(cgBBExecCounter, cp->dep1Tmp)) {
      CG_ASSIGN(CG_LSCOPE("argL"), CG_TMP(cp->dep1Tmp));
   } else {
      CG_ASSIGN(CG_LSCOPE("argL"), CG_CONST(Ity_I32, cp->dep1Val));
   }

   CG_NEW_VAR(Ity_I32, CG_LSCOPE("argR"));
   if (isTmpSymbolicP(cgBBExecCounter,cp->dep2Tmp)) {
      CG_ASSIGN(CG_LSCOPE("argR"), CG_TMP(cp->dep2Tmp));
   } else {
      CG_ASSIGN(CG_LSCOPE("argR"), CG_CONST(Ity_I32, cp->dep2Val));
   }

   CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("res"),
         CG_SUB(Ity_I32, CG_LSCOPE("argL"), CG_LSCOPE("argR")));

   if (WANTS(C)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("cf"),
            CG_ITE(
               CG_LT(CG_CAST(depIrTy, CG_LSCOPE("res")), 
                  CG_CAST(depIrTy, CG_LSCOPE("argL"))), 
               CG_CONST(Ity_I32, 1), CG_CONST(Ity_I32, 0)
               ));
   }

   if (WANTS(P)) {
      cgDoParityFlag();
   }

   if (WANTS(A)) {
      /* XXX: is this flag ever used by the IR? Doesn't appear to be. */
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("af"),
            CG_AND(
               CG_SHR(Ity_I32,
                  CG_XOR(CG_XOR(CG_LSCOPE("res"), 
                        CG_LSCOPE("argL")), CG_LSCOPE("argR")), 
                  0x10-1),
               CG_CONST(Ity_I32, 0x1)));
   }

   if (WANTS(Z)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("zf"),
            CG_ITE(
               CG_EQUAL(CG_LSCOPE("res"), CG_CONST(Ity_I32, 0)),
               CG_CONST(Ity_I32, 1),
               CG_CONST(Ity_I32, 0))
            );
   }

   if (WANTS(S)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("sf"),
            CG_AND(CG_SHR(Ity_I32, CG_LSCOPE("res"), MSB_POS(depIrTy)),
               CG_CONST(Ity_I32, 1)));
   }

   if (WANTS(O)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("of"),
            CG_AND(CG_SHR(Ity_I32,
                  CG_AND(CG_XOR(CG_LSCOPE("argL"), CG_LSCOPE("argR")),
                     CG_XOR(CG_LSCOPE("argL"), CG_LSCOPE("res"))),
                  MSB_POS(depIrTy)), CG_CONST(Ity_I32, 1)));
   }
}

static void
cgCalculateCondition_LOGIC(HWord depIrTy, struct CalcStruct *cp, unsigned int mask)
{
   CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("cf"), CG_CONST(Ity_I32, 0));

   if (WANTS(P)) {
      cgDoParityFlag();
   }

   if (WANTS(A)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("af"), CG_CONST(Ity_I32, 0));
   }

   if (WANTS(Z)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("zf"),
            CG_ITE(
               CG_EQUAL(CG_TMP(cp->dep1Tmp), CG_CONST(Ity_I32, 0)),
               CG_CONST(Ity_I32, 1),
               CG_CONST(Ity_I32, 0))
            );
   }

   if (WANTS(S)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("sf"),
            CG_AND(CG_SHR(Ity_I32, CG_TMP(cp->dep1Tmp), MSB_POS(depIrTy)),
               CG_CONST(Ity_I32, 1)));
   }

   if (WANTS(O)) {
      CG_NEW_VAR_INIT(Ity_I32, CG_LSCOPE("of"), CG_CONST(Ity_I32, 0));
   }
}

/* @mask is a bitmask of eflags fields for which we should generate
 * constraints (most operations use only a subset of the fields). */
static void
cgEmitCalculateEflagsWork(struct CalcStruct *cp, unsigned int mask)
{
#define WORK(kind, ty) \
      cgCalculateCondition_##kind(ty, cp, mask)
   switch (cp->opVal) {
   case X86G_CC_OP_SUBB:
      WORK(SUB, Ity_I8);
      break;
   case X86G_CC_OP_SUBW:
      WORK(SUB, Ity_I16);
      break;
   case X86G_CC_OP_SUBL:
      WORK(SUB, Ity_I32);
      break;
   case X86G_CC_OP_LOGICB:
      WORK(LOGIC, Ity_I8);
      break;
   case X86G_CC_OP_LOGICW:
      WORK(LOGIC, Ity_I16);
      break;
   case X86G_CC_OP_LOGICL:
      WORK(LOGIC, Ity_I32);
      break;
   default:
      DEBUG_MSG(5, "Unhandled opVal=%d\n", cp->opVal);
      ASSERT_UNIMPLEMENTED(0);
      break;
   }
}

static void
cgEmitTmpCCallCalcCondition(
      HWord lhsTmp, HWord dep1Tmp, HWord dep2Tmp, HWord ndepTmp,
      HWord condVal, HWord opVal, HWord dep1Val, HWord dep2Val, HWord ndepVal,
      HWord tagVal
      )
{
   HWord inv;
   struct CalcStruct calc;

   if (!isTmpSymbolicP(cgBBExecCounter, lhsTmp)){
      return;
   }

   /* Each call to x86g_calculate_condition will require a new set of
    * constraint variables. For example, the AF flag for this call should
    * not be confused with the AF flag for a previous call. For this reason,
    * we start a new scope, which is simply a number postfixed to each
    * variable name to bind it to a particular invocation of this
    * function. */
   CG_NEW_LOCAL_SCOPE();


   calc.opVal = opVal;
   calc.dep1Val = dep1Val;
   calc.dep2Val = dep2Val;
   calc.ndepVal = ndepVal;
   calc.dep1Tmp = dep1Tmp;
   calc.dep2Tmp = dep2Tmp;
   calc.ndepTmp = ndepTmp;

   cgEmitCalculateEflagsWork(&calc, cgMaskFromCond(condVal));

   CG_NEW_TMP(tagVal, Ity_I32, lhsTmp);
#define CG_SET_GUARD(pred) \
   CG_ASSIGN(CG_TMP(lhsTmp), pred)

#define CG_SET_RESULT(flagStr) \
   CG_SET_GUARD(CG_XOR(CG_CONST(Ity_I32, inv), CG_LSCOPE(flagStr)))

   inv = condVal & 1;
   switch (condVal) {
   case X86CondNO:
   case X86CondO: /* OF == 1 */
      CG_SET_RESULT("of");
      break;
   case X86CondNZ:
   case X86CondZ: /* ZF == 1 */
      CG_SET_RESULT("zf");
      break;
   case X86CondNB:
   case X86CondB: /* CF == 1 */
      CG_SET_RESULT("cf");
      break;
   case X86CondNBE:
   case X86CondBE: /* (CF or ZF) == 1 */
      CG_SET_GUARD(CG_XOR(CG_CONST(Ity_I32, inv), CG_OR(CG_LSCOPE("cf"), CG_LSCOPE("zf"))));
      break;
   case X86CondNS:
   case X86CondS: /* SF == 1 */
      CG_SET_RESULT("sf");
      break;
   case X86CondNP:
   case X86CondP: /* PF == 1 */
      CG_SET_RESULT("pf");
      break;
   case X86CondNL:
   case X86CondL: /* (SF xor OF) == 1 */
      CG_SET_GUARD(CG_XOR(CG_CONST(Ity_I32, inv), CG_XOR(CG_LSCOPE("sf"), CG_LSCOPE("of"))));
      break;
   case X86CondNLE:
   case X86CondLE: /* ((SF xor OF) or ZF)  == 1 */
      CG_SET_GUARD(CG_XOR(CG_CONST(Ity_I32, inv), 
               CG_OR(CG_XOR(CG_LSCOPE("sf"), CG_LSCOPE("of")),
                  CG_LSCOPE("zf"))));
      break;
   default:
      ASSERT_UNIMPLEMENTED(0);
      break;
   }
}

static void
cgEmitTmpCCallCalcEflagsC(
      HWord lhsTmp, HWord dep1Tmp, HWord dep2Tmp, HWord ndepTmp,
      HWord opVal, HWord dep1Val, HWord dep2Val, HWord ndepVal,
      HWord tagVal
      )
{
   struct CalcStruct calc;

   if (!isTmpSymbolicP(cgBBExecCounter, lhsTmp)){
      return;
   }

   calc.opVal = opVal;
   calc.dep1Val = dep1Val;
   calc.dep2Val = dep2Val;
   calc.ndepVal = ndepVal;
   calc.dep1Tmp = dep1Tmp;
   calc.dep2Tmp = dep2Tmp;
   calc.ndepTmp = ndepTmp;

   cgEmitCalculateEflagsWork(&calc, X86G_CC_MASK_C);

   CG_NEW_TMP_INIT(tagVal, Ity_I32, lhsTmp, 
         CG_CAST(Ity_I32, CG_SHL(Ity_I32, CG_LSCOPE("cf"), X86G_CC_MASK_C)));
}

void 
cgAddTmpCCall(IRBB * bb, IRStmt * s)
{
   HWord lhsTmp;
   IRExpr * call; 
   IRDirty * d; 
   IRCallee * callee;
   IRExpr ** cargs;


   lhsTmp = s->Ist.Tmp.tmp;
   call = s->Ist.Tmp.data; 
   ASSERT(call->tag == Iex_CCall); 
   callee = call->Iex.CCall.cee;
   cargs = call->Iex.CCall.args;  

   if (VG_(strncmp)(callee->name, "x86g_calculate_condition", 24) == 0) {
      ASSERT(cargs[0]); /* cond */
      ASSERT(cargs[1]); /* cc_op */
      ASSERT(cargs[2]); /* cc_dep1 */
      ASSERT(cargs[3]); /* cc_dep2 */
      ASSERT(cargs[4]); /* cc_ndep */
      ASSERT(cargs[0]->tag != Iex_Tmp);
      //      ASSERT(cargs[1]->tag == Iex_Tmp); op is not a Iex_Tmp!
      //     ASSERT(cargs[2]->tag == Iex_Tmp);
      //     ASSERT(cargs[3]->tag == Iex_Tmp);
      //      ASSERT(cargs[4]->tag == Iex_Tmp);

      d = unsafeIRDirty_0_N(0,
            "cgEmitTmpCCallCalcCondition",
            &cgEmitTmpCCallCalcCondition,
            mkIRExprVec_10(
               mkIRExpr_HWord(lhsTmp),
               mkIRExpr_HWord(cargs[2]->Iex.Tmp.tmp),
               mkIRExpr_HWord(cargs[3]->Iex.Tmp.tmp),
               mkIRExpr_HWord(cargs[4]->Iex.Tmp.tmp),
               cargs[0],
               cargs[1],
               cargs[2],
               cargs[3],
               cargs[4],
	       mkIRExpr_HWord(cgBBCounter)
               )
            );   

      setHelperAnns(d); 
      addStmtToIRBB(bb, IRStmt_Dirty(d)); 
   } else if (VG_(strncmp)(callee->name, "x86g_calculate_eflags_c", 23) == 0) {
      ASSERT(cargs[0]); /* cc_op */
      ASSERT(cargs[1]); /* cc_dep1 */
      ASSERT(cargs[2]); /* cc_dep2 */
      ASSERT(cargs[3]); /* cc_ndep */
      //      ASSERT(cargs[0]->tag == Iex_Tmp); op is not an Iex_Tmp! 
      //  ASSERT(cargs[1]->tag == Iex_Tmp);
      // ASSERT(cargs[2]->tag == Iex_Tmp);
      //      ASSERT(cargs[3]->tag == Iex_Tmp);

      d = unsafeIRDirty_0_N(0,
            "cgEmitTmpCCallCalcEflagsC",
            &cgEmitTmpCCallCalcEflagsC,
            mkIRExprVec_9(
               mkIRExpr_HWord(lhsTmp),
               mkIRExpr_HWord(cargs[1]->Iex.Tmp.tmp),
               mkIRExpr_HWord(cargs[2]->Iex.Tmp.tmp),
               mkIRExpr_HWord(cargs[3]->Iex.Tmp.tmp),
               cargs[0],
               cargs[1],
               cargs[2],
               cargs[3],
	       mkIRExpr_HWord(cgBBCounter)
               )
            );   

      setHelperAnns(d); 
      addStmtToIRBB(bb, IRStmt_Dirty(d)); 
   } else {
     //      ASSERT_UNIMPLEMENTED(0);
     // do nothing 
   }

   return;
}
