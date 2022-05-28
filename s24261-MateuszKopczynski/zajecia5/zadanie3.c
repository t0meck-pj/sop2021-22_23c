#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  int result, i;
  int p = fork();

  if (p > 0) {
    wait(0);
    for (i = 0; i < atoi(argv[1]); i++) {
      result += i;
    }

    printf("Wynik: %d \n", result);
  }
  else {
    printf("Liczby nieparzyste: \n");
    for (i = 0; i <= atoi(argv[1]); i++) {
      if (i % 2 == 1) printf("%d \n", i);
    }
  }

  return 0;
}
