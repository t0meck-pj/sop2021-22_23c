#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

bool program_should_end = false;

void handler(int signum) {
	printf("Dostalem sygnal, koncze prace\n");
	program_should_end = true;
}

int main() {
	signal(SIGUSR1, handler);

	printf("Moj PID: %d\n", getpid());

	while (! program_should_end) {
		printf("W funkcji main\n");
		sleep(5);
	}

	return 0;
}
