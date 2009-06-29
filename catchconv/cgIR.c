/*--------------------------------------------------------------------*/
/*--- CatchConversions                           cgIR.c            ---*/
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


#include "libvex_basictypes.h"
#include "libvex_ir.h"
#include "libvex.h"


#include "ca_vex_util.h"


#include "pub_tool_basics.h"
#include "pub_tool_libcassert.h"
#include "pub_tool_tooliface.h"

#include "pub_tool_machine.h" 
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
#include "catchconv.h" 


/*---------------------------------------------------------------*/
/*--- Generate STP  from VEX IR                               ---*/
/*---------------------------------------------------------------*/

/* --- Globals --- */

// BB counters
// cgBBCounter is # of BB translated, for debugging
// cgBBExecCounter is # of currently executing BB, avoids false sharing

HWord cgBBCounter = 0; 
HWord cgBBExecCounter = 0; 
HWord cgJCCounter = 0; 
HWord localScope = 0; 

Bool inlinePathQueriesP = True; 

// Machine state instance number
// because STP cannot update in place
unsigned int n_mach_state_instance = 0;

// Memory state instance number
// because STP cannot update in place
unsigned int n_mem_state_instance = 0;

// Stat counters
HWord numCalcCondition = 0; 


/* --- Helper Functions --- */

HWord numBytesOfConst( IRConst * con)
{
  IRConstTag contag;
  vassert(con != NULL); 
  contag = con->tag; 
  switch(contag)
  {
  case Ico_U1:
    return 1; 
  case Ico_U8:
    return 1; 
  case Ico_U16:
    return 2; 
  case Ico_U32:
    return 4; 
  case Ico_U64:
    return 8; 
  case Ico_F64:
    return 8; 
  case Ico_F64i:
    return 8; 
  case Ico_V128:
    return 16;
  default:
    if (ca_output_comment)
    {
      VG_(printf)("XXX Unhandled IRConstTag %x in numBytesOfConst! \n", contag); 
    }
    return 4; 
  }
}

HWord numBytesOfTmpvar ( IRSB * bb, IRTemp tmp)
{
  IRType ty;
  HWord ret; 

  ty = bb->tyenv->types[tmp];
  vassert(bb != NULL); 
  ret = numBytesOfType(ty); 
  return ret; 
}

HWord numBytesOfType(IRType ty)
{
  switch(ty)
  {
  case Ity_INVALID:
    vpanic("Invalid type passed to NumBytesOfTmpvar! \n");
    break; 
  case Ity_I1:
    return 1; 
  case Ity_I8: 
    return 1;
  case Ity_I16:
    return 2; 
  case Ity_I32:
    return 4; 
  case Ity_I64:
    return 8; 
  case Ity_I128:
    return 16; 
  case Ity_F32:
    return 4; 
  case Ity_F64:
    return 8; 
  case Ity_V128:
    return 8; 
  default:
    if (ca_output_comment)
    {
      VG_(printf)("XXX Unhandled IRType %x in numBytesOfType, returning size=4 bytes! \n", ty); 
    }
  return 4;
  } 
}

void setHelperLoadConcreteAnns(IRDirty * di)
{
  di->nFxState = 1; 
  di->fxState[0].fx = Ifx_Read; 
  di->fxState[0].offset = 0; 
  di->fxState[0].size = 0; 

}

void cgIncExecCounter(void)
{
  cgBBExecCounter++; 
  return; 
}

/* STP requires that constant values be left-0-padded to a constant */
/* length depending on the size of the LHS variable. For example,   */
/* assigning 0xA to a 32-bit bitvector uses 0hex0000000a.           */ 
/* cgPrintHWord takes an HWord, a number of hexits, and then prints */
/* in the appropriate format. Does _not_ print the 0hex prefix.     */
/* This code supports any amount of padding, but at the moment this */
/* routine should only be used to print single VEX values. So to    */
/* help catch errors in which an invalid value is passed, we        */
/* complain if the size is bigger that 128 bits (32 hex digits).    */

void cgPrintHWord(HWord val, Int hexits)
{
  char buf[256];
  int size, i; 
  size = 0; 

  VG_(snprintf)(buf,sizeof(buf),"%x",val); 
  size = VG_(strlen)(buf); 
 
  vassert(hexits <= 32);
  if( !((hexits - size) >= 0) )
  {
    VG_(printf)("ERROR (buffer too small in cgPrintHWord): ");
    VG_(printf)(buf);
    VG_(printf)(" VAL : %u ", val); 
    VG_(printf)("SIZE : %u ", size);
    VG_(printf)("HEXITS : %u \n", hexits); 
    vassert((hexits - size) >= 0);  
  }

  for(i = 0; i < (hexits - size); i++)
  {
    VG_(printf)("0");
  }
  VG_(printf)(buf); 
}

void cgPrintTmpNameWide(HWord tmpName, HWord transBB)
{
  cgPrintTmpName(tmpName, transBB);
  VG_(printf)("Wide"); 
}

void cgPrintTmpName(HWord tmpName, HWord transBB)
{
  HWord PID;
  HWord TID;
  
  PID = VG_(getpid)(); 
  TID = VG_(get_running_tid)();

  VG_(printf)("CV%d",transBB);
  VG_(printf)("e%d",cgBBExecCounter); 
  VG_(printf)("t%d",tmpName);
  VG_(printf)("p%d",PID);
  VG_(printf)("th%d",TID);
}

void cgPrintExtTmpName(HWord tmpName, HWord transBB,HWord execBB)
{
  HWord PID;
  HWord TID;
  
  PID = VG_(getpid)(); 
  TID = VG_(get_running_tid)();

  VG_(printf)("CV%d",transBB);
  VG_(printf)("e%d",execBB); 
  VG_(printf)("t%d",tmpName);
  VG_(printf)("p%d",PID);
  VG_(printf)("th%d",TID);

}

void cgPrintTmpVarTy(TmpVarTy tmpVar)
{
  VG_(printf)("CV%d",tmpVar.CV);
  VG_(printf)("e%d",tmpVar.e); 
  VG_(printf)("t%d",tmpVar.t);
  VG_(printf)("p%d",tmpVar.p);
  VG_(printf)("th%d",tmpVar.th);
}



/* Prints mach state instance for current PID and TID */
/* NOTE: Caller's responsibility to increment instance number */ 
void cgPrintMachState(HWord n_instance)
{
  HWord PID;
  HWord TID;

  PID = VG_(getpid)(); 
  TID = VG_(get_running_tid)();
  
  VG_(printf)("MaSt%d",n_instance); 
  VG_(printf)("p%d",PID);
  VG_(printf)("th%d",TID);
}

/* Prints mem state instance for current PID and TID */
/* NOTE: Caller's responsibility to increment instance number */ 
void cgPrintMemState(HWord n_instance)
{
  HWord PID;
  HWord TID;

  PID = VG_(getpid)(); 
  TID = VG_(get_running_tid)();

  VG_(printf)("MemState%d",n_instance); 
  VG_(printf)("p%d",PID);
  VG_(printf)("th%d",TID);
  return; 
}


/* Prints mem region state instance for current PID and TID */
/* NOTE: Caller's responsibility to increment instance number */ 
void cgPrintMemRegionState(HWord n_instance, HWord baseAddr)
{
  HWord PID;
  HWord TID;

  PID = VG_(getpid)(); 
  TID = VG_(get_running_tid)();

  VG_(printf)("MemRegion%d",n_instance); 
  VG_(printf)("p%d",PID);
  VG_(printf)("th%d",TID);
  VG_(printf)("base%x",baseAddr); 
  return; 
}

HWord cgConstToHword(IRExpr * ircon)
{
  HWord ret; 
  IRConst * thecon;
  vassert(ircon);
  vassert(ircon->tag == Iex_Const); 

  thecon = ircon->Iex.Const.con; 
  vassert(thecon); 
  
  switch (thecon->tag)
    {
    case (Ico_U8):
      ret = (HWord)thecon->Ico.U8; 
      break; 
    case (Ico_U32):
      ret = (HWord) thecon->Ico.U32; 
      break; 
    default:
      ret = 0xDEADBEEF; 
      break; 
    }
  return ret; 
}

void cgPrintOp(IROp op)
{
  switch (op)
    {
    case(Iop_CmpLT32S):
      VG_(printf)(" BVSLT");
      break;
    case(Iop_CmpLE32S):
      VG_(printf)(" BVSLE");
      break;
    case(Iop_CmpLT32U):
      VG_(printf)(" BVLT");
      break;
    case(Iop_CmpLE32U):
      VG_(printf)(" BVLE");
      break;
    case(Iop_Sub32):
    case(Iop_Sub16):
    case(Iop_Sub8):
      VG_(printf)(" BVSUB");
      break; 
    case(Iop_Add32):
    case(Iop_Add16):
    case(Iop_Add8):
      VG_(printf)(" BVPLUS"); 
      break; 
    case(Iop_Mul32):
    case(Iop_MullU32):
      VG_(printf)(" BVMULT"); 
      break; 
    case (Iop_Xor32):
      VG_(printf)(" BVXOR");
      break;
    case (Iop_CmpEQ32):
    case (Iop_CmpEQ16):
    case (Iop_CmpEQ8):
    case (Iop_CmpNE32):
    case (Iop_CmpNE16):
    case (Iop_CmpNE8):
      VG_(printf)(" = "); 
      break; 
    case(Iop_Or32):
    case(Iop_Or16):
    case(Iop_Or8):
      VG_(printf)(" | ");
      break; 
    case (Iop_And32):
    case (Iop_And16):
    case (Iop_And8):
      VG_(printf)(" & "); 
      break; 
    case (Iop_Shl64):
    case (Iop_Shl32):
      VG_(printf)(" << ");
      break; 
    case (Iop_Shr32):
    case (Iop_Shr64):
    case (Iop_Sar32):
      VG_(printf)(" >> "); 
      break; 
    default:

      if (ca_output_comment)
      {
	VG_(printf)("XXX Warning : Unhandled op ");
	ppIROp(op); 
	VG_(printf)("\n"); 
      }
      break;
    }
  return; 
}


void cgDeclareTmpWideIfUndeclared(
				  HWord transBB, 
				  HWord tmpName
				  )
{
  HWord execBB = cgBBExecCounter;
  if (! cgTmpWideIsDeclaredP(tmpName, transBB, execBB) )
  {
    cgDeclareTmpWide(transBB, tmpName);
    cgSetTmpWideDeclared(tmpName, transBB, execBB); 
  }
}

void cgDeclareTmpIfUndeclared(
			      HWord transBB, 
			      HWord execBB, 
			      HWord tmpName, 
			      IRType ty
			      )
{
  if (! cgTmpIsDeclaredP(tmpName, transBB, execBB) )
  {
    cgDeclareTmp(transBB, execBB, tmpName, ty);
    cgSetTmpDeclared(tmpName, transBB, execBB); 
  }
}

void cgDeclareTmpVarTyIfUndeclared(TmpVarTy tmpVar, IRType ty)
{
  cgDeclareTmpIfUndeclared(tmpVar.CV, tmpVar.e, tmpVar.t, ty); 
}


void cgDeclareTmpAtRunIfUndeclared(HWord transBB,  
				   HWord tmpName, 
				   IRType ty
			      )
{
  if (! cgTmpIsDeclaredP(tmpName, transBB, cgBBExecCounter) )
  {
    //    VG_(printf)(" NOT DECLARED \n");
    cgDeclareTmpAtRun(transBB, tmpName, ty);
    cgSetTmpDeclared(tmpName, transBB, cgBBExecCounter); 
  }
  else
  {
    //    VG_(printf)(" DECLARED \n");
  }
}

void cgDeclareTmpAtRun(HWord transBB, HWord tmpName, IRType ty)
{
  VG_(printf)("\n"); 
  switch (ty)
    {
    case (Ity_I1):
      cgPrintTmpName(tmpName,transBB);
      VG_(printf)(" : BOOLEAN;\n"); 
	  break; 
	case (Ity_I8):
	case (Ity_I16):
	case (Ity_I32):
    case (Ity_F32):
    case (Ity_F64):

	  cgPrintTmpName(tmpName,transBB);
	  VG_(printf)(" : BITVECTOR(32);\n"); 
	  break;
	case (Ity_I64):

 	  cgPrintTmpName(tmpName,transBB);
	  VG_(printf)(" : BITVECTOR(64);\n"); 
	  break; 
	default:
	  if (ca_output_comment)
	  {
	    VG_(printf)(" XXX Warning: unhandled IRType ");
	    ppIRType(ty); 
	    VG_(printf)("in cgDeclareTmp \n"); 
	  }
	  break;
	}

}

void cgDeclareTmpWide(HWord transBB, HWord tmpName)
{
  VG_(printf)("\n"); 
  cgPrintTmpNameWide(tmpName, transBB);
  VG_(printf)(" : BITVECTOR(64);\n");  // should be 128 if Tmp is 64 bit
}

void cgDeclareTmp(HWord transBB, HWord execBB, HWord tmpName, IRType ty)
{
  VG_(printf)("\n"); 
  switch (ty)
    {
    case (Ity_I1):
      cgPrintExtTmpName(tmpName,transBB, execBB);
      VG_(printf)(" : BOOLEAN;\n"); 
	  break; 
	case (Ity_I8):
	case (Ity_I16):
	case (Ity_I32):
	  cgPrintExtTmpName(tmpName,transBB, execBB);
	  VG_(printf)(" : BITVECTOR(32);\n"); 
	  break;
	case (Ity_I64):
	  cgPrintExtTmpName(tmpName,transBB, execBB);
	  VG_(printf)(" : BITVECTOR(64);\n"); 
	  break; 
	default:
	  if (ca_output_comment)
	  {
	    VG_(printf)(" XXX Warning: unhandled IRType ");
	    ppIRType(ty); 
	    VG_(printf)("in cgDeclareTmp \n"); 
	  }
	  break;
	}
}

