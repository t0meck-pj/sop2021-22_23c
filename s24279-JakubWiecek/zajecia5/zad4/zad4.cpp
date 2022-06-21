#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
pid_t getpid(void);
pid_t getppid(void);

int main() {

    int status = 0;
    pid_t prcs;

    cout << "Parent PID: " << getpid() << ", PPID: " << getppid() << endl;
    for (int i = 0; i < 10; i++) {

        prcs = fork();

        if (prcs > 0) {
            waitpid(-1,&status,0);
            exit(0);
            }

        if (prcs == 0) {
           cout << "Child nr: " << i+1 << ", PID: " << getpid() << ", PPID: " << getppid() << endl;
        }
    }


    return 0;
}
