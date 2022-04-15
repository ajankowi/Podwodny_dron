#include "WyrazenieZesp.hh"


/*!!!*****************************************************!!!*/
/* Plik zawiera funkcje wczytywania i wyswietlania znaku     */
/* arytmetycznego (dla starej i nowej wersji programu),      */
/* funkcje wyswietlania i wczytywania wyrazenia zespolonego, */
/* fukncje obliczajaca wynik wyrazenia zespolonego, oraz     */
/* funckje przeciazenia operatorow przesuniecia bitowego     */
/* w lewo i prawo dla wyrazenia zespolonego.                 */
/*!!!*****************************************************!!!*/


/*****************************************************/
/* Funkcja obliczajaca wartosc danego wyrazenia      */
/* zespolonego. Funkcja korzysta z funkcji przciazen */
/* operatorow i zwraca za kazdym razem to, co zwraca */
/* dane przeciazenie    	                         */
/*****************************************************/

LZespolona Oblicz (WyrazenieZesp WyrZ)
{
  LZespolona B;
  switch (WyrZ.Op){
  case Op_Dodaj:
    return operator + (WyrZ.Arg1, WyrZ.Arg2);
    break;

  case Op_Odejmij:
    return operator - (WyrZ.Arg1, WyrZ.Arg2);
    break;

  case Op_Mnoz:
    return operator * (WyrZ.Arg1, WyrZ.Arg2);
    break;

  case Op_Dziel:
    return operator / (WyrZ.Arg1, WyrZ.Arg2);
    break;
  }
  return B;
}


/**********************************************************/
/* Funkcja potrzebna przy przeciazeniu operatora          */
/* przesuniecia bitowego w lewo dla wyrazenia zespolonego */
/* Funkcja przekazuje dla strumienia wyjsciowego aktualny */
/* znak dzialania znajdujacy sie w enumie Operator        */
/**********************************************************/

char ZwrocSymbol (Operator operatort)
{
  char B;
  switch (operatort){
  case Op_Dodaj:
    B = '+';
    break;

  case Op_Odejmij:
    B = '-';
    break;

  case Op_Mnoz:
    B = '*';
    break;

  case Op_Dziel:
    B = '/';
      }
  return B;
}


/*********************************************************/
/* Funkcja wczytujaca znak dzialania ze std, jest ona    */
/* potrzebna dla przeciazenia operatora przesuniecia     */
/* bitowego w prawo dla wyrazenia zespolonego. Funkcja   */
/* nieco sie rozni od tej uzywanej w wersji programu bez */
/* przeciazenia operatorow przesuniecia bitwoego. Zmiana */
/* jest przyjmowanie argumentu, oraz brak wczytywania ze */
/* std. funkcja cin       	                             */
/*********************************************************/

Operator WczytajSymbol (char operatort)
{
  Operator oper;
  switch (operatort){
  case '+':
    oper = Op_Dodaj;
    break;

  case '-':
    oper = Op_Odejmij;
    break;

  case '*':
    oper = Op_Mnoz;
    break;

  case '/':
    oper = Op_Dziel;
  }
  return oper;
}


/********************************************************/
/* Funkcja przeciazenia biotwego w lewo dla wyrazenia   */
/* zespolonego. Funkcja zwraca strumien wyjsciowy       */
/* a przyjmuje strukture wyrazenia zespolonego. Funkcja */
/* uwzywa funkcji zwrocenia symbolu                     */
/********************************************************/

ostream& operator << (ostream& StrWyj, WyrazenieZesp wyr)
{
  StrWyj << wyr.Arg1;
  StrWyj << ZwrocSymbol (wyr.Op);
  StrWyj << wyr.Arg2 << endl;
  return StrWyj;
}


/********************************************************/
/* Funkcja przeciazenia biotwego w prawo dla wyrazenia  */
/* zespolonego. Funkcja zwraca strumien wejsciowy       */
/* a przyjmuje strukture wyrazenia zespolonego. Funkcja */
/* uzywa funkcji wczytania symbolu                      */
/********************************************************/

istream& operator >> (istream& StrWej, WyrazenieZesp& wyr)
{
	char znak;
	StrWej >> wyr.Arg1;
	StrWej >> znak;
	wyr.Op = WczytajSymbol(znak);
	StrWej >> wyr.Arg2;
	return StrWej;
}

/************************LINIA ODZIELAJACA NIEUZYWANE FUNKCJE********************************/


/********************************************/
/* Funkcja wyswietlajaca znak arytemtyczny  */
/* aktualnie znajdujacy sie we wprowadzonej */
/* zmiennej typu 'Operator'    		        */
/********************************************/

void WyswietlSymbol(Operator operatort)
{
  switch (operatort){
  case Op_Dodaj:
    cout << "+";
    break;

  case Op_Odejmij:
    cout << "-";
    break;

  case Op_Mnoz:
    cout << "*";
    break;

  case Op_Dziel:
    cout << "/";
  }
}


/*******************************************/
/* Funkcja wczytujaca znak arytemtyczny    */
/* zwracajaca go w postaci typu 'Operator' */
/*******************************************/

Operator WczytajSymbol ()
{
  Operator oper;
  char operatort;
  cin >> operatort;
  switch (operatort){
  case '+':
    oper = Op_Dodaj;
    break;

  case '-':
    oper = Op_Odejmij;
    break;

  case '*':
    oper = Op_Mnoz;
    break;

  case '/':
    oper = Op_Dziel;
  }
  return oper;
}


/******************************************************/
/* Funkcja wyswietlajaca wyrazenie zespolone          */
/* przy pomocy dwoch funkcji wyswietlania liczby      */
/* zespolonej i jednej funkcji wyswietlania operatora */
/* arytmetycznego                                     */
/******************************************************/

void WyswietlWyr (WyrazenieZesp WyrZ)
{
  Wyswietl (WyrZ.Arg1);
  WyswietlSymbol (WyrZ.Op);
  Wyswietl (WyrZ.Arg2);
  cout << endl;
}


/*****************************************************/
/* Funkcja wczytuajca wyrazenie zespolone ze std.    */
/* Funkcja korzysta z dwoch funkcji wczytania liczby */
/* zespolonej i jednej funkcji wczytania znaku       */
/* arytmetycznego. Zakladamy ze uzytkownik ma        */
/* pojecia na temat tego jak powinna wygladac        */
/* liczba zespolona 				                 */
/*****************************************************/

WyrazenieZesp WczytajWyr ()
{
  LZespolona A, B;
  WyrazenieZesp Z;
  A = Wczytaj ();
  Operator oper = WczytajSymbol ();
  B = Wczytaj ();
  Z.Arg1 = A;
  Z.Arg2 = B;
  Z.Op = oper;
  return Z;
}
