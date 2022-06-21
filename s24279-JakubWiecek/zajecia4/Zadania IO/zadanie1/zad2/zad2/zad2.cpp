#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file;
    string name;
    int rozmiar;
    int i;
    int* tab;

    if (argc > 2){
        cout << "Za duzo argumentow" << endl;
    }
    if (argc == 2) {
    file.open(argv[1], std::ios::in );
    }else {
        cout << "Podaj nazwe pliku (dane.txt): " << endl;
        cin >> name;
        file.open(name.c_str());
    }

    if (file.is_open()) { cout << "Otwarto plik" << endl; }

    file >> rozmiar;
    tab = (int*) malloc(rozmiar * sizeof(int));

    file.ignore(1, '\n');
    for (i = 0; i < rozmiar; i++) {
        file >> tab[i];
    }

    for (i = rozmiar; i > 0; i--) {
        cout << tab[i - 1] << endl;
    }
    free(tab);
    file.close();
    cout << "Plik zamkniety" << endl;
    return 0;
}
