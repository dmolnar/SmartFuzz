/* From blexim's article on "basic integer overflows" */ 
/* ex4.c - various arithmetic overflows */
/* Adapted to read the value of l from a file */ 
    #include <stdio.h>

    int main(int argc, char ** argv){
            int l, x;
	    char input[80];
	    FILE *fd = fopen(argv[1], "r");
	    fgets(input, sizeof input, fd);

	    //           l = 0x40000000;
	    l = input[0]; 

            printf("l = %d (0x%x)\n", l, l);

            x = l + 0xc0000000;
            printf("l + 0xc0000000 = %d (0x%x)\n", x, x);

	    if (x == 0) 
	    {
	      exit(1); 
	    }

            x = l * 0x4;
            printf("l * 0x4 = %d (0x%x)\n", x, x);

	    if (x == 0 && (l != 0))
	    {
	      exit(2); 
	    }

            x = l - 0xffffffff;
            printf("l - 0xffffffff = %d (0x%x)\n", x, x);

	    if (x == (l + 1))
	    {
	      exit(3); 
	    }

            return 0;
    }

