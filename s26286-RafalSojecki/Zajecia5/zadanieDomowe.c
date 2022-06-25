/*Napisz program, który wygeneruje drzewko procesów wyglądające tak
(oczywiście procesy nie będą się nazywały A, B, ...):
A \
  |\B \
  |   |\D
  |    \E
   \C \
      |\F
       \G

A jest rodzicem 2 procesów - B oraz C, a te są odpowiednio rodzicami D i E,
oraz F i G.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int process = fork();

    if (process == 0)
    {
        printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
        int process2 = fork();
        if (process2 == 0)
        {
            printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
        }
        if (process2 > 0)
        {
            int process3 = fork();
            if (process3 == 0)
            {
                printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
            }
        }
    }

    if (process > 0)
    {

        int processb = fork();

        if (processb == 0)
        {
            printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
            int process2 = fork();
            if (process2 == 0)
            {
                printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
            }
            if (process2 > 0)
            {
                int process3 = fork();
                if (process3 == 0)
                {
                    printf("Process\tPID: %i\tPPID:%i\n", getpid(), getppid());
                }
            }
        }
    }
    int status;
    wait(&status);
    char x;
    scanf("%c", &x);
    return 0;
}

/*
Output z pstree (osx):
 | | |   \-+= 13681 rafal.sojecki@schibsted.pl ./zadanieDomowe
 | | |     |-+- 13682 rafal.sojecki@schibsted.pl ./zadanieDomowe
 | | |     | |--- 13684 rafal.sojecki@schibsted.pl ./zadanieDomowe
 | | |     | \--- 13686 rafal.sojecki@schibsted.pl ./zadanieDomowe
 | | |     \-+- 13683 rafal.sojecki@schibsted.pl ./zadanieDomowe
 | | |       |--- 13685 rafal.sojecki@schibsted.pl ./zadanieDomowe
 | | |       \--- 13687 rafal.sojecki@schibsted.pl ./zadanieDomowe
 */
