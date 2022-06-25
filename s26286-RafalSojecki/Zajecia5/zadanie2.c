/*
Napisz program, który uruchomi podproces za pomocą komendy fork. Niech proces
rodzica oczekuje na proces potomka. Oba procesy powinny wypisać swój PID oraz
PPID.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t currentPID = getpid();
    pid_t childPID = fork();
    int status;
    waitpid(0, &status, 0);
    if (childPID > 0)
    {
        printf("Rodzic\tPID: %i\tPPID:%i\n", getpid(), getppid());
    }
    else
    {
        printf("Dziecko\tPID: %i\tPPID:%i\n", getpid(), getppid());
    }

    return 0;
}
