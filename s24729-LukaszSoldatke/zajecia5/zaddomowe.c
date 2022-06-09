#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int wait_for_input;
	pid_t pid;

	printf("Proces glowny A, PID: %d, PPID: %d\n", getpid(), getppid());

	pid = fork();
	printf("Proces potomny B, PID: %d, PPID: %d\n", getpid(), getppid());

	if (pid > 0) {
		pid = fork();
		printf("Proces potomny C, PID: %d, PPID: %d\n", getpid(), getppid());
	}

	if (pid == 0) {
		pid = fork();
		printf("Proces potomny potomka D/F, PID: %d, PPID: %d\n", getpid(), getppid());

		if (pid > 0) {
			pid = fork();
			printf("Proces potomny potomka E/G, PID: %d, PPID: %d\n", getpid(), getppid());
		}
	}

	scanf("%d", &wait_for_input);

	return 0;
}
