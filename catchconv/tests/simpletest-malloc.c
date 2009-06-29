#include<stdlib.h>

int main (int argc, char** argv)
{
int * ptr; 

	printf("%x\n",&(argv[1]));
	int i = atol(argv[1]);
	printf("%x\n",&i); 
	unsigned int j = 0;

	if (i < 10)
	{
		j = i; 
		ptr = (int *) malloc(j); 
	}

return 0;

}
