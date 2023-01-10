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

            SymbolA *A = new SymbolA(12, 6, 0, 0);
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