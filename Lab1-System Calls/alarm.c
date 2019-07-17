#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void handle_alarm( int sig ) {
    printf("\nAlarm set\n");
    exit(0);
}

int main() {
    signal( SIGALRM, handle_alarm ); // Install handler first,
    alarm( 1 ); // before scheduling it to be called.

    while(1){
    printf("\nAlarm not set");
    }
}
