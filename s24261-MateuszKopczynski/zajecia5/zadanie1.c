#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    int number = 0;

    printf("PID: %d \n", pid);
    printf("PPID: %d \n", ppid);
    if (scanf("%d", &number)) {};

    return 0;
}
