#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
        int num, i, result = 0, p = fork();
        sscanf (argv[1],"%d",&num);

        if (p > 0) 
        {
                waitpid(0, 0, 0);
                for (i = 0; i <= num; i++) 
                {
                        result += i;
                }

                printf("Result: %d \n", result);
        } 
        else 
        {
                for (i = 0; i <= num; i++) 
                {
                        if (i % 2 == 1) printf("Number: %d \n", i);
                }
        }

        return 0;
}
