/*
Napisz program obliczający sumę liczb wprowadzonych przez użytkownika (ze
standardowego wejścia) i wypisujący wynik na standardowe wyjście.
Przydatne hasła to:
scanf
printf
operatory arytmetyczne
if
for albo while

Przerób ten program tak, aby wartość była zwracana jako kod zakończenia
programu. Wyświetl tą wartość z linii komend.
Przydatne komendy:
return
*/
#include <stdio.h>
int main()
{
    int buffer = 0, returned = 0;
    while (scanf("%i", &buffer))
    {
        returned += buffer;
    }
    // printf("%i", returned);
    return returned;
}
