/* From blexim's article "Basic Integer Overflows" */ 
/* ex3.c - change of signedness */
    #include <stdio.h>

    int main(void){
            int l;

            l = 0x7fffffff;

            printf("l = %d (0x%x)\n", l, l);
            printf("l + 1 = %d (0x%x)\n", l + 1 , l + 1);

            return 0;
    }
    /* EOF */
