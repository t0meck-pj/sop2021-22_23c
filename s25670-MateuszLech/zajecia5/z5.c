#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    pid_t masterPid = getpid();
    printf("Masterpid: %d\n", masterPid);
    fflush(stdout);

    for(i=0; i<10;i++)
    {   
        if(getpid() == masterPid)
        {
            if(fork()== 0)
            {
                printf("i=%d PID:%d\tPPID:%d\n", i,getpid(), getppid());
                fflush(stdout);
            }
        } 
    }

    if(masterPid == getpid())
    {
        int status = 0;
        waitpid(0, &status, 0);
        printf("Rodzic zaczekal na zakonczenie swoich dzieci i sam sie zakonczyl\n");
        fflush(stdout);
    }

    return 0;
}
