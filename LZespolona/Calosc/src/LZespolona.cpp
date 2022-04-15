
#include "LZespolona.hh"
#include <cmath>
#include <iostream>

using namespace std;

/*!
 * Realizuje zmiane znaku czesci urojonej danej liczby zespolonej.
 * Argumenty:
 *    Skl.im - czesc urojona,
 * Zwraca:
 *    Wartosc odwrotna czesci urojonej danej liczby zespolonej.
 */

LZespolona  sprzezenie (LZespolona Skl)
{
  Skl.im = -(Skl.im);
  return Skl;
}

/*!
 * Oblicza modul z liczby zespolonej.
 * Argumenty:
 *    Skl - Liczba zespolona ,
 * Zwraca:
 *    Iloraz dwuch takich samych liczb zespolonych podniesiony do potęgi .
 */
double modul2(LZespolona Skl){

    double Wynik;

    Wynik = (sqrt((Skl.re * Skl.re) + (Skl.im * Skl.im)));
    return Wynik;
}



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenia dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - licznik,
 *    Skl2 - mianownik.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */


LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
   
  Wynik=operator * (Skl1, sprzezenie(Skl2));
  Wynik.re = Wynik.re/pow(modul2(Skl2), 2);
  Wynik.im = Wynik.im/pow(modul2(Skl2), 2);
  return Wynik;
}

/*
 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 $ Wyswietla liczbę zespoloną za pomocą przeciążenia $
 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 */

ostream& operator << (ostream &StrmWy, LZespolona liczba){
    return StrmWy << '(' << liczba.re << showpos << liczba.im << noshowpos << 'i' << ')';
   
}

/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Wczytuje liczbę zepoloną wykorzystując przeciążenie operatora @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/
istream& operator >> (istream &StrmWe, LZespolona &liczba){
    
    char znak;

    StrmWe >> znak;
    if (znak != '(') {StrmWe.setstate(ios::failbit);}
    StrmWe >> liczba.re;
    StrmWe >> liczba.im; 
    StrmWe >> znak;
    if (znak != 'i') {StrmWe.setstate(ios::failbit);}
    StrmWe >> znak;
    if (znak != ')') {StrmWe.setstate(ios::failbit);}
    
    return StrmWe;
}








