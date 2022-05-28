#include <stdio.h>

int fibonacci(int number);

int main() {
    int numberOfFibonacciElements, i, next = 1, number = 0;

    printf("Number of fibonacci elements: ");
    scanf("%d", &numberOfFibonacciElements);

    //iteracyjnie
    for (i = 0; i < numberOfFibonacciElements; ++i) {
        if (i == 0)  {
            printf("Number %d: value: %d\n", i + 1, 0);
        } else {
            printf("Number %d: value: %d\n", i + 1, next);
            next += number;
            number = next - number;
        }
    }

    //rekursywnie
    for (i = 0; i < numberOfFibonacciElements; i++) {
        printf("Element: %d value: %d\n",i + 1 , fibonacci(i));
    }

    return 0;
}

int fibonacci(int number) {
    if (number == 0) return 0;
    if (number == 1) return 1;
    return (fibonacci(number - 1) + fibonacci(number - 2));
}
