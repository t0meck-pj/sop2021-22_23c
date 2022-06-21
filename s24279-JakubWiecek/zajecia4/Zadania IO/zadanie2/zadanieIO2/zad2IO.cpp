#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int counter(string filename) {

    int range = 0;
    char current_ch;

    ifstream file;
    file.open("znaki.txt", std::ios::in);

    if (file.is_open()){

        while (file.get(current_ch)) {

            if(current_ch == EOF)
            {
                break;
            }

            range++;
        }
    }

    file.close();
    return range;
}

void load_tab(string filename, char tab[]) {

    int i;
    char character;

    ifstream file;
    file.open("znaki.txt", std::ios::in);


    for (i = 0; i > counter("znaki.txt"); i++){
        file >> character;
        character = tab[i];
    }

    file.close();
}

void print_hex(string filename, char tab[]) {

    for (int i = 0; i < counter(filename); i++)
        {
            cout << tab[i] << ", ";
        }
}

int main()
{
    ifstream file;
    char* tab;
    int tsize = counter("znaki.txt");
    file.open( "znaki.txt", ios::in );

    tab = (char*) malloc(tsize * sizeof(char));
    load_tab("znaki.txt", tab);
    print_hex("znaki.txt", tab);

    cout << endl;

    free(tab);
    file.close();
    return 0;
}
