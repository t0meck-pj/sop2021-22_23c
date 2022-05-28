#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int i;
    	for (i = 0; i <= 100; i++) {
        	if (fork() == 0) {
           		printf("Dziecko nr %d, PID dziecka: %d, PPID: %d \n", i, getpid(), getppid());
            		return 0;
        	}
	wait(0);
    	}

    	for (i = 0; i <= 100; i++) {
        	waitpid(0, 0, 0);
    	}

    	return 0;
}
