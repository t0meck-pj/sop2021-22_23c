#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int make_child(int x, int y);

int main() {
  make_child(0, 100);

  return 0;
}

int make_child(int x, int y) {
  if (x <= y) {
    printf("Poziom %d, PID dziecka: %d, PPID: %d \n", x, getpid(), getppid());

    pid_t pid = fork();

    if (pid == 0) {
      sleep(1);
      return make_child(x + 1, y);
    }
  }

  return wait(0);
}
