#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int main()
{
    pid_t pid;
    pid_t getpid();
    int sig;
    kill(pid,sig);
    printf("\nkill()=%d\n",kill(pid,sig));
    return 0;
}
