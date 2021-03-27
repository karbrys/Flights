/** @file */
//  funkcje.cpp
//  LOTY
//  Created by Karola on 29/12/2019.
//  Copyright © 2019 Karolina Bryś. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "funkcje.h"
using namespace std;

// funkcje struktury lot
void pokazLot(lot* temp) {
    cout << temp->symbol_lotu << " " << temp->lotnisko_startowe << " "  << temp->data_lotu << " " << endl;
}

void pokazWszystkieLoty(lot* lista_lotow) {
    while (lista_lotow != nullptr)
    {
        pokazLot(lista_lotow);
        lista_lotow=lista_lotow->nastepny_lot;
    }
}

lot* nowyLot(string symbol_lotu, string lotnisko_startowe, string data_lotu) {
    return new lot{symbol_lotu, lotnisko_startowe, data_lotu, nullptr, nullptr};
}

void dodajLotDoListy(lot* &lista_lotow, string symbol_lotu, string lotnisko_startowe, string data_lotu) {
    if (lista_lotow == nullptr)
    {
        lista_lotow = nowyLot(symbol_lotu, lotnisko_startowe, data_lotu);
    }
    else {
        lot* p = lista_lotow;
        while (p != nullptr) {
            if (p->symbol_lotu.compare(symbol_lotu) == 0) {
                return;
            }
            if (p->nastepny_lot == nullptr) {
                p->nastepny_lot = nowyLot(symbol_lotu, lotnisko_startowe, data_lotu);
                return;
            }
            p = p->nastepny_lot;
        }
    }
}

// funkcje struktury pasazer
void pokazPasazera(pasazer* temp) {
    cout << temp->nazwisko_pasazera << " " << temp->numer_miejsca << endl;
}

void pokazWszystkichPasazerow(pasazer* lista_pasazerow) {
    while (lista_pasazerow != nullptr) {
        pokazPasazera(lista_pasazerow);
        lista_pasazerow=lista_pasazerow->nastepny_pasazer;
    }
}

pasazer* nowyPasazer(string nazwisko_pasazera, int numer_miejsca) {
    return new pasazer{nazwisko_pasazera, numer_miejsca, nullptr};
}

void dodajPasazeraDoListy(pasazer* &lista_pasazerow, string nazwisko_pasazera, int numer_miejsca) {
    if (lista_pasazerow == nullptr)
    {
        lista_pasazerow = nowyPasazer(nazwisko_pasazera, numer_miejsca);
    }
    else {
        pasazer* poprzedni_pasazer = nullptr;
        pasazer* obecny_pasazer = lista_pasazerow;
        while (obecny_pasazer != nullptr) {
            if (obecny_pasazer->numer_miejsca > numer_miejsca) {        // szukamy na liście pasażera z wyższym numerem miejsca
                if (obecny_pasazer == lista_pasazerow)                  // jeśli odnaleziony pasażer JEST pierwszy na liście...
                {
                    lista_pasazerow = nowyPasazer(nazwisko_pasazera, numer_miejsca);
                    // ...dodajemy nowego pasażera na początek
                    lista_pasazerow->nastepny_pasazer = obecny_pasazer;
                    // ...i wskazujemy odnalezionego pasażera jako kolejnego
                    return;
                }
                else                                                    // jeśli odnaleziony pasażer NIE JEST pierwszy na liście...
                {
                    poprzedni_pasazer->nastepny_pasazer = nowyPasazer(nazwisko_pasazera, numer_miejsca);
                    // ...podpinamy nowego pasażera pod poprzedniego z listy
                    poprzedni_pasazer->naoostepny_pasazer->nastepny_pasazer = obecny_pasazer;
                    // ...i każemy wskazywać nowo dodanemy pasażerowi na odnalezionego pasażera o wyższym numerze miejsca
                    return;
                }
                
            }
            if (obecny_pasazer->nastepny_pasazer == nullptr) {          // jeśli doszliśmy w poszukiwaniach na koniec listy...
                obecny_pasazer->nastepny_pasazer = nowyPasazer(nazwisko_pasazera, numer_miejsca);
                // ... po prostu dodajemy tam nowego pasażera
                return;
            }
            poprzedni_pasazer = obecny_pasazer;
            obecny_pasazer = obecny_pasazer->nastepny_pasazer;
        }
    }
}

