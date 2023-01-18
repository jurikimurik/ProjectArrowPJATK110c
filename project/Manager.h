#ifndef MANAGER
#define MANAGER 1
#include "SymbolA.h"
#include "Screen.h"
#include <termios.h>

#include <curses.h>

//Pomocniczy enum
enum class direction
{
    up = 1,
    left = 2,
    right = 3,
    down = 4
};

//Klasa Manager zajmuje sie calym programem. Nadzoruje i zleca ekranowi oraz symbolom dzialania.
//Jest mozgiem programu.
class Manager {
    public:
        //Kontruktor domniemany z symbolem A na samym poczatku.
        Manager() {

            //Mechanizm wprowadzenia poprawnej dlugosci i wysokosci
            int sizeX;
            int sizeY;
            //Dobra dlugosc moze byc tylko taka, gdy jest wieksza w 2 razy od wysokosci (dla dobrych proporcji)
            bool isGoodResolution = false;
            while (!isGoodResolution) {
                std::cout << "Wprowadz rozmiar wedlug X: ";
                std::cin >> sizeX;

                std::cout << "Wprowadz rozmiar wedlug Y: ";
                std::cin >> sizeY;

                if(sizeX / 2 == sizeY)
                    isGoodResolution = true;
                else
                    std::cout << "Rozmiar symbolu X powinien byc dwa razy wiekszy od Y!" << std::endl;
            }

                        SymbolA *A = new SymbolA(sizeX, sizeY, 0, 0);
            daneSymboli.push_back(A);

            showScreen();
        }

        ~Manager() {
            for(auto wsk : daneSymboli)
                delete wsk;
        }

        ////////////////////////////////////////////////////////////////////

        //Zajmuje sie wypisywaniem ciagu danych na ekran
        void showScreen() {
            ekran.oczyszcz();
            for (auto &symb : daneSymboli)
            {
                ekran.addObject(symb->data(), symb->getX(), symb->getY());
            }
            ekran.odswiez();
        }

        ////////////////////////////////////////////////////////////////////

        //Pobiera od uzytkownika kliknięcia
        void getInput();

        ////////////////////////////////////////////////////////////////////

        //Probuje przemieścić określony symbol w ktoryms kierunku
        bool moveSymbol(int indexSymbolu, enum direction kierunek, int ile = 1);

        ////////////////////////////////////////////////////////////////////

        //Zmienia rozmiar symbolu o jeden
        bool changeSize(int indexSymbolu, rozmiar zwCzyZm);


    private:
        Screen ekran;
        std::vector<Symbol*> daneSymboli;
};

#endif