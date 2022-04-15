#ifndef SCENA_HH
#define SCENA_HH

#include "lacze_do_gnuplota.hh"
#include "PowierzchniaDna.hh"
#include "PowierzchniaWody.hh"
#include "Dron.hh"
#include <cstdio>
#include <cstring>

class Scena : public Dron, public PowierzchniaDna, public PowierzchniaWody{

    public:

        
        
        
        //Metoda wyswietla opcje w menu
        void WyswietlMenu();
        
        void Menu();

        //Sprawdza czy wprowadzona wartosc jest liczba
        double ObslBl();

        //Uruchamia porgram
        void Start();

        
        


};














#endif
