#ifndef funkcje_h
#define funkcje_h

#include "struktury.h"

void pokazLot(lot* temp);

void pokazWszystkieLoty(lot* lista_lotow);

lot* nowyLot(string symbol_lotu, string lotnisko_startowe, string data_lotu);

void dodajLotDoListy(lot* &lista_lotow, string symbol_lotu, string lotnisko_startowe, string data_lotu);

void pokazPasazera(pasazer* temp);

void pokazWszystkichPasazerow(pasazer* lista_pasazerow);

pasazer* nowyPasazer(string nazwisko_pasazera, int numer_miejsca);

void dodajPasazeraDoListy(pasazer* &lista_pasazerow, string nazwisko_pasazera, int numer_miejsca);


void dodajLotOrazPasazeraDoListy(lot* &lista_lotow, string symbol_lotu, string lotnisko_startowe, string data_lotu, string nazwisko_pasazera, int numer_miejsca);


void pokazWszystkieLotyOrazPasazerow(lot* lista_lotow);


void usunListePasazerow(pasazer* &lista_pasazerow);


void usunListeLotow(lot* &lista_lotow);


void wczytywanieLotowOrazPasazerow(string sciezka_do_pliku, lot* &lista_lotow);


void zapisListLotowDoPlikow(lot* lista_lotow);

#endif
