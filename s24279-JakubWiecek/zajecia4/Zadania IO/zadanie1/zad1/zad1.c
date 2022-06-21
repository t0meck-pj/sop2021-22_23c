#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s, n, i;
    FILE* file;

    file = fopen("dane.txt", "r");

    fscanf(file, "%d", &s);
    printf("size %d \n", s);

    for (i = 0; i < s; i++)
        {
            fscanf(file, "%d", &n);
            printf("%d \n", n);
        }
    fclose(file);

    return 0;
}
