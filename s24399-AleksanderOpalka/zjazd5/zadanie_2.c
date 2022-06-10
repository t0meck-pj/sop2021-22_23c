#include <stdio.h>
#include <unistd.h>

int main() {

    int idk=fork();

    printf("fork value= %d \n\n",idk);

    if (idk > 0) {
		printf("Parent Pid is: %d \n", getpid());
		printf("Parent Parent Pid is %d \n\n", getppid());
	} else if(idk==0){
		printf("Child Pid is: %d \n", getpid());
        printf("Child Parent Pid is %d \n", getppid());
	}
    
    return 0;
}
