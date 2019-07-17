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
	/*printf("READ() SYSTEM CALL\nwith count=0 :\n");
	int fd2=read(fd,data,0);
	printf("No. of bytes read = %d\n ",fd2);	//returns 0 if no error
	printf("with count<=MAX :\n");
	fd2=read(fd,data,MAX);
	printf("No. of bytes read = %d\n ",fd2);	//returns no. of bytes read
	printf("with count>MAX :\n");
	fd2=read(fd,data,MAX+5);
	printf("No. of bytes read = %d\n ",fd2);	//unexpected results*/
	
	/*printf("\nWRITE() SYSTEM CALL");
	printf("\nEnter data to be written : ");
	gets(data);
	int fd3=write(fd,data,strlen(data));
	printf("\nNo. of bytes written= %d\n",fd3);
	fd3=write(fd,data,strlen(data));
	printf("\nNo. of bytes written= %d\n",fd3);*/
	//close(fd);
	/*fd=open("open.txt",O_RDWR);
	int fd2=read(fd,d1,MAX);
	d1[fd2]='\0';
	putchar('\n');puts(d1);*/
	
	/*printf("\nLSEEK() SYSTEM CALL");
	int fd2=read(fd,d1,MAX);
	putchar('\n');puts(d1);
	printf("\nNo. of bytes read = %d",fd2);
	int seek=lseek(fd,5, SEEK_SET); 
	printf("\nlseek return= %d",seek);
	fd2=read(fd,d1,MAX);
	d1[fd2]='\0';
	putchar('\n');puts(d1);*/
	
	/*printf("\nDUP() SYSTEM CALL");
	int newfd=dup(fd);
	printf("\n new fd =%d",newfd);*/
	
	/*printf("\nLINK() SYSTEM CALL");
	int link1=link("open.txt","o.txt");
	printf("\n link =%d",link1);
	
	int unlink1=unlink("o.txt");
	printf("\n unlink =%d",unlink1);*/
	
	int fd1=close(fd);
	printf("\nclosed fd= %d\n",fd1);
}

