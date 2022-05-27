#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t PID_rodzica = getpid();
	pid_t P2 = 10;
	pid_t P;

	printf("\n");

	P = fork();
	if(P > 0){
		printf("Main.rodzic_PID:%d\n", getpid());
		P = fork();
	}

	if(P == 0){
		pid_t PID_P_rodzica = getpid();
		P2 = fork();
		
		if(P2 > 0){
			printf("Potomek.rodzic_PID:%d\n", getpid());
			P2 = fork();
 		}
		
		if(P2 == 0){
			sleep(0.5);
			printf("Potomek.potomek_PID:%d\n", getpid());
		}
		
		if(PID_P_rodzica == getpid()){
			
			int status = 100;
			pid_t odebrany;
			
			sleep(1);
			/*int x;
			scanf("%d", &x);*/
			
			printf("\n");
			while((odebrany = wait(&status)) > 0){
				printf("PID:%d Odebiera PID:%d\n",getpid(), odebrany);
			}
		}
	}
	
	if(PID_rodzica == getpid()){
		
		int status = 100;
		pid_t odebrany;
		
		while((odebrany = wait(&status)) > 0){
			printf("PID:%d Odebiera PID:%d\n",getpid(), odebrany);
		}
		printf("\n");
	}

	return 0;
}