//fukcje dla dwóch list
void dodajLotOrazPasazeraDoListy(lot* &lista_lotow, string symbol_lotu, string lotnisko_startowe, string data_lotu, string nazwisko_pasazera, int numer_miejsca) {
    if (lista_lotow == nullptr)
    {
        lista_lotow = nowyLot(symbol_lotu, lotnisko_startowe, data_lotu);
        dodajPasazeraDoListy(lista_lotow->lista_pasazerow, nazwisko_pasazera, numer_miejsca);
    }
    else {
        lot* p = lista_lotow;
        while (p != nullptr) {
            if (p->symbol_lotu.compare(symbol_lotu) == 0) {
                dodajPasazeraDoListy(p->lista_pasazerow, nazwisko_pasazera, numer_miejsca);
                return;
            }
            if (p->nastepny_lot == nullptr) {
                p->nastepny_lot = nowyLot(symbol_lotu, lotnisko_startowe, data_lotu);
                dodajPasazeraDoListy(p->nastepny_lot->lista_pasazerow, nazwisko_pasazera, numer_miejsca);
                return;
            }
            p = p->nastepny_lot;
        }
    }
}

void pokazWszystkieLotyOrazPasazerow(lot* lista_lotow) {
    while (lista_lotow != nullptr) {
        pokazLot(lista_lotow);
        pasazer* p = lista_lotow->lista_pasazerow;
        while (p != nullptr) {
            pokazPasazera(p);
            p=p->nastepny_pasazer;
        }
        cout << endl;
        lista_lotow=lista_lotow->nastepny_lot;
    }
}

void usunListePasazerow(pasazer* &lista_pasazerow) {
    while (lista_pasazerow != nullptr) {
        pasazer *pp = lista_pasazerow->nastepny_pasazer;
        delete lista_pasazerow;
        lista_pasazerow = pp;
    }
}

void usunListeLotow(lot* &lista_lotow) {
    while (lista_lotow != nullptr) {
        lot *pl = lista_lotow->nastepny_lot;
        
        usunListePasazerow(lista_lotow->lista_pasazerow);
        
        delete lista_lotow;
        lista_lotow = pl;
    }
}

// funkcje glownego programu

void wczytywanieLotowOrazPasazerow(string sciezka_do_pliku,lot* &lista_lotow)
{
    string wczytany_symbol_lotu;
    string wczytany_lotnisko_startowe;
    string wczytany_data_lotu;
    string wczytany_nazwisko_pasazera;
    int wczytany_numer_miejsca;
    
    ifstream plik;
    plik.open(sciezka_do_pliku);
    
    
    if (plik.good() == true)
    {
        
        while (!plik.eof())
        {
            plik >> wczytany_symbol_lotu >> wczytany_lotnisko_startowe >> wczytany_data_lotu >> wczytany_nazwisko_pasazera >> wczytany_numer_miejsca;
            
            if (plik.eof()) break;
            
            dodajLotOrazPasazeraDoListy(lista_lotow, wczytany_symbol_lotu, wczytany_lotnisko_startowe, wczytany_data_lotu, wczytany_nazwisko_pasazera, wczytany_numer_miejsca);
            
        }
        plik.close();
        pokazWszystkieLotyOrazPasazerow(lista_lotow);
    }
    else
    {
        cout << "Nie odnaleziono pliku lub plik uszkodzony." << endl;
    }
}

void zapisListLotowDoPlikow(lot* lista_lotow)
{
    ofstream plik;
    
    while (lista_lotow != nullptr)
    {
        string nazwa_pliku = lista_lotow->symbol_lotu + ".txt";
        plik.open (nazwa_pliku);
        
        plik << left << setw(13) << setfill(' ') << "symbol lotu: " << lista_lotow->symbol_lotu << endl;
        plik << left << setw(13) << "lotnisko: " << lista_lotow->lotnisko_startowe << endl;
        plik << left << setw(13) << "data lotu: " << lista_lotow->data_lotu << endl;
        plik << endl;
        plik << "lista pasazerow:" << endl;
        
        int liczba_rezerwacji = 0;
        pasazer* p = lista_lotow->lista_pasazerow;
        
        while (p != nullptr) {
            
            plik << right << setw(2) << setfill('0') << p->numer_miejsca << " " << p->nazwisko_pasazera << endl;
            
            liczba_rezerwacji++;
            p=p->nastepny_pasazer;
        }
        
        plik << endl;
        plik << "liczba rezerwacji: " << liczba_rezerwacji << endl;
        
        plik.close();
        
        lista_lotow=lista_lotow->nastepny_lot;
    }
}
