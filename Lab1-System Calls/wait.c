
// C program to demonstrate working of wait() 
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  
int main() 
{ 
    if (fork()== 0) 
        printf("HC: hello from child\n"); 
    else
    { 
        printf("HP: hello from parent\n"); 
        printf("\n%d",wait(NULL)); 
        printf("CT: child has terminated\n"); 
    } 
  
    printf("Bye\n");
	
    return 0; 
} 
//wait(): on success, returns the process ID of the terminated child; on error, -1 is returned.
