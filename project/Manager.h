#ifndef MANAGER

#include "Symbol.h"
#include "Screen.h"
#include "DataTypes.h"
#include <termios.h>

#include <curses.h>

enum class direction
{
    up = 1,
    left = 2,
    right = 3,
    down = 4
};

class Manager {
    public:

        Manager() {

            Symbol A(symbol::A, 12, 6, 0, 0);
            daneSymboli.push_back(A);

            showScreen();
        }

        ////////////////////////////////////////////////////////////////////

        void showScreen() {
            ekran.oczyszcz();
            for (auto &symb : daneSymboli)
            {
                ekran.addObject(symb.data(), symb.getX(), symb.getY());
            }
            ekran.odswiez();
        }

        ////////////////////////////////////////////////////////////////////

        void getInput();

        ////////////////////////////////////////////////////////////////////

        bool moveSymbol(int indexSymbolu, enum direction kierunek, int ile = 1);

        ////////////////////////////////////////////////////////////////////

        bool changeSize(int indexSymbolu, rozmiar zwCzyZm);


    private:
        Screen ekran;
        std::vector<Symbol> daneSymboli;
};

#endif