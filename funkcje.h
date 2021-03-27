/** @file */
//  funkcje.h
//  LOTY
//  Created by Karola on 29/12/2019.
//  Copyright © 2019 Karolina Bryś. All rights reserved.

#ifndef funkcje_h
#define funkcje_h

#include "struktury.h"

// funkcje struktury lot
/** Funkcja wypisuje liste jednokierunkową od początku (iteracyjnie).
 @param temp Wskaźnik na pierwszy element listy.
 */
void pokazLot(lot* temp);

/** Funkcja wypisuje liste jednokierunkową od początku (iteracyjnie).
 @param lista_lotow Wskaźnik na pierwszy element listy.
 */
void pokazWszystkieLoty(lot* lista_lotow);

/** Funkcja tworzy nowy element listy jednokierunkowej "lista_lotow".
 @param symbol_lotu Wartość nowego elementu symbolizująca symbol danego lotu.
 @param lotnisko_startowe Wartość nowego elementu symbolizująca lotnisko startowe danego lotu.
 @param data_lotu Wartość nowego elementu symbolizująca datę danego lotu.
 */
lot* nowyLot(string symbol_lotu, string lotnisko_startowe, string data_lotu);

/**Funkcja dodaje nowy lot na koniec listy jednokierunkowej (iteracyjnie).
 @param lista_lotow Wskaźnik na pierwszy element listy jednokierunkowej.
 @param symbol_lotu Wartość elementu do dodania symbolizująca symbol danego lotu.
 @param lotnisko_startowe Wartość elementu do dodania symbolizująca lotnisko startowe danego lotu.
 @param data_lotu Wartość elementu do dodania symbolizująca datę danego lotu.
 */
void dodajLotDoListy(lot* &lista_lotow, string symbol_lotu, string lotnisko_startowe, string data_lotu);

// funkcje struktury pasazer
/** Funkcja wypisuje liste jednokierunkową od początku (iteracyjnie).
 @param temp Wskaźnik na pierwszy element listy.
 */
void pokazPasazera(pasazer* temp);

/** Funkcja wypisuje liste jednokierunkową od początku (iteracyjnie).
 @param lista_pasazerow Wskaźnik na pierwszy element listy.
 */
void pokazWszystkichPasazerow(pasazer* lista_pasazerow);

/**Funkcja tworzy nowy element listy jednokierunkowej "lista_pasazerow".
 @param nazwisko_pasazera Wartość nowego elementu symbolizująca nazwisko danego pasażera.
 @param numer_miejsca Wartość nowego elementu symbolizująca numer miejsca danego pasażera.
 */
pasazer* nowyPasazer(string nazwisko_pasazera, int numer_miejsca);

/**Funkcja dodaje nowy lot na koniec listy jednokierunkowej (iteracyjnie).
 @param lista_pasazerow Wskaźnik na pierwszy element listy jednokierunkowej.
 @param nazwisko_pasazera Wartość elementu do dodania symbolizująca nazwisko danego pasażera.
 @param numer_miejsca Wartość elementu do dodania symbolizująca numer miejsca danego pasażera.
 */
void dodajPasazeraDoListy(pasazer* &lista_pasazerow, string nazwisko_pasazera, int numer_miejsca);

//fukcje dla dwóch list
/**Funkcja dodaje na koniec listy jednokierunkowej nowy element (iteracyjnie).
 @param lista_lotow Wskaźnik na pierwszy element listy.
 @param symbol_lotu Wartość elementu do dodania symbolizująca symbol danego lotu.
 @param lotnisko_startowe Wartość elementu do dodania symbolizująca lotnisko startowe danego lotu.
 @param data_lotu Wartość elementu do dodania symbolizująca datę danego lotu.
 @param nazwisko_pasazera Wartość elementu do dodania symbolizująca nazwisko danego pasażera.
 @param numer_miejsca Wartość elementu do dodania symbolizująca numer miejsca danego pasażera.
 */
void dodajLotOrazPasazeraDoListy(lot* &lista_lotow, string symbol_lotu, string lotnisko_startowe, string data_lotu, string nazwisko_pasazera, int numer_miejsca);

/**Funkcja wypisuje liste jednokierunkową od początku (iteracyjnie).
 @param lista_lotow Wskaźnik na pierwszy element listy.
 */
void pokazWszystkieLotyOrazPasazerow(lot* lista_lotow);

/**Funkcja usuwa listę (iteracyjnie).
 @param lista_pasazerow Wskaźnik na pierwszy element listy – po usunięciu listy jest równy nullptr.
 */
void usunListePasazerow(pasazer* &lista_pasazerow);

/**Funkcja usuwa listę (iteracyjnie).
 @param lista_lotow Wskaźnik na pierwszy element listy – po usunięciu listy jest równy nullptr.
 */
void usunListeLotow(lot* &lista_lotow);

// funkcje glownego programu
/** Funkcja wczytuje z pliku bazowego (w tym przypadku z pliku biuro_centralne.txt) dane oraz tworzy nowe elementy listy jednokierunkowej.
 @param sciezka_do_pliku Ścieżka prowadząca do pliku bazowego, wprowadzana w wierszu poleceń.
 @param lista_lotow Wskaźnik na pierwszy element listy jednokierunkowej.
 */
void wczytywanieLotowOrazPasazerow(string sciezka_do_pliku, lot* &lista_lotow);

/**Funkcja zapisuje poszczególne loty (oraz przypisane do nich dane) do osobnych plików.
 @param lista_lotow Wskaźnik na pierwszy element listy jednokierunkowej.
 */
void zapisListLotowDoPlikow(lot* lista_lotow);

#endif
