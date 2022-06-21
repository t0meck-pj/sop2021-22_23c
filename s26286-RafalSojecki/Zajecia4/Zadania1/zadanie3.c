/*
Napisz program wyświetlający tradycyjną choinkę o zadanej wysokości. Wysokość niech będzie podana jako parametr wywołania programu.
Przydatne hasła to:
atoi
argc, argv
for
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int height = atoi(argv[1]);
    printf("%i\n", height);
    for (int level = 0; level < height; level++)
    {
        int starCount = (2 * (level + 1)) - 1;
        int shift = height - level - 1;
        while (shift--)
        {
            printf(" ");
        }
        while (starCount--)
        {
            printf("*");
        }
        printf("\n");
    }
    int baseShiftCount = height - 1;
    while (baseShiftCount--)
    {
        printf(" ");
    }
    printf("#\n");
    return 0;
}
