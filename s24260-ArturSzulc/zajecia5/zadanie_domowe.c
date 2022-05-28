#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

static int createChilds(int i, int numberOfRecess, int numberOfChild);

int main(void) {
  return createChilds(0, 2, 2);
}

static int createChilds(int i, int n, int numberOfChild) {
  if (i < n) {
    printf("Poziom %d, PID to: %d, PPID to: %d \n", i, getpid(), getppid());

    for (int j = 0; j < numberOfChild; j++) {
      pid_t pid = fork();

      if (pid == -1) {
        return 1;
      } else if (pid == 0) {
        return createChilds(i + 1, n, numberOfChild);
      }
    }

  } else {
    printf("Poziom maksymalny %d, PID to: %d, PPID to: %d \n", i, getpid(), getppid());
  }
  wait(0);
  wait(0);
  return 0;
}
