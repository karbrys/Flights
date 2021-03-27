#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[])
{
    string sciezka_do_pliku;
    
    if (argc < 3) {
        cout << "Aby uruchomic program, podaj sciezke do pliku tekstowego z lista lotow w postaci: " << argv[0] << " -i SCIEZKA_DO_PLIKU" << endl;
        return 1;
    }
    
    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-i") {
            if (i + 1 < argc) {
                sciezka_do_pliku = argv[++i];
            } else {
                cout << "Przelacznik -i wymaga dodania argumentu." << std::endl;
                return 1;
            }
        }
    }
    
    lot* lista_lotow = nullptr;
    
    wczytywanieLotowOrazPasazerow(sciezka_do_pliku, lista_lotow);
    zapisListLotowDoPlikow(lista_lotow);
    usunListeLotow(lista_lotow);
    
    return(0);
    
}
