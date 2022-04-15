#include "Scena.hh"
#include <cstdio>
#include <cstring>

void Scena::WyswietlMenu()
{
    
    std::cout << "\tw -- Jazda na wprost" << std::endl;
    std::cout << "\to -- Obrot o kat" << std::endl;
    std::cout << "\tm -- Wyswietlenie menu" << std::endl;
    std::cout << "\tk -- Zakonczenie dzialania programu" << std::endl;
}
void Scena::Menu(){
    
    
    std::cout << std::endl << "***************** Podwodny Dron *******************" <<     std::endl << std::endl;
    WyswietlMenu();
        
    const char TabOp[] = "womk";    
    const char *wOp;
    char CzytOp = 'x';
   
    
    do
    {
        std::cout << "\tWybierz opcje: ";
        std::cin >> CzytOp;
        while ((wOp = strchr(TabOp,CzytOp)) == nullptr) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            std::cout << "Prosze podac poprawna opcje\n";
            std::cin >> CzytOp;

        }

        switch(CzytOp)
        {
        case 'w':
            double Predkosc;
            double Czas;
            double Gamma;
            std::cout << "\n";            
            std::cout << "Podaj predkosc i czas lotu Drona: \n";

            std::cout << "\t Prędkość: ";                       
            std::cin >> Predkosc;
            if (std::cin.fail()) Predkosc = ObslBl(); 

            std::cout << "\t Czas: ";                       
            std::cin >> Czas;
            if (std::cin.fail()) Czas = ObslBl();
    
            std::cout << "\t Kat pochulenia lotu: ";                       
            std::cin >> Gamma;
            if (std::cin.fail()) Czas = ObslBl();


            Przesun(Predkosc, Czas, Gamma);
            
            
            break;

        case 'm':
            WyswietlMenu();
            break;

      

        case 'o':
            double alfa;
            std::cout << "\n";
            std::cout << "Podaj kat obrotu Drona: ";
            std::cin >> alfa;
            if (std::cin.fail()) alfa = ObslBl();
            Obrot(alfa);
            break;


        default:
            if(CzytOp == 'k')
            {
                std::cout << "**************Koniec dzialania programu************* \n";
                return;
            }
       
            break;
        }
    }while(CzytOp != 'k');

}

double Scena::ObslBl()
{
    double liczba;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        std::cout << "!!! Prosze podac cyfre !!!\n";
        std::cout << "\t";
        std::cin >> liczba;
    }
    return liczba;
}

void Scena::Start(){
      
   

    Lacze.DodajNazwePliku("bryly/Dronek.dat");
    Lacze.DodajNazwePliku("bryly/PowierzchniaDna.dat");
    Lacze.DodajNazwePliku("bryly/PowierzchniaWody.dat");

  
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

    Lacze.UstawZakresX(-20, 20);
    Lacze.UstawZakresY(-20, 20);
    Lacze.UstawZakresZ(-10, 10);


    Lacze.UstawRotacjeXZ(40,40); // Tutaj ustawiany jest widok

    Lacze.Rysuj();

    //Inicjuje współrzędne Drona
    Wspolrzedne();

    //Inicjuje współrzędne Wody
    InicjujWode();

    //Inicjuje współrzędne Dna
    InicjujDno();

    
        

    Menu();



}





