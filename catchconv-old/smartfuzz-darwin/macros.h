/*--------------------------------------------------------------------*/
/*--- CatchConversions                         macros.h            ---*/
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

/* Constraint generation macros -- Eliminates some of the tedium of
 * generating STP formulas in text form. */

#pragma once

#define CG_TRUE \
   CgenOut(" TRUE ");

#define CG_FALSE \
   CgenOut(" FALSE ");

#define CG_BINOP(opstr, a, b) \
   CgenOut(opstr); CgenOut("("); a; CgenOut(", "); b; CgenOut(")");

#define CG_BINOP_TYPED(opstr, irType, a, b) \
   CgenOut(opstr); CgenOut("(%d, ", IRTYPE2BITS(irType)); a; CgenOut(", "); b; CgenOut(")");

#define CG_BINOP_INFIX(opstr, a, b) \
   CgenOut("("); a; CgenOut(" " opstr " "); b; CgenOut(")");

#define CG_UNOP(opstr, a) \
   CgenOut(opstr " "); a;

#define CG_EXTRACT(hiVal, loVal, var) \
   var; CgenOut("[%d:%d]", hiVal, loVal);

#define CG_LO(irType, v) \
   CgenOut("("); v; CgenOut(")[%d:0]", IRTYPE2BITS(irType)-1);

/* XXX: assume v is a 64-bit var -- we need to keep track of variable
 * type, if we want to eliminate this restriction. */
#define CG_HI(irType, v) \
   CgenOut("("); v; CgenOut(")[63:%d]", 63-(IRTYPE2BITS(irType)-1));

/* XXX: Need to remember variable types so that we know whether
 * to cast up or down. For now, assume down. */
#define CG_CAST(irType, v) \
   CgenOut("("); v; CgenOut(")[%d:0]", IRTYPE2BITS(irType)-1);

#define CG_XOR(a, b) \
   CG_BINOP("BVXOR", a, b)

#define CG_EQUIV(a, b) \
   a; CgenOut(" <=> "); b;

#define CG_LT(a, b) \
   CG_BINOP("BVLT", a, b)

#define CG_SLT(a, b) \
   CG_BINOP("SBVLT", a, b)

#define CG_LE(a, b) \
   CG_BINOP("BVLE", a, b)

#define CG_SLE(a, b) \
   CG_BINOP("SBVLE", a, b)

#define CG_AND(a, b) \
   CG_BINOP_INFIX("&", a, b)

#define CG_OR(a, b) \
   CG_BINOP_INFIX("|", a, b)

#define CG_ADD(irType, a, b) \
   CG_BINOP_TYPED("BVPLUS", irType, a, b)

#define CG_SUB(irType, a, b) \
   CG_BINOP_TYPED("BVSUB", irType, a, b)

#define CG_MULT(irType, a, b) \
   CG_BINOP_TYPED("BVMULT", irType, a, b)

#define CG_UMOD(irType, a, b) \
   CG_BINOP_TYPED("BVMOD", irType, a, b)

#define CG_UDIV(irType, a, b) \
   CG_BINOP_TYPED("BVDIV", irType, a, b)

#define CG_NOT(a) \
   CG_UNOP("NOT", a);

#define CG_EQUAL(a, b) \
   a; CgenOut(" = "); b;

#define CG_ITE(a, b, c) \
   CgenOut("(IF "); a; CgenOut(" THEN "); b; CgenOut(" ELSE "); c; CgenOut(" ENDIF)");

#if 0
   /* XXX: STP quirk -- doesn't like shift by 0 */
   ASSERT_UNIMPLEMENTED(b > 0);
   ASSERT_UNIMPLEMENTED(b > 0);
#endif

#define CG_SHIFT(opStr, a, b) \
   if (b > 0) { \
      CG_BINOP_INFIX(opStr, a, CG_DEC(b)); \
   } else if (b == 0) { \
      /* STP doesn't like shifts by 0. */ \
      a; \
   } else { \
      ASSERT(0); \
   }

#define CG_SHL(irType, a, b) \
   CG_CAST(irType, CG_SHIFT("<<", a, b));

   /* Right-shifting doesn't alter size. */
#define CG_SHR(irType /* for uniformity */, a, b) \
   CG_SHIFT(">>", a, b);

#define CG_ASSERT(f) \
   CgenOut("ASSERT("); f; CgenOut(");\n");

#define CG_ASSIGN(l, r) \
   CG_ASSERT({l; CgenOut(" = "); r;});




/* Declaration helpers. */
#define CG_NEW_LOCAL_SCOPE() \
   localScope++; 

#define ASSERT_UNIMPLEMENTED(msg) \
    vpanic(msg); 

#define DEBUG_MSG(level, fmt, vals) \
   VG_(printf)("XXX level fmt", vals);

#define ASSERT(cond) \
   vassert(cond); 



#define CG_NEW_VAR(irType, l) \
   l; CgenOut(" : BITVECTOR(%d);\n", IRTYPE2BITS(irType));

#define CG_NEW_VAR_INIT(irType, l, r) \
   CG_NEW_VAR(irType, l); \
   CG_ASSIGN(l, r);


#define CG_NEW_TMP(tagVal, irType, tmpName) \
   cgDeclareTmpAtRunIfUndeclared(tagVal, tmpName, irType);

#define CG_NEW_TMP_INIT(tagVal, irType, tmpName, r) \
   CG_NEW_TMP(tagVal, irType, tmpName); \
   CG_ASSIGN(CG_TMP(tmpName), r); 

/* Variables. */

/* Prints value in decimal. */ 
#define CG_DEC(v) \
   CgenOut("%llu", (ULong)v);

/* Prints in hex. */
#define CG_CONST(irType, v) \
   CgenOut("0hex%.16llx[%d:0]", (ULong)v, IRTYPE2BITS(irType)-1);

#define CG_TM_TMP(tmVar) \
   cgPrintTmpVarTy(tmVar); 

#define CG_TMP(t) \
   cgPrintTmpName(t, cgBBExecCounter);


#define CG_ARG(ty, argp) \
   printArg(ty, argp);

/* Reference a variable defined within the most recent local scope. */
 #define CG_LSCOPE(s) \
   CgenOut(s); CgenOut("%d", localScope); 

/* Misc. */
#define CG_COMMENT(s, ...) \
   if (wantsComments) { \
      CgenOut("%% "); \
      CgenOut(s, ##__VA_ARGS__); \
   }

static inline int
IRTYPE2BITS(IRType ty)
{
   switch (ty) {
   case Ity_I1:
      return 1;
   default:
      return sizeofIRType(ty)*8;
      break;
   }

   //   NOTREACHED();
}
