#include <fcntl.h>
#include <errno.h>
#include "namelist.h"
#include <unistd.h>
#include <sys/types.h>
#define  MAXTRIES 5

void remove2(char *where){
	listread();
	char number[30];
    printf("삭제할 학번을 입력하시오: ");
    scanf(" %[^\n]",number);
    struct flock lock;
    struct namelist namelist2;
    struct namelist namelist3;
    int fd, sum = 0, try = 0;
    char where2[100]="namelist";
    
    if ((fd = open(where2, O_RDWR)) == -1) {
        perror(where2);
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
            printf("%s busy -- try later \n", where2);
            return -1;
        }
        perror(where2);
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
		else if(strcmp(namelist2.number,number)==0){
			start=lseek(fd,0,SEEK_CUR)-sizeof(namelist2);
			}
            
    }
    if(start>=0){
		printf("reset\n");
		ftruncate (fd, start);
		char doit[100]="rm ";
		strcat(doit,number);
		system(doit);
		}
	else{
		printf("존재하지않습니다\n");
		}

    lock.l_type = F_UNLCK; /* unlock file */
    fcntl(fd, F_SETLK, &lock);
    close(fd);
}
