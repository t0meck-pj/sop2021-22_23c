#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i, childNumber = 100;

    for (i = 0; i <= childNumber; i++) {
	int p = fork();

        if (p == 0) {
            printf("PID dziecka: %d, PPID: %d \n", getpid(), getppid());
            return 0;
        }
    }

    for (i = 0; i <= childNumber; i++) {
    	waitpid(0, 0, 0);
    }

    return 0;
}
