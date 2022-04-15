#ifndef LAMANA_HH
#define LAMANA_HH

#include "Wektor3D.hh"
#include "SWektor.hh"
#include <vector>
#include <fstream>
#include <limits>




class Lamana {
    
    public:

        std::vector<Wektor3D> _Wierz;
        


        //Metoda zapisuje łamaną jako Wektor3D  
        void DodajWierzcholek(double X, double Y, double Z);

        void DodajWierzcholek(Wektor3D Wek);
      
       
        void Wyswietl();

        void UsunWierzcholek();
   
};


#endif




