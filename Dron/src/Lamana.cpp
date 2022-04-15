#include <fstream>
#include "Lamana.hh"
#include "SWektor.hh"
#include <vector>
#include "Wektor3D.hh"




//Metoda umożliwia zapistanie łamanej do pliku
void Lamana::DodajWierzcholek(double X, double Y, double Z){

    
    Wektor3D Wek;
    
    Wek[0] = X;
    Wek[1] = Y;
    Wek[2] = Z;
    _Wierz.push_back(Wek);

}

void Lamana::DodajWierzcholek(Wektor3D Wek){

    _Wierz.push_back(Wek);

}
void Lamana::UsunWierzcholek(){
    
    _Wierz.clear();
}


void Lamana::Wyswietl(){

    
    
    DodajWierzcholek(1,2,3);
    DodajWierzcholek(4,5,6);
    DodajWierzcholek(7,8,9);
    DodajWierzcholek(1,2,3);
    
    
}

