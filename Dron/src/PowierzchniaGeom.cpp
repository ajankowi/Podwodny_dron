#include <fstream>
#include "PowierzchniaGeom.hh"
#include "Lamana.hh"
#include "Wektor3D.hh"
#include "SWektor.hh"
#include <iomanip>



std::ostream& operator << (std::ostream &Strm, const Lamana &La){

       for (unsigned int Ind = 0; Ind < 4; Ind++){
         Strm << La._Wierz[Ind] << "\n";     
    }
    return Strm;


}


void PowierzchniaGeom::DodajLamana(Lamana La){
 

    _TabLamanych_Lok.push_back(La);

/*
    std::fstream plik("bryly/Dronek.dat",std::ios::out);
    plik << _TabLamanych_Lok[0] << "\n";

     plik.close();
  
   for (const Wektor3D&  W_lok : _Wierz){
        
        W_glob = W_lok[1] ;
        std::cout << W_glob << std::endl;
    }
*/

}









