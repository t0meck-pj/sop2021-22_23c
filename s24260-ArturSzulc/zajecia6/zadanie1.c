#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

//https://stackoverflow.com/questions/7508630/why-does-printf-not-work-before-infinite-loop

void myFunction(int signalNumber){

    printf("End by %d \n", signalNumber);
    exit(1);
}

int main() {
    signal(SIGUSR1, myFunction);
    printf("My pid is: %d \n", getpid());
    fflush(stdout);

    while (1) {}
    return 0;
}
