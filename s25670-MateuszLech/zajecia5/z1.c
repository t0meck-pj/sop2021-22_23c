#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int temp = 0;

    printf("PID = %d\n", getpid());
    printf("PIDD = %d\n", getppid());
    scanf("%d", &temp);
    return 0;
} 
