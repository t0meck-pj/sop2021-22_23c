/*
Napisz program obliczający sumę liczb wprowadzonych przez użytkownika (ze standardowego wejścia) i wypisujący wynik na standardowe wyjście.
Przydatne hasła to:
scanf
printf
operatory arytmetyczne
if
for albo while
*/
#include <stdio.h>
int main()
{
    int buffer = 0, returned = 0;
    while (scanf("%i", &buffer))
    {
        returned += buffer;
    }
    printf("%i\n", returned);
    return 0;
}
