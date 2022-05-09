#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int size, number, i = 0;
  char filename[255];
  int* tab;
  FILE* file;

  if (argc > 2) {
    printf("Podales za duzo argumentow \n");
    return 1;
  }
  
  if (argc == 2) {
    file = fopen(argv[1], "r");
  }
  else {
    printf("Podaj nazwe pliku: ");
    if (scanf("%s", filename)) {};

    file = fopen(filename, "r");
  }

  if (fscanf(file, "%d", &size)) {};

  tab = (int*) malloc(size * sizeof(int));

  for (i = 1; i <= size; i++) {
    if (fscanf(file, "%d", &number)) {};
    tab[i] = number;
  }

  for (i = size; i > 0; i--) {
    printf("%d \n", tab[i]);
  }
  printf("%d \n", size);

  fclose(file);
  free(tab);

  return 0;
}
