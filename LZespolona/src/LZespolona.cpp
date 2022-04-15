#include "LZespolona.hh"
#include <cmath>


/*!!!**********************************************!!!*/
/* Plik zawiera funkcje przeciazen operatorow,        */
/* fuknkcje modulu i sprzezenia potrzebne do funkcji  */
/* przeciazenia operatora dzielenia, oraz funkcje     */
/* wyswietlania i wczytywania liczby zespolonej       */
/*!!!**********************************************!!!*/


/********************************************************/
/* Funkcja przeciazenia operatora przesuniecia bitowego */
/* w lewo. Funkcja ma na celu wyswietlac liczbe         */
/* zespolona. Zwraca strumien wyjsciowy z taka wlasnie  */
/* liczba.                                              */
/********************************************************/

ostream& operator << (ostream& StrWyj, LZespolona liczba)
{
  StrWyj << "(" << liczba.re << showpos << liczba.im << "i)" << noshowpos;
  return StrWyj;
}


/*************************************************************/
/* Funkcja przeciazenia operatora przesuniecia               */
/* bitowego w prawo dla wczytywania liczby zespolonej        */
/* ze std. Funkcja po wczytaniu kazdego obiektu sprawdza czy */
/* spelnia on zalozenia tego jak ma wygladac liczba          */
/* zespolona. Jezeli cos sie nie zgadza, blokuje strumien    */
/* wejsciowy flaga 'failbit' i konczy swoje dzialanie        */
/*************************************************************/

istream& operator >> (istream& StrWej, LZespolona& liczba)
{
	char tmp;

	StrWej >> tmp;
	if  (tmp != '(')
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> liczba.re;
	if (!StrWej)
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> liczba.im;
	if (!StrWej)
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> tmp;
	if  (tmp != 'i')
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> tmp;
	if  (tmp != ')')
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	return StrWej;
}

/**************************LINIA ODZIELAJACA NIEUZYWANE FUNKCJE*************************/


/***************************************/
/* Funkcja zamieniajaca znak czesci    */
/* urojonej wybranej liczby zespolonej */
/* na odwrotny			               */
/***************************************/

LZespolona  sprzezenie (LZespolona Skl)
{
  Skl.im = -(Skl.im);
  return Skl;
}


/****************************************/
/* Funkcja obliczajaca "modul" ze wzoru */
/* dla wprowadzonej liczby zespolonej   */
/* i zwracajaca jego wartosc w postaci  */
/* jednej liczby w formacie double      */
/****************************************/

double  modul (LZespolona Skl)
{
  double Wynik;

  Wynik = sqrt(pow(Skl.re, 2) + pow(Skl.im, 2));
  return Wynik;
}


/**********************************************/
/* Funkcja przeciazenia operatora dodawania.  */
/* Wykonuje dodawanie dwoch liczb zespolonych */
/**********************************************/

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*********************************************/
/* Funkcja przeciazenia operatora mnozenia.  */
/* Wykonuje mnozenie dwoch liczb zespolonych */
/*********************************************/

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2 .re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}


/***************************************************/
/* Funkcja przeciazenia operatora dzielenia.       */
/* Wykonuje dzielenie dwoch liczb zespolonych      */
/* wykorzysujac do tego rowniez funkcje sprzezenia */
/* modulu i przeciazenia oper. mnozenia            */
/***************************************************/

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik=operator * (Skl1, sprzezenie(Skl2));
  Wynik.re = Wynik.re/pow(modul(Skl2), 2);
  Wynik.im = Wynik.im/pow(modul(Skl2), 2);
  return Wynik;
}


/************************************************/
/* Funkcja przeciazenia operatora odejmowania.  */
/* Wykonuje odejmowanie dwoch liczb zespolonych */
/************************************************/

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/************************************************/
/* Funkcja wyswietlajaca dana liczbe zespolona  */
/************************************************/

void Wyswietl (LZespolona arg)
{
  cout<<"("<<arg.re<<showpos<<arg.im<<"i)"<<noshowpos;
}


/*******************************************************/
/* Funkcja wczytujaca liczbe zespolona z std.          */
/* Funkcja uzywa zmiennej 'tmp' w wiekoszci przypadkow */
/* jako tzw. smietnika                                 */
/*******************************************************/

LZespolona Wczytaj()
{
  LZespolona liczba;
  char tmp;

  cin >> tmp;
  cin >> liczba.re;
  cin >> tmp;
  cin >> liczba.im;
  if(tmp=='-')
  	liczba.im=liczba.im*(-1);
  cin >> tmp;
  cin >> tmp;
  return liczba;
}
