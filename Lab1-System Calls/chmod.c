#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define MAX 100
void main()
{
	int fd=open("open.txt",O_RDWR);
	printf("\nopened fd= %d",fd);
	char data[MAX],d1[MAX];
	int fd2=chmod("open.txt",S_IRUSR);
	printf("\nchmod() fd= %d",fd2);	//0 success, 1 error
	int fd1=close(fd);
	printf("\nclosed fd= %d\n",fd1);
}
/*
chmod, fchmod - change permissions of a file

Tag	Description
S_ISUID 	04000 set user ID on execution
S_ISGID 	02000 set group ID on execution
S_ISVTX 	01000 sticky bit
S_IRUSR 	00400 read by owner
S_IWUSR 	00200 write by owner
S_IXUSR 	00100 execute/search by owner
S_IRGRP 	00040 read by group
S_IWGRP 	00020 write by group
S_IXGRP 	00010 execute/search by group
S_IROTH 	00004 read by others
S_IWOTH 	00002 write by others
S_IXOTH 	00001 execute/search by others 
*/
