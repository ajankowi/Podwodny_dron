#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>

using namespace std;


 /*********************************************/
 /* Modeluje pojecie dobrej i zlej odpowiedzi */
 /*********************************************/

struct Stat {

  int git;
  int niegit;
};


 /*********************************************/
 /* Zapowiedz funkcji wyswietlania statystyki */
 /*********************************************/

void WyswietlWynik(Stat P);

#endif
