int main (int argc, char** argv)
{
	int i = atol(argv[1]);
	unsigned int j = 0;

	if (i < 10)
	{
		j = i; 
		if ( j > 50) 
		{
		 printf("Surprise! Bad input : %x \n", j); 
		 return 1;
		}
	}

return 0;

}
