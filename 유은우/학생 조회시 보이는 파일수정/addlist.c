#include <fcntl.h>
#include "namelist.h"
void addlist(char s1[30] ,char s2[30]) {
	struct namelist namelist2;
	int fd;
	if((fd= open("namelist",O_WRONLY | O_CREAT | O_EXCL, 0640))== -1) {
                if((fd= open("namelist",O_RDWR | O_CREAT, 0640))== -1) {
					perror("just error");
					exit(2);
				}
				else{
					lseek(fd,0,SEEK_END);
				}
        }
        strcpy(namelist2.name,s1);
        strcpy(namelist2.number,s2);
        printf("name= %s값을 받았습니다\n",namelist2.name);
        printf("number= %s값을 받았습니다\n",namelist2.number);

		write(fd,(char *) &namelist2,sizeof(namelist2));
		close(fd);
                                                
}
