/*--------------------------------------------------------------------*/
/*--- CatchConversions                           cgIR.h            ---*/
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

#include "trackmemIR.h"

#pragma once 

/* --- Typedefs --- */ 

typedef 
enum {
  Unknown,
  Taken,
  NotTaken
}
cgPathCondStatus;

typedef
enum {
  ConstConst,
  ConstTmp,
  TmpConst,
  TmpTmp
}
cgITEStackType;

/* -------- ADDING STRUCTS FOR 64-bit ------- */

typedef
struct __cgArgs_EmitUnopTmp {
  IROp theop;
  HWord lhsname;
  HWord argname;
  HWord tagVal;
  IRType lhsty;
  IRType rhsty;
}
cgArgs_EmitUnopTmp;

typedef
struct __cgArgs_EmitTmpBinopConstConst {
  IROp theop;
  HWord tagVal;
  IRType lhsty;
  HWord lhsname;
}
cgArgs_EmitTmpBinopConstConst;

typedef
struct __cgArgs_EmitTmpBinopTmpConst {
  IROp theop;
  HWord tagVal;
  IRType lhsty;
  IRType arg1ty;
  HWord lhsname;
  HWord arg1name;
  HWord arg2val;
}
cgArgs_EmitTmpBinopTmpConst;

typedef
struct __cgArgs_EmitTmpBinopConstTmp {
  IROp theop;
  HWord tagVal;
  IRType lhsty;
  IRType arg2ty;
  HWord lhsname;
  HWord arg1val;
  HWord arg2name;
}
cgArgs_EmitTmpBinopConstTmp;

typedef
struct __cgArgs_EmitTmpBinopTmpTmp {
  IROp theop;
  HWord tagVal;
  IRType lhsty;
  IRType arg1ty;
  IRType arg2ty;
  HWord lhsname;
  HWord arg1name;
  HWord arg2name;
}
cgArgs_EmitTmpBinopTmpTmp;

typedef
struct __cgArgs_EmitTmpMux0X {
  HWord lhstmpname;
  HWord condtmpname;
  HWord truetmpname;
  HWord falsetmpname;
  HWord tagVal;
  HWord assignTy;
}
cgArgs_EmitTmpMux0X;

/* Hash node type for cgPathCond - records the name of a JUMPCOND  variable */
/* corresponding to a branch, and whether that branch was taken or not taken.*/
typedef
struct __cgPathCondHashNode {
  struct __cgPathCondHashNode * next; 
  HWord key;
  HWord BBCounter;
  HWord execCounter;
  HWord condCounter; 
  cgPathCondStatus taken; 
}
cgPathCondHashNode; 


/* Hash node type for keeping track of whether a temp has been declared.*/
/* Need all this information to resolve hash collisions. Hash keys are  */
/* only 32 bit, and mplayer traces can have over 150K > 2^15 temp vars. */
typedef
struct __cgIsDeclaredHashNode {
  struct __cgIsDeclaredHashNode * next; 
  HWord key;
  HWord addr; 
  HWord offset; 
  HWord tmpName; 
  HWord transBB;
  HWord execBB; 
}
cgIsDeclaredHashNode; 

/* Part of support for a now-unused alternative method for constraint */
/* generation: instead of writing array reads and writes, expand into */
/* explicit IF-THEN-ELSE statements. Added to allow comparison of     */
/* STP's optimized array processing vs. "naive" processing.           */
/* With addition of array suppression in 11/07, no longer needed.     */ 
typedef
struct __cgITEWriteStackNode { 
  struct __cgITEWriteStackNode * next; 
  HWord key; 
  cgITEStackType ty; 
  HWord addrName;
  HWord addrBBCounter;
  HWord addrExecCounter;
  HWord valName; 
  HWord valBBCounter;
  HWord valExecCounter; 
}
cgITEWriteStackNode;



/* --- Globals --- */

