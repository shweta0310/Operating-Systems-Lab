/*Changes the owner or group (or both) of a file. pathname is the name of the file whose owner or group you want to change. owner is the user ID (UID) of the new owner of the file. group is the group ID (GID) of the new group for the file.*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define MAX 100
int main()
{
	int fd=open("open.txt",O_RDWR);
	printf("\nopened fd= %d",fd);
	uid_t uid=1001;
	gid_t gid=1001;
	int fd2=chown("open.txt",uid,gid);
	printf("\nchown() fd=%d",fd2);
	int fd1=close(fd);
	printf("\nclosed fd= %d\n",fd1);
}

	
	
