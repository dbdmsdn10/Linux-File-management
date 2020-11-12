#include <fcntl.h>
#include <errno.h>
#include "namelist.h"
#include <unistd.h>
#include <sys/types.h>
#define  MAXTRIES 5

main(argc, argv)
int argc;
char* argv[];
{
    struct flock lock;
    struct namelist namelist2;
    struct namelist namelist3;
    int fd, sum = 0, try = 0;
    
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
    }

    lock.l_type = F_RDLCK;
    lock.l_whence = 0;
    lock.l_start = 0L;
    lock.l_len = 0L; /* whole file adders space */
    while (fcntl(fd, F_SETLK, &lock) == -1) {
        if (errno == EACCES) {
			
            if (try++ < MAXTRIES) {
                sleep(1);
                continue;
            }
            printf("%s busy -- try later \n", argv[1]);
            return -1;
        }
        perror(argv[1]);
        return -1;
    }
    int start= -1,end=-1;
    while (read(fd, (char *) &namelist2, sizeof(namelist2)) > 0) {
        if(start>=0){
			end=lseek(fd,0,SEEK_CUR);
			
			lseek(fd,start,SEEK_SET);
				strcpy(namelist3.name,namelist2.name);
				strcpy(namelist3.number,namelist2.number);
				write(fd,(char *) &namelist3,sizeof(namelist3));
				start=lseek(fd,0,SEEK_CUR);
				lseek(fd,end,SEEK_SET);
			}
		else if(strcmp(namelist2.number,argv[2])==0){
			start=lseek(fd,0,SEEK_CUR)-sizeof(namelist2);
			}
            
    }
    if(start>=0){
		printf("reset\n");
		ftruncate (fd, start);
		}

    lock.l_type = F_UNLCK; /* unlock file */
    fcntl(fd, F_SETLK, &lock);
    close(fd);
}