VgHashTable cgPathCond; /* Initialized in ca_main.c:pre_clo_init */ 
VgHashTable cgIsDeclared; /* Initialized in ca_main.c:pre_clo_init */ 
VgHashTable cgIsDeclaredWide; /* Initialized in ca_main.c:pre_clo_init */ 
VgHashTable cgITEWriteStackMemSt; /* Initialized in ca_main.c:pre_clo_init */ 
VgHashTable cgITEWriteStackMaSt;  /* Initialized in ca_main.c:pre_clo_init */ 

// BB counters
// cgBBCounter is # of BB translated, aids debugging 
// cgBBExecCounter is # of currently executing BB, avoids false sharing
// cgJCCounter is # of conditional branches seen, needed because 
// a single BB may have more than one exit.

extern HWord cgBBCounter; 
extern HWord cgBBExecCounter; 
extern HWord cgJCCounter; 
extern HWord localScope; 



/* --- Prototypes --- */ 

Bool cgMemDeclaredP(HWord loadAddr, HWord offset); 
Bool cgTmpIsDeclaredP(HWord tmpName, HWord transBB, HWord execBB);
void cgSetMemDeclared(HWord loadAddr, HWord offset); 
void cgSetTmpDeclared(HWord tmpName, HWord transBB, HWord execBB); 

HWord nameToHashKey(HWord tmpName, HWord BBcounter, HWord execounter);
UInt cgExtractByte(HWord word, UInt byteno);

void cgSetJumpNotTaken(HWord tagVal);
int cgTmpSymbolicP(HWord tmpname, HWord bbval, HWord execval);
int cgMemSymbolicP(HWord addr);
int cgJumpcondSymbolicP(HWord bbval, HWord execval, HWord condval);
int cgRegSymbolicP(HWord offset);
void cgPrintTmpName(HWord tmpName, HWord transBB);
void cgPrintTmpNameWide(HWord tmpName, HWord transBB);
void cgPrintTmpVarTy(TmpVarTy tmpVar);


void cgPrintMachState(HWord n_instance);
void cgPrintMemState(HWord n_instance);
void cgPrintMemRegionState(HWord n_instance, HWord baseAddr);
IRType cgConstToIRType(IRExpr * rhs);

void cgPrintHWord(HWord val, Int hexits);
HWord cgConstToHword(IRExpr * ircon);
void cgPrintOp(IROp op);
void cgDeclareVars(IRTypeEnv * tyenv, HWord tagVal);

void cgEmitQueryTmpTmp(HWord tArg1,HWord tArg2, HWord BBCounter, IROp op);
void cgEmitQueryBadRange(HWord tArg, HWord BBCounter);

void setHelperLoadConcreteAnns(IRDirty * di);

void cgEmitNot1(HWord lhsname, HWord argname, HWord tagVal);

/* "DeclareTmpAtRun" means use the current value of the execBB counter */
/* We need this because the "correct" value of the BB counter is       */
/* not known at instrumentation time. We also need a version that      */
/* allows specifying execBB directly for tempvars from LOAD and GET.   */

void cgDeclareTmpAtRun(HWord transBB, 
		       HWord tmpName, 
		       IRType ty);
void cgDeclareTmp(HWord transBB, 
		  HWord execBB, 
		  HWord tmpName, 
		  IRType ty);
void cgDeclareTmpWide(HWord transBB,  
		      HWord tmpName);
void cgDeclareTmpIfUndeclared(HWord transBB, 
			      HWord execBB, 
			      HWord tmpName, 
			      IRType ty
			      );

void cgDeclareTmpAtRunIfUndeclared(HWord transBB,  
				   HWord tmpName, 
				   IRType ty
				   );
void cgDeclareTmpVarTyIfUndeclared(TmpVarTy tmpVar, IRType ty);

void cgIncExecCounter(void);

/* function 1 changed
void cgEmitUnopTmp(IROp theop, 
		   HWord lhsname, 
		   HWord argname, 
		   HWord tagVal, 
		   IRType lhsty,
		   IRType argty,
		   HWord argval, 
		   HWord lhsval
		   );*/
