#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	int zmienna = 0;

	printf("PID = %d\n", getpid());
	printf("PIDD = %d\n", getppid());
	scanf("%d", &zmienna);
	
	return 0;
} 
