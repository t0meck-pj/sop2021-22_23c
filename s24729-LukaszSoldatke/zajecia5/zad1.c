#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int x;

	printf("PID: %d\n", getpid());
	printf("PPID: %d\n", getppid());
	scanf("%d", &x);

	return 0;
}
