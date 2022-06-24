#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void usr1Handler(int signum) {
        printf("Wykryto probe uruchomienia drugiej instancji programu\n");
}

void intHandler(int signum) {
        remove("/tmp/lock");
	exit(1);
}

int main() {
	int active_process_pid;
	FILE* lock_file = fopen("/tmp/lock", "r");

	printf("Moj PID: %d\n", getpid());

	if (lock_file == NULL) {
		printf("Plik lock NIE ISTNIEJE, tworze nowy.\n");
		lock_file = fopen("/tmp/lock", "w");
		fprintf(lock_file, "%d", getpid());
		signal(SIGUSR1, usr1Handler);
        	signal(SIGINT, intHandler);
		fclose(lock_file);
                while (1) {
                        sleep(1);
                }
	} else {
		printf("Plik lock ISTNIEJE, wczytuje jego zawartosc.\n");
		fscanf(lock_file, "%d", &active_process_pid);
		fclose(lock_file);
		printf("Wysylam USR1 do PID: %d\n", active_process_pid);
		raise(SIGUSR1);
	}

	return 0;
}
