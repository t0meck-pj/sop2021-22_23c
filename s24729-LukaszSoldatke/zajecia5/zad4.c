#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int i;
	pid_t main_process_pid = getpid(), pid;

	for (i = 0; i < 101; i++) {
		pid = fork();

		if (pid > 0) {
                        break;
                }
	}

	if (main_process_pid == getpid()) {
		printf("Proces glowny z nr PID: %d\n", getpid());
	} else {
		printf("Proces potomny z nr PID: %d\n", getpid());
	}

	if (pid > 0) {
		int status = 0;

		waitpid(0, &status, 0);
		sleep(1);
	}

	if (main_process_pid == getpid()) {
		printf("\n");
	}

	return 0;
}
