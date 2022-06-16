#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
pid_t getpid(void);
pid_t getppid(void);

using namespace std;

int main()
{
    int status = 0;
    pid_t f, f2;
    f = fork ();

    if (f > 0) {
        cout << "Linia startowa, PID: " << getpid() << ", PPID: " << getppid() << endl;
        wait(&status);
        f = fork();
    }

    if (f == 0) {
        f2 = fork();

        if (f2 > 0) {
            cout << "Linia nr 1, PID: " << getpid() << ", PPID: " << getppid() << endl;
            wait(&status);
            f2 = fork();
        }

        if (f2 == 0) {
            cout << "Linia nr 2, PID: " << getpid() << ", PPID: " << getppid() << endl;
        }

    }
    wait(&status);






    return 0;
}
