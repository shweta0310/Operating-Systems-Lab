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
	execl("hello",NULL);
	int fd1=close(fd);
	printf("\nclosed fd= %d\n",fd1);
}
