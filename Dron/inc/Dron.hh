#ifndef DRON_HH
#define DRON_HH

#include "lacze_do_gnuplota.hh"
#include "Wektor3D.hh"
#include "Lamana.hh"
#include "PowierzchniaGeomScn.hh"
#include <unistd.h>
#include <math.h>
#include <memory>

class Dron : public PowierzchniaGeomScn{

    public:
        //Umozliwia bieżące rysowanie Drona
        PzG::LaczeDoGNUPlota Lacze;

        double odleglosc;

        //Zmienna zapisujaca kat obrotu
        double Kat;

        //Metoda przesuwa Drona na dana odlegosc
        void Przesun(double Predkosc, double Czas, double Gamma);
        
        //Metoda inicjuje wspolrzedne drona
        void Wspolrzedne(); 
        
        //Metoda umozliwiajaca obrot Drona  
        void Obrot(double beta);
    
        bool Kolizja();

};

#endif
