#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

using namespace std;

 /*!!!****************************************************!!!*/
 /* Plik zawiera definicje struktury 'LZesplona', zapowiedzi */
 /* przeciazen operatorow dzialajacych na tej                */
 /* strukturze, funkcje wyswietlania i wczytwywania liczby   */
 /* zespolonej oraz funkcje obliczajace modul i sprzezenie   */
 /* potrzebne do przeciazenia operatora dzielenia.           */
 /*!!!****************************************************!!!*/


 /**************************************/
 /* Modeluje pojecie liczby zespolonej */
 /**************************************/

struct LZespolona {
  double re;    // Pole repezentuje czesc rzeczywista
  double im;    // Pole repezentuje czesc urojona
};




 /****************************************/
 /* Prototypy wyzej wymienionych funkcji */
 /****************************************/


ostream& operator << (ostream& StrWyj, LZespolona liczba);
void Wyswietl (LZespolona arg);
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona sprzezenie (LZespolona Skl);
double modul (LZespolona Skl);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
LZespolona Wczytaj();
istream& operator >> (istream& StrWej, LZespolona& liczba);

#endif
