#include <iostream>
#include <stdlib.h>

using namespace std;
//
int main(int argc, char *argv[])
{
    int height = atoi(argv[1]);

    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j <= height - i; j++)
            {
                cout << " ";
            }
        for (int j = 1; j <= 2 * i - 1; j++)
            {
                cout << "*";
            }
        cout << endl;
    }
}
