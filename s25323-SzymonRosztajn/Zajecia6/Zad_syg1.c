#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handler(int sigNum)
{
    printf("I got a signal, it's my ending: %d\n",sigNum);
    exit(1);
}

int main()
{
    
    signal(SIGUSR1,handler);
    printf("My PID: %d \n",getpid());
    
    for(;;){};
    
    return 0;
}
