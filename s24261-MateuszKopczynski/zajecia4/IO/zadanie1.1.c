#include <stdio.h>

int main() {
    int size, number, i = 0;
    FILE* file;

    file = fopen("liczby.txt", "r");

    if (fscanf(file, "%d", &size)) {};

    printf("%d \n", size);
  
    for (i = 1; i <= size; i++) {
      if (fscanf(file, "%d", &number)) {};
      printf("%d \n", number);
    }

    fclose(file);

    return 0;
}
