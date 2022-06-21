#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void exist();
void removeFile();

int main() {
    FILE* file;
    signal(SIGUSR1, exist);
    signal(SIGINT, removeFile);

    file = fopen("/tmp/lock", "r");

    if (file) {
        int pid = 0;
        fscanf(file, "%d", &pid);
        fclose(file);

        kill(pid, SIGUSR1);
    } else {
        file = fopen("/tmp/lock", "w");
        fprintf(file, "%d", getpid());
        fclose(file);

        for(;;) {}
    }

    return 0;
}

void exist() {
    printf("Wyrkyto probe uruchomienia drugiej instancji programu. \n");
    exit(1);
}

void removeFile() {
    remove("/tmp/lock");
}
