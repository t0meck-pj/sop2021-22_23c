#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

pid_t getpid(void);
pid_t wait(pid_t pid, int *status, int options);

int main(int argc, char* argv[])
{
    int status;
    int pid = fork();
    int number;
    number = atoi(argv[1]);
    int sum = 0;

    if (pid > 0){

        wait(&status);
        cout << "Parent" << endl;
        for (int i = 0; i <= number; i++) {
            sum = sum + i;
        }
        cout << sum << endl;
    }else {
        cout << "Child" << endl;
        for (int i = 1; i <= number; i++) {
            if (i%2!=0){
            cout << i << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
