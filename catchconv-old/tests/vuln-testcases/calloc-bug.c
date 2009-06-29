#include <stdio.h>
/* Test case for calloc() argument bug. */
/* Leads to NULL deref on modern 
/* See  http://bugzilla.mplayerhq.hu/show_bug.cgi?id=1113 */
/* See  http://cert.uni-stuttgart.de/advisories/calloc.php */

int main (int argc, char** argv)
{
  int i = 0;
  int j = 0;
  int * buf;
  FILE * infile; 

  infile = fopen(argv[1],"r"); 
  fread(&i, sizeof(int), 1, infile); 

  /* Possible calloc() bug - i could be negative */
  /* On modern libc results in NULL return       */
  /* Older libc will allocate the wrong amount   */
  buf = calloc(i, sizeof(int)); 
 

  /* This will cause InvalidWrite when i is negative. */
  /* On modern libc this is a NULL deref, but on      */
  /* older libc can cause heap overflow.              */
  for(j = 0; j<i; j++)
  {
     buf[j] = 42; 
  }

return 0;
}
