#include <stdio.h>

int main (void) {

	int pid = getpid();
	int ppid = getppid();

	printf("Nr PID: %d\n", pid);
        printf("Nr PPID: %d\n", ppid);
	
	scanf("%d");


return 0;
}
