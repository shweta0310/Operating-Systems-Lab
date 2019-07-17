#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
void sighandler(int signum)
{
	printf("\nSignal reached\n");
	exit(0);
}
int main()
{
	signal(SIGINT,sighandler);
	while(1)
	{
		printf("\nSignal not reached");
	}
	return 0;
}
	

