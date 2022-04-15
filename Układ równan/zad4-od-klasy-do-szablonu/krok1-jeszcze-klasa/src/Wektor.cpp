#include "Wektor.hh"

using namespace std;


Wektor Wektor::operator - (const  Wektor &Odjemnik) const
{
  Wektor  Wynik;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
       Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  }
  return Wynik;
}



Wektor Wektor::operator *  (double Mnoznik) const
{
  Wektor  Wynik;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
      Wynik[Ind] = (*this)[Ind]*Mnoznik;
  }
  return Wynik;  
}


ostream& operator << (ostream &StrmWyj, const Wektor& W)
{
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
       StrmWyj << " " << W[Ind];
  }  
  return StrmWyj;
}
