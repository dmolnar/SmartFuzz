
/*--------------------------------------------------------------------*/
/*--- CatchConversions                           ca_main.c ---*/
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
   General Public License fill callor more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/

#include "pub_tool_basics.h"
#include "pub_tool_libcassert.h"
#include "pub_tool_tooliface.h"

#include "pub_tool_libcprint.h"
#include "pub_tool_debuginfo.h"
#include "pub_tool_libcbase.h"
#include "pub_tool_vki.h"
#include "pub_tool_libcfile.h" 
#include "pub_tool_options.h"
#include "pub_tool_libcproc.h"
#include "pub_tool_hashtable.h" 
#include "ca_interval.h"
#include "ogIR.h" 
#include "cgIR.h"
#include "isIR.h"
#include "catchconv.h" 
#include "ca_malloc_wrappers.h" 
#include "ca_callbacks.h" 
#include "ca_settings.h"
#include "ca_stats.h"
#include "trackmemIR.h"
#include "findRepMov.h"
#include "ufOgIR.h"


/* declarations */
static Int ca_count_hashtable(VgHashTable table);

/* --- Globals --- */ 

HWord caMainBBCounter = 0; 
Bool emitPathCondp = True; 

MemHandleMode ca_mem_handling = CA_suppress_arrays;
HWord ca_output_comment = 0;      // Do we output comments in const. gen?
                                  // Default is no. 

HWord ca_type_inference = 0;      // Do we use type inference in const. gen?
                                  // Default is no, due to memory usage.
                                  // Temp change default to yes. 
 
Int run_prefix_task = 0;          // Have we read from tainted data yet? 
                                  // Initialize to 0, false. 

char * inputfilename = NULL;      // Specified with --input-file= on command
                                  // line, names the symbolic input file


void ca_read_memregions_from_file(char * path)
{
  SysRes memregionsFileDes; 
  char line[1024]; 
  int i; 

  HWord regionBase, regionSize; 


  // open path
  memregionsFileDes = VG_(open)(path, 0,0);
  //  if (memregionsFileDes.isError)
  //  return; 

  // make val point to SysRes value later 
  int val = 0;

  // while not EOF
  // read next line
  while (! VG_(get_line)(val,line,sizeof(line)) )
    {
      // parse line 
      // expected format: <regionBase> <space> <regionSize>
      
      regionBase = VG_(strtoll10)(line,NULL); 
      
      i = 0;

      while ( ! VG_(isspace)(line[i]))
	{ i++; }
      
      regionSize = VG_(strtoll10)(&line[i+1],NULL); 

      // declare memory region 
      // MEMORY -  caInsertInterval(regionBase,regionSize,caIntervalTable); 
    }
		  
  return; 
}

void ca_read_origins_from_file(char * path)
{
  SysRes originFileDes; 
  char line[1024];  
  HWord originMem; 

  return; 
  // open path
  /*
  originFileDes = VG_(open)(path, VKI_O_RDONLY,0);
  if (originFileDes.isError)
    return; 
  */ 
  // while not EOF
  // read next line
  /*
  while (! VG_(get_line)(originFileDes.val,line,sizeof(line)) )
    {
      // convert line to address
      originMem = VG_(atoll_base)(line,16); 
      // declare that address as origin
      isSetKeyOrigin(locToHashKey(originMem,0,MemLoc),0); 
    }
  */ 	  
  return; 
}

void ca_make_args_origin(void)
{
  UInt i; 
  Char ** a; 

  return; 

  // Declare argv[] as origin
  // really should declare entire range as origin, 
  // but start for now with first word of each entry
  //  a = VG_(args_for_client); 

  /*
  for (i = 0; i < VG_(client_argc); i ++)
  {
    isSetKeyOrigin(locToHashKey((HWord)&(*a[i]),0,MemLoc),i); 
  }
  */
  // declare env as origin, as well. 
  /*
  for (i = 0; VG_(client_envp)[i] != NULL; i++) 
    {
      isSetKeyOrigin(locToHashKey((HWord)&VG_(client_envp)[i],0,MemLoc),i);
    }
  */
  return; 
}

void ca_track_new_mem_stack(Addr a, SizeT len)
{

  // Declare a new memory region for the stack
  //   caChunkTy * newStackChunk; 
  // MEMORY - newStackChunk = caInsertInterval(a,len,caIntervalTable); 
  // MEMORY - caDeclareChunk(newStackChunk); 

  // Update the type inference constraints
  ogEmitStackConstraints(a,len); 

  return; 
}


