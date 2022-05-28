#include <stdio.h>
#include <stdlib.h>

int main() {
  int numberOfNumbers, i, result = 0;

  printf("Enter a number of numbers: ");
  scanf("%d", &numberOfNumbers);

  for (i = 1; i <= numberOfNumbers; ++i) {
    int number = 0;
    printf("Enter number %d: ", i);
    scanf("%d", &number);

    result += number;
  }

  printf("Sum of numbers = %d \n", result);
  
  return 0;
}
