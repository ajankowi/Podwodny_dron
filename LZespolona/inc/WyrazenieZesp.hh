#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

 /*!!!*******************************************************!!!*/
 /* Plik zawiera definicje struktury 'WyrazenieZesp', typu      */
 /* wyliczeniowego 'Operator', zapowiedzi funkcji wczytujacych  */
 /* i wyswietlajacych symbol znaku arytmetycznego (dla starej   */
 /* i nowej wersji programu), funkcji wyswietlajacych           */
 /* i wczytujacych wyrazenie zespolone, fukncji obliczajacej    */
 /* wynik wyrazenia zespolonego, oraz funkcji przeciazenia      */
 /* operatora przesunieca bitowego w lewo i prawo dla wyrazenia */
 /* zespolonego.                                                */
 /*!!!*******************************************************!!!*/


 /********************************************/
 /* Modeluje zbior operatorow arytmetycznych */
 /********************************************/

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };


 /***********************************************************/
 /* Modeluje pojecie dwuargumentowego wyrazenia zespolonego */
 /***********************************************************/

struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


 /****************************************/
 /* Prototypy wyzej wymienionych funkcji */
 /****************************************/

ostream& operator << (ostream& StrWyj, WyrazenieZesp wyr);
Operator WczytajSymbol ();
void WyswietlSymbol (Operator operatort);
void WyswietlWyr(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
WyrazenieZesp WczytajWyr ();
char ZwrocSymbol (Operator operatort);
Operator WczytajSymbol (char operatort);
istream& operator >> (istream& StrWej, WyrazenieZesp& wyr);

#endif