void cgDeclareVars(IRTypeEnv * tyenv, HWord transBB)
{
  int tmpName = 0; 
  IRType curType; 
  vassert(tyenv);
  
  for (tmpName = 0; tmpName < tyenv->types_used; tmpName++)
    {
      curType = tyenv->types[tmpName];


  switch (curType)
    {
    case (Ity_I1):
      
      cgPrintTmpName(tmpName,transBB);
      VG_(printf)(" : BOOLEAN;\n"); 
	  break; 
	case (Ity_I8):
	case (Ity_I16):
	case (Ity_I32):
	
	  cgPrintTmpName(tmpName,transBB);
	  VG_(printf)(" : BITVECTOR(32);\n"); 
	  break;
	case (Ity_I64):
	  cgPrintTmpName(tmpName,transBB);
	  VG_(printf)(" : BITVECTOR(64);\n"); 
	  break; 
	default:
	  if (ca_output_comment)
	  {
	    VG_(printf)(" XXX Warning: unhandled IRType in cgDeclareTmp \n"); 
	  }
	  break;
	}
    }
  
  return; 
}

/* ---- Emit Constraint functions ---- */

void cgEmitQueryBadRange(HWord tArg, HWord BBCounter)
{
  // can the temp be in the range where it causes a signed LT comparison to
  // succeed but and unsigned one to fail? 
  // i.e. is 0x80000000 < tmp <= 0xFFFFFFFF
  // i.e is tmp always LT 0x800000000

  // added extra condition: emit QUERY only if tmp tainted
  // and so in principle query could go either way
  // Note this is only correct for 32-bit values used as signed/unsigned.

  if (isTmpSymbolicP(BBCounter,tArg))
  {
    VG_(printf)("XXX QUERY(BVLT( "); 
    cgPrintTmpName(tArg,BBCounter); 
    VG_(printf)(" ,");
    VG_(printf)("0hex80000000));  %% TYPE SignedUnsignedBadRange \n"); 
  }
  else if (ca_output_comment)
  {
    VG_(printf)("XXX untainted tmp "); 
    cgPrintTmpName(tArg,BBCounter); 
    VG_(printf)(" set to Bot \n");
  }
  return; 
}

void cgEmitQueryTmpTmp(HWord tArg1, HWord tArg2, HWord BBCounter, IROp op)
{
  VG_(printf)("XXX QUERY( "); 

  switch (op)
    {
    case (Iop_CmpLE32S):
    case (Iop_CmpLE32U):
      //  QUERY( BVLE(a,b) AND BVSLE(a,b) );  

      VG_(printf)("BVLE( ");
      cgPrintTmpName(tArg1,BBCounter);
      VG_(printf)(" , ");
      cgPrintTmpName(tArg2,BBCounter);
      VG_(printf)(") AND "); 
      VG_(printf)("BVSLE( ");
      cgPrintTmpName(tArg1,BBCounter);
      VG_(printf)(" , ");
      cgPrintTmpName(tArg2,BBCounter);
      VG_(printf)(") ); \n"); 

      break;
      
    case (Iop_CmpLT32S):
    case (Iop_CmpLT32U):
      // QUERY( BVLT(a,b) AND BVSLT(a,b)); 

      VG_(printf)("BVLT( ");
      cgPrintTmpName(tArg1,BBCounter);
      VG_(printf)(" , ");
      cgPrintTmpName(tArg2,BBCounter);
      VG_(printf)(") AND "); 
      VG_(printf)("BVSLT( ");
      cgPrintTmpName(tArg1,BBCounter);
      VG_(printf)(" , ");
      cgPrintTmpName(tArg2,BBCounter);
      VG_(printf)(" ) ); \n"); 

      break; 

    default:
      VG_(printf)("Unahndled op in queryTmpTmp : " ); 
      ppIROp(op); 
      VG_(printf)(" )\n"); 
      break; 
    }

  return; 
}

void cgEmitPreamble(void)
{
  /* Emit comment showing the current basic block exec'd number */ 

  VG_(printf)("XXX START BASIC BLOCK EXEC: %d \n", cgBBExecCounter); 

  if (ca_mem_handling == CA_suppress_arrays)
  {
    /* We are suppressing array output. No need for rest of preamble. */
    return; 
  }
  cgPrintMachState(0); 
  VG_(printf)(" : ARRAY BITVECTOR(12) OF BITVECTOR(32);\n"); 
  cgPrintMemState(0); 
  VG_(printf)(" : ARRAY BITVECTOR(32) OF BITVECTOR(32);\n"); 

  // MEMORY -  caDeclareAllIntervals(caIntervalTable);

  return; 
}


void cgEmitPutUnconstrained_32Bit (HWord putOffset, IRType ty)
{
	ULong n_old_mach_state_instance;
	HWord numBytes; 
	HWord arrayBase;
	HWord arrayOffset; 
	
	arrayOffset = putOffset % 4; 
	arrayBase = putOffset - arrayOffset; 

	if (ca_mem_handling == CA_suppress_arrays)
	{
	  return; 
	}

	
	switch (ty)
	  {
	  case (Ity_I32):
	    numBytes = 4; 
	    break; 
	  case (Ity_I16):
	    numBytes = 2; 
	    break; 
	  case (Ity_I8):
	    numBytes = 1; 
	    break; 
	  default:
	    numBytes = 4; 
	    if (ca_output_comment)
	    {
	      VG_(printf)("XXX Unhandled IRType in cgEmitPutUnconstrained ");
	      ppIRType(ty); 
	      VG_(printf)(" \n"); 
	    }
	  break; 
	  }


	    n_old_mach_state_instance = n_mach_state_instance;
	    n_mach_state_instance++;


	    VG_(printf)("UNCONSTRAINED%x : BITVECTOR(32);\n",
			n_old_mach_state_instance); 
	    
	    
	    cgPrintMachState(n_mach_state_instance); 
	    VG_(printf)(" : ARRAY BITVECTOR(12) OF BITVECTOR(32)"); 
	    VG_(printf)(" = ");
	    cgPrintMachState(n_old_mach_state_instance); 

	
	    VG_(printf)(" WITH [0hex");
	    cgPrintHWord(arrayBase,3);
	    VG_(printf)("] := UNCONSTRAINED%x",
			n_old_mach_state_instance);
	    VG_(printf)(";\n"); 


	return; 
}

UInt cgExtractByte(HWord word, UInt byteno)
{
  switch (byteno)
    {
    case 4:
      return (word>>24); 
    case 3:
      return ((word<<8)>>24);
    case 2:
      return ((word<<16)>>24); 
    case 1:
      return ((word<<24)>>24); 
    default:
      return 0xFF;
    }
}

void cgEmitPutConstStmt_8bit (HWord putOffset, HWord putData, IRType ty)
{
	ULong n_old_mach_state_instance;
	HWord numBytes;
	HWord curOffset; 
	UInt curByte; 

	switch (ty)
	  {
	  case (Ity_I32):
	    numBytes = 4; 
	    break; 
	  case (Ity_I16):
	    numBytes = 2; 
	    break; 
	  case (Ity_I8):
	    numBytes = 1; 
	    break; 
	  default:
	    numBytes = 4;
	    if (ca_output_comment)
	    {
	      VG_(printf)("XXX Unhandled IRType in cgEmitPutConstStmt ");
	      ppIRType(ty); 
	      VG_(printf)(" \n"); 
	    }
	  break; 
	  }

	for (curOffset = putOffset; curOffset < putOffset+numBytes;curOffset++)
	  {
	    n_old_mach_state_instance = n_mach_state_instance;
	    n_mach_state_instance++;

	    cgPrintMachState(n_mach_state_instance); 
	    VG_(printf)(" : ARRAY BITVECTOR(12) OF BITVECTOR(8)"); 
	    VG_(printf)(" = ");
	    cgPrintMachState(n_old_mach_state_instance); 
	    //	VG_(printf)("WITH [0hex%x] := ", putOffset);  
	    VG_(printf)(" WITH [0hex");
	    cgPrintHWord(curOffset,3);
	    VG_(printf)("] := 0hex"); 
	    //        VG_(printf)(" 0hex%x", putData);
	    curByte = cgExtractByte(putData,(putOffset+numBytes - curOffset)); 
	    cgPrintHWord(curByte,2); 
	    VG_(printf)(";\n");
	  }
	return; 
}

void cgEmitPutConstStmt_32bit (HWord putOffset, HWord putData, IRType ty)
{
	ULong n_old_mach_state_instance;
	HWord numBytes;

	HWord arrayBase;
	HWord arrayOffset; 
	HWord assignHigh;
	HWord assignLow; 

	arrayOffset = putOffset % 4; 
	arrayBase = putOffset - arrayOffset; 


	switch (ty)
	  {
	  case (Ity_I32):
	    numBytes = 4; 
	    break; 
	  case (Ity_I16):
	    numBytes = 2; 
	    break; 
	  case (Ity_I8):
	    numBytes = 1; 
	    break; 
	  default:
	    numBytes = 4; 
	    if (ca_output_comment)
	    {
	      VG_(printf)("XXX Unhandled IRType in cgEmitPutConstStmt ");
	      ppIRType(ty); 
	      VG_(printf)(" \n");
	    }
	  break; 
	  }


	    n_old_mach_state_instance = n_mach_state_instance;
	    n_mach_state_instance++;


	    // The common case. Emit a direct update with constant. 
	    if (arrayOffset == 0 && numBytes == 4)
	      {
		cgPrintMachState(n_mach_state_instance); 
		VG_(printf)(" : ARRAY BITVECTOR(12) OF BITVECTOR(32)"); 
		VG_(printf)(" = ");
		cgPrintMachState(n_old_mach_state_instance); 
		//	VG_(printf)("WITH [0hex%x] := ", putOffset);  
		VG_(printf)(" WITH [0hex");
		cgPrintHWord(arrayBase,3);
		VG_(printf)("] := 0hex"); 
		//        VG_(printf)(" 0hex%x", putData);
		cgPrintHWord(putData,8); 
		VG_(printf)(";\n");
		
	      }
	    else
	      {
		// The annoying case - we are setting a subreg
		// to a constant value. Need to declare new tmp,
		// stitch together the appropriate value
		// and finally update with the new tmp. 

		// As a result will update with a tmp instead of
		// a constant value. This could be fixed with
		// some work, but it's not clear whether that
		// would be worth it. So I'll do it this way
		// first and see what the performance results are.


		// Compute range to assign putData
		assignHigh = 31 - (8*arrayOffset);
		assignLow = assignHigh - (8*numBytes) + 1;
		
		// Sanity check assertions
		vassert(assignHigh <= 31);
                vassert(assignHigh >= 7);
                vassert(assignLow >= 0);
                vassert(assignLow <= 24);

                // Declare new tmp
                VG_(printf)("SUBCONST%x",n_old_mach_state_instance);
                VG_(printf)(" : BITVECTOR(32);\n");


		// Set appropriate bytes equal to the data
                VG_(printf)("ASSERT(");
                VG_(printf)("SUBCONST%x",n_old_mach_state_instance);
                VG_(printf)("[%u:",assignHigh);
                VG_(printf)("%u]",assignLow);
		VG_(printf)(" = ");
		VG_(printf)("0hex"); 
		cgPrintHWord(putData,(numBytes*2)); 
		VG_(printf)(");\n"); 
		

		// Set remaining pieces equal to MaSt[arrayBase]
		if (assignHigh < 31)
		  {
		    VG_(printf)("ASSERT(");
		
		    VG_(printf)("SUBCONST%x",n_old_mach_state_instance); 
		    VG_(printf)("[31:%u]",(assignHigh+1));
		    VG_(printf)(" = ");
		    cgPrintMachState(n_old_mach_state_instance);
		    VG_(printf)("[0hex");
		    cgPrintHWord(arrayBase,3); 
		    VG_(printf)("]"); 
		    VG_(printf)("[31:%u]",(assignHigh+1));
		    VG_(printf)(");\n");  
		  }

		if (assignLow > 0)
		  {
		    VG_(printf)("ASSERT(");
		    VG_(printf)("SUBCONST%x",n_old_mach_state_instance); 
		    VG_(printf)("[%u:0]",(assignLow-1));
		    VG_(printf)(" = ");
		    cgPrintMachState(n_old_mach_state_instance);
		    VG_(printf)("[0hex");
		    cgPrintHWord(arrayBase,3); 
		    VG_(printf)("]"); 
		    VG_(printf)("[%u:0]",(assignLow-1));
		    VG_(printf)(");\n");  
		  }



	      }
	return; 
}

