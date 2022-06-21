#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_usr1_function(int signalNumber){
    printf("Ok this is the end, bye. Number of signal: %d\n",signalNumber);
    exit(1);
}

int main(){
    signal(SIGUSR1,sig_usr1_function);
    printf("My name(PID) is: %d \n",getpid());
    while(1){}    
    return 0;
}
