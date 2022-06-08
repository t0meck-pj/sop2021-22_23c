/*
Napisz program liczący kolejne wartości ciągu Fibonacciego w wersji:
rekursywnej (rekurencyjnej)
iteracyjnej
*/
#include <stdio.h>
#include <stdlib.h>

unsigned int fibonacciR(unsigned int n);
unsigned int fibonacciI(unsigned int n);

int main(int argc, char *argv[])
{
    printf("Wynik rekurencyjny: %i \n", fibonacciR(atoi(argv[1])));
    printf("Wynik iteracyjny: %i \n", fibonacciI(atoi(argv[1])));
    return 0;
}

unsigned int fibonacciR(unsigned int n)
{
    unsigned int a = 0, b = 0;
    if (n <= 2)
    {
        return n;
    }
    else
    {
        unsigned int a = fibonacciR(n - 1);
        unsigned int b = fibonacciR(n - 2);
        return (a + b);
    }
}

unsigned int fibonacciI(unsigned int n)
{
    unsigned int a = 0, b = 1;

    for (int i = 0; i < n; i++)
    {
        b += a;
        a = b - a;
    }
    return b;
}
