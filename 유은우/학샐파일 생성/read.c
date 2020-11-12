#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include "student.h"
#define  MAXTRIES 5

main(argc, argv)
int argc;
char* argv[];
{
    struct flock lock;
    struct student student;
    int fd, sum = 0, try = 0;
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        return -1;
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
    sum = 0;
    struct tm* t;
    int aaa=-1;
    int kkk=1;
    time_t now;
    printf("------------%d week \n",kkk);
    kkk++;
    while (read(fd, (char *) &student, sizeof(student)) > 0) {
        t=localtime(&student.time);
		int year = t->tm_year + 1900;
        int month = t->tm_mon + 1;
        int day = t->tm_mday;
        if(aaa==-1){
			aaa=t->tm_wday;
			now=student.time;
			}
		else if(aaa>=t->tm_wday&&now!=student.time){
				printf("------------%d week \n",kkk);
				kkk++;
				aaa=t->tm_wday;
				now=student.time;
			}
        int period = student.period;
        int how = student.how;

        printf("%04d.%02d.%02d  %d 교시 상태: %d\n",
            year, month, day, period, how);
    }

    lock.l_type = F_UNLCK; /* unlock file */
    fcntl(fd, F_SETLK, &lock);
    close(fd);
}
