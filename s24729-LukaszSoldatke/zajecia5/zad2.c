#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t main_process_pid = getpid();
	pid_t pid = fork();

	if (pid > 0) {
		printf("Parent PID: %d\n", getpid());
		printf("Parent PPID: %d\n", getppid());
	} else {
		printf("Child PID: %d\n", getpid());
		printf("Child PPID: %d\n", getppid());
	}

	if (main_process_pid == getpid()) {
		int status = 0;
		waitpid(0, &status, 0);
	}

	return 0;
}