void cgEmitPutTmpStmt_32bit (HWord putOffset, HWord tagVal, HWord tmpName, IRType ty)
{
	ULong n_old_mach_state_instance;
	HWord numBytes;

	HWord arrayBase;
	HWord arrayOffset; 
	HWord assignHigh;
	HWord assignLow;

	arrayOffset = putOffset % 4; 
	arrayBase = putOffset - arrayOffset; 

	switch (ty)
	  {
	  case (Ity_I32):
	    numBytes = 4; 
	    break; 
	  case (Ity_I16):
	    numBytes = 2; 
	    break; 
	  case (Ity_I8):
	    numBytes = 1; 
	    break; 
	  default:
	    numBytes = 4; 
	    if (ca_output_comment)
	    {
	      VG_(printf)("XXX Unhandled IRType in cgEmitPutTmpStmt ");
	      ppIRType(ty); 
	      VG_(printf)(" \n"); 
	    }
	    break; 
	  }

	    n_old_mach_state_instance = n_mach_state_instance;
	    n_mach_state_instance++;


	    assignHigh = 31 - (8*arrayOffset);
	    assignLow = assignHigh - (8*numBytes) + 1;


	    // If PUT-ing less than 32 bits, need to declare
	    // a new 32 bit temp and stitch together the 
	    // src and current MaSt value. 
	    if (numBytes < 4)
	      {
		// Assert assignHigh and assignLow in sane range
		vassert(assignHigh <= 31);
		vassert(assignHigh >= 7);
		vassert(assignLow >= 0);
		vassert(assignLow <= 24);

		// Declare new tmp
		cgPrintTmpName(tmpName,tagVal); 
		VG_(printf)("SUBSET%x",n_old_mach_state_instance); 
		VG_(printf)(" : BITVECTOR(32);\n"); 

		// Set appropriate range equal to src tmp
		
		VG_(printf)("ASSERT(");
		cgPrintTmpName(tmpName,tagVal); 
		VG_(printf)("SUBSET%x",n_old_mach_state_instance); 
		VG_(printf)("[%u:",assignHigh);
		VG_(printf)("%u]",assignLow);
		VG_(printf)(" = ");
		cgPrintTmpName(tmpName,tagVal); 
		VG_(printf)("[%u:",assignHigh);
		VG_(printf)("%u]",assignLow);
		VG_(printf)(");\n");  

		// Set remaining pieces equal to MaSt[arrayBase]
		if (assignHigh < 31)
		  {
		    VG_(printf)("ASSERT(");
		    cgPrintTmpName(tmpName,tagVal); 
		    VG_(printf)("SUBSET%x",n_old_mach_state_instance); 
		    VG_(printf)("[31:%u]",(assignHigh+1));
		    VG_(printf)(" = ");
		    cgPrintMachState(n_old_mach_state_instance);
		    VG_(printf)("[0hex");
		    cgPrintHWord(arrayBase,3); 
		    VG_(printf)("]"); 
		    VG_(printf)("[31:%u]",(assignHigh+1));
		    VG_(printf)(");\n");  
		  }

		if (assignLow > 0)
		  {
		    VG_(printf)("ASSERT(");
		    cgPrintTmpName(tmpName,tagVal); 
		    VG_(printf)("SUBSET%x",n_old_mach_state_instance); 
		    VG_(printf)("[%u:0]",(assignLow-1));
		    VG_(printf)(" = ");
		    cgPrintMachState(n_old_mach_state_instance);
		    VG_(printf)("[0hex");
		    cgPrintHWord(arrayBase,3); 
		    VG_(printf)("]"); 
		    VG_(printf)("[%u:0]",(assignLow-1));
		    VG_(printf)(");\n");  
		  }


	      }
	    
	    
	    cgPrintMachState(n_mach_state_instance); 
	    VG_(printf)(" : ARRAY BITVECTOR(12) OF BITVECTOR(32)"); 
	    VG_(printf)(" = "); 
	    cgPrintMachState(n_old_mach_state_instance); 
	    VG_(printf)(" WITH [0hex"); 
	    cgPrintHWord(arrayBase,3); 
	    VG_(printf)("] := "); 
	    if (numBytes == 4)
	      {
		vassert(arrayOffset == 0); 
		cgPrintTmpName(tmpName,tagVal);
	      }
	    else
	      {
		cgPrintTmpName(tmpName,tagVal);
		VG_(printf)("SUBSET%x",n_old_mach_state_instance); 
	      }
	    VG_(printf)(";\n"); 
	  

	return; 
}      


void cgEmitStoreConstConst (HWord addr, HWord data)
{
  
	ULong n_old_mem_state_instance;
	caChunkTy * addrChunk; 
	HWord constSize; 
	HWord arraySize; 
	HWord addrOffset; 

	if (ca_mem_handling == CA_suppress_arrays)
	{
	  return; 
	}
	
	// Arrays supressed - forget about the following
	addrChunk = caAddrToChunk(addr,caIntervalTable);       
       
	if (addrChunk)
	  {
	    n_old_mem_state_instance = addrChunk->n_instance;
	    addrChunk->n_instance++; 
	    constSize = (addrChunk->regSize)/4;
	    arraySize = addrChunk->regSize; 
	    addrOffset = addr - addrChunk->baseAddr;
	  }
	else
	  {
	    n_old_mem_state_instance = n_mem_state_instance;
	    n_mem_state_instance++; 
	    constSize = 8; 
	    arraySize = 32; 
	    addrOffset = addr; 
	  }

      if (addrChunk)
	{
	  cgPrintMemRegionState(addrChunk->n_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_mem_state_instance); 
	  }

	VG_(printf)(" : ARRAY BITVECTOR(%u) OF BITVECTOR(32)", arraySize);
	VG_(printf)(" = "); 
	

      if (addrChunk)
	{
	  cgPrintMemRegionState(n_old_mem_state_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_old_mem_state_instance); 
	}

     
	VG_(printf)(" WITH [0hex");
	cgPrintHWord(addrOffset,constSize);
	VG_(printf)("] :=");
        VG_(printf)(" 0hex");
	cgPrintHWord(data,8); 
	VG_(printf)(";\n"); 
	
	return; 
}

void cgEmitStoreTmpConst (HWord addr, HWord addrTmp, HWord tagVal, HWord data)
{

	ULong n_old_mem_state_instance;
	caChunkTy * addrChunk;
	HWord arraySize;

	caChunkTy *theChunk;
	
	if (run_buffer_overflow_task == 1) {
	/* Buffer overflow checker */
	if (isMemSymbolicP(addr)) {
		/* Checking if the concrete address is in the current stack frame */
		theChunk = caAddrToChunk (addr, caIntervalTable);
		if (theChunk) {
			// upper bound
			VG_(printf)("XXX QUERY( BVLT( ");
			cgPrintTmpName (addrTmp, tagVal);
			VG_(printf)(" , ");
			VG_(printf)("%u", theChunk->baseAddr + theChunk->size);
			VG_(printf)(" ) ); \n");
			// lower bound
			VG_(printf)("XXX QUERY( BVLT( ");
			cgPrintTmpName (addrTmp, tagVal);
			VG_(printf)(" , ");
			VG_(printf)("%u", theChunk->baseAddr);
			VG_(printf)(" ) ); \n");
		}
		else {
			// emit a warning
			VG_(printf)("XXX WARNING the address %u was not in a chunk in the interval table", addr);
		}
	}
	}

	if (ca_mem_handling == CA_suppress_arrays)
	{
	  return; 
	}

	// Arrays supressed - forget about the following
	addrChunk = caAddrToChunk(addr,caIntervalTable);       

	if (addrChunk)
	  {
	    n_old_mem_state_instance = addrChunk->n_instance;
	    addrChunk->n_instance++; 
	    arraySize = addrChunk->regSize; 
	  }
	else
	  {
	    n_old_mem_state_instance = n_mem_state_instance;
	    n_mem_state_instance++; 
	    arraySize = 32; 
	  }



      if (addrChunk)
	{
	  cgEmitTmpOffsetConstraints(addrChunk,addrTmp,tagVal); 
	  cgPrintMemRegionState(addrChunk->n_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_mem_state_instance); 
	}

	VG_(printf)(" : ARRAY BITVECTOR(%u) OF BITVECTOR(32)",arraySize);
	VG_(printf)(" = "); 
	

      if (addrChunk)
	{
	  cgPrintMemRegionState(n_old_mem_state_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_old_mem_state_instance); 
	}
       
	VG_(printf)(" WITH [");
	cgPrintTmpName(addrTmp,tagVal);
	if (addrChunk) 
	  {
	    VG_(printf)("OFFSET");
	  }
	VG_(printf)(" ] := "); 
        VG_(printf)(" 0hex");
	cgPrintHWord(data,8); 
	VG_(printf)(";\n"); 
	return; 


}

void cgEmitStoreConstTmp(HWord addr, HWord tagVal, HWord dataTmp)
{
  ULong n_old_mem_state_instance;
  caChunkTy * addrChunk; 
  HWord arraySize; 
  HWord addrOffset; 
  HWord addrSize; 

  if (ca_mem_handling == CA_suppress_arrays)
  {
    return; 
  }

  // Arrays supressed, so ignore following
  addrChunk = caAddrToChunk(addr,caIntervalTable);       
  
  if (addrChunk)
    {
      n_old_mem_state_instance = addrChunk->n_instance;
      addrChunk->n_instance++; 
      arraySize = addrChunk->regSize; 
      addrSize = arraySize/4; 
      addrOffset = addr - addrChunk->baseAddr;
    }
  else
    {
      n_old_mem_state_instance = n_mem_state_instance;
      n_mem_state_instance++; 
      arraySize = 32; 
      addrSize = 8;
      addrOffset = addr; 
    }

	

      if (addrChunk)
	{
	  cgPrintMemRegionState(addrChunk->n_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_mem_state_instance); 
	}

	VG_(printf)(" : ARRAY BITVECTOR(%u) OF BITVECTOR(32)",arraySize);
	VG_(printf)(" = "); 
	

      if (addrChunk)
	{
	  cgPrintMemRegionState(n_old_mem_state_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_old_mem_state_instance); 
	}

 
	VG_(printf)(" WITH [0hex");
	cgPrintHWord(addrOffset,addrSize);
	VG_(printf)("] := ");

	cgPrintTmpName(dataTmp,tagVal); 
	VG_(printf)(";\n"); 
	return; 
} 

void cgEmitStoreTmpTmp(HWord addr, HWord addrTmp, HWord tagVal, HWord dataTmp)
{
  ULong n_old_mem_state_instance;
  caChunkTy * addrChunk; 
  HWord arraySize; 

  caChunkTy *theChunk;
  if (run_buffer_overflow_task == 1) {
  /* Buffer overflow checker */
  if (isMemSymbolicP(addr))
  {
	/* Checking if the concrete address is in the current stack frame */
	theChunk = caAddrToChunk (addr, caIntervalTable);
	if (theChunk) {
		// upper bound
		VG_(printf)("XXX QUERY( BVLT( ");
		cgPrintTmpName (addrTmp, tagVal);
		VG_(printf)(" , ");
		VG_(printf)("%u", theChunk->baseAddr + theChunk->size);
		VG_(printf)(" ) ); \n");
		// lower bound
		VG_(printf)("XXX QUERY( BVLT( ");
		cgPrintTmpName (addrTmp, tagVal);
		VG_(printf)(" , ");
		VG_(printf)("%u", theChunk->baseAddr);
		VG_(printf)(" ) ); \n");
	}
	else {
		// emit a warning
		VG_(printf)("XXX WARNING the address %u was not in a chunk in the interval table\n", addr);
  	}
  }
  }

  if (ca_mem_handling == CA_suppress_arrays)
  {
    return; 
  }

  // Arrays supressed - so ignore following
  addrChunk = caAddrToChunk(addr,caIntervalTable);       
  
  if (addrChunk)
    {
      n_old_mem_state_instance = addrChunk->n_instance;
      addrChunk->n_instance++; 
      arraySize = addrChunk->regSize; 
    }
  else
    {
      n_old_mem_state_instance = n_mem_state_instance;
      n_mem_state_instance++; 
      arraySize = 32; 
    }



      if (addrChunk)
	{
	  cgEmitTmpOffsetConstraints(addrChunk,addrTmp,tagVal); 
	  cgPrintMemRegionState(addrChunk->n_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_mem_state_instance); 
	}

	VG_(printf)(" : ARRAY BITVECTOR(%u) OF BITVECTOR(32)",arraySize);
	VG_(printf)(" = "); 
	

      if (addrChunk)
	{

	  cgPrintMemRegionState(n_old_mem_state_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_old_mem_state_instance); 
	}

 
  VG_(printf)(" WITH [");
  cgPrintTmpName(addrTmp,tagVal);
  if (addrChunk) VG_(printf)("OFFSET"); 
  VG_(printf)("] := ");
  cgPrintTmpName(dataTmp,tagVal); 
  VG_(printf)(";\n"); 
  return; 
}

void cgEmitStoreOrigin(HWord addr)
{

  return; 
}


void cgEmitStoreConstConcrete (HWord addr)
{
  
	ULong n_old_mem_state_instance;
	caChunkTy * addrChunk; 
	HWord constSize; 
	HWord arraySize; 
	HWord addrOffset; 
	HWord data;


	if (ca_mem_handling == CA_suppress_arrays)
	{
	  return; 
	}

	data = * (HWord *)(addr); 
        
	// Arrays supressed. Ignore following
	addrChunk = caAddrToChunk(addr,caIntervalTable);       

	if (addrChunk)
	  {
	    n_old_mem_state_instance = addrChunk->n_instance;
	    addrChunk->n_instance++; 
	    constSize = (addrChunk->regSize)/4;
	    arraySize = addrChunk->regSize; 
	    addrOffset = addr - addrChunk->baseAddr;
	  }
	else
	  {
	    n_old_mem_state_instance = n_mem_state_instance;
	    n_mem_state_instance++; 
	    constSize = 8; 
	    arraySize = 32; 
	    addrOffset = addr; 
	  }

      if (addrChunk)
	{
	  cgPrintMemRegionState(addrChunk->n_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_mem_state_instance); 
	}

	VG_(printf)(" : ARRAY BITVECTOR(%u) OF BITVECTOR(32)", arraySize);
	VG_(printf)(" = "); 
	

      if (addrChunk)
	{
	  cgPrintMemRegionState(n_old_mem_state_instance, addrChunk->baseAddr);
	}
      else
	{
	  cgPrintMemState(n_old_mem_state_instance); 
	}

	VG_(printf)(" WITH [0hex");
	cgPrintHWord(addrOffset,constSize);
	VG_(printf)("] :=");
        VG_(printf)(" 0hex");
	cgPrintHWord(data,8); 
	VG_(printf)(";\n"); 
	return; 
}


void cgSetJumpNotTaken(HWord tagVal)
{
  cgPathCondHashNode * jccNode;

  jccNode = VG_(HT_lookup)(cgPathCond,cgBBExecCounter); 
  if (jccNode)
  {
    jccNode->taken = NotTaken;
  }
  else if (ca_output_comment)
  {
    /* This is expected if the corresponding JUMPCOND is not tainted. */ 
    VG_(printf)("XXX Bogus jccNode at cgBBExecCounter %u \n",cgBBExecCounter); 
  }

}


void cgAddExitPost(IRSB * bb, IRStmt * s)
{
  IRDirty * d; 

  vassert(s->tag == Ist_Exit); 

  d = unsafeIRDirty_0_N(0,
			"cgSetJumpNotTaken",
			&cgSetJumpNotTaken,
			mkIRExprVec_1(
				      mkIRExpr_HWord(cgBBCounter)
				      )
			);

  setHelperAnns(d); 
  addStmtToIRSB(bb, IRStmt_Dirty(d)); 
  return; 
}

