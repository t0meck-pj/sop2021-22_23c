#include <stdio.h>
#include <stdlib.h>

typedef int (* f) (int, int);

int max(int first, int second);
int min(int first, int second);
int sum(int first, int second);
int operate(int* tableOfNumbers, int elementCount, f operation1);

void getFunctionId(int *functionId);
void getElementCount(int *elementCount);

int main() {
    int functionId, elementCount, result, i;
    int* tableOfNumbers;

    f tableOfPointers[3];
    f maxF = max;
    f minF = min;

    f sumF = sum;
    tableOfPointers[0] = maxF;
    tableOfPointers[1] = minF;
    tableOfPointers[2] = sumF;

    getFunctionId(&functionId);
    getElementCount(&elementCount);

    tableOfNumbers = calloc(elementCount, sizeof(int));

    for (i = 0; i < elementCount; ++i) {
        printf("Podaj %d liczbe: ", i);
        scanf("%d", &tableOfNumbers[i]);
    }

    result = operate(tableOfNumbers, elementCount, tableOfPointers[functionId]);
    printf("V = %d \n", result);

    free(tableOfNumbers);

    return 0;
}

int max(int first, int second) {
    return first > second ? first : second;
}

int min(int first, int second) {
    return first < second ? first : second;
}

int sum(int first, int second) {
    return first + second;
}

int operate(int* tableOfNumbers, int elementCount, f operation1) {
    int v = tableOfNumbers[0], i;

    for(i = 1; i < elementCount; i++) {
        v = operation1(v, tableOfNumbers[i]);
    }
    return v;
}

void getFunctionId(int *functionId) {
    printf("Podaj co chcesz zrobic \n");
    printf("0 - maksimum \n");
    printf("1 - minimum \n");
    printf("2 - suma \n");
    printf("Wynik: ");

    scanf("%d", functionId);

    if (*functionId < 0 || *functionId > 2) exit(0);
}

void getElementCount(int *elementCount) {
    printf("Ile pobieramy liczb:");
    scanf("%d", elementCount);

    if (*elementCount <= 0) exit(0);
}
