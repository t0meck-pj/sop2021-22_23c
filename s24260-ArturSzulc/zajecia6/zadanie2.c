#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sigUsrFunction() {
    printf("Wykryto probe uruchomienia drugiej instancji programu.");
    exit(1);
}

void sigIntFunction() {
    remove("/tmp/lock");
}

int main() {
    FILE* file;
    signal (SIGUSR1, sigUsrFunction);
    signal (SIGINT, sigIntFunction);

    file = fopen("/tmp/lock", "r");

    if (!file) {
        file = fopen("/tmp/lock", "w");
        fprintf(file, "%d", getpid());
        fclose(file);

        while(1) { sleep(1); }
    } else {
        int pid;
        fscanf (file, "%d", &pid);
        fclose(file);

        raise(SIGUSR1);
    }

    return 0;
}
