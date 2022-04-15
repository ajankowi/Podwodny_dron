#include "Statystyka.hh"


 /********************************************/
 /* Funkcja wyswietlajaca informacje zebrane */
 /* w strukturze 'Stat', oraz obliczajaca    */
 /* z nich wynik procentowy i rowniez        */
 /* go wyswietlajaca                         */
 /********************************************/

void WyswietlWynik(Stat P)
{
    double Wynik;
    Wynik = ((double)P.git / ((double)P.git + (double)P.niegit)) * 100;
    cout << "Liczba dobrych odpowiedzi: " << P.git << endl;
    cout << "Liczba zlych odpowiedzi: " << P.niegit << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << Wynik << "%" << endl;
}

