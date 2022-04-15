#ifndef POWIERZCHNIAGEOM_HH
#define POWIERZCHNIAGEOM_HH



#include "Wektor3D.hh"
#include <vector>
#include <fstream>
#include "Lamana.hh"
#include "SWektor.hh"
#include <limits>

class PowierzchniaGeom {
    
    public:

        std::vector<Lamana> _TabLamanych_Lok ;
        
        Lamana La;

        void DodajLamana(Lamana La);

       
        
            
        
   
};
std::ostream& operator << (std::ostream &Strm, const Lamana &La);



#endif

