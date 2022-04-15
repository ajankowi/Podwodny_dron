#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>

#include "rozmiar.h"

class Wektor {
    double  _Wsp[ROZMIAR];
  public:
    Wektor() { for (double &Wsp_i: _Wsp) Wsp_i = 0; }
  
    double  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    double &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    Wektor operator - (const Wektor &Odjemnik) const;
    Wektor operator * (double Mnoznik) const;
};


std::ostream& operator << (std::ostream &StrmWyj, const Wektor& W);

#endif
