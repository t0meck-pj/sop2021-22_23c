#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int i;
	pid_t main_process_pid = getpid(), pid;

	printf("Proces glowny z nr PID: %d\n", main_process_pid);

	for (i = 0; i < 100; i++) {
		pid = fork();

		if (pid == 0) {
			printf("Proces potomny z nr PID: %d\n", getpid());
			break;
		}
	}

	if (pid > 0) {
		int status = 0;

		waitpid(0, &status, 0);
		sleep(2);
	}

	if (main_process_pid == getpid()) {
                printf("\n");
        }

	return 0;
}
