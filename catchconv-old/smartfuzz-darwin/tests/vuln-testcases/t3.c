#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/* Test case for malloc(arg), arg overflowed argument bug. */
/* See CESA-2007-006 notes                                 */


/* Original code snippet:

pcre_compile:
---
// Compute the size of data block needed and get it, either from malloc or
// externally provided function. 

size = length + sizeof(real_pcre) + name_count * (max_name_size + 3);
re = (real_pcre *)(pcre_malloc)(size);
---

Unfortunately, a malicious regex can easily cause large "name_count" and 
"max_name_size" such that this calculation overflows. Demo:


*/ 


int main (int argc, char** argv)
{
  int size = 0; 
  int length = 0; 
  int name_count = 0; 
  int max_name_size = 0; 
  char * re; 
  char   real_pcre[128]; 
  int infile; 

  infile = open(argv[1],O_RDONLY); 
  read(infile, &name_count, sizeof(int)); 
  read(infile, &max_name_size, sizeof(int)); 

  /* Malicious regex in pcr can cause large name_count and max_name_size */
  size = length + sizeof(real_pcre) + name_count * (max_name_size + 3);
  re = (char *)malloc(size); 

  return 0;
}
