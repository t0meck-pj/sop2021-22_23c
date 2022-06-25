/*Napisz program, który uruchomi 100 procesów w taki sposób, że każdy kolejny
potomek stworzy potomka. Niech każdy proces poczeka na zakończenie procesu
potomka. Możesz korzystać z oczekiwania na wejście lub z komendy sleep i zobacz
czy drzewko procesów jest takie jak się spodziewasz (możesz w tym celu
ograniczyć liczbę procesów do 10). Zobacz podpowiedź na początku tej strony.

Czyli drzewo procesów ma wynikowo wyglądać tak:
główny -> potomek1 -> potomek2 -> ... -> potomek99 -> potomek100
Przydatne przy sprawdzaniu: Drzewo procesów można wydrukować poleceniem pstree
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    //int childCount = 10;
    int childCount = 100;

    while (childCount--)
    {
        if (fork() > 0) {
            sleep((rand() + childCount) % 5);
            printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
            break;
        }
    }
    int status;
    wait(&status);
    // char x;
    // scanf("%c", &x);

    return 0;
}

/*
Output z pstree (osx) dla 10 procesów:
 | | |   \-+= 01369 rafal.sojecki@schibsted.pl ./zadanie4
 | | |     \-+- 01370 rafal.sojecki@schibsted.pl ./zadanie4
 | | |       \-+- 01371 rafal.sojecki@schibsted.pl ./zadanie4
 | | |         \-+- 01372 rafal.sojecki@schibsted.pl ./zadanie4
 | | |           \-+- 01373 rafal.sojecki@schibsted.pl ./zadanie4
 | | |             \-+- 01374 rafal.sojecki@schibsted.pl ./zadanie4
 | | |               \-+- 01375 rafal.sojecki@schibsted.pl ./zadanie4
 | | |                 \-+- 01376 rafal.sojecki@schibsted.pl ./zadanie4
 | | |                   \-+- 01377 rafal.sojecki@schibsted.pl ./zadanie4
 | | |                     \-+- 01378 rafal.sojecki@schibsted.pl ./zadanie4
 | | |                       \--- 01379 rafal.sojecki@schibsted.pl ./zadanie4
 */