void cgEmitUnopTmp(cgArgs_EmitUnopTmp *extra_args,
		   HWord argval,
                   HWord lhsval
		   );

void cgEmit1Uto32(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit32to1(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit64loto32(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit64HIto32(HWord lhsname, HWord argname, HWord tagVal);
void cgEmitStoreInfo(HWord addr );
void cgEmitStoreInfoByte(HWord addr );
void cgEmitTmpAssignConcrete(HWord lhstmp, HWord tagVal, HWord ty, HWord val);
void cgEmitTmpLoadConcrete(HWord addr, HWord lhstmp, HWord tagVal, IRType ty);

void cgEmit1Uto8(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit8Uto32(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit16Uto32(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit32to8Tmp(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit32to16Tmp(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit32to8Const(HWord lhsname, HWord argval, HWord tagVal);
void cgEmit32to16Const(HWord lhsname, HWord argval, HWord tagVal);
void cgEmit8Sto32(HWord lhsname, HWord argname, HWord tagVal);
void cgEmitNot32(HWord lhsname, HWord argname, HWord tagVal);
void cgEmit16Sto32(HWord lhsname, HWord argname, HWord tagVal);

void cgEmitPreamble(void);

/* function 2 change 
void cgEmitTmpBinopConstConst (
			       IROp theop, 
			       HWord tagVal,
			       IRType lhsty,
			       HWord lhsname, 
			       HWord arg1val, 
			       HWord arg2val
			       ); */
void cgEmitTmpBinopConstConst (
			       cgArgs_EmitTmpBinopConstConst *extra_args,
			       HWord arg1val,
			       HWord arg2val
			       );
/* function change - TROUBLESOME ONE
void cgEmitTmpBinopTmpConst (
			     IROp theop, 
			     HWord tagVal,
			     IRType lhsty,
			     IRType arg1ty,
			     HWord lhsname, 
			     HWord arg1name, 
			     HWord arg2val
			     ); */
void cgEmitTmpBinopTmpConst (
			     cgArgs_EmitTmpBinopTmpConst *extra_args
			     );
/* function 3 change
void cgEmitTmpBinopConstTmp (
			     IROp theop, 
			     HWord tagVal,
			     IRType lhsty,
			     IRType arg2ty,
			     HWord lhsname, 
			     HWord arg1val, 
			     HWord arg2name
			     );*/
void cgEmitTmpBinopConstTmp (
			     cgArgs_EmitTmpBinopConstTmp *extra_args
			     );
/* function 5 change 
void cgEmitTmpBinopTmpTmp (
			   IROp theop, 
			   HWord tagVal,
			   IRType lhsty,
			   IRType arg1ty,
			   IRType arg2ty,
			   HWord lhsname, 
			   HWord arg1name, 
			   HWord arg2name,
			   HWord arg1val,
			   HWord arg2val
			   ); */
void cgEmitTmpBinopTmpTmp (
			   cgArgs_EmitTmpBinopTmpTmp *extra_args,
			   HWord arg1val,
			   HWord arg2val
			   );
void cgEmitPutConstStmt (HWord putOffset, HWord putData, IRType ty);
void cgEmitPutTmpStmt (HWord putOffset, HWord tagVal, HWord tmpName, IRType ty);
void cgEmitStoreConstConst (HWord addr, HWord data);
void cgEmitStoreTmpConst (HWord addr, HWord addrTmp, HWord tagVal, HWord data);
void cgEmitStoreConstTmp(HWord addr, HWord tagVal, HWord dataTmp);
void cgEmitStoreTmpTmp(HWord addr, HWord addrTmp, HWord tagVal, HWord dataTmp);
void cgEmitStoreConstConcrete (HWord addr);
void cgEmitStoreOrigin (HWord addr); 
void cgEmitPutUnconstrained_8Bit (HWord putOffset, IRType ty);
void cgEmitPutUnconstrained_32Bit (HWord putOffset, IRType ty);
void cgEmitPutConstStmt_8bit (HWord putOffset, HWord putData, IRType ty);
void cgEmitPutConstStmt_32bit (HWord putOffset, HWord putData, IRType ty);
void cgEmitPutTmpStmt_8bit (HWord putOffset, HWord tagVal, HWord tmpName, IRType ty);
void cgEmitPutTmpStmt_32bit (HWord putOffset, HWord tagVal, HWord tmpName, IRType ty);
void cgEmitTmpGetConstraints_8bit(HWord offset, HWord tmpname, HWord tagVal, IRType ty);
void cgEmitTmpGetConstraints_32bit(HWord offset, HWord tmpname, HWord tagVal, IRType ty, HWord tmpval);

void cgEmitTmpAssignSymbolic(HWord lhstmp, 
			     HWord tagVal, 
			     HWord ty, 
			     HWord rhstmp);

void cgEmitTmpAssignConcreteIfLHSSymbolic(HWord lhstmp, 
					  HWord tagVal, 
					  HWord ty, 
					  HWord val);

void cgAddTmpMux0X(IRSB * bb, IRStmt * s);

/* function 6 change
void cgEmitTmpMux0X(HWord lhstmpname,
		    HWord condtmpname, 
		    HWord truetmpname, 
		    HWord falsetmpname,
		    HWord condval,
		    HWord trueval,
		    HWord falseval,
		    HWord tagVal,
		    HWord assignTy);
*/
void cgEmitTmpMux0X(cgArgs_EmitTmpMux0X *extra_args,
                    HWord condval,
		    HWord trueval,
		    HWord falseval);

void cgEmitExitTmpConstraints(HWord tmpName, HWord tagVal, HWord condVal, HWord destAddr);

HWord cgGoodDirtyArgTyP(IRType ty); 
int cgGetTypeOK(IRType ty); 
  
void cgAddTmpCCall(IRSB * bb, IRStmt * s);
void cgAddPreamble(IRSB * bb, HWord cntVal);
void cgAddStoreStmtConstraints(IRSB * bb, IRStmt * s);
void cgAddPutStmtConstraints(IRSB * bb, IRStmt * s);

void cgEmitTmpLoadTmpConstraints(HWord loadAddr, HWord rhstmp, HWord lhstmp, HWord tagVal, IRType assignTy);
void cgEmitTmpLoadConstConstraints(HWord addr, HWord lhstmp, HWord tagVal, IRType assignTy);

void cgEmitTmpTmpConstraints(HWord lhstmp, HWord rhstmp, HWord tagVal, 
			     IRType ty);
void cgEmitPathCond(void);

void cgAddExitPost(IRSB * bb, IRStmt * s);
void cgAddExitPre(IRSB * bb, IRStmt * s);
void cgAddTmpTmpConstraints(IRSB * bb, IRStmt * s);
void cgAddTmpUnopConstraints(IRSB * bb, IRStmt * s);
void cgAddTmpBinopConstraints(IRSB * bb, IRStmt * s);
void cgAddTmpStmtConstraints(IRSB * bb, IRStmt * s);
// void cgAddExitStmtConstraints(IRBB * bb, IRStmt * s);

void cgEmitTmpOffsetConstraints(caChunkTy * addrChunk, HWord addrTmp, HWord tagVal); 

void cgIRStmt ( IRSB * bb, IRStmt* s, ULong bb_counter );

void cgPrintExtTmpName(HWord tmpName, HWord transBB,HWord execBB);
void cgPrintCommentChar(void);
void cgAddPrintVars(IRSB * bb, IRStmt * s);
void cgPrintEndln(void);

HWord cgIsSupportedBinop(IROp op);
HWord cgIsSupportedUnop(IROp op);

void cgSetTmpWideDeclared(
			  HWord tmpName, 
			  HWord transBB, 
			  HWord execBB
			  );
Bool cgTmpWideIsDeclaredP(HWord tmpName, HWord transBB, HWord execBB);
void cgPrintTmpNameWide(HWord tmpName, HWord transBB);
void cgDeclareTmpWideIfUndeclared(
				  HWord transBB, 
				  HWord tmpName
				  );
