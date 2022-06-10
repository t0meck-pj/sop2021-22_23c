#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int signal){
    printf("Program zakonczyl sie");
    exit(1);
}

int main() {
    signal(SIGUSR1, signalHandler);
    printf("PID: %d \n", getpid());

    for(;;){};

    return 0;
}
