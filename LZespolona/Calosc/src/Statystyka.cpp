#include "Statystyka.hh"


/*Wyswietla statystyke uzyskanych punktow*/
void WyswStat(Stat S)
{
    double Wynik;
    Wynik = 100 * S.dobre / (S.dobre + S.zle);
    cout << " Liczba dobrych odpowiedzi: " << S.dobre << endl;
    cout << " Liczba zlych odpowiedzi: " << S.zle << endl;
    cout << " Wynik procentowy poprawnych odpowiedzi: " << Wynik << "%" << endl << endl << endl;

}

