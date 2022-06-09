#include <sys/types.h>
#include <sys/wait.h>

int main () {

        int pidRodzica;
        int pidPotomka;

        pidRodzica= getpid();
        pidPotomka= fork();

        if (pidPotomka > 0){
                printf("Rodzic: PID- %d , PPID- %d\n", getpid(), getppid());
        }
        if (pidPotomka == 0){
                printf("Potomek: PID- %d , PPID- %d\n", getpid(), getppid());
        }

return 0;
}

