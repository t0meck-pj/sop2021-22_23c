#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

	pid_t PID_rodzica;
	pid_t PID_warunkowy;
	int status;

	PID_rodzica = getpid();
	PID_warunkowy = fork();

	if(PID_warunkowy > 0){
		printf("Jestem rodzicem, moje:\nPID = %d\nPPID = %d\n", getpid(), getppid());
	}
	else{
		printf("Jestem dzieckiem, moje:\nPID = %d\nPPID = %d\n", getpid(), getppid());
	}
	if(PID_rodzica == getpid()){
		/* waitpid(pid, status, opcje);*/
		waitpid(0, &status, 0);
	}
	/*informacja dodatkowa*/
	printf("status = %d\n", status);
	return 0;
}
