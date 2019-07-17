#include <unistd.h> 
#include<stdio.h>
int main()
{
	int fd=chdir("/home/student/171CO245/create");
	printf("\nchdir()=%d\n",fd);
	return 0;
} 
