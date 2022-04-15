#include <fstream>
#include "PowierzchniaGeomScn.hh"
#include <vector>
#include "Lamana.hh"
#include "PowierzchniaGeom.hh"
#include <iostream>
#include "Wektor3D.hh"
#include <iomanip>



void PowierzchniaGeomScn::PrzesunWektor(Wektor3D Wek){

    
    _Trans[0] = _Trans[0] + Wek[0];
    _Trans[1] = _Trans[1] + Wek[1];
    _Trans[2] = _Trans[2] + Wek[2];
    
  

}

void PowierzchniaGeomScn::ZapiszDoPliku(Lamana La){
    
    const int Kole[20]= { 
            0, 1, 2, 3,
            0, 4, 5, 3, 
            0, 6, 7, 3, 
            0, 8, 9, 3,
            0, 1, 2, 3 };


    std::fstream plik("bryly/Dronek.dat",std::ios::out);


    for(int i = 0; i < 20; i++) {
        Wektor3D Pomocy;
             
    
          Pomocy = La._Wierz[Kole[i]] + _Trans;       
    
          plik << Pomocy << "\n";

          if(i % 4 == 3) 
          {
              plik << "\n";
          }
      }

    plik.close();   

}



