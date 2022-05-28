#include <stdio.h>

int FibonacciSeries(int number);

int main() {
    int numberOfElements, i;

    printf("Wprowadz liczbe elementow: ");
    scanf("%d", &numberOfElements);

    printf("Ciag Fibonacciego (rekurencja): \n");
    for (i = 0; i < numberOfElements; i++) {
        printf("%d \n", FibonacciSeries(i));
    }

    return 0;
}

int FibonacciSeries(int number) {
    if (number == 0) return 0;
    if (number == 1) return 1;
    return (FibonacciSeries(number - 1) + FibonacciSeries(number - 2));
}
