int main (int argc, char** argv)
{
	printf("%x \n", &argv[1]); 
	int i = atol(argv[1]);
	printf("%x \n", &i); 
	unsigned int j = 0;

	if (i < 10)
	{
		j = i; 
		if ( j > 50) 
		{
		 printf("Surprise! \n"); 
		 return 1;
		}
	}

return 0;

}
