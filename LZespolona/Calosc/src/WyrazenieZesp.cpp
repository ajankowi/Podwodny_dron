#include "WyrazenieZesp.hh"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */




/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Funkcja oblicza wartość danego rówanania dla liczb zespolonych.% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

LZespolona Oblicz(WyrazenieZesp  WyrZ){
    
    LZespolona Z;
    
    switch(WyrZ.Op){
    
    case Op_Dodaj:
        return operator + (WyrZ.Arg1,WyrZ.Arg2);
        break;

    case Op_Odejmij:
        return operator - (WyrZ.Arg1,WyrZ.Arg2);
    break;

    case Op_Mnoz:
        return operator * (WyrZ.Arg1,WyrZ.Arg2);
    break;

    case Op_Dziel:
        return operator / (WyrZ.Arg1,WyrZ.Arg2);
    break;
    }
    
    return Z;
}
/*Przeciazenie umozliwiajace wyswietlenie znaku*/
ostream &operator << (ostream &StrmWy, Operator Op){
    
    const char ZnakOp[] = "+-*/";
    return StrmWy << ZnakOp[Op];

}


/*Przeciazenie umozliwiajace wyswietlenie wyrazenia zespolonego*/
ostream &operator << (ostream &StrmWyj, WyrazenieZesp  Wyr){

    return StrmWyj << Wyr.Arg1 << Wyr.Op << Wyr.Arg2;

}

/*Przeciążenie wczytywania znaku*/


istream &operator >> (istream &StrmWe, Operator &WczytSym) { 

    Operator TabTypOp[] = {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel}; 
    const char TabSymOp[] = "+-*/"; 
    const char *wSymOp; 
    char CzytSymOp = 'x'; 
    
    StrmWe >> CzytSymOp; 
    if ((wSymOp = strchr(TabSymOp,CzytSymOp)) == nullptr) {StrmWe.setstate(ios::failbit);} 
    else {WczytSym = TabTypOp[wSymOp - TabSymOp];} 
    
    return StrmWe;
       
}
/*Przeciazenie wczytywania wyrazenia zespolonego*/

istream &operator >> (istream &StrmWe, WyrazenieZesp &Wyr){

    return StrmWe >> Wyr.Arg1 >> Wyr.Op >> Wyr.Arg2;
}



