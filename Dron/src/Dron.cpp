#include "Dron.hh"
#include "Wektor3D.hh"
#include "Lamana.hh"
#include "PowierzchniaGeomScn.hh"


void Dron::Wspolrzedne(){

    //Poczatkowe wspolrzedne Drona
    _WierzLok.DodajWierzcholek(0, -2,  0);
    _WierzLok.DodajWierzcholek(1, -2,  1);
    _WierzLok.DodajWierzcholek(1,  2,  1);
    _WierzLok.DodajWierzcholek(0,  2,  0);
    _WierzLok.DodajWierzcholek(1, -2, -1);
    _WierzLok.DodajWierzcholek(1,  2, -1);
    _WierzLok.DodajWierzcholek(-1, -2, -1);
    _WierzLok.DodajWierzcholek(-1,  2, -1);
    _WierzLok.DodajWierzcholek(-1, -2,  1);
    _WierzLok.DodajWierzcholek(-1,  2,  1);

    ZapiszDoPliku(_WierzLok);



    
}
//Umozliwia przesuniecie Dorna o zadany wektor 
void Dron::Przesun(double Predkosc, double Czas, double Gamma){
    

    Wektor3D Wek;
    Wektor3D Pomocyy;    

    Gamma = M_PI*Gamma/180;

    //Wspolrzedne Drona uwzgledniajce kat obrotu
    Wek[0] = cos(Kat);
    Wek[1] = sin(Kat);
    Wek[2] = tan(Gamma);
    
        

        for(double i = 1; i < 15; i++) {  
            if(Kolizja()){
                Pomocyy = (Wek * Czas  * Predkosc);
                Pomocyy = Pomocyy / 14;

                PrzesunWektor(Pomocyy);
                              
                ZapiszDoPliku(_WierzLok);  
                Lacze.Rysuj(); 
                usleep(100000);        
            } 
        }             
            
    
}  



void Dron::Obrot(double beta){
    Wektor3D Wektor;
    
    double x,y,a;
    //Kat obrotu 
    beta = beta*M_PI/180;

    //Calkowity kat obrotu Drona
    Kat = Kat + beta;
   
    
        
        for(unsigned int j = 0; j < 10; ++j){

        //Zmienna umozliwoajaca stworzenie animacji obrotu
        a =  beta/10;     
    
            for(unsigned int i = 0; i < 10; ++i){
                x = _WierzLok._Wierz[i][0];
                y = _WierzLok._Wierz[i][1];
        
                Wektor[0] = x*cos(a) - y*sin(a);
                Wektor[1] = x*sin(a) + y*cos(a);
                Wektor[2] = _WierzLok._Wierz[i][2];

                _Pomoc.DodajWierzcholek(Wektor);
                    
            }

            _WierzLok._Wierz.clear();

            for (const Wektor3D&  W_lok : _Pomoc._Wierz){
                _WierzLok.DodajWierzcholek(W_lok);
       
            }
        _Pomoc._Wierz.clear();
        ZapiszDoPliku(_WierzLok);
        Lacze.Rysuj();
        usleep(100000);         
        }
    
  
}

//Metoda sprawdza kolizje z dnem lub wyplyniecie powyzej tafli wody
bool Dron::Kolizja(){

    

    for (const Wektor3D&  W_lok : _WierzLok._Wierz){
                
        if ((W_lok[2] + _Trans[2] >= 8)||(W_lok[2] + _Trans[2] <= -9)){

            if(W_lok[2] + _Trans[2] >= 8){
                 std::cout << "Uderzyles o Powierzchnie Wody" << std::endl;           
            }
            else if (W_lok[2] + _Trans[2] <= -9){
                  std::cout << "Uderzyles o Dno" << std::endl;        
            }


            return false;
        }       
    }         
       
    return true; 

}









