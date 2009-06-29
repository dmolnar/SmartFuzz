#pragma once 
/*--------------------------------------------------------------------*/
/*--- CatchConversions                           ufOgIR.h          ---*/
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




#define FALSE 0
#define TRUE 1

/* ---- Types --- */ 

/* --------- Condition codes, Intel encoding. --------- */
/* --------- From VEX/priv/host-x86/hdefs.h   --------- */

// Temporarily comment out below; duplicated in ogIR.h 
// Eventually will replace ogIR.h with this
#if 0 
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
#endif 


/* Node type for union-find data structure */
typedef
struct _ufOgNode {
  struct _ufOgNode * parent; 
  HWord  tmpName;
  HWord  bbTransNum;
  HWord  bbExecNum;
  IntType tmpType; 
  UInt   memRefCount;
  UInt   childRefCount; 
  UInt   rank; 
} 
ufOgNode;

/* Hash node type for map H from temporary var names to union-find nodes */
/* First two fields match core's VgHashNode. */
/* Note that we will have hash chaining. */ 
typedef
struct _ufOgHashNode {
  struct _ufOgHashNode * next;
  HWord  loc;
  ufOgNode * ufNode;
}
ufOgHashNode;

// Define a value for temp name meaning "not a temp var", i.e. a constant
#define NONTEMP -1

VgHashTable ufOgHash; /* Initialized in ca_main - pre_clo_init */
VgHashTable ufOgLiveTempVarNodes; /* Initialized in ca_main - pre_clo_init */

/* --- Function prototypes --- */ 

ufOgNode * ufSingleton(HWord tmpName, HWord transNum, HWord execNum);  
ufOgNode * ufFind(ufOgNode * element);
ufOgNode * ufUnion(ufOgNode * element1, ufOgNode * element2); 
UInt ufCheck(ufOgNode * element, UInt cleanupP); 
void ufDestroy(ufOgNode * element); 
ufOgNode * tmpNametoNode(HWord tmpName, HWord transNum, HWord execNum);
void ufHandleStore(HWord addr, HWord tmpName, HWord bbTransNum);
void ufHandleAssignment(HWord tmpLHS, HWord tmpRHS, HWord bbTransNum);
void ufInstOgIRExit (IRSB * bb,  IRStmt* s , ULong bb_counter);
void ufCleanup(void); 
void ufHandleBinop(HWord tmpZ, HWord tmpX, HWord tmpY, HWord bbTransNum);
void ufHandleCompare(HWord tmpX, HWord tmpY, HWord bbTransNum, IntType CompareType);
IntType ufMeet(IntType x, IntType y); 
void ufInstOgIRStmt (IRSB * bb,  IRStmt* s , ULong bb_counter); 
void ufHandleUnop(HWord tmpLHS, HWord tmpRHS, HWord bbTransNum);
void ufHandleLoad(HWord addr, HWord LHSTmpName, HWord bbTransNum); 
void ufInstOgIRPut (IRSB * bb,  IRStmt* s , ULong bb_counter);
UInt isCompare(IROp op);
IntType opToType(IROp op);
void ufInstOgIRTemp (IRSB * bb,  IRStmt* s , ULong bb_counter);
void ufInstOgIRStore (IRSB * bb,  IRStmt* s , ULong bb_counter);
void ufHandleStoreConstant(HWord addr, HWord bbTransNum);