void cgEmitPathCond(void)
{
  cgPathCondHashNode * curJumpCond; 

  VG_(HT_ResetIter)(cgPathCond);
  
  for (curJumpCond = VG_(HT_Next)(cgPathCond); curJumpCond != NULL;
       curJumpCond = VG_(HT_Next)(cgPathCond))
    {

      /* Ignore path condition variables for non-tainted branches */ 
      if (! isJCSymbolicP(curJumpCond->BBCounter, 
			    curJumpCond->execCounter,
			    curJumpCond->condCounter))
     {
       continue; 
     }

      /* JumpCond is tainted */ 
      if (curJumpCond->taken == Taken)
	{

	  /* Emit QUERY if tainted */
	  /* Note STP attempts to falsify QUERY, so we make */
	  /* the QUERY in the "same direction" as observed JUMPCOND */
	  if (isJCSymbolicP(curJumpCond->BBCounter, 
			    curJumpCond->execCounter,
			    curJumpCond->condCounter))
	  {
	    VG_(printf)("XXX QUERY( "); 
	    VG_(printf)("JUMPCOND%d",curJumpCond->BBCounter);
	    VG_(printf)("e%d",curJumpCond->execCounter);
	    VG_(printf)("c%d ); %% TYPE Coverage \n",curJumpCond->condCounter);
	  }

	  VG_(printf)("ASSERT( "); 
	  VG_(printf)("JUMPCOND%d",curJumpCond->BBCounter);
	  VG_(printf)("e%d",curJumpCond->execCounter);
	  VG_(printf)("c%d );\n",curJumpCond->condCounter);

	}
      else if (curJumpCond->taken == NotTaken)
	{	  

	  /* Emit QUERY if tainted */
	  if (isJCSymbolicP(curJumpCond->BBCounter, 
			    curJumpCond->execCounter,
			    curJumpCond->condCounter))
	  {
	    VG_(printf)("XXX QUERY(NOT "); 
	    VG_(printf)("JUMPCOND%d",curJumpCond->BBCounter);
	    VG_(printf)("e%d",curJumpCond->execCounter);
	    VG_(printf)("c%d ); %% TYPE Coverage \n",curJumpCond->condCounter);
	  }

	  VG_(printf)("ASSERT(NOT "); 
	  VG_(printf)("JUMPCOND%d",curJumpCond->BBCounter);
	  VG_(printf)("e%d",curJumpCond->execCounter);
	  VG_(printf)("c%d );\n",curJumpCond->condCounter);


	}
      else 
	{
	  VG_(printf)("XXX Bogus pathcond node: ");
	  VG_(printf)("JUMPCOND%d",curJumpCond->BBCounter);
	  VG_(printf)("e%d",curJumpCond->execCounter);
	  VG_(printf)("c%d \n",curJumpCond->condCounter);
	}
    }

}



void cgEmitExitTmpConstraints(HWord tmpName, HWord tagVal, HWord condVal, HWord destAddr)
{

  HWord tmpSymbolicP; 

  /* Declares JUMPCOND for appropriate BB  */ 

  cgPathCondHashNode * newPCnode; 

  newPCnode = (cgPathCondHashNode *)VG_(malloc)("pathCondHashNode", sizeof(cgPathCondHashNode)); 
  newPCnode->key = cgBBExecCounter;
  newPCnode->BBCounter = tagVal;
  newPCnode->execCounter = cgBBExecCounter; 
  newPCnode->condCounter = cgJCCounter; 
  newPCnode->taken = Taken; // If NT, will be reversed by
                            // following IR instruction, as in
                            // Lackey 




  /* Flow symbolic from tmp to jumpcond var or clear if needed */ 

  tmpSymbolicP = isTmpSymbolicP(tagVal, tmpName); 
  if (tmpSymbolicP)
  {

    if (ca_output_comment)
    {
      VG_(printf)("XXX set "); 
      VG_(printf)("JUMPCOND%d",tagVal);
      VG_(printf)("e%d",cgBBExecCounter);
      VG_(printf)("c%d symbolic \n",cgJCCounter);
    }

    // add PID and TID here ?
    VG_(printf)("JUMPCOND%d",tagVal);
    VG_(printf)("e%d",cgBBExecCounter);
    VG_(printf)("c%d : BOOLEAN;\n",cgJCCounter);

    VG_(HT_add_node)(cgPathCond, newPCnode); 
    isSetJCSymbolic(tagVal, cgBBExecCounter, cgJCCounter); 

  }
  else
  {
    /* Do not emit constraint for untainted JUMPCOND. */
    /* Reclaim memory for path condition node. */ 
    VG_(free)(newPCnode); 
    return;
  }

  // Declare temporary if not previously declared. 
  cgDeclareTmpAtRunIfUndeclared(tagVal, tmpName, Ity_I1); 
  
  VG_(printf)("ASSERT(");
  cgPrintTmpName(tmpName,tagVal);
  VG_(printf)(" <=> "); 
  VG_(printf)("JUMPCOND%d",tagVal);
  VG_(printf)("e%d",cgBBExecCounter);
  VG_(printf)("c%d);\n",cgJCCounter);
 
  /* Emit inline path query if desired. Note we don't know at this time */ 
  /* whether the jump will be taken or not.                             */
  /* For now emit QUERYs for both directions when jump not taken        */
  /* and let STP sort it out.                                           */
  /* TODO: fix this and emit only one QUERY.                            */
  /* TODO: fix problem where we don't know which ASSERT to emit for     */
  /* direction of JUMPCOND for same reason.                             */

  if (inlinePathQueriesP)
  {
    VG_(printf)("ASSERT("); 
    if (condVal == 0)
    {
      VG_(printf)(" NOT "); 
    }
    VG_(printf)("JUMPCOND%d",newPCnode->BBCounter);
    VG_(printf)("e%d",newPCnode->execCounter);
    VG_(printf)("c%d);\n",newPCnode->condCounter);

    /* Emit QUERY if tainted */
    if (isJCSymbolicP(newPCnode->BBCounter, 
		      newPCnode->execCounter,
		      newPCnode->condCounter))
      {
	VG_(printf)("XXX QUERY("); 
	if (condVal == 0)
	{
	  VG_(printf)(" NOT "); 
	}
	VG_(printf)("JUMPCOND%d",newPCnode->BBCounter);
	VG_(printf)("e%d",newPCnode->execCounter);
	VG_(printf)("c%d ); %% TYPE Coverage ",newPCnode->condCounter);
	VG_(printf)("XXX The destAddr = 0x%x ;\n",destAddr);
      }
  }

  cgJCCounter++; 
}

void cgEmitStoreInfo(HWord addr )
{
  HWord value;
  caChunkTy * addrChunk;

  value = *((HWord *)addr);


  if (ca_output_comment)
  {
      VG_(printf)("XXX StoreAddr %x ", addr); 
      VG_(printf)("Value %x ", value); 
  
      // MEMORY 
      /*
	addrChunk = caAddrToChunk(addr,caIntervalTable); 
      if (addrChunk)
      {
	VG_(printf)("RegionBase %x \n", addrChunk->baseAddr); 
      }
      else
      {
	VG_(printf)("BOGUSCHUNK \n");
	}
      */
  }
  return; 
}

void cgEmitStoreInfoByte(HWord addr )
{
  UChar value;
  caChunkTy * addrChunk;

  value = *((UChar *)addr);


  if (ca_output_comment)
  {
    VG_(printf)("XXX StoreAddr %x ", addr); 
    VG_(printf)("Value %x ", value); 

  addrChunk = caAddrToChunk(addr,caIntervalTable); 
  if (addrChunk)
    {
      VG_(printf)("RegionBase %x \n", addrChunk->baseAddr); 
    }
  else
    {
      VG_(printf)("BOGUSCHUNK \n");
    }
  }

  return; 

}

/* ---- Add statement to BB functions ---- */ 

void cgAddPreamble(IRSB * bb, HWord cntVal)
{
  IRDirty * d = NULL;
  IRDirty * d2 = NULL; 
  IRTypeEnv * tyenv;
  
  if (cntVal == 0)
    {
      d = unsafeIRDirty_0_N(0,
			"cgEmitPreamble",
			&cgEmitPreamble,
			mkIRExprVec_0()
			);
  setHelperAnns(d);
  addStmtToIRSB(bb,IRStmt_Dirty(d)); 
    }
  
  d2 = unsafeIRDirty_0_N(0,
			 "cgIncExecCounter",
			 &cgIncExecCounter,
			 mkIRExprVec_0()
			 );
  setHelperAnns(d2); 
  addStmtToIRSB(bb,IRStmt_Dirty(d2)); 

  tyenv = bb->tyenv; 
  vassert(tyenv); 



  /* Previously declared all temp vars at the beginning of each basic block. */
  /* Removed to focus on declaring only temp vars actually used. */ 
  /* Declaring only as used requires more helper functions but dramatically */
  /* reduces the size of the input to STP. */ 
}

void cgAddStoreStmtConstraints(IRSB * bb, IRStmt * s)
{
  IRExpr * addr;
  IRExpr * rhs; 
  IRDirty * d;
  IRDirty * d2;

  HWord rhsHword = 0xDEADBEEF; 
  HWord addrHword = 0xBEEFBEEF;
  vassert(s);
  vassert(bb); 
  vassert(s->tag == Ist_Store); 

  addr = s->Ist.Store.addr; 
  rhs = s->Ist.Store.data; 

  if (ca_mem_handling == CA_suppress_arrays)
  {
    /* We are suppressing array output. No need for store instrumentation. */
    return; 
  }


  switch (addr->tag)
    {
    case (Iex_RdTmp):
	  switch (rhs->tag)
	    {
	    case (Iex_RdTmp):
	      
	      vassert(addr->tag == Iex_RdTmp);
	      vassert(rhs->tag == Iex_RdTmp); 
	      addrHword = (HWord)addr->Iex.RdTmp.tmp;
	      rhsHword = (HWord)rhs->Iex.RdTmp.tmp;
  //	   void cgEmitStoreTmpTmp(HWord addrTmp, HWord tagVal, HWord dataTmp)
	      d = unsafeIRDirty_0_N(0,
				    "cgEmitStoreTmpTmp",
				    &cgEmitStoreTmpTmp,
				    mkIRExprVec_4(addr,
						  mkIRExpr_HWord(addrHword),
						  mkIRExpr_HWord(cgBBCounter),
						  mkIRExpr_HWord(rhsHword)
						  )
				    );
	      setHelperAnns(d); 
	      addStmtToIRSB(bb,IRStmt_Dirty(d));


	      d2 = unsafeIRDirty_0_N(0,
				     "cgEmitStoreInfo",
				     &cgEmitStoreInfo,
				     mkIRExprVec_1(addr)
				     );
	      setHelperAnns(d2); 
	      addStmtToIRSB(bb,IRStmt_Dirty(d2)); 
	      break; 

	    case (Iex_Const):

	      vassert(addr->tag == Iex_RdTmp); 
	      vassert(rhs->tag == Iex_Const);
	      addrHword = (HWord)addr->Iex.RdTmp.tmp; 
	      rhsHword = cgConstToHword(rhs); 

	      d = unsafeIRDirty_0_N(0,
				    "cgEmitStoreTmpConst",
				    &cgEmitStoreTmpConst, 
				    mkIRExprVec_4(addr, 
						  mkIRExpr_HWord(addrHword),
						  mkIRExpr_HWord(cgBBCounter),
						  mkIRExpr_HWord(rhsHword)
						  )
				    );
	      setHelperAnns(d); 
	      addStmtToIRSB(bb,IRStmt_Dirty(d)); 

	      d2 = unsafeIRDirty_0_N(0,
				     "cgEmitStoreInfo",
				     &cgEmitStoreInfo,
				     mkIRExprVec_1(addr)
				     );
	      setHelperAnns(d2); 
	      addStmtToIRSB(bb,IRStmt_Dirty(d2)); 

	      break; 
	    default:
	      if (ca_output_comment)
	      {
		VG_(printf)(" XXX Unhandled store rhs tag (addr is tmp) ");
		ppIRStmt(s); 
		VG_(printf)("\n"); 
	      }
	      break; 
	    }
	  break; 
	  
    case (Iex_Const):

      switch (rhs->tag)
	{
	case (Iex_RdTmp):
	  vassert(addr->tag == Iex_Const); 
	  vassert(rhs->tag == Iex_RdTmp); 
	  
	  addrHword = cgConstToHword(addr); 
	  rhsHword = (HWord) rhs->Iex.RdTmp.tmp; 
	  d = unsafeIRDirty_0_N(0,
				"cgEmitStoreConstTmp",
				&cgEmitStoreConstTmp,
				    mkIRExprVec_3(mkIRExpr_HWord(addrHword),
						  mkIRExpr_HWord(cgBBCounter),
						  mkIRExpr_HWord(rhsHword)
						  )
				);
	  setHelperAnns(d); 
	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 

	      d2 = unsafeIRDirty_0_N(0,
				     "cgEmitStoreInfo",
				     &cgEmitStoreInfo,
				     mkIRExprVec_1(addr)
				     );
	      setHelperAnns(d2); 
	      addStmtToIRSB(bb,IRStmt_Dirty(d2)); 


	  break;
	case(Iex_Const):
	  vassert(addr->tag == Iex_Const); 
	  vassert(rhs->tag == Iex_Const); 

	  // helper function that takes IRconst and returns HWord 
	  addrHword = cgConstToHword(addr); 
	  rhsHword = cgConstToHword(rhs); 
	  //void cgEmitStoreConstConst (HWord addr, HWord data)	
	  d = unsafeIRDirty_0_N(0, 
				  "cgEmitStoreConstConst",
				  &cgEmitStoreConstConst,
				  mkIRExprVec_2(mkIRExpr_HWord(addrHword),
						mkIRExpr_HWord(rhsHword)
						)
				  );
	  setHelperAnns(d); 
	  addStmtToIRSB(bb, IRStmt_Dirty(d)); 

	      d2 = unsafeIRDirty_0_N(0,
				     "cgEmitStoreInfo",
				     &cgEmitStoreInfo,
				     mkIRExprVec_1(addr)
				     );
	      setHelperAnns(d2); 
	      addStmtToIRSB(bb,IRStmt_Dirty(d2)); 
				  
	  break; 
	default:
	  if (ca_output_comment)
	  {
	    VG_(printf)(" XXX Unhandled store rhs tag (addr is const) ");
	    ppIRStmt(s); 
	    VG_(printf)("\n");
	  } 
	  break; 
	}
      break; 

    case(Iex_Binder):
      if (ca_output_comment)
      {
	VG_(printf)("XXX addr tag is Iex_binder in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n"); 
      }
      break;

    case(Iex_Get):
      if (ca_output_comment)
      {
      VG_(printf)("XXX addr tag is Iex_Get in store statement ");
      ppIRStmt(s); 
      VG_(printf)("\n"); 
      }
      break;

    case(Iex_GetI):
      if (ca_output_comment)
      {      
	VG_(printf)("XXX addr tag is Iex_GetI in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n"); 
      }
      break;
      
    case(Iex_Binop):
      if (ca_output_comment)
      {
	VG_(printf)("XXX addr tag is Iex_binop in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n"); 
      }
      break;

    case(Iex_Unop):
      if (ca_output_comment)
      {
	VG_(printf)("XXX addr tag is Iex_unop in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n");
      } 
      break;

    case(Iex_Load):
      if (ca_output_comment)
      {
	VG_(printf)("XXX addr tag is Iex_Load in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n");
      } 
      break;

    case(Iex_Mux0X):
      if (ca_output_comment)
      {
	VG_(printf)("XXX addr tag is Iex_Mux0X in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n");
      } 
      break;
      
    case(Iex_CCall):
      if (ca_output_comment)
      {
	VG_(printf)("XXX addr tag is Iex_CCall in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n");
      } 
      break;




    default:
      if (ca_output_comment)
      {
	VG_(printf)(" XXX Unhandled addr tag in store statement ");
	ppIRStmt(s); 
	VG_(printf)("\n");
      } 
      break; 
    }


  // Add instrumentation function to show the address stored

  return; 
}

