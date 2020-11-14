#include <fcntl.h>
#include <errno.h>
#include "namelist.h"
#define  MAXTRIES 5

void listread()
{
    struct flock lock;
    struct namelist namelist2;
    int fd, sum = 0, try = 0;
    char namelist[100]="namelist";
    
    if ((fd = open(namelist, O_RDONLY)) == -1) {
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
    while (read(fd, (char *) &namelist2, sizeof(namelist2)) > 0) {
        char *name=namelist2.name;
		char *number=namelist2.number;
        printf("name: %s \nnumber: %s\n",
            name,number);
    }

    lock.l_type = F_UNLCK; /* unlock file */
    fcntl(fd, F_SETLK, &lock);
    close(fd);
}
