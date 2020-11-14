#include<stdio.h>
main(argc,argv)
int argc;
char *argv[];
{
        if(argc < 2) {
                fprintf(stderr,"Usage: %s file\n",argv[0]);
                exit(1);
        }
        printf("result= %d\n",search("",argv[1]));
}