IRType cgConstToIRType(IRExpr * rhs)
{

  return Ity_I32; 
}

void cgAddPutStmtConstraints(IRSB * bb, IRStmt * s)
{
  IRExpr * rhs;
  HWord putOffset;
  HWord tmpname; 
  HWord rhsval; 
  IRType assignty; 
  IRDirty * d; 
  void * cgEmitPutTmpStmtPtr; 
  void * cgEmitPutConstStmtPtr; 

  vassert(s); 
  vassert(bb); 
  vassert(s->tag == Ist_Put); 

  putOffset = s->Ist.Put.offset; 
  rhs = s->Ist.Put.data; 

  if (ca_mem_handling == CA_suppress_arrays)
  {
    /* We are suppressing array output. No need for put instrumentation. */
    return; 
  }



  cgEmitPutTmpStmtPtr = &cgEmitPutTmpStmt_32bit; 
  cgEmitPutConstStmtPtr = &cgEmitPutConstStmt_32bit;

  switch (rhs->tag)
    {
    case (Iex_RdTmp):

      tmpname = (HWord) rhs->Iex.RdTmp.tmp;
      assignty = bb->tyenv->types[tmpname]; 
      // void cgEmitPutTmpStmt (HWord putOffset, HWord tagVal, HWord tmpName)
      d = unsafeIRDirty_0_N(0,
			    "cgEmitPutTmpStmt",
			    cgEmitPutTmpStmtPtr,
			    mkIRExprVec_4(mkIRExpr_HWord(putOffset),
					  mkIRExpr_HWord(cgBBCounter),
					  mkIRExpr_HWord(tmpname),
					  mkIRExpr_HWord(assignty)
					  )
			    );
      setHelperAnns(d);
      addStmtToIRSB(bb,IRStmt_Dirty(d)); 
      break; 
    case (Iex_Const):
      // void cgEmitPutConstStmt (HWord putOffset, HWord putData)

      rhsval = cgConstToHword(rhs); /* Otherwise leads to VEX error */
                                    /* when const not I32 or I64    */

      assignty = cgConstToIRType(rhs); 


      d = unsafeIRDirty_0_N(0,
			    "cgEmitPutConstStmt",
			    cgEmitPutConstStmtPtr,
			    mkIRExprVec_3(mkIRExpr_HWord(putOffset),
					  mkIRExpr_HWord(rhsval),
					  mkIRExpr_HWord(assignty)
					  )
			    ); 
      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d));
      break; 
    default:
      if (ca_output_comment)
      {
	VG_(printf)(" XXX cgAddPutStmtConstraints ");
	ppIRStmt(s); 
	VG_(printf)("\n");  
      }
      break; 

    }
  return; 
}


void cgEmitTmpGetConstraints_32bit(HWord offset, 
				   HWord tmpname, 
				   HWord tagVal, 
				   IRType ty,
				   HWord tmpval)
{
  HWord numBytes; 

  HWord arrayBase;
  HWord arrayOffset; 
  HWord assignHigh;
  HWord assignLow; 
  TmTypeOfHashNode * tmNode = NULL; 
  HWord tmpSymbolicP; 

  arrayOffset = offset % 4; 
  arrayBase = offset - arrayOffset;  

  if (ca_output_comment)
  {
    VG_(printf)("XXX cgEmitTmpGetConstraints offset: %d", offset); 
    VG_(printf)(" arrayOffset: %d", arrayOffset); 
    VG_(printf)(" arrayBase: %d \n", arrayBase); 
  }


  tmpSymbolicP = isTmpSymbolicP(tagVal, tmpname); 

    if (tmpSymbolicP)
    {

      	// Declare temp if not previously declared
	cgDeclareTmpAtRunIfUndeclared(tagVal, tmpname, ty); 

	if (ca_output_comment)
	{
	  VG_(printf)("XXX TAINTED GET \n"); 
	}

      if (ca_mem_handling == CA_suppress_arrays)
      {
        tmNode = VG_(HT_lookup)(tmAddrToVar, offset);
        if (!tmNode)
        {
          VG_(printf)("XXX BOGUS GET BEFORE PUT\n");
          return;
        }
        else
        {
	  if (ca_output_comment)
	  {
	    VG_(printf)("XXX SUPPRESSED GET \n");
	  }
	}
      }

	switch (ty)
	  {
	  case (Ity_I32):
	    numBytes = 4; 
	    break; 
	  case (Ity_I16):
	    numBytes = 2; 
	    break; 
	  case (Ity_I8):
	    numBytes = 1; 
	    break; 
	  default:
	    numBytes = 4; 
	    VG_(printf)("XXX Unhandled IRType in cgEmitTmpGetConstraints_32bit ");
	  ppIRType(ty); 
	  VG_(printf)(" \n"); 
	  break; 
	  }

	/* Arrays are 0-indexed, offsets are in bytes */ 
	assignHigh = (arrayOffset*8)+7; 
	assignLow = arrayOffset*8; 


      if (ca_mem_handling == CA_suppress_arrays && tmNode != NULL)
      {

	/* Strictly speaking the variable should have been declared */
	/* earlier, ahead of the PUT which set the register value to */
	/* tmNode->var . Unfortunately it can happen due to unhandled ops */
	/* that this is the first time we declare a new variable. */ 
	VG_(printf)("XXX e: %d t: %d\n", tmNode->var.e, tmNode->var.t); 
	cgDeclareTmpVarTyIfUndeclared(tmNode->var, ty); 
      }



      if (ca_output_comment)
      {
	VG_(printf)("XXX cgEmitTmpGetConstraints assignHigh: %d", assignHigh); 
	VG_(printf)(" assignLow: %d \n", assignLow); 
      }
  
      // ASSERT ( CV$tagValt$tmpname = MachState$i[$offset]) 
      VG_(printf)("ASSERT("); 
      cgPrintTmpName(tmpname,tagVal); 
      if (numBytes < 4)    /* XXX Needs to change for 64-bit! */
      {
	  if (assignLow > 24)
	  {
	      VG_(printf)("assignLow: %d numBytes: %d offset: %d", assignLow, numBytes, arrayOffset ); 
	  }
	  vassert(assignHigh <= 31);
	  vassert(assignHigh >= 7); 
	  vassert(assignLow >= 0); 
	  vassert(assignLow <= 24);
	  VG_(printf)("[%u:",assignHigh); 
	  VG_(printf)("%u]",assignLow); 
	}

      VG_(printf)(" = "); 

      if (ca_mem_handling == CA_suppress_arrays && tmNode != NULL)
      {
	cgPrintTmpVarTy(tmNode->var);
      }
      else
      {
      cgPrintMachState(n_mach_state_instance); 
      VG_(printf)("[0hex");
      cgPrintHWord(arrayBase,3);
      VG_(printf)("]");
      }

      if (numBytes < 4) /* XXX Needs to change for 64-bit! */ 
      {
	vassert(assignHigh <= 31);
	vassert(assignHigh >= 7); 
	vassert(assignLow >= 0); 
	vassert(assignLow <= 24);
	VG_(printf)("[%u:",assignHigh); 
	VG_(printf)("%u]",assignLow); 
      }
        VG_(printf)(" );\n"); 
      }
      
  return; 
}

void cgSetMemDeclared(HWord loadAddr, HWord offset)
{
  cgIsDeclaredHashNode * newNode; 
  HWord key; 

  // If already declared, then no need to re-set.
  if (cgMemDeclaredP(loadAddr, offset))
  {
    return; 
  }

  key = locToHashKey(loadAddr, 0, MemLoc); 
  newNode = VG_(malloc)("isDeclaredHashNode",sizeof(cgIsDeclaredHashNode)); 
  newNode->key = key;
  newNode->addr = loadAddr; 
  newNode->offset = offset;
  newNode->tmpName = 0; 
  newNode->transBB = 0; 
  newNode->execBB = 0; 

  VG_(HT_add_node)(cgIsDeclared,newNode); 
  return; 
}

void cgSetTmpWideDeclared(
			  HWord tmpName, 
			  HWord transBB, 
			  HWord execBB
			  )
{
  cgIsDeclaredHashNode * newNode; 
  HWord key; 

  // If already declared, then no need to re-set.
  if (cgTmpWideIsDeclaredP(tmpName, transBB, execBB))
  {
    return; 
  }

  key = nameToHashKey(tmpName, transBB, execBB); 
  newNode = VG_(malloc)("isDeclaredHashNode", sizeof(cgIsDeclaredHashNode)); 
  newNode->key = key;
  newNode->tmpName = tmpName; 
  newNode->transBB = transBB;
  newNode->execBB = execBB; 
  newNode->addr = 0; 
  newNode->offset = 0;

  VG_(HT_add_node)(cgIsDeclaredWide,newNode); 
  return; 
}

void cgSetTmpDeclared(HWord tmpName, HWord transBB, HWord execBB)
{
  cgIsDeclaredHashNode * newNode; 
  HWord key; 

  // If already declared, then no need to re-set.
  if (cgTmpIsDeclaredP(tmpName, transBB, execBB))
  {
    return; 
  }

  key = nameToHashKey(tmpName, transBB, execBB); 
  newNode = VG_(malloc)("isDeclaredHashNode",sizeof(cgIsDeclaredHashNode)); 
  newNode->key = key;
  newNode->tmpName = tmpName; 
  newNode->transBB = transBB;
  newNode->execBB = execBB; 
  newNode->addr = 0; 
  newNode->offset = 0;

  VG_(HT_add_node)(cgIsDeclared,newNode); 
  return; 
}

Bool cgMemDeclaredP(HWord loadAddr, HWord offset)
{
  cgIsDeclaredHashNode * node;
  HWord key; 
  HWord ret; 

  key = locToHashKey(loadAddr,0, MemLoc);
  node = VG_(HT_lookup)(cgIsDeclared,key);
  ret = 0; 

  while (node != NULL)
  {
    if (node->addr == loadAddr &&
	node->offset == offset)
    {
      ret = 1;
      break; 
    }
    else
    {
      node = node->next; 
    }
  }
  return ret; 
}

Bool cgTmpWideIsDeclaredP(HWord tmpName, HWord transBB, HWord execBB)
{
  cgIsDeclaredHashNode * node;
  HWord key; 
  HWord ret = 0; 
  key = nameToHashKey(tmpName, transBB, execBB); 
  node = VG_(HT_lookup)(cgIsDeclaredWide,key);

  while (node != NULL)
  {
    if (node->tmpName == tmpName && 
	node->transBB == transBB &&
	node->execBB == execBB)
    {
	ret = 1;
	break; 
    }
    else
    {
      node = node->next; 
    }
  }
  return ret; 
}

Bool cgTmpIsDeclaredP(HWord tmpName, HWord transBB, HWord execBB)
{
  cgIsDeclaredHashNode * node;
  HWord key; 
  HWord ret = 0; 
  key = nameToHashKey(tmpName, transBB, execBB); 
  node = VG_(HT_lookup)(cgIsDeclared,key);

  while (node != NULL)
  {
    if (node->tmpName == tmpName && 
	node->transBB == transBB &&
	node->execBB == execBB)
    {
	ret = 1;
	break; 
    }
    else
    {
      node = node->next; 
    }
  }
  return ret; 
}

HWord nameToHashKey(HWord tmpName, HWord BBcounter, HWord execounter)
{
  // XXX revisit this later - almost certainly has collisions!
  return (BBcounter << 25 | execounter << 8 | tmpName); 

}

void cgEmitTmpOffsetConstraints(caChunkTy * addrChunk, HWord tmpName, HWord tagVal)
{
  HWord constSize;
  vassert(addrChunk);

	  /* Declare and compute offset, emit query */ 

	  /* Declare if not already declared */ 

  if (!cgTmpIsDeclaredP(tmpName,tagVal,cgBBExecCounter))
    {
          cgDeclareTmpAtRunIfUndeclared(tagVal, tmpName, Ity_I32); 
	  cgPrintTmpName(tmpName,tagVal);
	  VG_(printf)("OFFSET");
	  VG_(printf)(" : BITVECTOR(%u);\n",addrChunk->regSize); 
	  cgSetTmpDeclared(tmpName,tagVal,cgBBExecCounter);
    }

	  /* Compute */ 
	  constSize = (addrChunk->regSize)/4;

	  VG_(printf)("ASSERT("); 
	  cgPrintTmpName(tmpName,tagVal);
	  VG_(printf)("OFFSET");
	  VG_(printf)(" = ");
	  VG_(printf)("BVSUB(32,"); 
	  cgPrintTmpName(tmpName,tagVal);
	  VG_(printf)(",0hex");
	  cgPrintHWord(addrChunk->baseAddr,8); 
	  VG_(printf)(")[%u:0]);\n",(addrChunk->regSize-1)); 

	  /* Emit in-range query -- commented out */ 
	  VG_(printf)("XXX BQ(BVLE( ");
	  cgPrintTmpName(tmpName,tagVal);
	  VG_(printf)("OFFSET");
	  VG_(printf)(" , ");
	  cgPrintHWord(addrChunk->size,constSize);
	  VG_(printf)(" ));\n"); 

}

