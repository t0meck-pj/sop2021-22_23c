#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void received (int signum){

    if(signum == SIGUSR1){
        printf("Received signal!\n");
       }
        exit(1);
}

int main(void)
{
    int x;
    signal(SIGUSR1, received);
    signal(SIGINT, SIGUSR1);
    printf("PID %d\n", getpid());
    scanf("%d", x);


    return 0;
}
