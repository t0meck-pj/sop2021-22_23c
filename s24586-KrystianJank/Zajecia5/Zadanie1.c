#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
	int PID = getpid(),PPID = getppid(),liczba;

	printf("Pid: %d \n", PID);
	printf("PPID: %d \n", PPID);
	printf("Waiting room do podania liczby:");
	scanf("%d", &liczba);
	return 0;
}

