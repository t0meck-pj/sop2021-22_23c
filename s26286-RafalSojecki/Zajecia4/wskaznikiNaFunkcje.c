/*
Napisz program z 3 funkcjami, każda funkcja niech będzie miała taką sygnaturkę:
 int (*f)(int,int)
Niech będą to funkcje: maksimum, minimum oraz suma.

Zapamiętaj wskaźniki do tych funkcji w tablicy trójelementowej

Niech program pobiera kolejno wartości:
functionId - liczba od 0 do 2 oznaczająca indeks funkcji w tablicy
elementCount - liczba elementów ciągu do pobrania
kolejno liczby w ilości elementCount

Niech program przetwarza wczytaną tablicę w taki sposób, że:
Niech v przyjmie wartość pierwszego elementu
w pętli po wszystkich elementach od drugiego (indeks 1 w tablicy)
wykona funkcję o numerze functionId przekazując jako argumenty v oraz element o
aktualnym indeksie. Niech wynik zostanie zapisany do v
Wypisze wartość v na koniec

Czyli piszemy program który pozwoli na wykonanie albo sumy, albo znalezienia
maksimum, albo znalezienia minimum z elementCount liczb.
Program nie będzie korzystał z instrukcji warunkowych (w pętli głównej) do
wyboru jaka funkcja ma być wykonana.
Czyli nigdzie w kodzie nie może pojawić się instrukcja if ani switch.
Korzystając z wiedzy z poprzedniego zadania, napisz funkcję, która będzie
przetwarzała tablicę za pomocą uniwersalnej funkcji podanej jako argument
funkcji.
Na przykład:
int wynik = forAll(tablica, liczbaElementow, maksimum); // maksimum to nazwa
funkcji porownojacej dwie wartosci
*/
#include <stdio.h>
#include <stdlib.h>

typedef int (*f)(int, int);
int maksimum(int a, int b);
int minimum(int a, int b);
int suma(int a, int b);
int forAll(int *numbers, int count, f func);

int main(int argc, char *argv[])
{
    f functions[] = {minimum, maksimum, suma};
    int functionId = atoi(argv[1]);
    int elementCount = atoi(argv[2]);
    int *numbers;
    numbers = (int *)malloc((elementCount + 1));
    for (int i = 0; i < elementCount; i++)
    {
        numbers[i] = atoi(argv[i + 3]);
    }
    int v = numbers[0];
    printf("Wynik: %i \n", forAll(numbers, elementCount, functions[functionId]));
}

int forAll(int *numbers, int count, f func)
{
    int v = numbers[0];
    for (int i = 1; i < count; i++)
    {
        v = func(v, numbers[i]);
    }
    return v;
}

int maksimum(int a, int b)
{
    return a >= b ? a : b;
}
int minimum(int a, int b)
{
    return a <= b ? a : b;
}
int suma(int a, int b)
{
    return a + b;
}
