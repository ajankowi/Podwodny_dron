#ifndef POWIERZCHNIAGEOMSCN_HH
#define POWIERZCHNIAGEOMSCN_HH

#include "Wektor3D.hh"
#include "Lamana.hh"
#include "PowierzchniaGeom.hh"
#include <vector>
#include <fstream>
#include <limits>
#include <iostream>
#include <iomanip>



class PowierzchniaGeomScn : public PowierzchniaGeom {
        
    
    public:
    
        std::vector<Lamana> _TabLamanychGlb;
        std::vector<Wektor3D> _WierzGlb;

        //Lamana zapisuje wspolrzedne wierzcholkow drona
        Lamana _WierzLok;

        //Lamana pomocnicza 1
        Lamana _Pomoc;
        
        //Lamana pomocnicza 2
        Lamana _Pomoc2;

        //Wektor zapisujacy wektor translacji
        Wektor3D _Trans;

       //Lamana umozliwia zapisanie wspolrzednych Dna
        Lamana _PowDna;
        
        //Zapisuje współrzędne wody
        Lamana _PowWody;



        //Zapisuje wartość kątu obrotu Drona
        double _KatObz;

        //Zapisuje przesuniecie wektora od wektore globalnego _Trans
        void PrzesunWektor(Wektor3D Wek);
        
        //Zapisuje lamana do pliku
        void ZapiszDoPliku(Lamana La);

        
     
        
   
};






#endif

