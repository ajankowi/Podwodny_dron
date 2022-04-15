#include "PowierzchniaDna.hh"

#define ZAKRES_X 20
#define ZAKRES_Y 10

#define X -10 
#define Y -10
#define Z -9

void PowierzchniaDna::InicjujDno(){

    Wektor3D Wek1, Wek2, Poczatek;
    

    //Ustawianie wartosci 1 wektora 
    Wek1[0] = 1;
    Wek1[1] = 0;
    Wek1[2] = 0;

    //Ustawianie wartosci 2 Wektora
    Wek2[0] = 0;
    Wek2[1] = 2;
    Wek2[2] = 0;

    //Algorytm tworzacy powierzchnie dna
    for(unsigned int i = 0; i < ZAKRES_X; i++) {
        
        for(unsigned int j = 0; j < ZAKRES_Y; j++) {

                //Poczatkowe wspolrzedne dna
                Poczatek[0] = X;
                Poczatek[1] = Y;
                Poczatek[2] = Z;              

               
                Poczatek =  Poczatek + Wek1*i + Wek2*j;              
                _PowDna.DodajWierzcholek(Poczatek);

                 Poczatek = Poczatek + Wek1;        
                _PowDna.DodajWierzcholek(Poczatek);

                Poczatek = Poczatek + Wek2;
                _PowDna.DodajWierzcholek(Poczatek);

                Poczatek = Poczatek - Wek1;               
                _PowDna.DodajWierzcholek(Poczatek);

                
                if(j == ZAKRES_Y-1){
                    Poczatek[0] = X;
                    Poczatek[1] = Y;
                    Poczatek[2] = Z; ;  
                    Poczatek = Poczatek + Wek1*i;
                    _PowDna.DodajWierzcholek(Poczatek);
                }
                

        }
    }
                
    ZapiszDno();      
        
    

}

void PowierzchniaDna::ZapiszDno(){


std::fstream plik("bryly/PowierzchniaDna.dat",std::ios::out);    

     for(unsigned int i = 0; i < _PowDna._Wierz.size(); i++) {
               
    
          plik << _PowDna._Wierz[i] << "\n";

         
      }

    plik.close();  

}
