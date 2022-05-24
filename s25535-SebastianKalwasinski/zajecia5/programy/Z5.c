

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

	int P;
	int i = 0;
	pid_t PID_rodzica = getpid();

	printf("\n");
	while(i != 100){
		i++;
		P = fork();
		if(P == 0) break;
	}

	if(P == 0){
		printf("Jestem dzieckiem, PID = %d, PPID = %d\n",getpid(), getppid());
	}

	if(PID_rodzica == getpid()){
	
	
		/*int x;*/
		int status = 100;
		pid_t PID_dziecka;

		sleep(1); /*scanf("%d", &x);*/
		printf("\nJestem rodzicem, PID = %d, PPID = %d\n\n", getpid(), getppid());

		while ((PID_dziecka = wait(&status)) > 0){
			printf("Odbieram dziecko z PID = %d\n", PID_dziecka);
		}
		printf("\n");
	}
	return 0;
}
