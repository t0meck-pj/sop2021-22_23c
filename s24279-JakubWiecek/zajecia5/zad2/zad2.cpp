#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

pid_t getpid(void);
pid_t getppid(void);
pid_t waitpid(pid_t pid, int *status, int options);

int main()
{
    int status;
    int pid = fork();

    if (pid > 0) {
    cout << "Parent PID:  " << getpid() << endl;
    cout << "Parent PPID: " << getppid() << endl << endl;
    }else
    {
    cout << "Child PID:  " << getpid() << endl;
    cout << "Child PPID: " << getppid() << endl << endl;
    }

    waitpid(0, &status, 0);



    return 0;
}
