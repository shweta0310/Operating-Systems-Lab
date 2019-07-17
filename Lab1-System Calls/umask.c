#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define MAX 100
int main()
{
	umask(S_IWGRP | S_IWOTH);
	int fd=open("open.txt",O_CREAT|O_WRONLY, 0666);
	printf("\nopened fd= %d",fd);
	printf("\numask fd= %d",umask(S_IWGRP | S_IWOTH));
	int fd1=close(fd);
	printf("\nclosed fd= %d\n",fd1);
}
