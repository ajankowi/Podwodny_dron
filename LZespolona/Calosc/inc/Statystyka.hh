#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>

using namespace std;


 /*********************************************/
 /* Modeluje pojecie dobrej i zlej odpowiedzi */
 /*********************************************/

struct Stat {

  double dobre;
  double zle;
};


 /*********************************************/
 /* Zapowiedz funkcji wyswietlania statystyki */
 /*********************************************/

void WyswStat(Stat P);

#endif