void cgEmitTmpLoadTmpConstraints(HWord loadAddr, HWord rhstmp, HWord lhstmp, HWord tagVal, IRType assignTy)
{
  // ASSERT (CVXtY = MemState[rhstmp])
  caChunkTy * addrChunk; 
  TmTypeOfHashNode * tmNode; 
  OffT offset; 
  HWord tmNodeOffset; 
  HWord numBytes; 
  HWord assignHigh, assignLow; 
  HWord assignHighLHS, assignLowLHS; 
 
  caChunkTy *theChunk;

  if (ca_output_comment)
  {
    VG_(printf)("XXX cgEmitTmpLoadTmpConstraints loadAddr: %x, rhstmp: %u, lhstmp:%u, tagVal: %u, IRType: %u \n",loadAddr, rhstmp, lhstmp, tagVal, assignTy); 
  }
  

 if (run_buffer_overflow_task == 1) 
 {
   /* Buffer overflow check */
   if (isMemSymbolicP(loadAddr))
   {
	/* Checking if the concrete address is in the current stack frame */
	theChunk = caAddrToChunk (loadAddr, caIntervalTable);
	if (theChunk) {
		// upper bound
		VG_(printf)("XXX QUERY( BVLT( ");
		cgPrintTmpName (rhstmp, tagVal);
		VG_(printf)(" , ");
		VG_(printf)("%u", theChunk->baseAddr + theChunk->size);
		VG_(printf)(" ) ); \n");

		// lower bound
		VG_(printf)("XXX QUERY( BVLT( ");
		cgPrintTmpName (rhstmp, tagVal);
		VG_(printf)(" , ");
		VG_(printf)("%u", theChunk->baseAddr);
		VG_(printf)(" ) ); \n");
	}
	else {
		// emit a warning
		VG_(printf)("XXX WARNING the address %u was not in a chunk in the interval table", loadAddr);
	}
   }
 }

  if (isMemOriginP(loadAddr, &offset))
  {
      cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, assignTy); 
      cgDeclareTmpAtRunIfUndeclared(tagVal, rhstmp, assignTy); 
      if (ca_output_comment)
      {
	VG_(printf)("XXX ORIGIN LOAD \n"); 
      }

      if (!cgMemDeclaredP(loadAddr, offset))
      {
	VG_(printf)("INPUT_MEM%x_",loadAddr);
	VG_(printf)("OFFSET%x",offset); 
	VG_(printf)(" : BITVECTOR(32);\n"); 
	cgSetMemDeclared(loadAddr, offset); 
      }

      VG_(printf)("ASSERT("); 
      cgPrintTmpName(lhstmp,tagVal);
      if (assignTy == Ity_I64)
	VG_(printf)("[31:0]"); 
      VG_(printf)(" = "); 
      
      VG_(printf)("INPUT_MEM%x_",loadAddr);
      VG_(printf)("OFFSET%x",offset); 
      VG_(printf)(" );\n"); 
  }
  else if (isMemSymbolicP(loadAddr)) 
  {

      cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, assignTy); 
      cgDeclareTmpAtRunIfUndeclared(tagVal, rhstmp, assignTy); 

      if (ca_output_comment)
      {
	VG_(printf)("XXX TAINTED LOAD loadAddr %x \n", loadAddr);
      } 
      if (ca_mem_handling == CA_suppress_arrays)
      {
	tmNode = VG_(HT_lookup)(tmAddrToVar,loadAddr);
	if (!tmNode)
        {
	  VG_(printf)("XXX BOGUS LOAD BEFORE STORE loadAddr %x \n", loadAddr); 
	  return; 
        }
	else
        {
	  cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, assignTy); 
	  cgDeclareTmpAtRunIfUndeclared(tagVal, rhstmp, assignTy); 
	  cgDeclareTmpVarTyIfUndeclared(tmNode->var, assignTy); 

	  /* XXX TOADD: deal with case of overlapping tmps in memory */
	  if (ca_output_comment)
	  {
	    VG_(printf)("XXX SUPPRESSED LOAD \n"); 
	  }

	  tmNodeOffset = tmNode->offset;
	  numBytes = numBytesOfType(assignTy);

	  /* tmNodeOffset ranges from 0 to 3 */
	  /* numBytes ranges from 1 to 4     */ 
	  assignLow = ((tmNodeOffset)*8);
	  assignHigh = (assignLow + (numBytes*8))-1;  
	  assignLowLHS = 0; 
	  assignHighLHS = (numBytes*8)-1; 


	  VG_(printf)("ASSERT( ");  
	  cgPrintTmpName(lhstmp,tagVal);
	  VG_(printf)("[%d:%d]", assignHighLHS, assignLowLHS); 
	  VG_(printf)(" = ");
	  cgPrintTmpVarTy(tmNode->var); 
	  VG_(printf)("[%d:%d]", assignHigh, assignLow); 
	  VG_(printf)(" );\n"); 
        }
      }
      else
      {
	// NOT GOING TO BE REACHED
	addrChunk = caAddrToChunk(loadAddr,caIntervalTable);       
      

	if (addrChunk)
	{
	  cgEmitTmpOffsetConstraints(addrChunk,rhstmp,tagVal); 
	}

	VG_(printf)("ASSERT(");
	cgPrintTmpName(lhstmp,tagVal); 
	if (assignTy == Ity_I64)
	  VG_(printf)("[31:0]"); 
	VG_(printf)(" = ");
	

	if (addrChunk)
	{
	  cgPrintMemRegionState(addrChunk->n_instance, addrChunk->baseAddr);
	}
	else
	{
	  cgPrintMemState(n_mem_state_instance); 
	}


      VG_(printf)("["); 
      
      if (addrChunk)
	{
	  cgPrintTmpName(rhstmp,tagVal);
	  VG_(printf)("OFFSET"); 
	}

      else
	{
	  cgPrintTmpName(rhstmp,tagVal);
	}
      VG_(printf)("]);\n", rhstmp); 
      }   
  }
  else
  {
    if (ca_output_comment)
    {
      VG_(printf)("XXX NON-SYMBOLIC LOAD ADDRESS %x \n", loadAddr); 
    }
  }
  return; 
}


void cgEmitTmpAssignSymbolic(HWord lhstmp, 
			     HWord tagVal, 
			     HWord ty, 
			     HWord rhstmp)
{

  cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, ty); 
  cgDeclareTmpAtRunIfUndeclared(tagVal, rhstmp, ty); 

   VG_(printf)("ASSERT("); 
   cgPrintTmpName(lhstmp,tagVal); 
   if (ty == Ity_I64)         // Eventually replace with appropriate switch
   {
     VG_(printf)(" [31:0]"); 
   }    
   VG_(printf)(" = "); 
   cgPrintTmpName(rhstmp, tagVal); 
   VG_(printf)(" );\n"); 

}

void cgEmitTmpAssignConcreteIfLHSSymbolic(HWord lhstmp, 
				     HWord tagVal, 
				     HWord ty, 
				     HWord val)
{
  /* Do not emit this constraint if lhstmp is untainted. */

  if (! isTmpSymbolicP(tagVal, lhstmp)) 
  {
   return; 
  }
  else 
  {
    cgEmitTmpAssignConcrete(lhstmp, tagVal, ty, val); 
  }
}

void cgEmitTmpAssignConcrete(HWord lhstmp, HWord tagVal, HWord ty, HWord val)
{

  cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, ty); 

  if (ca_output_comment)
  {
    VG_(printf)("XXX EmitTmpAssignConcrete. lhstype : ");
    ppIRType(ty); 
    VG_(printf)(" value : %x \n", val); 
  }

  VG_(printf)("ASSERT("); 
  cgPrintTmpName(lhstmp,tagVal); 
  VG_(printf)(" = "); 
  VG_(printf)("0hex"); 
  if (ty == Ity_I64)         // Eventually replace with appropriate switch
    cgPrintHWord(val,16);
  else
    cgPrintHWord(val,8); 
  VG_(printf)(" );\n"); 
  
  return;  
}

void cgEmitTmpLoadConcrete(HWord addr, HWord lhstmp, HWord tagVal, IRType ty)
{
  // Given address and type, extracts the content of the GUEST memory
  // at this address as a constant C. Then outputs the constraint
  // ASSERT( t = C)
  // DOES NOT reference memory array in constraints
  // Checks whether destination temp is tainted; if tainted,
  // then DOES NOT output constraint

  long long value64;
  double valueF64; 
  HWord value32; 
  UShort value16; 
  UChar value8; 
  float valueF32; 
  caChunkTy * addrChunk; 
 


  if (ca_output_comment)
  {
    VG_(printf)("XXX LoadAddr %x ",addr); 
    VG_(printf)("Type ");
    ppIRType(ty);
    VG_(printf)(" Value ");

      switch (ty)
	{

	case (Ity_F64):
	  valueF64 = * ((double * )addr); 
	  value32 = valueF64; 
	  cgPrintHWord(value32,8);
	  break;

	case (Ity_F32):
	  valueF32 = * ((float *)addr); 
	  value32 = valueF32; 
	  cgPrintHWord(value32,8);
	  break; 
	case (Ity_I64):
	  value64 = * ((long long *) addr); 
	  cgPrintHWord(value64,16); 
	  break; 
	  
	case (Ity_I32):
	  value32 = * ((HWord *)addr);
	  cgPrintHWord(value32,8); 
	  break; 
	  
	case (Ity_I16):
	  value16 = * ((UShort *)addr);
	  cgPrintHWord(value16,8); 
	  break; 
	case(Ity_I8):
      value8 = * ((UChar *)addr); 
      cgPrintHWord(value8,8); 
      break; 

	default:
	  VG_(printf)("\n XXX Unhandled type in cgEmitTmpLoadConcrete :  ");
	  ppIRType(ty); 
	  VG_(printf)("\n"); 
	  vassert(0);  
	  break; 
	}

      // MEMORY
      /*
addrChunk = caAddrToChunk(addr,caIntervalTable); 
  if (addrChunk)
    {
      VG_(printf)(" RegionBase %x \n", addrChunk->baseAddr); 
    }
  else
    {
      VG_(printf)(" BOGUSCHUNK \n");
    }
      */
  }
  vassert(addr);

  if (!isTmpSymbolicP(tagVal,lhstmp))
    {

      cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, ty); 
      VG_(printf)("ASSERT("); 
      cgPrintTmpName(lhstmp,tagVal); 
      VG_(printf)(" = "); 
      
      VG_(printf)("0hex"); 

      switch (ty)
	{

	case (Ity_F64):
	  valueF64 = * ((double * )addr); 
	  value32 = valueF64; 
	  cgPrintHWord(value32,8);
	  break;

	case (Ity_F32):
	  valueF32 = * ((float *)addr); 
	  value32 = valueF32; 
	  cgPrintHWord(value32,8);
	  break; 
	case (Ity_I64):
	  value64 = * ((long long *) addr); 
	  cgPrintHWord(value64,16); 
	  break; 
	  
	case (Ity_I32):
	  value32 = * ((UInt *)addr);
	  cgPrintHWord(value32,8); 
	  break; 
	  
	case (Ity_I16):
	  value16 = * ((UShort *)addr);
	  cgPrintHWord(value16,8); 
	  break; 
	case(Ity_I8):
      value8 = * ((UChar *)addr); 
      cgPrintHWord(value8,8); 
      break; 

	default:
	  VG_(printf)("\n XXX Unhandled type in cgEmitTmpLoadConcrete :  ");
	  ppIRType(ty); 
	  VG_(printf)("\n"); 
	  vassert(0);  
	  break; 
	}

      VG_(printf)(");\n"); 
    }

  return; 
}

void cgEmitTmpLoadConstConstraints(HWord addr, HWord lhstmp, HWord tagVal, 
IRType assignTy)
{
  // ASSERT (CVXtY = MemState[const])
  // Outputs constraint ONLY IF destination is tainted
  // Otherwise outputs nothing. 
  caChunkTy * addrChunk; 
  HWord addrConstSize;
  HWord addrOffset;
  TmTypeOfHashNode * tmNode; 


  if (ca_output_comment)
  {
    VG_(printf)("XXX load from const address %x \n", addr);
  }

  if (isTmpSymbolicP(tagVal,lhstmp))
  {
    cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, assignTy); 

    if (ca_output_comment)
    {
      VG_(printf)("XXX TAINTED LOAD\n");
    }

    if (ca_mem_handling == CA_suppress_arrays)
    {

      tmNode = VG_(HT_lookup)(tmAddrToVar,addr);
      if (!tmNode)
      {
	VG_(printf)("XXX BOGUS LOAD BEFORE STORE\n"); 
	return; 
      }
      else
      {
	if (ca_output_comment)
	{
	  VG_(printf)("XXX SUPPRESSED LOAD \n");
	} 
	VG_(printf)("ASSERT( ");  
	cgPrintTmpName(lhstmp,tagVal);
	if (assignTy == Ity_I64)
	  VG_(printf)("[31:0]");   
	VG_(printf)(" = ");
	cgPrintTmpVarTy(tmNode->var); 
	VG_(printf)(" );\n"); 
      }
    }
    else
    {
      if (ca_output_comment)
      {
	VG_(printf)("XXX NO-SUPPRESS ARRAY\n");
      }
      VG_(printf)("ASSERT(");  
      cgPrintTmpName(lhstmp,tagVal); 
      VG_(printf)(" = ");  
      
      // MEMORY
      /*addrChunk = caAddrToChunk(addr,caIntervalTable);       
      if (addrChunk)
      {
	cgPrintMemRegionState(addrChunk->n_instance, addrChunk->baseAddr);
	addrConstSize = addrChunk->regSize/4;
	addrOffset = addr - addrChunk->baseAddr; 
      }
      else
      {
	cgPrintMemState(n_mem_state_instance); 
	addrConstSize = 8; 
	addrOffset = addr;
	}
     */

      VG_(printf)("[0hex"); 
      cgPrintHWord(addrOffset,addrConstSize); 
      VG_(printf)("]);\n"); 
    }
  }
  return; 
}

