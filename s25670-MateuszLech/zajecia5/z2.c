#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int input;
    pid_t pid = fork();

    if(pid > 0)
    {
        printf("R PID: %d\tR PPID: %d\n", getpid(), getppid());
        waitpid(0, &input, 0);
        printf("Rodzic zakonczyl czekanie na swoje dziecko\n");
        /*rodzic*/
    }

    else if(pid == 0)
    {
        printf("D PID: %d\tD PPID: %d\n", getpid(), getppid());
        /* dziecko */
    }

    else
    {
        printf("Nie udalo sie utworzyc dziecka\n");
    }

    return 0;
}
