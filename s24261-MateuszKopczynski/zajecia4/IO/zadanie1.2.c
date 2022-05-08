#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int size, number, i = 0;
    int* ptr;
    FILE* file;

    file = fopen(argv[1], "r");

    if (fscanf(file, "%d", &size)) {};

    ptr = (int*) malloc(size * sizeof(int));
  
    for (i = 1; i <= size; i++) {
      if (fscanf(file, "%d", &number)) {};
      ptr[i] = number;
    }

    for (i = size; i > 0; i--) {
      printf("%d \n", ptr[i]);
    }
    printf("%d \n", size);

    fclose(file);
    free(ptr);

    return 0;
}
