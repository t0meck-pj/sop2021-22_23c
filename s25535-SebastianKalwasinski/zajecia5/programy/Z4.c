#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	int P;
	int i = 0;
	int ilosc = 100;
	pid_t PID_rodzica = getpid();

	printf("\n");
	while(i != (ilosc-1)){
		i++;
		P = fork();
		if(P > 0) break;
	}

	if(P > 0){
		printf("Jestem rodzicem, PID = %d, PPID = %d\n", getpid(), getppid());
	}

	if(P == 0){
		printf("Jestem potomkiem PID = %d, PPID = %d\n\n", getpid(), getppid());
	}

	if(P > 0){
		int status = 100;
		/*int x;*/
		pid_t buff;
		
		/*scanf("%d", &x);*/
		buff = wait(&status);
		printf("PID:%d Odbiera PID:%d\n",getpid() , buff);
	}
	
	if(PID_rodzica == getpid()){	
		printf("\n");
	}
	return 0;
}
