#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    int input;
    int liczba = atoi(argv[1]);
    pid_t pid = fork();

    if(pid > 0)
    {
        int suma = 0;
        int i = 0;

        for(i = 0; i <= liczba; i++)
        {
            suma+=i;
        }

        waitpid(0, &input, 0);
        printf("Suma z rodzica: %d\n", suma);
    }

    else if(pid == 0)
    {
        int i=0;

        for(i = 1; i <= liczba; i = i+2)
        {
            printf("Dziecko, liczba nieparzysta: %d\n", i);
        }
    }

    else
    {
        printf("Nie udalo sie utworzyc dziecka\n");

    }

    return 0;
}
