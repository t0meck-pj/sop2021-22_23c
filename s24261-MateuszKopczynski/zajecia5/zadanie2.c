#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t masterPid = getpid();
    int p = fork();

    if (p > 0) {
        printf("PID rodzica: %d \n", getpid());
        printf("PPID rodzica: %d \n", getppid());
    }
    else {
        printf("PID dziecka: %d \n", getpid());
        printf("PPID dziecka: %d \n", getppid());
    }

    if (masterPid == getpid()) {
       int status = 0;
       waitpid(0, &status, 0);
    }

    return 0;
}
