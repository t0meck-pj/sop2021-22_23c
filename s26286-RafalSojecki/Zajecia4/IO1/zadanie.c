/*
Napisz program wczytujący z pliku tekstowego ciąg liczb.
Format pliku jest taki:
liczba elementów ciągu (jako liczba naturalna)
Kolejne liczby - każda w nowej linii
Przykład:
3
5
1
9
Opis przykładu:
3 liczby do wczytania
liczby: 5, 1, 9
Niech program wypisze je w odwrotnej kolejności. Program powinien przyjmować zero albo jeden argument:
jeśli nie podano argumentu, to ma wczytywać ze standardowego wejścia
jeśli podano argument, to jest to nazwa pliku do wczytania
Skorzystaj z:
fopen
fclose
fscanf
Zabezpiecz przed przepełnieniem bufora.
Skorzystaj z funkcji do dynamicznej rezerwacji/alokacji pamięci:
malloc lub calloc
free
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int numbersCount = 0;
    int *numbers;
    if (argc == 2)
    {
        FILE *fileP = fopen(argv[1], "r");
        if (fileP == NULL)
        {
            return 1;
        }
        fscanf(fileP, "%i", &numbersCount);
        numbers = (int *)malloc((numbersCount + 1));
        for (int i = 0; i < numbersCount; i++)
        {
            int number = 0;
            fscanf(fileP, "%i", &number);
            numbers[i] = number;
        }
    }
    else
    {
        scanf("%i", &numbersCount);
        numbers = (int *)malloc((numbersCount + 1));
        for (int i = 0; i < numbersCount; i++)
        {
            int number = 0;
            scanf("%i", &number);
            numbers[i] = number;
        }
    }
    for (int i = numbersCount; i >= 0; i--)
    {
        printf("%i\n", numbers[i]);
    }
    free(numbers);
    return 0;
}
