#include <stdio.h>
#include <unistd.h>


int main() {

    int p=fork();


    if (p > 0) {
		printf("Jestem rodzicem, moje:\nPID = %d\nPPID = %d\n", getpid(), getppid());
	} else if(p==0){
		printf("Jestem dzieckiem, moje:\nPID = %d\nPPID = %d\n", getpid(), getppid());
	}
    
    return 0;
}
