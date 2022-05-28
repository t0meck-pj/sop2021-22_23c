#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int masterPid = getpid();
	int parentPid = getppid();
	int number;

	printf("Pid is = %d \n", masterPid);
	printf("Parent Pid is = %d \n", parentPid);
	printf("Write number:");
	scanf("%d", &number);
	return 0;
}
