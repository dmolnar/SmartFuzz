
#pragma once 
/*--------------------------------------------------------------------*/
/*--- CatchConversions                           ogIR.h            ---*/
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


/* --- Function prototype --- */ 

void ogEmitStackConstraints(Addr stackAddr, SizeT len);

/* --- Types --- */ 

/* --------- Condition codes, Intel encoding. --------- */
/* --------- From VEX/priv/host-x86/hdefs.h   --------- */

typedef
   enum {
      Xcc_O      = 0,  /* overflow           */
      Xcc_NO     = 1,  /* no overflow        */

      Xcc_B      = 2,  /* below              */
      Xcc_NB     = 3,  /* not below          */

      Xcc_Z      = 4,  /* zero               */
      Xcc_NZ     = 5,  /* not zero           */

      Xcc_BE     = 6,  /* below or equal     */
      Xcc_NBE    = 7,  /* not below or equal */

      Xcc_S      = 8,  /* negative           */
      Xcc_NS     = 9,  /* not negative       */

      Xcc_P      = 10, /* parity even        */
      Xcc_NP     = 11, /* not parity even    */

      Xcc_L      = 12, /* jump less          */
      Xcc_NL     = 13, /* not less           */

      Xcc_LE     = 14, /* less or equal      */
      Xcc_NLE    = 15, /* not less or equal  */

      Xcc_ALWAYS = 16  /* the usual hack     */
   }
   ogX86CondCode;


typedef enum {
  MemLoc,    /* Location is a memory address */ 
  RegLoc,    /* Location is a register name */ 
  TmpLoc,    /* Location is a temporary */
  JCLoc,     /* Location is a jump condition variable */ 
  ErrorLoc   /* Error condition */ 
} LocType;

typedef enum {
  HopelessHint,     /* Op neither implies signed nor unsigned */
  SignedHint,       /* Op implies arguments are signed */ 
  UnsignedHint,     /* Op implies arguments are unsigned */ 
  ErrorHint         /* Error condition */  
} 
IntTyStateHint;

typedef enum {
  noRegs,    /* cc_op implies nothing about either dep1 or dep2 */
  oneReg,    /* cc_op uses dep1 but not dep2 */
  twoRegs
} ccOpHint; 

typedef enum {
  Top,        /* Unknown type */ 
  SignedTy,  /* Signed type */
  UnsignedTy, /* Unsigned type */
  Bot,       /* Contradictory type */ 
  BogusTy,     /* Error condition */
} IntType; 


/* Hash node type for VarOf() map. First two fields match core's VgHashNode */
typedef
struct _OgVarOfHashNode {
  struct _OgVarOfHashNode * next; 
  HWord  loc; 
  HWord  varname; 
} 
OgVarOfHashNode;

/* Hash node type for TypeOf() map. First two fields match core's VgHashNode */
typedef
struct _OgTypeOfHashNode {
  struct _OgTypeOfHashNode * next; 
  HWord varname;
  IntType type;
} 
OgTypeOfHashNode; 

/* Hash node type for keeping track of structs for 64-bit implementation */
typedef 
struct _OgStructHashNode {
  struct _OgStructHashNode * next;
  HWord basic_block; // address of the basic block - KEY
  HWord struct_info; // pointer to the struct - VALUE
}
OgStructHashNode;

/* --- Globals --- */ 

VgHashTable ogVarOf; /* Initialized in ca_main - pre_clo_init */
VgHashTable ogTypeOf; /* Also initialized in ca_main - pre_clo_init */
VgHashTable argStructHashTable; /* Also initialized in ca_main - pre_clo_init */

// static HWord varCounter = 0;

/* --- Prototypes --- */

void setHelperAnns ( IRDirty* di );
IntTyStateHint opToHint(IROp op);
IntTyStateHint og86codeToHint(ogX86CondCode condcode);
ccOpHint ogccOpToHint(HWord op);
int setVarOf(HWord loc, HWord varname);
HWord getVarOf(HWord loc);
int setTypeOf(HWord varname, IntType type);
IntType getTypeOf(HWord varname);
IntType setTypeOfToMeet(HWord varname, IntType rhstype);

/* new ones to take take care of struct's */
int getStructOf (HWord basic_block, HWord struct_info);
int removeStructOf (HWord basic_block);
void removeStructOfHelper (HWord basic_block, OgStructHashNode *node);

ULong ogTest(IRTemp foo);
void ogEmitStackConstraints(Addr stackAddr, SizeT len);
ULong ogEmitGuardConstraints (  ULong cc_op,
				ULong cc_dep1,
				ULong cc_dep2,
				ULong cc_ndep);
void ogEmitRegConstraint(HWord reg, IntTyStateHint hint);
void ogEmitTmpConstraint(HWord tmp, IntTyStateHint hint, ULong TagVal);
void ogAddOpRhsTypeConstraints(IRSB * bb, IRExpr * arg, IntTyStateHint hint);
void ogTmp2TmpAliasHelper(HWord lhs, HWord rhs, HWord eip);
void ogAddTmp2TmpAliasHelper(IRSB * bb, IRTemp lhs, IRTemp rhs);
void ogTmp2GetAliasHelper(HWord templhs, HWord offset, HWord eip);
void ogAddTmp2GetAliasHelper(IRSB * bb, IRTemp lhs, IRExpr * rhs);
void ogTmp2LoadAliasHelper(HWord lhs, HWord addr, HWord eip );
void ogAddTmp2LoadAliasHelper(IRSB * bb, IRTemp lhs, IRExpr * addr);
void ogEmitCalcCondConstraints(HWord cond, HWord cc_op, HWord eip);
void ogAddCCallConstraints(IRSB * bb, IRTemp rst, IRExpr * call);
void ogEmitNewTmpTyvar(HWord tmpname, HWord TagValue);
void ogEmitBinopTmpTmpTypeCons(HWord lhs, HWord opcode, 
			       HWord tmp1, HWord tmp2, 
			       HWord TagVal);

void ogEmitBinopTmpConstTypeCons(HWord lhs, HWord opcode, 
				 HWord tmp, HWord TagVal);
void ogAddBinopAliasAndTypeConstraints(IRSB * bb, IRStmt * st);
void ogAddTmpConstraints(IRSB * bb, IRStmt * st, IRExpr * rhs);
void ogEmitPutConstConstraints(HWord offset, HWord eip);
void ogEmitPutTmpConstraints(HWord offset, HWord tmpname, HWord eip);
void ogAddPutConstraints(IRSB * bb, Int offset, IRExpr * data);
void ogEmitStoreTmp2TmpConstraints(HWord addr, HWord tmpname, HWord eip);
void ogAddStoreConstraints(IRSB * bb, IRExpr * addr, IRExpr * data);
void ogIRStmt (IRSB * bb,  IRStmt* s , ULong bb_counter);
void  ogEmitStoreTmp2ConstConstraints (HWord addr);
HWord locToHashKey(HWord loc1, HWord loc2, LocType ltype);
HWord locToHashKeyJC(HWord loc1, HWord loc2, HWord loc3, LocType ltype);
IntType ogBinopTypeStateFunc(HWord opcode, IntType arg1, IntType arg2);
int clearVarOf(HWord loc);