Bool ca_process_cmd_line_option(Char* arg)
{
  char * ca_memregions_path; 
  char * ca_origins_path; 

  ca_memregions_path = NULL;
  ca_origins_path = NULL;

  if VG_STR_CLO(arg, "--mem-regions",ca_memregions_path) {}
  else if VG_STR_CLO(arg,"--origins",ca_origins_path) {}
  else if VG_STR_CLO(arg,"--input-file", inputfilename) {}
  else if VG_BOOL_CLO(arg,"--output-comments", ca_output_comment) {}
  else if VG_BOOL_CLO(arg,"--type-inference", ca_type_inference) {}
  else if VG_BOOL_CLO(arg,"--inline-path-queries", inlinePathQueriesP) {}
  else if (VG_XACT_CLO(arg, "--concretize-indices=yes", ca_mem_handling, CA_concretize_indices))
  {
  }
  else if (VG_XACT_CLO(arg, "--suppress-arrays=yes", ca_mem_handling, CA_suppress_arrays))
  {
  }
  else if (VG_XACT_CLO(arg, "--full-mem=yes", ca_mem_handling, CA_full))
  {}
  else
  {
    return False; /* unrecognized arg => error */
  }

  if (ca_origins_path) ca_read_origins_from_file(ca_origins_path); 
  if (ca_memregions_path) ca_read_memregions_from_file(ca_memregions_path); 
  
 return True; 
}

void ca_print_usage(void)
{

   VG_(printf)(
"    --mem-regions=<file>             use memory regions from file\n"
"    --origins=<file>                 read list of origin addrs from file\n"
);

   return; 
}

void ca_print_debug_usage(void)
{

  return; 
}


static void ca_post_clo_init(void)
{

  if (ca_output_comment)
  {
    VG_(printf)("XXX post_clo_init\n");
    VG_(printf)("XXX inputfilename : %s\n", inputfilename); 
  }
  return; 
}

/* Counting the number of entries in a hash table */
static Int ca_count_hashtable( VgHashTable table )
{
  return VG_(HT_count_nodes)(table) * sizeof(VgHashNode);
} 

static
IRSB* ca_instrument( VgCallbackClosure * closure, 
		     IRSB* bb_in, 
		     VexGuestLayout* layout, 
                     VexGuestExtents* vge,
                     IRType gWordTy, IRType hWordTy )
{
   Int      i;
   IRSB*    bb;
   Int      count1;
   Int      count2;
   Int      count3;
   Int      count4;
   Int      count5;
   Int      count6;
   Int      count7;
   Int      count8;
   Int      count9;
   Int      sum; 
   findRepMovContext * repMovContext; 

  // do not instrument block if we have not yet read from tainted data
    if (run_prefix_task == 0)
    {

      /* Update count of BBs instrumented. Do it here to agree with */
      /* Valgrind core numbering of BBs instrumented.               */ 
      /* NOTE: our numbering of BBs executed does not agree w/core! */
      caMainBBCounter++; 
      return bb_in;
    }



   /* Counting the number of entries in a hash table */
   count1 = ca_count_hashtable(ogVarOf);
   count2 = ca_count_hashtable(ogTypeOf);
   count3 = ca_count_hashtable(cgPathCond);
   count4 = ca_count_hashtable(isIsSymbolic);
   count5 = ca_count_hashtable(caIntervalTable);
   count6 = ca_count_hashtable(cgIsDeclared);
   count7 = ca_count_hashtable(cgITEWriteStackMemSt);
   count8 = ca_count_hashtable(cgITEWriteStackMaSt);
   count9 = ca_count_hashtable(tmAddrToVar);

   // debugging option
   if (ca_output_comment) {
     VG_(printf)("XXX The number of has entries in hash tables 1-9 are %d %d %d %d %d %d %d %d %d\n",
	       count1, count2, count3, count4, count5, count6, count7, count8, count9);

     sum = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
     VG_(printf)("XXX The total number of hash entries in all the tables is %d\n", sum);

     VG_(printf)("XXX The size of each entry for the hash tables 1-9 are %d %d %d %d %d %d %d %d %d\n", 
	       sizeof(OgVarOfHashNode), sizeof(ogTypeOf), sizeof(cgPathCond),
	       sizeof(isIsSymbolic), sizeof(caIntervalTable), sizeof(cgIsDeclared), 
	       sizeof(cgITEWriteStackMemSt), sizeof(cgITEWriteStackMaSt), sizeof(tmAddrToVar));
   }

   if (gWordTy != hWordTy) {
	VG_(printf)("MISMATCH: "); 
	ppIRType(gWordTy);
	VG_(printf)(" "); 
	ppIRType(hWordTy);
	VG_(printf)("\n"); 
      /* We don't currently support this case. */
      VG_(tool_panic)("host/guest word size mismatch");
   }


   /* Set up BB */
   bb           = emptyIRSB();
   bb->tyenv    = deepCopyIRTypeEnv(bb_in->tyenv);
   bb->next     = deepCopyIRExpr(bb_in->next);
   bb->jumpkind = bb_in->jumpkind;

   /* Set up context for finding rep mov instructions */
   /* assume at most 400 tmp vars per basic block     */ 
   repMovContext = createRepMovContext(bb->tyenv->types_used); 


   // Copy verbatim any IR preamble preceding the first IMark
   i = 0;
   while (i < bb_in->stmts_used && bb_in->stmts[i]->tag != Ist_IMark) {
      addStmtToIRSB( bb, bb_in->stmts[i] );
      i++;
   }

     cgAddPreamble(bb,caMainBBCounter); 

   for (/*use current i*/; i < bb_in->stmts_used; i++) {
      IRStmt* st = bb_in->stmts[i];
      if (!st || st->tag == Ist_NoOp) continue;

      
      if (st->tag == Ist_Exit)
	{
	  cgAddExitPre(bb,st);
	}

      addStmtToIRSB(bb, st );
      if (ca_type_inference)
      {
	ogIRStmt(bb, st, caMainBBCounter);
      }
      
      ufInstOgIRStmt(bb, st, caMainBBCounter); 
      findRepMovIRStmt(bb, st, repMovContext, caMainBBCounter); 
      isIRStmt(bb, st, caMainBBCounter); 
      tmIRStmt(bb, st, caMainBBCounter);
      cgIRStmt(bb, st, caMainBBCounter); 
     
      if (st->tag == Ist_Exit)
      {
	cgAddExitPost(bb,st);  
      }
      
   }


   /* Update count of BBs instrumented. Do it here to agree with */
   /* Valgrind core numbering of BBs instrumented.               */ 
   caMainBBCounter++; 

   /* Destroy the rep mov context */ 
   destroyRepMovContext(repMovContext); 

   /* Return the new bb */ 
    return bb;
}

