#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "student.h"
long CarculDate(int year, int month, int day);
void returndate(int date[6],int when[6][12],char *argv) {
	printf("%s",argv);
        int fd;
        long daytime = 60 * 60 * 24;
        time_t start, end;
        start = CarculDate(date[0] - 1969, date[1], date[2]) * daytime;
        end = CarculDate(date[3] - 1969, date[4], date[5]) * daytime;
        struct tm* t;
        t=localtime(&start);
        struct student student;
        if((fd= open(argv,O_WRONLY | O_CREAT | O_EXCL, 0640))== -1) {
                perror(argv);
                exit(2);
        }
        while (start <= end) {
                for (int i = 0; i < 6; i++) {
            if (when[i][0] == -1) {
                                break;
                        }
                        if (t->tm_wday == when[i][0]) {//0일요일 1 월요일... 6토요일
                                int year = t->tm_year + 1900;
                                int month = t->tm_mon + 1;
                                int day = t->tm_mday;
                                for (int j = 1; j < 12; j++) {
                                        if(when[i][j]==-1){
                                                break;
                                        }
                                        else {
                                                student.time=start;
                                                student.period=when[i][j];
                                                student.how=-1;
                                                student.pid=getpid();
                                                write(fd,(char *) &student,sizeof(student));
                                        }
                                }
                        }
	}
	

                start += daytime;
                t=localtime(&start);
        }
        close(fd);
}

