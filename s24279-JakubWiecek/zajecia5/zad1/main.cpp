#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    int status = 0;
    pid_t p = fork();
    if (p > 0) {
        cout << "1 Child PID: " << getpid() << endl;
        cout << "2 Child PPID: " << getppid() << endl;
        wait(&status);
    }else{
        cout << "3 Parent PID: " << getpid() << endl;
        cout << "4 Parent PPID: " << getppid() << endl;
    }
    return 0;
}
