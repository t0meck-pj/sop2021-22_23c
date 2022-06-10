#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char* argv[]){

    int user_input=0;
    int fork_result=fork();
    int i=0;
    int i2=0;
    int result=0;

    user_input=atoi(argv[1]);

    if(fork_result>0){
        waitpid(0, 0, 0);
        for(i=0;i<=user_input;i++){
            result+=i;
        }
        printf("Result equals: %d\n",result);
    }
    else if(fork_result==0){
        for(i2=0;i2<=user_input;i2++){
            if (i2%2!=0){
                printf("%d\n",i2);
            }
        }
    }
    return 0;
}
