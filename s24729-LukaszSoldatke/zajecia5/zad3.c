#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	int argument = atoi(argv[1]);
	pid_t main_process_pid = getpid();
	pid_t pid = fork();

	if (pid == 0) {
		int i;

                printf("Nieparzyste od 1 do %d: ", argument);
                for (i = 1; i <= argument; i++) {
                        if (i % 2 != 0) {
                                printf("%d ", i);
                        }
                }
                printf("\n");
	}

	if (main_process_pid == getpid()) {
		int status = 0;
                waitpid(0, &status, 0);
        }

	if (pid > 0) {
		int sum, i;

                for (i = 0; i <= argument; i++) {
                        sum += i;
                }
                printf("Suma liczb od 0 do %d: %d\n", argument, sum);
	}

	return 0;
}
