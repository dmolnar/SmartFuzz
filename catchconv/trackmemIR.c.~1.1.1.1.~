
/* trackmemIR.c - create and maintain a map from memory addresses to 
   (tainted) temporary variable names. Used to optimize constraint
   generation in mode that suppresses arrays by concretizing all 
   array indices and tracking the resulting dependencies. */ 

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
#include "pub_tool_libcproc.h" 
#include "pub_tool_threadstate.h"

#include "ca_interval.h"
#include "isIR.h"
#include "ca_settings.h"
#include "ogIR.h" 
#include "catchconv.h"
#include "trackmemIR.h"
#include "cgIR.h" 

/* Used for case where we store a constant to an address. In this case,
   we always want to clear the entry in the hash table that maps the 
   address addr to a tmp variable. */ 
void tmClearAddr(HWord addr, HWord numBytes)
{
  TmTypeOfHashNode * tmNode;
  HWord key; 
  HWord offset; 

  for (offset = 0; offset < numBytes; offset++)
  {
    key = addr+offset; /* Memory is byte-addressed */  
    tmNode = VG_(HT_remove)(tmAddrToVar,key);
    if (tmNode) 
    {
      VG_(free)(tmNode);

      if (ca_output_comment)
      {
	VG_(printf)("XXX TM_CLEAR addr %x offset %d \n", addr, offset); 
      }
    }
  }
}


/* Used for case where we store a tmpvar to an address. We update 
   the map from the concrete address value to the tmpvar. 
   TODO: optimize by updating only if address is tainted. */ 
void tmUpdate
     (
      HWord addr, 
      HWord tmpname,
      HWord numBytes,
      HWord tagVal
      )
{
  TmTypeOfHashNode * tmNode; 
  HWord PID;
  HWord TID;
  HWord offset = 0; 
  HWord key; 
  PID = VG_(getpid)();
  TID = VG_(get_running_tid)();

  for (offset = 0; offset < numBytes; offset++)
  {
    key = addr + offset; 
    tmNode = VG_(HT_lookup)(tmAddrToVar, key); 
    if (!tmNode)
    {
    /* allocate new hash node */ 
      tmNode = (TmTypeOfHashNode *)VG_(malloc)(sizeof(TmTypeOfHashNode));
      tmNode->memAddr = key; 
      tmNode->offset = offset; 
      tmNode->numBytes = numBytes; 
      VG_(HT_add_node)(tmAddrToVar,tmNode); 
    }
    vassert(tmNode->memAddr == key);
    tmNode->offset = offset; 
    tmNode->var.CV = tagVal; 
    tmNode->var.t = tmpname;  
    tmNode->var.p = PID; 
    tmNode->var.e = cgBBExecCounter;
    tmNode->var.th = TID;

    if (ca_output_comment)
    {
      VG_(printf)("XXX TM_UPDATE addr %x key %x VAR ", addr, key); 
      cgPrintTmpVarTy(tmNode->var);
      VG_(printf)(" offset: %d", offset); 
      VG_(printf)(" numBytes: %d", numBytes); 
      VG_(printf)(" \n"); 
    }
  }
}
  
void tmIRStore(IRBB * bb, IRStmt * s, HWord BBCounter)
{

  IRExpr * addrExpr;
  IRExpr * dataExpr; 
  IRDirty * d = NULL;
  HWord tmpname;
  HWord numBytes = 0;  /* Depends on type of data stored. */ 


  vassert(s->tag == Ist_Store);
  addrExpr = s->Ist.Store.addr; 
  dataExpr = s->Ist.Store.data; 

  switch (dataExpr->tag)
  {
    case (Iex_Const):
    {
      numBytes = numBytesOfConst(dataExpr->Iex.Const.con);  
	d = unsafeIRDirty_0_N(0,
			      "tmClearAddr",
			      &tmClearAddr,
			      mkIRExprVec_2(addrExpr,
					    mkIRExpr_HWord(numBytes)
					    )
			     
			      );
	break; 
    }
    case (Iex_Tmp):
    {
      numBytes = numBytesOfTmpvar(bb, dataExpr->Iex.Tmp.tmp);
      tmpname = (HWord)dataExpr->Iex.Tmp.tmp; 
      d = unsafeIRDirty_0_N(0,
			    "tmUpdate",
			    &tmUpdate,
			    mkIRExprVec_4(addrExpr,
					  mkIRExpr_HWord(tmpname),
					  mkIRExpr_HWord(numBytes),
					  mkIRExpr_HWord(BBCounter)
					  )
			    );
	break; 
    }
    default:
    {
      d = NULL; 
    }
  }

  if (d != NULL)
  {
    setHelperAnns(d); 
    addStmtToIRBB(bb,IRStmt_Dirty(d)); 
  }

  
}

/* Handle a PUT(X) = tY or PUT(X) = constant. */
void tmIRPut(IRBB * bb, IRStmt * s, HWord BBCounter)
{

  HWord putOffset;
  IRExpr * dataExpr; 
  IRDirty * d = NULL;
  HWord tmpname;
  HWord numBytes; 


  vassert(s->tag == Ist_Put);
  putOffset = s->Ist.Put.offset; 
  dataExpr = s->Ist.Put.data; 


  switch (dataExpr->tag)
  {
    case (Iex_Const):
    {
      numBytes = numBytesOfConst(dataExpr->Iex.Const.con);  
	d = unsafeIRDirty_0_N(0,
			      "tmClearAddr",
			      &tmClearAddr,
			      mkIRExprVec_2(
					    mkIRExpr_HWord(putOffset),
					    mkIRExpr_HWord(numBytes)
					    )
			      );
	break; 
    }
    case (Iex_Tmp):
    {
      numBytes = numBytesOfTmpvar(bb, dataExpr->Iex.Tmp.tmp);
      tmpname = (HWord)dataExpr->Iex.Tmp.tmp; 
      d = unsafeIRDirty_0_N(0,
			    "tmUpdate",
			    &tmUpdate,
			    mkIRExprVec_4(
					  mkIRExpr_HWord(putOffset),
					  mkIRExpr_HWord(tmpname),
					  mkIRExpr_HWord(numBytes), 
					  mkIRExpr_HWord(BBCounter)
					  )
			    );
	break; 
    }
    default:
    {
      d = NULL; 
    }
  }

  if (d != NULL)
  {
    setHelperAnns(d); 
    addStmtToIRBB(bb,IRStmt_Dirty(d)); 
  }

  
}


/* We only care about the case of an IRStore or an IRPut. */ 
/* NEXTVERSION: handle a PUTI.                            */

void tmIRStmt(IRBB * bb, IRStmt * s, HWord BBCounter)
{

  switch (s->tag)
    {
    case Ist_Store:
      tmIRStore(bb,s,BBCounter);
      break;
    case Ist_Put:
      tmIRPut(bb,s,BBCounter); 
      break; 
    default:
      break;
    }
}
