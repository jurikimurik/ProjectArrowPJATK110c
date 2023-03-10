#include "Manager.h"

using namespace std;


//****************************************************************************************
//Pobiera od uzytkownika nacisniecia klawiszy
void Manager::getInput() {
    while(true) {
        int ch;

        // Przygotowanie do pobierania
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();

        // Proces pobierania
        ch = getch();

        switch (ch)
        {
        case KEY_UP:
            moveSymbol(0, direction::up);
            break;

        case KEY_DOWN:
            moveSymbol(0, direction::down);
            break;

        case KEY_LEFT:
            moveSymbol(0, direction::left);
            break;

        case KEY_RIGHT:
            moveSymbol(0, direction::right);
            break;

        case 43 /* + */:
            changeSize(0, rozmiar::powieksz);
            break;

        case 45 /* - */:
            changeSize(0, rozmiar::zmniejsz);
            break;

        case 113 /* q */:
            return;

        default:
            printw("%c", ch);
        }

        // Koniec pobierania, wracamy do zwyklych ustawien ekranu
        refresh();
        endwin();
        showScreen();
    }
}

//****************************************************************************************
bool Manager::moveSymbol(int indexSymbolu, enum direction kierunek, int ile) {
    
    Symbol *cos = daneSymboli.at(indexSymbolu);

    int oldX = cos->getX();
    int oldY = cos->getY();

    switch (kierunek)
    {
    case direction::up:
        cos->setY(cos->getY() - 1);
        break;
    
    case direction::left:
        cos->setX(cos->getX() - 1);
        break;
    
    case direction::right:
        cos->setX(cos->getX() + 1);
        break;
    
    case direction::down:
        cos->setY(cos->getY() + 1);
        break;

    default:
        return false;
    }

    if (!ekran.checkPlace(cos->data(), cos->getX(), cos->getY()))
    {
        cos->setX(oldX);
        cos->setY(oldY);
        return false;
    }

    daneSymboli.pop_back();
    daneSymboli.push_back(cos);
}

//****************************************************************************************
bool Manager::changeSize(int indexSymbolu, enum rozmiar zwCzyZm) {
    Symbol * cos = daneSymboli.at(indexSymbolu);

    screenVecDat_t oldData = cos->data();
    int oldRX = cos->rozmiarX;
    int oldRY = cos->rozmiarY;

    cos->zmienRozmiar(zwCzyZm);

    if (!ekran.checkPlace(cos->data(), cos->getX(), cos->getY()))
    {
        cos->symbolData = oldData;
        cos->rozmiarX = oldRX;
        cos->rozmiarY = oldRY;
        return false;
    }

    daneSymboli.pop_back();
    daneSymboli.push_back(cos);
}