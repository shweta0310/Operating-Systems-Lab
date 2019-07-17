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
	int fd2=access("open.txt",F_OK);	
	/* F_OK tests for the existence of the
       file.  R_OK, W_OK, and X_OK test whether the file exists and grants
       read, write, and execute permissions, respectively.*/
	printf("\nAccess() fd= %d",fd2);	//0 success, 1 error
	int fd1=close(fd);
	printf("\nclosed fd= %d\n",fd1);
}

