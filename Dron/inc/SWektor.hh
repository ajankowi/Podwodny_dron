#ifndef SWEKTOR_HH
#define SWEKTOR_HH

#include <iostream>
#include <cmath>
#include <cstdio>
#include <limits>
#include <iomanip>

//Szablon wektor

template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    //Wyzerowanie warości poszczególnych wartości wektora


    /*
    SWektor() { for (STyp &Wsp_i: _Wsp) Wsp_i = 0; 
    SWektor(float r, float i){ for (STyp &Wsp_i: _Wsp) Wsp_i.re = 0; Wsp_i.im = 0; }
    */
    STyp  operator [] (unsigned int Idn) const {return _Wsp[Idn];}
    STyp &operator [] (unsigned int Idn)       {return _Wsp[Idn];}  


    //Przeciążenie operatora mnożenia i dzielenia wektora przez liczbe
    SWektor<STyp,SWymiar> operator * (STyp n) const;
    SWektor<STyp,SWymiar> operator / (STyp n) const;    

    
    

    //Przeciążenie dodawania i odejmowania dwoch wektorow
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Wek);
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Wek);

    //Obliczanie dlugosci wektora
    double dlugosc();
};






//Przeciazenie czytania wektora 
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek){
    for (unsigned int Ind =0; Ind < SWymiar; Ind++){
            
            Strm >> Wek[Ind];
            while (std::cin.fail()){
                
                std::cout << std::endl << "!!!! Nalezy podac liczbe !!!! " << std::endl << std::endl;   
                std::cin.clear();  //"Czyszczenie standardowego wejscia"
                std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n');
                Strm >> Wek[Ind];                            
            }             
        } 
    return Strm;
}








//Przeciazenie wyświetlania wektora
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<STyp,SWymiar> &Wek){
    for (unsigned int Ind =0; Ind < SWymiar; Ind++){
         Strm  << std::fixed << std::setprecision(4) << Wek[Ind] << "  ";     
    }
    return Strm;
}









//Przeciążenie operatora mnożenia wektora przez liczbe
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (STyp n) const{
        
   SWektor<STyp,SWymiar> W;
       
    for (unsigned int Ind =0; Ind < SWymiar; Ind++){
         W[Ind] = (*this)[Ind]*n;     
    }    
    return W;    
}



//Przeciazenie operatora dzelenia wektora przez liczbe
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (STyp n) const{
        
    SWektor<STyp,SWymiar> W;
       
    for (unsigned int Ind =0; Ind < SWymiar; Ind++){
         W[Ind] = (*this)[Ind]/n;     
    }    
    return W;
   
}











//Przeciazenie operatora dodawania dwoch wektorow
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Wek){

    SWektor<STyp,SWymiar> W;
    for (unsigned int Ind =0; Ind < SWymiar; Ind++){
         W[Ind] = _Wsp[Ind] + Wek[Ind];     
    }
    
    return W;
}







//Przeciazenie operatora odejmowania dwoch wektorow
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Wek){
    
    SWektor<STyp,SWymiar> W;
    for (unsigned int Ind =0; Ind < SWymiar; Ind++){
         W[Ind] = _Wsp[Ind] - Wek[Ind];     
    }
    
    return W;
}









//Funkcja oblicza dlugosc wektora
template <typename STyp, int SWymiar>
double SWektor<STyp,SWymiar>::dlugosc(){
    
    double wynik = 0;
    SWektor<STyp,SWymiar> W;
    for (unsigned int Ind =0; Ind < SWymiar; Ind++){
        W[Ind] = _Wsp[Ind] * _Wsp[Ind];   
        wynik =  wynik + W[Ind];
    }
    wynik = sqrt(wynik);
    return wynik;
}



#endif
