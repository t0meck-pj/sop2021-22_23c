#include <iostream>

using namespace std;

int main()
{
    int number;
    int result = 0;

    cout << "Wprowadz liczby do zsumowania. Wpisz 0, gdy konczysz wypisywac liczby:" << endl;

    do {
        cin >> number;
        result = result + number;
    }while(number != 0);

    if (!cin){
        cout << "Podales litere.... Tak sie nie bawimy!!" << endl;
    }else
        cout << "Twoj wynik to: ";
    return result;
}
