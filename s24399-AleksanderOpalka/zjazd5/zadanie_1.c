#include <stdio.h>
#include <unistd.h>

int main() {

    int current_pid=getpid();
    int current_ppid=getppid();
    int user_input;
    
    printf("Current PID: %d \nCurrent PPID: %d \n\n\n\n",current_pid,current_ppid);

    printf("Enter any key to continue...");
    scanf("%d",&user_input);
    
    return 0;
}
