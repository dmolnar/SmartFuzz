/* Also from blexim "Basic Integer Overflows */
/* TODO: make this read from a file, then turn into a test case */
/* by calling abort() if overflow happens. */ 
/* ex2.c - an integer overflow */
    #include <stdio.h>

    int main(int argc, char ** argv){
      char input[80]; 
      FILE *fd = fopen(argv[1], "r"); 
      fgets(input, sizeof input, fd); 
      unsigned int num = input[0];
      unsigned int num2 = num + 1; 

      if (num2 < num)
      {
            printf("num is %d bits long\n", sizeof(num) * 8);
            printf("num = 0x%x\n", num);
            printf("num + 1 = 0x%x\n", num + 1);
	    abort(); 
      }
            return 0;
    }
    /* EOF */
