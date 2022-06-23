#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int gPID = getpid();
	int p = fork();
	if (p > 0) {
		printf("PID to: %d \n", getpid());
		printf("PPID to:  %d \n", getppid());
	} else {
		printf("PID dziecka: %d \n", getpid());
                printf("PPID dziecka %d \n", getppid());
	}

	if (gPID == getpid()){
       int status =0;
waitpid (0,&status,0);
}

        return 0;
}

