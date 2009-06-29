#include <stdio.h>
/* Test case for malloc(i1*i2) argument bug. */

int main (int argc, char** argv)
{
  int i1 = 0;
  int i2 = 0; 
  int j = 0;
  int * buf;
  FILE * infile; 

  infile = fopen(argv[1],"r"); 
  fread(&i1, sizeof(int), 1, infile); 
  fread(&i2, sizeof(int), 1, infile); 

  /* Possible malloc() bug - i1*i2 could overflow */
  buf = malloc(i1*i2); 
 

  /* This will cause InvalidWrite when i1*i2 overflows. */
  /* On VS 2005 and some gcc this is a NULL deref,      */
  /* in other cases can cause heap overflow.            */
  for(j = 0; j<i2; j++)
  {
     buf[j] = 42; 
  }

return 0;
}
