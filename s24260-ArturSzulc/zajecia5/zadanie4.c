#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

static int createChilds(int i, int numberOfRecess);

int main(void) {
  return createChilds(0, 100);
}

static int createChilds(int i, int n) {
  if (i <= n) {
    printf("Poziom %d, PID to: %d, PPID to: %d \n", i, getpid(), getppid());
      pid_t pid = fork();

      if (pid == -1) {
        return 1;
      } else if (pid == 0) {
        return createChilds(i + 1, n);
      }

  }

  wait(0);
  wait(0);
  return 0;
}
