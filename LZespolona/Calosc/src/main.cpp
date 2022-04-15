#include <iostream>
#include <cstdio>
#include <cstring>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;



int main(int argc, char **argv)
{

   /*Sprawdzanie poprawnosci uruchomienia trybu programu*/
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

 /*Sprawdzanie bledow*/
  BazaTestu   BazaT = { nullptr, 0, 0 };

  LZespolona X, Y; /*Zmienna zapisujaca liczbe zespolona*/
  WyrazenieZesp WyrZ_PytanieTestowe;
  Stat S;

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


                  /*Pocztatek testu*/
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  
        /*Petla dzialajaca tak dlugo jak dostepne sa nowe zadania*/
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " :? Podaj wynik operacji: ";
    cout << WyrZ_PytanieTestowe << " = " << endl;;
    cout << " :0 Twoja odpowiedz: ";
    cin >> X;
        

    while (cin.fail()){ /*Sprawdzanie poprawnosci wpisywanej liczby zespolonej*/
    
    	cin.clear();
    	cin.ignore(10, '\n');
    	cerr << " To nie jest liczba zespolona!" << "  Przyklad:  (1-2i)" << endl << endl <<  " :? Podaj liczbe zespolona: ";
 
        cin >> X;
    }
    Y = Oblicz(WyrZ_PytanieTestowe);

        /*Porównanie liczb wraz z informacją o poprawności wczesniejszych obliczen*/
    if ((X.re == Y.re) && (X.im == Y.im)){ 
        cout << " :3 Poprawna odpowiedz! " << endl << endl << endl;
        S.dobre++;
    }
    else{
        cout << " :/ Zla odpowiedz " << endl << endl;
        cout << "    Poprawna odpowiedz to: " << Y << endl << endl << endl;
        S.zle++;    
    }
  }  

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  
    /*Wyswietla statystyke*/
  WyswStat(S);

}
