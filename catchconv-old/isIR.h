/*--------------------------------------------------------------------*/
/*--- CatchConversions                            isIR.h           ---*/
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

/* Header file for isSymbolic map. */ 

/* Hash node type for cgIsSymbolic - just notes whether location is symbolic */
typedef
struct __isIsSymbolicHashNode {
  struct __isIsSymbolicHashNode * next;
  HWord key; 
  HWord isOrigin; 
  HWord offset; 
}
isIsSymbolicHashNode; 

/* Hash node type for cgIsDeclared - notes whether location is declared, */
/* and contains enough information to resolve hash collisions.           */

/* Hash table for isSymbolic map */ 
VgHashTable isIsSymbolic; /* Initialized in ca_main.c:pre_clo_init */ 


/* --- Prototypes --- */ 

void isSetKeySymbolic(HWord key);
void isSetKeyConcrete(HWord key);
void isSetKeyOrigin(HWord key, HWord offset);
void isSetJCSymbolic(HWord BB, HWord exec, HWord CC);
void isSetKeyDeclared(HWord key); 
void isSetMemDeclared(HWord addr);
void isSetMemConcrete(HWord addr, HWord numBytes);
void isFlowToMem(HWord srckey, HWord addr, HWord numBytes); 
void isSetRegConcrete(HWord offset); 
void isFlowToReg(HWord srckey, HWord regOffset, HWord numBytes); 


HWord isKeySymbolicP(HWord key);
HWord isKeyDeclaredP(HWord key);
HWord isKeyOriginP(HWord key, HWord * offset);
HWord isJCSymbolicP(HWord BB, HWord exec, HWord CC);

void isFlowMapByKey(HWord srcKey, HWord sinkKey);
void isFlowMapByKeyBinary(HWord srcKey1, HWord srcKey2, HWord sinkKey);
void isFlowMapByKeyTrinary(HWord srcKey1, 
			   HWord srcKey2, 
			   HWord srcKey3,
			   HWord sinkKey);



void isIRTmp(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRStmt(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpUnop(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpBinop(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpTmp(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpGet(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpLoad(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRPut(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRStore(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpMux0X(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpCCall(IRSB * bb, IRStmt * s, HWord BBCounter);
void isIRTmpCCallCalcConditionAdd(IRSB * bb, IRStmt * s, HWord BBCounter); 

HWord isTmpSymbolicP(HWord BB, HWord tmpname);
HWord isRegSymbolicP(HWord offset);
HWord isMemSymbolicP(HWord addr);

HWord isTmpOriginP(HWord BB, HWord tmpname);
HWord isRegOriginP(HWord offset);
HWord isMemOriginP(HWord addr, HWord * offset);
HWord isMemInputDeclaredP(HWord addr, HWord offset);
HWord isTmpDeclaredP(HWord tmpName, HWord bbName, HWord execBBName); 


