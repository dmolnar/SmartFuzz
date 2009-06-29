
#pragma once

typedef 
struct _TmpVarTy {
  int CV;
  int e;
  int t; 
  int p;
  int th;
}
TmpVarTy; 

/* Hash node type for trackMem map. 
First two fields match core's VgHashNode */
typedef
struct _TmTypeOfHashNode {
  struct _TmTypeOfHashNode * next;
  HWord memAddr;
  HWord offset;   /* which byte of the tmpvar is this? */
  HWord numBytes; /* how many bytes is this tmpvar? */ 
  TmpVarTy var;
}
TmTypeOfHashNode;

/* --- Globals --- */

VgHashTable tmAddrToVar; /* Initialized in ca_main - pre_clo_init */


/* --- Prototypes --- */ 

void tmClearAddr(HWord addr, HWord numBytes); 
void tmUpdate(HWord addr, HWord tmpname, HWord numBytes, HWord tagVal); 

void tmIRStmt(IRSB * bb, IRStmt * s, HWord BBCounter);
void tmIRStore(IRSB * bb, IRStmt * s, HWord BBCounter);
void tmIRPut(IRSB * bb, IRStmt * s, HWord BBCounter);