void cgEmitTmpTmpConstraints(HWord lhstmp, HWord rhstmp, HWord tagVal, 
			     IRType ty)
{
  // ASSERT(CVXtY = or <=> CVXtZ)

  HWord lhsSymP; 
  HWord rhsSymP; 

  lhsSymP = isTmpSymbolicP(tagVal, lhstmp); 
  rhsSymP = isTmpSymbolicP(tagVal, rhstmp); 

  if (! lhsSymP && ! rhsSymP )
  {
    /* If neither LHS nor RHS is symbolic, do not emit constraint */
    return; 
  }

  /* Both right hand side and left hand side should be tainted */ 
  vassert(lhsSymP && rhsSymP);


  cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmp, ty); 
  cgDeclareTmpAtRunIfUndeclared(tagVal, rhstmp, ty); 

  VG_(printf)("ASSERT("); 
  cgPrintTmpName(lhstmp,tagVal); 
  if (ty == Ity_I1)
    VG_(printf)(" <=> "); 
  else if (ty == Ity_I64)
    {
      VG_(printf)("[31:0]"); 
      VG_(printf)(" = ");
    }
  else {
    VG_(printf)(" = ");
  }
  cgPrintTmpName(rhstmp,tagVal); 
  if (ty == Ity_I64)
    {
      VG_(printf)("[31:0]");
    }
  VG_(printf)(");\n",rhstmp); 

  return; 
}

void cgEmitTmpMux0X
(                   /*HWord lhstmpname,
		    HWord condtmpname, 
		    HWord truetmpname, 
		    HWord falsetmpname,
		    HWord condval,
		    HWord trueval,
		    HWord falseval,
		    HWord tagVal,
		    HWord assignTy*/
                    cgArgs_EmitTmpMux0X *extra_args,
		    HWord condval,
		    HWord trueval,
		    HWord falseval)
{

  HWord lhsSymP;
  HWord condSymP; 
  HWord trueSymP; 
  HWord falseSymP; 
  Int hexits; 
  
  // extracting arguments from struct
  HWord lhstmpname = extra_args->lhstmpname;
  HWord condtmpname = extra_args->condtmpname;
  HWord truetmpname = extra_args->truetmpname;
  HWord falsetmpname = extra_args->falsetmpname;
  HWord tagVal = extra_args->tagVal;
  HWord assignTy = extra_args->assignTy;
  

  lhsSymP = isTmpSymbolicP(tagVal, lhstmpname); 

  if (lhsSymP)
  {
    cgDeclareTmpAtRunIfUndeclared(tagVal, lhstmpname, assignTy); 
  }


  if (condtmpname == -1) 
  {
    condSymP = 0; 
  }
  else
  {
    condSymP = isTmpSymbolicP(tagVal, condtmpname); 
  }

  if (truetmpname == -1) 
  {
    trueSymP = 0; 
  }
  else 
  {
    trueSymP = isTmpSymbolicP(tagVal, truetmpname);
  }
 
  if (falsetmpname == -1)
  {
      falseSymP = 0; 
  }
  else 
  {
    falseSymP = isTmpSymbolicP(tagVal, falsetmpname);
  }


  if (assignTy == Ity_I64)
  {
    hexits = 16;
  }
  else
  {
    hexits = 8; 
  } 
 
  /* If lhstmp is not tainted, skip this constraint. Depends on isIRStmt */
  /* occurring _before_ cgIRStmt in ca_main.c to update taint flow.      */ 

  if (! lhsSymP)
  {
      return;
  }
 
  /* If condtmp is not tainted, then collapse Mux to truexpr or falsexpr.*/ 

  if (lhsSymP && ! condSymP)
  {
    if (condval == 0)
    {
      if (falseSymP)
      {
	cgEmitTmpAssignSymbolic(lhstmpname, tagVal, falsetmpname, assignTy); 
      }
      else
      {
	cgEmitTmpAssignConcrete(lhstmpname, tagVal, falseval, assignTy); 
      }
    }
    else if (condval != 0)
    {

      if (trueSymP)
      {
	cgEmitTmpAssignSymbolic(lhstmpname, tagVal, truetmpname, assignTy); 

      }
      else
      {
	cgEmitTmpAssignConcrete(lhstmpname, tagVal, trueval, assignTy); 
      }
    }
  }


  /* If condtmp is tainted, then emit IF THEN ELSE. */ 
  if (lhsSymP && condSymP)
  {

    if (condtmpname != -1)
    {
      cgDeclareTmpAtRunIfUndeclared(tagVal, condtmpname, assignTy);
    }

    if (truetmpname != -1)
    {
      cgDeclareTmpAtRunIfUndeclared(tagVal, truetmpname, assignTy);
    }

    if (falsetmpname != -1)
    {
      cgDeclareTmpAtRunIfUndeclared(tagVal, falsetmpname, assignTy); 
    }

    VG_(printf)("ASSERT( IF ( ");
    cgPrintTmpName(condtmpname,tagVal);
    VG_(printf)(" = 0hex00000000 ) THEN "); 

    if (trueSymP)
    {
      VG_(printf)(" ( ");
      cgPrintTmpName(lhstmpname, tagVal);
      VG_(printf)(" = ");
      cgPrintTmpName(truetmpname, tagVal);
      VG_(printf)(" )"); 
    }
    else
    {
      VG_(printf)(" ( ");
      cgPrintTmpName(lhstmpname, tagVal);
      VG_(printf)(" = ");
      VG_(printf)("0hex"); 
      cgPrintHWord(trueval, hexits); 
      VG_(printf)(" )"); 
    }

    VG_(printf)(" ELSE ");

    if (trueSymP)
    {
      VG_(printf)(" ( ");
      cgPrintTmpName(lhstmpname, tagVal);
      VG_(printf)(" = ");
      cgPrintTmpName(falsetmpname, tagVal);
      VG_(printf)(" )"); 
    }
    else
    {
      VG_(printf)(" ( ");
      cgPrintTmpName(lhstmpname, tagVal);
      VG_(printf)(" = ");
      VG_(printf)("0hex"); 
      cgPrintHWord(falseval, hexits); 
      VG_(printf)(" )"); 
    }

    VG_(printf)(" ENDIF );\n"); 
  }

}


HWord cgGoodDirtyArgTyP(IRType ty)
{

  return ( (ty == Ity_I1) ||
	   (ty == Ity_I8) ||
	   (ty == Ity_I16) ||
	   (ty == Ity_I32) );
}

void cgAddTmpMux0X(IRSB * bb, IRStmt * s)
{

  IRExpr * rhs; 
  IRExpr * condexpr; 
  IRExpr * truexpr; 
  IRExpr * falsexpr;
  
  // struct to hold extra information
  cgArgs_EmitTmpMux0X *extra_args = NULL;

  HWord lhsName;
  HWord condName;
  HWord trueName;
  HWord falseName; 

  IRType lhsTy, condTy, trueTy, falseTy; 
  IRDirty * d; 
  
  vassert(bb);
  vassert(s);
  vassert(s->tag == Ist_WrTmp);

  rhs = s->Ist.WrTmp.data; 

  vassert(rhs->tag == Iex_Mux0X); 
  condexpr = rhs->Iex.Mux0X.cond; 
  truexpr = rhs->Iex.Mux0X.expr0;
  falsexpr = rhs->Iex.Mux0X.exprX; 

  vassert(condexpr->tag == Iex_RdTmp || condexpr->tag == Iex_Const); 
  vassert(truexpr->tag == Iex_RdTmp || truexpr->tag == Iex_Const); 
  vassert(falsexpr->tag == Iex_RdTmp || falsexpr->tag == Iex_Const); 

  lhsName = (HWord)s->Ist.WrTmp.tmp; 

  if (condexpr->tag == Iex_RdTmp)
  {
    condName = (HWord)condexpr->Iex.RdTmp.tmp; 
    condTy = (HWord) bb->tyenv->types[condName];
  }
  else if (condexpr->tag == Iex_Const)
  {
    condName = -1; 
    condTy = Ity_I32; 
  }
  else
  {
    vassert(0); 
  }

  if (truexpr->tag == Iex_RdTmp)
  {
    trueName = (HWord)truexpr->Iex.RdTmp.tmp;
    trueTy = (HWord) bb->tyenv->types[trueName];
  }
  else if (truexpr->tag == Iex_Const)
  {
    trueName = -1; 
    trueTy = Ity_I32; 
  }
  else
  {
    vassert(0); 
  }

  if (falsexpr->tag == Iex_RdTmp)
  {
    falseName = (HWord)falsexpr->Iex.RdTmp.tmp; 
    falseTy = (HWord) bb->tyenv->types[falseName];
  }
  else if (falsexpr->tag == Iex_Const)
  {
    falseName = -1;
    falseTy = Ity_I32;
  }
  else
  {
    vassert(0); 
  }


  lhsTy = (HWord) bb->tyenv->types[lhsName];

  
  /* Make sure we only pass in arguments of a type we can handle! */ 
  if ( ! ( cgGoodDirtyArgTyP(condTy) && 
	   cgGoodDirtyArgTyP(falseTy) &&
	   cgGoodDirtyArgTyP(trueTy) 
	   ) )
 {
   return;
 }

  extra_args = VG_(malloc)("extraArgs",sizeof(cgArgs_EmitTmpMux0X));
  getStructOf(bb, extra_args); // adding struct to hash table
  extra_args->lhstmpname = mkIRExpr_HWord(lhsName);
  extra_args->condtmpname = mkIRExpr_HWord(condName);
  extra_args->truetmpname = mkIRExpr_HWord(trueName);
  extra_args->falsetmpname = mkIRExpr_HWord(falseName);
  extra_args->tagVal = mkIRExpr_HWord(cgBBCounter);
  extra_args->assignTy = mkIRExpr_HWord(lhsTy);
  
  d = unsafeIRDirty_0_N(0,
			"cgEmitTmpMux0X",
			&cgEmitTmpMux0X,
			mkIRExprVec_4(/*mkIRExpr_HWord(lhsName),
				      mkIRExpr_HWord(condName),
				      mkIRExpr_HWord(trueName),
				      mkIRExpr_HWord(falseName),
				      condexpr,
				      truexpr,
				      falsexpr,
				      mkIRExpr_HWord(cgBBCounter),
				      mkIRExpr_HWord(lhsTy)
				      */
                                      mkIRExpr_HWord(extra_args),
				      condexpr,
				      truexpr,
				      falsexpr
				      )
			);


  setHelperAnns(d); 
  addStmtToIRSB(bb,IRStmt_Dirty(d)); 
  
}

void cgAddTmpTmpConstraints(IRSB * bb, IRStmt * s)
{
  IRExpr * rhs; 
  HWord lhsName;
  HWord rhsName; 
  IRType assignTy;
  IRDirty * d; 
  
  vassert(bb);
  vassert(s);
  vassert(s->tag == Ist_WrTmp);

  rhs = s->Ist.WrTmp.data; 
  vassert(rhs->tag == Iex_RdTmp);

  lhsName = (HWord)s->Ist.WrTmp.tmp; 
  rhsName = (HWord)rhs->Iex.RdTmp.tmp; 

  vassert(bb->tyenv->types[lhsName] == bb->tyenv->types[rhsName]); 
  assignTy = bb->tyenv->types[lhsName];

  d = unsafeIRDirty_0_N(0,
			"cgEmitTmpTmpConstraints",
			&cgEmitTmpTmpConstraints,
			mkIRExprVec_4(mkIRExpr_HWord(lhsName),
				      mkIRExpr_HWord(rhsName),
				      mkIRExpr_HWord(cgBBCounter),
				      mkIRExpr_HWord(assignTy)
				      )
			);
  setHelperAnns(d); 
  addStmtToIRSB(bb,IRStmt_Dirty(d)); 
  return; 
}


#if 0 

void cgAddTmpCCall(IRSB * bb, IRStmt * s)
{

  IRTemp lhs; 
  HWord tmpName;
  IRExpr * lhsexpr = VG_(malloc)(sizeof(IRExpr));  /// XXX memory leak!
  IRExpr * call; 
  IRDirty * d; 
  IRType lhsty; 
  IRCallee * callee;
  IRExpr ** callee_args;


  call = s->Ist.WrTmp.data; 
  vassert(call->tag == Iex_CCall); 
  callee = call->Iex.CCall.cee;
  callee_args = call->Iex.CCall.args;  

  if (! VG_(strncmp)(callee->name, "x86g_calculate_condition",24))
 {

   if (ca_output_comment)
   {
     VG_(printf)("XXX x86g_calculate_condition instrumented in cgIR.c\n");
   }

   numCalcCondition++; /* Increment stat counter */ 

   lhs = s->Ist.WrTmp.tmp; 
   tmpName = (HWord)lhs; 

  lhsexpr->tag = Iex_RdTmp;
  lhsexpr->Iex.RdTmp.tmp = lhs;
  vassert(tmpName < bb->tyenv->types_used); 

  lhsty = (HWord)bb->tyenv->types[lhs]; 
  
    d = unsafeIRDirty_0_N(0,
			  "cgEmitTmpAssignConcreteIfLHSSymbolic",
			  &cgEmitTmpAssignConcreteIfLHSSymbolic,
			     mkIRExprVec_4(mkIRExpr_HWord(tmpName),
					   mkIRExpr_HWord(cgBBCounter),
					   mkIRExpr_HWord(lhsty),
					   lhsexpr
					   )
			     );   

    setHelperAnns(d); 
    addStmtToIRSB(bb, IRStmt_Dirty(d)); 


 }
 else 
 {
   if (ca_output_comment)
   {
     VG_(printf)(" XXX Concrete CCall : ");
     ppIRStmt(s); 
     VG_(printf)("\n"); 
   } 
 
  lhs = s->Ist.WrTmp.tmp; 
  tmpName = (HWord)lhs; 

  lhsexpr->tag = Iex_RdTmp;
  lhsexpr->Iex.RdTmp.tmp = lhs;
  vassert(tmpName < bb->tyenv->types_used); 

  lhsty = (HWord)bb->tyenv->types[lhs]; 
  
    d = unsafeIRDirty_0_N(0,
			  "cgEmitTmpAssignConcreteIfLHSSymbolic",
			  &cgEmitTmpAssignConcreteIfLHSSymbolic,
			     mkIRExprVec_4(mkIRExpr_HWord(tmpName),
					   mkIRExpr_HWord(cgBBCounter),
					   mkIRExpr_HWord(lhsty),
					   lhsexpr
					   )
			     );   

    setHelperAnns(d); 
    addStmtToIRSB(bb, IRStmt_Dirty(d)); 

 }

  return;
}

