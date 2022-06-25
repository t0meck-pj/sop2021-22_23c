/*Przygotuj program, który będzie pozwalał na uruchomienie tylko jednej swojej
instancji.
Dodatkowo w momencie próby uruchomienia drugiej instancji będzie powiadamiał
już uruchomiony proces o tym.
Można to zrobić tak:
Program uruchamia się i sprawdza, czy jest plik /tmp/lock
Jeśli taki plik nie istnieje, wtedy:
tworzony jest taki plik. Do niego zapisywany jest PID bieżącego procesu
program instaluje obsługę sygnału USR1, która w momencie otrzymania sygnału
wypisuje tekst:
Wyrkyto probe uruchomienia drugiej instancji programu.
program instaluje obsługę sygnału generowanego przez CTRL+C (poszukaj jaki to
sygnał), która w momencie otrzymania tego sygnału skasuje plik /tmp/lock i
spowoduje wyjście z pętli nieskończonej (patrz następny punkt)
program wykonuje pętlę nieskończoną zawierającą tylko instrukcję sleep.
Jeśli taki plik istnieje, wtedy:
Wczytywana jest zawartość tego pliku - pid procesu uruchomionego
generowany jest sygnał USR1 do procesu o pid takim jak wczytany
program kończy pracę
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void multipleInstancesErrorMessage()
{
    printf("Wyrkyto probe uruchomienia drugiej instancji programu.\n");
    exit(1);
}

void deleteLock()
{
    remove("/tmp/lock");
}

int main()
{
    FILE *file;
    signal(SIGINT, deleteLock);
    signal(SIGUSR1, multipleInstancesErrorMessage);

    if (access("/tmp/lock", F_OK) == 0)
    {
        int pid = 0;
        file = fopen("/tmp/lock", "r");
        fscanf(file, "%i", &pid);
        printf("PID = %i\n", pid);
        raise(SIGUSR1);
    }
    else
    {
        file = fopen("/tmp/lock", "w");
        fprintf(file, "%i", getpid());
        while (1)
        {
            sleep(10);
        }
    }
    return 0;
}
