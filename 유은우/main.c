#include<stdio.h>
main(argc,argv)
int argc;
char *argv[];
{
        if(argc < 2) {
                fprintf(stderr,"Usage: %s file\n",argv[0]);
                exit(1);
        }
        Addstudent(argv[1]);
}
