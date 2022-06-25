/*Napisz program, który uruchomi 100 procesów potomnych w taki sposób, że
będzie jeden rodzic i 100 potomków.
Proces główny niech oczekuje na zakończenie wszystkich procesów potomnych.
Przydatne funkcje: waitpid i wait
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int childCount = 10;

    while (childCount--)
    {
        if (fork() == 0)
        {
            sleep((rand() + childCount) % 5);
            printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
            break;
        }
        int status;
        wait(&status);
    }

    return 0;
}
