#include <fcntl.h>
#include <errno.h>
#include "namelist.h"
#include <unistd.h>
#include <sys/types.h>
#define  MAXTRIES 5

int search(char *where,char *number)

{
	//char where2[1024];
	//strcpy(where2, where);
	char namelist[1024]="namelist";
	//strcat(where2, s1);  //문자열 붙이기
    struct flock lock;
    struct namelist namelist2;
    struct namelist namelist3;
    int fd, sum = 0, try = 0;
    
    if ((fd = open(namelist, O_RDWR)) == -1) {
        perror(namelist);
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
            printf("%s busy -- try later \n", namelist);
            return -1;
        }
        perror(namelist);
        return -1;
    }
    int start= -1,end=-1;
    while (read(fd, (char *) &namelist2, sizeof(namelist2)) > 0) {
       
		if(strcmp(namelist2.number,number)==0){
			start= lseek(fd,0,SEEK_CUR)-sizeof(namelist2);
			break;
			}
            
    }

    lock.l_type = F_UNLCK; /* unlock file */
    fcntl(fd, F_SETLK, &lock);
    close(fd);
    return start;
}
