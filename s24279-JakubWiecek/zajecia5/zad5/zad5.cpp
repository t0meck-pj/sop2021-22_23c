#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
pid_t getpid(void);
pid_t getppid(void);

int main() {

   int status = 100;
    pid_t prcs;

    cout << "Parent PID: " << getpid() << ", PPID: " << getppid() << endl;

    for (int i = 0; i < 100; i++) {
        prcs = fork();

        if (prcs == 0) {
            cout << "Child nr: " << i+1 << ", PID: " << getpid() << ", PPID: " << getppid() << endl;
            exit(0);
        }
        wait(&status);
    }
    return 0;
}
