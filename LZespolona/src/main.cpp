#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) // jesli nie podano w wywolaniu funkcji trudnosci testu zakoncz program
  {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe; // zmienna do obs³ugi funkcji wyrazenia zespolonego
  LZespolona C, D; // zmeinne do obslugi liczby zespolonej szeroko pojetej
  Stat Z; // zmienna do komunikacji z struktura statystyki
  double w,y; // zmienne pomocnicze sluzace do porownywania poprawnej odpowiedzi i wprowadzonej przez uzytkownika

  Z.git = 0;
  Z.niegit = 0;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) // glowna petla testu, pobiera kolejne pytanie w kazdym swoim zapetleniu
  {
    cout << "Podaj wynik operacji:";
    cout << WyrZ_PytanieTestowe << endl;
    cin >> D;
    while (cin.fail()) // dopoki uzytkownik podaje zly format liczby, czysc strumien i pros o kolejna liczbe
    {
    	cin.clear();
    	cin.ignore(10000, '\n');
    	cerr << "Zly format liczby zespolonej. Podaj inna liczbe:" << endl;
    	cin >> D;
	}
    w = D.im; // wprowadzenie czesci rzeczywistej i urojonej liczby od uzytkownika pod zmienne pomocnicze w celu dalszego porownania
    y = D.re;
    C=Oblicz (WyrZ_PytanieTestowe); // obliczanie prawdilowego wyniku
    if(C.re == y && C.im == w) // jesli porownanie liczb sie zgadza to odpowiedz dobra
    {
    	cout << "Odpowiedz poprawna :)" << endl << endl;
    	++Z.git; // zliczanie dobrych odpowiedzi
	}
	else // gdy porownanie zle, odpowiedz niepoprawna
	{
		cout << "Zla odpowiedz :(" << endl << "Poprawnym wynikiem jest: " << C << endl << endl;
		++Z.niegit; // zliczanie zlych odpowiedzi
	}
  }

  WyswietlWynik(Z); // wyswietlanie wyniku

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
