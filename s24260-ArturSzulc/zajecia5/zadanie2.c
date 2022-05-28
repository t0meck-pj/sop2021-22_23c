#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int masterPid = getpid();
	int p = fork();

	if (p > 0) {
		printf("Parent Pid is: %d \n", getpid());
		printf("Parent Parent Pid is %d \n", getppid());
	} else {
		printf("Child Pid is: %d \n", getpid());
                printf("Child Parent Pid is %d \n", getppid());
	}

	if (masterPid == getpid()) waitpid(0, 0, 0);

        return 0;
}