void ca_printStats(void)
{

  VG_(printf)("XXX Stat counters: \n"); 
  VG_(printf)("XXX Unhandled binop: %d \n", numUnhandledBinops); 
  VG_(printf)("XXX Unhandled unop: %d \n", numUnhandledUnops); 
  VG_(printf)("XXX CalcCondition: %d \n", numCalcCondition); 

}

static void ca_fini(Int exitcode)
{

  if (emitPathCondp && !inlinePathQueriesP) cgEmitPathCond(); 

  ca_printStats(); 

  return; 
}

static void ca_pre_clo_init(void)
{
   VG_(details_name)            ("Catchconv");
   VG_(details_version)         (NULL);
   VG_(details_description)     ("a type mismatch constraint generator");
   VG_(details_copyright_author)(
      "Copyright (C) 2006-7, Regents of the University of California, Berkeley.");
   VG_(details_bug_reports_to)  (VG_BUGS_TO);

   VG_(basic_tool_funcs)        (ca_post_clo_init,
                                 ca_instrument,
                                 ca_fini);


   /* Initialize hash tables */ 
   ogVarOf = VG_(HT_construct) ("ogVarOf");
   ogTypeOf = VG_(HT_construct) ("ogTypeOf"); 
   ufOgHash = VG_(HT_construct)("ufOgHash");
   ufOgLiveTempVarNodes = VG_(HT_construct)("ufOgLiveTempVarNodes");
   cgPathCond = VG_(HT_construct)("cgPathCond"); 
   isIsSymbolic = VG_(HT_construct)("isIsSymbolic"); 
   caIntervalTable = VG_(HT_construct)("caIntervalTable"); 
   cgIsDeclared = VG_(HT_construct)("cgIsDeclared"); 
   cgIsDeclaredWide = VG_(HT_construct)("cgIsDeclaredWide"); 
   cgITEWriteStackMemSt = VG_(HT_construct)("cgITEWriteStackMemSt"); 
   cgITEWriteStackMaSt = VG_(HT_construct)("cgITEWriteStackMaSt"); 
   tmAddrToVar = VG_(HT_construct)("tmAddrToVar");
   argStructHashTable = VG_(HT_construct)("argStructHashTable");


   /* Track new stack entries */ 
   VG_(track_new_mem_stack)(&ca_track_new_mem_stack); 

   /* Declare that we take command line options */ 
   VG_(needs_command_line_options)(ca_process_cmd_line_option,
                                   ca_print_usage,
                                   ca_print_debug_usage);

   /* Mark argv[] as symbolic - currently turned off */
   //   ca_make_args_origin();

   VG_(track_pre_mem_write)(ca_track_pre_mem_write); 
   VG_(track_post_mem_write)(ca_track_post_mem_write); 
   VG_(track_post_reg_write)(ca_track_post_reg_write); 
   VG_(track_post_reg_write_clientcall_return)(ca_track_post_reg_write_clientcall_return); 
   
   /* Register callbacks before and after syscalls */ 
   VG_(needs_syscall_wrapper) ( ca_pre_syscall,
				ca_post_syscall); 



   /* Declare that we need malloc replacements */ 
   /*  VG_(needs_malloc_replacement)  ( CA_malloc,
                                   CA__builtin_new,
                                   CA__builtin_vec_new,
                                   CA_memalign,
                                   CA_calloc,
                                   CA_free,
                                   CA__builtin_delete,
                                   CA__builtin_vec_delete,
                                   CA_realloc,
                                   CA_MALLOC_REDZONE_SZB );
   */ 
 /* Discarding the basic block */
 /* VG_(needs_basic_block_discards)(removeStructOf); */

}

VG_DETERMINE_INTERFACE_VERSION(ca_pre_clo_init)

/*--------------------------------------------------------------------*/
/*--- end                                                          ---*/
/*--------------------------------------------------------------------*/
