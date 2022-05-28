#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int make_child(int x, int y);

int main() {
  make_child(0, 2);

  return 0;
}

int make_child(int x, int y) {
  int i;

  if (x < y) {
    printf("Poziom %d, PID dziecka: %d, PPID: %d \n", x, getpid(), getppid());

    for (i = 0; i < 2; i++) {
      int pid = fork();

      if (pid == 0) {
        sleep(1);
        return make_child(x + 1, y);
      }
    }
  } else {
    printf("Poziom %d, PID dziecka: %d, PPID: %d \n", x, getpid(), getppid());
  }

  return wait(0);
}
