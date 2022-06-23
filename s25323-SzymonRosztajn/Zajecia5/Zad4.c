#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int next_child(int x, int level);

int main()
{
    next_child (0,100);
    
        return 0;
}

int next_child(int i, int j) {
  if (i <= j) 
  {
    printf("Level %d, PID: %d, PPID: %d \n", i, getpid(), getppid());
      pid_t pid = fork();

      if (pid == -1) 
      {
        return 1;
      } 
      else if (pid == 0) 
      {
        sleep(1);
        return next_child(i + 1, j);
      }

  }
    return wait(0);
}
