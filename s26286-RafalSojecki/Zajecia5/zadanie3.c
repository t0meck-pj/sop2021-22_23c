/*
Napisz program, który będzie pobierał jeden argument z wiersza poleceń
i będzie obliczał w 2 procesach:
Proces rodzica: Wartość sumy liczb od 0 do wartości zadanej jako
pierwszy argument wykonania programu.
Proces potomny: Wypisujący liczby nieparzyste od 1 do wartości zadanej
jako pierwszy argument wykonania programu.
Program powinien wypisać wyniki w kolejności takiej, że najpierw wypisze
wynik proces potomny, a następnie proces rodzica.
Nie korzystaj z komendy sleep.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int data = atoi(argv[1]);
    pid_t currentPID = getpid();
    pid_t childPID = fork();
    int status;
    waitpid(0, &status, 0);
    if (childPID > 0)
    {
        int sum = 0;

        do
        {
            sum += data;
        } while (data--);
        printf("Suma: %i\n", sum);
    }
    else
    {
        printf("Liczby nieparzyste: ");
        for (int i = 2; i <= data; i += 2)
        {
            printf("%i, ", i);
        }
        printf("\n");
    }

    return 0;
}
