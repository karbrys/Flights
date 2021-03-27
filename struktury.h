/** @file */
//  struktury.h
//  LOTY
//  Created by Karola on 29/12/2019.
//  Copyright © 2019 Karolina Bryś. All rights reserved.

#ifndef struktury_h
#define struktury_h

#include <string>
using namespace std;

/** Element listy jednokierunkowej "lista_pasazerow"  */
struct pasazer
{
    string nazwisko_pasazera;   ///Wartość przechowywana w liście symbolizująca nazwisko danego pasażera.
    int numer_miejsca;          ///Wartość przechowywana w liście symbolisująca numer miejsca danego pasażera.
    pasazer *nastepny_pasazer;  ///Wskaźnik na następny element listy jednokierunkowej.
};

/** Element listy jednokierunkowej "lista_lotow"  */
struct lot
{
    string symbol_lotu;         ///Wartość przechowywana w liście symbolizująca symbol danego lotu.
    string lotnisko_startowe;   ///Wartość przechowywana w liście symbolizująca  lotnisko startowe danego lotu.
    string data_lotu;           ///Wartość przechowywana w liście symbolizująca datę danego lotu.
    lot *nastepny_lot;          ///Wskaźnik na następny element listy jednokierunkowej "lista_lotow".
    pasazer *lista_pasazerow;   ///Wskaźnik na następny element listy jednokierunkowej "lista_pasazerow".
};

#endif 
