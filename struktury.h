#ifndef struktury_h
#define struktury_h

#include <string>
using namespace std;

struct pasazer
{
    string nazwisko_pasazera;   
    int numer_miejsca;          
    pasazer *nastepny_pasazer;  
};

struct lot
{
    string symbol_lotu;         
    string lotnisko_startowe;   
    string data_lotu;           
    lot *nastepny_lot;         
    pasazer *lista_pasazerow;   
};

#endif 
