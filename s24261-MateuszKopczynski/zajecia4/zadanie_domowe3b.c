#include <stdio.h>

int main() {
    int numberOfElements, i;
    int firstNumber = 0, secondNumber = 1, result = 0;

    printf("Wprowadz liczbe elementow: ");
    scanf("%d", &numberOfElements);

    printf("Ciag Fibonacciego (iteracja): \n");
    for (i = 0; i < numberOfElements; i++) {
        if (i > 1) {
            result = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = result;
        } else result = i;

        printf("%d \n", result);
    }

    return 0;
}
