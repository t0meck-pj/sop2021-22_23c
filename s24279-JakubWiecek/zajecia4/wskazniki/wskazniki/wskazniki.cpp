#include <iostream>
#include <cstdlib>

using namespace std;

typedef int (*f) (int, int);
int minimum(int a, int b);
int maximum(int a, int b);
int suma(int a, int b);
int wynik(int* tablica, int liczbaElementow, f funkcja);

int main()
{
    int functionID, elementCount, num;
    int* numbers, v;

    f tab[3];
    f mini = minimum;
    f maxi = maximum;
    f sum = suma;

    tab[0] = mini;
    tab[1] = maxi;
    tab[2] = sum;

    cout << "Ile chcesz wgrac liczb do tablicy:" << endl;
    cin >> elementCount;

    numbers = (int*) calloc(elementCount, sizeof(int));

    cout << "\nOk. To podaj te liczby:" << endl;
    for (int i = 0; i < elementCount; i++) {
        cin >> num;
        numbers[i] = num;
    }


    cout << "\nCo robimy z tymi liczbami? \n1.Szukamy minimum?\n2.Szukamy maximum?\n3.Sumujemy?\n";
    cout << "Twoja opcja: ";
    cin >> functionID;

    v = numbers[0];

    for (int i = 1; i < elementCount; i++) {
        v = tab[functionID-1](v,numbers[i]);
    }
    cout << "Wynik V to: ";
    cout << v;

    cout << endl;
    cout << wynik(numbers, elementCount, tab[functionID-1]);

    free(numbers);

    return 0;
}

int wynik(int* tablica, int liczbaElementow, f funkcja){

    int v;
    v = tablica[0];

    for (int i = 1; i < liczbaElementow; i++) {
        v = funkcja(v,tablica[i]);
    }
    cout << "Wynik forAll to: ";
    return v;
}

int minimum(int a, int b) {
    if (a > b) { return b;}
    else
        return a;
}
int maximum(int a, int b) {
    if (a < b) { return a;}
    else
        return b;
}
int suma(int a, int b) {
    return a + b;
}
