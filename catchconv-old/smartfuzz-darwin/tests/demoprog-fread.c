#include <stdio.h>

int main (int argc, char** argv)
{
  int i = 0;
  unsigned int j = 0;
  FILE * infile; 
  
  infile = fopen(argv[1],"r"); 
  fread(&i, 4, 1, infile); 

	if (i < 0x20746e6A)
	{
		j = i; 
		if ( j > 0x80000000) 
		{
		 printf("Surprise! Bad inputs : %x %x \n", i, j); 
		 return 1;
		}
                else
		{
		 printf("Good i < 0x20746e69 j < 0x80000000 input : %x %x \n", i, j); 
                }
	}
	else
	{
	  j = i; 
	  printf("Good inputs : %x %x \n", i, j); 
        }

return 0;

}