#endif


int cgGetTypeOK(IRType ty)
{

  return (ty == Ity_I32 ||
	  ty == Ity_I64 ||
	  ty == Ity_I16 ||
	  ty == Ity_I8  ||
	  ty == Ity_I1 );
}

void cgAddTmpStmtConstraints(IRSB * bb, IRStmt * s)
{
  
  IRExpr * rhs;
  IRExpr * addrExpr;
  HWord tmpName; 
  HWord getOffset;
  HWord rhsTmpName; 
  HWord rhsAddr; 
  IRDirty * d; 
  IRType loadTy = Ity_I32; 
  IRExpr * lhsexpr = VG_(malloc)("lhsexpr",sizeof(IRExpr)); 
  IRType assignty = Ity_I32;
  void * cgEmitTmpGetConstraintsPtr; 

  vassert(bb); 
  vassert(s); 
  vassert(s->tag == Ist_WrTmp);

  rhs = s->Ist.WrTmp.data; 
 
  tmpName = (HWord) s->Ist.WrTmp.tmp;
  assignty = bb->tyenv->types[tmpName]; 

  cgEmitTmpGetConstraintsPtr = &cgEmitTmpGetConstraints_32bit; 

  // GET can fetch a non-I32 or non-I64 from registers.
  // In particular, SSE instructions manipulate V128 values.
  // Valgrind will fail if we try to pass the resulting lhsexpr 
  // to our IRDirty, so check for this case.
  // If we see a type we can't handle, report it and return. 
  if (! cgGetTypeOK(assignty))
  {
    if (ca_output_comment) 
    {
      VG_(printf)("XXX Unhandled GET type :");
      ppIRType(assignty); 
      VG_(printf)("\n"); 
     }
    return; 
  }


  switch (rhs->tag)
    {

    case (Iex_Const):

      /* If we have an assignment of the form tX = 0hexYYYY, then do */
      /* not emit constraint at this time. Later will concretize tX */
      /* and then fold in concrete value 0hexYYYY at that time.     */

      break; 


    case (Iex_Get):
      getOffset = (HWord) rhs->Iex.Get.offset; 

       lhsexpr->tag = Iex_RdTmp;
       lhsexpr->Iex.RdTmp.tmp = (IRTemp)s->Ist.WrTmp.tmp;

      d = unsafeIRDirty_0_N(0,
			    "cgEmitTmpGetConstraints",
			    cgEmitTmpGetConstraintsPtr,
			    mkIRExprVec_5(mkIRExpr_HWord(getOffset),
					  mkIRExpr_HWord(tmpName),
					  mkIRExpr_HWord(cgBBCounter),
					  mkIRExpr_HWord(assignty),
					  lhsexpr
					  )
			    );



      setHelperAnns(d); 
      addStmtToIRSB(bb,IRStmt_Dirty(d));         

      break; 

    case (Iex_Load):
      addrExpr = rhs->Iex.Load.addr;  

      switch(addrExpr->tag)
	{
	case (Iex_RdTmp):
	  rhsTmpName = addrExpr->Iex.RdTmp.tmp;
	  loadTy = bb->tyenv->types[tmpName]; 

	  d = unsafeIRDirty_0_N(0,
				   	"cgEmitTmpLoadTmpConstraints",
					&cgEmitTmpLoadTmpConstraints,
				mkIRExprVec_5(addrExpr,
					      mkIRExpr_HWord(rhsTmpName),
					      mkIRExpr_HWord(tmpName),
					      mkIRExpr_HWord(cgBBCounter),
					      mkIRExpr_HWord(loadTy)
					      )
				); 
	  setHelperAnns(d); 

	  /* Previous versions added additional constraints for concrete */
	  /* load into tmp. Now, use tainting: if concrete value used in */
	  /* later constraint, we replace with the concrete value then.  */
	  /* The benefit of doing it this way is that it saves on the    */
	  /* size of the input to STP.                                   */
	  
	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 

	  break;

	case (Iex_Const):
	  rhsAddr = cgConstToHword(addrExpr); 
	  
	  d = unsafeIRDirty_0_N(0,
					"cgEmitTmpLoadConstConstraints",
					&cgEmitTmpLoadConstConstraints,
				mkIRExprVec_4(mkIRExpr_HWord(rhsAddr),
					      mkIRExpr_HWord(tmpName),
					      mkIRExpr_HWord(cgBBCounter),
					      mkIRExpr_HWord(loadTy)
					      )
				); 
	  setHelperAnns(d); 

	  /*
	    // Do not emit constant load into tmp
	    // Instead later replace tmp name with constant value
	  d2 = unsafeIRDirty_0_N(0,
				 "cgEmitTmpLoadConcrete",
				 &cgEmitTmpLoadConcrete,
				 mkIRExprVec_4(addrExpr,
					       mkIRExpr_HWord(tmpName),
					       mkIRExpr_HWord(cgBBCounter),
					       mkIRExpr_HWord(loadTy) 
					       )
				 );
	  setHelperAnns(d2);


	  addStmtToIRSB(bb,IRStmt_Dirty(d2));
	  */ 

	  addStmtToIRSB(bb,IRStmt_Dirty(d)); 

	  break;
	  
	default:

	  if (ca_output_comment)
	  {
	    VG_(printf)("XXX Warning : Unhandled load addr tag in "); 
	    ppIRExpr(addrExpr); 
	    VG_(printf)("\n"); 
	  }
	  break;
	}
      break;
      
    case(Iex_RdTmp):
      cgAddTmpTmpConstraints(bb,s);
      break;

    case(Iex_Binop):
      cgAddTmpBinopConstraints(bb,s); 
      break;

    case(Iex_Unop):
      cgAddTmpUnopConstraints(bb,s); 
      break; 

    case (Iex_CCall):
      cgAddTmpCCall(bb,s);
      break; 

    case (Iex_Mux0X):
      cgAddTmpMux0X(bb,s);
      break; 

    default:
      if (ca_output_comment)
      {
	VG_(printf)("XXX Warning : Unhandled Ist_WrTmp : ");
	ppIRStmt(s); 
	VG_(printf)("\n");
      } 
    }

   

  return; 
}



void cgAddExitPre(IRSB * bb, IRStmt * s) 
{
  IRExpr * exitGuard; 
  IRDirty * d; 
  HWord guardNum;
  HWord destAddr; 
  vassert(bb); 
  vassert(s); 
  vassert(s->tag == Ist_Exit); 

  exitGuard = s->Ist.Exit.guard; 
  vassert(exitGuard); 
  destAddr = (HWord)s->Ist.Exit.dst->Ico.U32; 

  switch (exitGuard->tag)
    {
    case (Iex_RdTmp):
      
      guardNum = (HWord)exitGuard->Iex.RdTmp.tmp; 
      d = unsafeIRDirty_0_N(0,
			    "cgEmitExitTmpConstraints",
			    &cgEmitExitTmpConstraints,
			    mkIRExprVec_4( 
					  mkIRExpr_HWord(guardNum),
					  mkIRExpr_HWord(cgBBCounter),
					  IRExpr_RdTmp(exitGuard->Iex.RdTmp.tmp),
					  mkIRExpr_HWord(destAddr)
					  )
			    );
      setHelperAnns(d); 
      addStmtToIRSB(bb, IRStmt_Dirty(d)); 

      break;
    default:
      if (ca_output_comment)
      {
	VG_(printf)("XXX Warning : Unhandled guard in ");
	ppIRExpr(exitGuard);
	VG_(printf)("\n"); 
      }
      break;
    }

  return; 
}

void cgPrintCommentChar(void)
{
  if (ca_output_comment)
  {
    VG_(printf)("XXX");
  } 
}

void cgPrintEndln(void)
{
  if (ca_output_comment)
  {
    VG_(printf)("\n"); 
  }
}


// Prints XXX var1...varN, where each var is present in statement
void cgAddPrintVars(IRSB * bb, IRStmt * s) 
{
  IRDirty * d1;
  IRDirty * d2; 
  vassert(bb); 
  vassert(s); 

      d1 = unsafeIRDirty_0_N(0,
			    "cgPrintCommentChar",
			    &cgPrintCommentChar,
			    mkIRExprVec_0()
			    );
      setHelperAnns(d1); 
      addStmtToIRSB(bb, IRStmt_Dirty(d1)); 

      d2 = unsafeIRDirty_0_N(0,
			    "cgPrintEndln",
			    &cgPrintEndln,
			    mkIRExprVec_0()
			    );
      setHelperAnns(d2); 
      addStmtToIRSB(bb, IRStmt_Dirty(d2)); 

}

void cgEmitMallocQueries(HWord instBB)
{
  HWord argTaintedp; 
  TmTypeOfHashNode * tmNode = NULL;
  
  argTaintedp = isRegSymbolicP(0);  // 0 = offset of EAX
  if (argTaintedp)
  {
    tmNode = VG_(HT_lookup)(tmAddrToVar, 0);

    if (tmNode != NULL)
    {
      /* Emit symbolic queries over malloc()/calloc() argument */ 
     cgDeclareTmpVarTyIfUndeclared(tmNode->var, Ity_I32);

     VG_(printf)("XXX MALLOCARG \n"); 
     VG_(printf)("XXX QUERY(BVLT( ");
     cgPrintTmpVarTy(tmNode->var); 
     VG_(printf)(" ,");
     VG_(printf)("0hex80000000));  %% TYPE MallocArgNeg \n");


     VG_(printf)("XXX MALLOCARG \n"); 
     VG_(printf)("XXX QUERY(BVGT( ");
     cgPrintTmpVarTy(tmNode->var); 
     VG_(printf)(" ,");
     VG_(printf)("0hex00000000)); %% TYPE MallocArgGT0 \n");

     VG_(printf)("XXX MALLOCARG \n"); 
     VG_(printf)("XXX QUERY(BVGT( ");
     cgPrintTmpVarTy(tmNode->var); 
     VG_(printf)(" ,");
     VG_(printf)("0hex00000002)); %% TYPE MallocArgGT2 \n");

     VG_(printf)("XXX MALLOCARG \n"); 
     VG_(printf)("XXX QUERY(BVGT( ");
     cgPrintTmpVarTy(tmNode->var); 
     VG_(printf)(" ,");
     VG_(printf)("0hex00000004)); %% TYPE MallocArgGT4 \n");

     VG_(printf)("XXX MALLOCARG \n"); 
     VG_(printf)("XXX QUERY(BVGT( ");
     cgPrintTmpVarTy(tmNode->var); 
     VG_(printf)(" ,");
     VG_(printf)("0hex00000008)); %% TYPE MallocArgGT8 \n");

     VG_(printf)("XXX MALLOCARG \n"); 
     VG_(printf)("XXX QUERY(BVGT( ");
     cgPrintTmpVarTy(tmNode->var); 
     VG_(printf)(" ,");
     VG_(printf)("0hex0000000F)); %% TYPE MallocArgGT16 \n");
    }
  }
}


void cgAddEntryQueries(IRSB* bb, IRStmt* s)
{

  Char fnname[4096]; 
  Int fnline = 0; 
  IRDirty * d; 

  /* Check to see if we are at function entry. */ 
  if (VG_(get_fnname_if_entry)((Addr)s->Ist.IMark.addr, &fnname[0], fnline))
  {

    /* If so, then check whether a function we care about, add queries. */
    if (VG_(strstr)(fnname, "malloc"))
    {
      VG_(printf)("XXX Instrumenting %s function entry \n", fnname);
      d = unsafeIRDirty_0_N(0,
			    "cgEmitMallocQueries",
			    &cgEmitMallocQueries,
			    mkIRExprVec_0()
			    ); 
      
      setHelperAnns(d); 
      addStmtToIRSB(bb, IRStmt_Dirty(d)); 
    }  

    if (VG_(strstr)(fnname, "calloc"))
    {
      VG_(printf)("XXX Instrumenting %s function entry \n", fnname);
      d = unsafeIRDirty_0_N(0,
			    "cgEmitMallocQueries",
			    &cgEmitMallocQueries,
			    mkIRExprVec_0()
			    ); 
      
      setHelperAnns(d); 
      addStmtToIRSB(bb, IRStmt_Dirty(d)); 
    }
  }
}		  


void cgIRStmt (IRSB* bb, IRStmt* s, ULong bb_counter)
{

  cgBBCounter = bb_counter; 

   if (!s) {
      vex_printf("!!! IRStmt* which is NULL !!!");
      return;
   }

   // Prints the variables used in each statement; aids post-processing
   cgAddPrintVars(bb,s); 
   switch (s->tag) {
      case Ist_NoOp:
         break;
      case Ist_IMark:
        cgAddEntryQueries(bb,s); 
          break;
      case Ist_AbiHint:
         break;
      case Ist_Put:
	cgAddPutStmtConstraints(bb,s); 
         break;
      case Ist_PutI:
          break;
      case Ist_WrTmp:
	cgAddTmpStmtConstraints(bb,s);
         break;
      case Ist_Store:
	cgAddStoreStmtConstraints(bb,s);
        break;
      case Ist_Dirty:
	if (ca_output_comment)
	{
	  VG_(printf)("XXX Unhandled Ist_Dirty :");
	  ppIRStmt(s);
	  VG_(printf)("\n"); 
	}
         break;
	 /*      case Ist_MFence:
	if (ca_output_comment)
	{
	  VG_(printf)("XXX Unhandled Ist_MFence :");
	  ppIRStmt(s);
	  VG_(printf)("\n");
	} 
	break; */
      case Ist_Exit:
	//	cgAddExitStmtConstraints(bb,s);
	// Currently handled in ca_instrument with cgAddExitPre
         break;
      default: 
         vpanic("cgIRStmt");
   }
}

