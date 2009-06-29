/* From blexim "Basic Integer Overflows" */ 
/* http://www.phrack.org/issues.html?issue=60&id=10#article */ 
/* slightly modified to read from file instead of argv */ 

/* width1.c - exploiting a trivial widthness bug */
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]){
            char input[80]; 
            unsigned short s;
            int i;
            FILE * fd = fopen(argv[1], "r"); 
            char buf[80];


            if(argc < 3){
                    return -1;
            }

	    fgets(input, sizeof input, fd);
            i = atoi(input); 
            s = i;

            if(s >= 80){            /* [w1] */
                    printf("Oh no you don't!\n");
                    return -1;
            }

            printf("s = %d\n", s);

            memcpy(buf, argv[2], i);
            buf[i] = '\0';
            printf("%s\n", buf);

            return 0;
    }



