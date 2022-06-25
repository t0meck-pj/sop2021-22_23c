/*
Przygotuj prosty programik, który:
Wypisze na ekranie swój PID
będzie czekał w pętli nieskończonej do momentu otrzymania sygnału
użytkownika (SIGUSR1)
W momencie otrzymania tego sygnału program powinien wypisać na
ekranie, że dostał sygnał i się zakończyć.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void message(int signalNumber)
{
    printf("Zakonczono, kod sygnalu: %i\n", signalNumber);
    exit(1);
}

int main()
{
    signal(SIGUSR1, message);
    printf("PID:%i\n", getpid());
    while (1)
    {
    }
    return 0;
}

/*

Konsola 1
>./zadanieSygnaly1
PID:28182
Zakonczono, kod sygnalu: 30

Konsola 2

kill -SIGUSR1 28182

*/
