/*--------------------------------------------------------------------*/
/*--- CatchConversions                           catchconv.h       ---*/
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

/* Constants */

/* In some cases we have functions with constant arguments in the IR. */
/* When we see a constant argument, pass in this dummy value for the  */
/* "temp name" of the argument to the constraint generation function. */ 
#define ARG_IS_CONSTANT 0


/* Globals visible to both type constraint and STP constraint gen */

extern char * inputfilename; 
extern int run_prefix_task; // Avoid the prefix
Int run_buffer_overflow_task;

/* Utility functions */ 
void setHelperAnns ( IRDirty* di ); 
HWord numBytesOfConst ( IRConst * con); 
HWord numBytesOfTmpvar ( IRSB * bb, IRTemp tmp);
HWord numBytesOfType ( IRType ty);  

/* ca_main prototypes */ 

void ca_read_memregions_from_file(char * path);
void ca_read_origins_from_file(char * path);
void ca_print_usage(void);
void ca_print_debug_usage(void);
Bool ca_process_cmd_line_option(Char* arg);
void ca_make_args_origin(void);
void ca_track_new_mem_stack(Addr a, SizeT len);
