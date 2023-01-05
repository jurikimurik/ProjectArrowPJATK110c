#include "Manager.h"

using namespace std;


//****************************************************************************************
void Manager::getInput() {
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

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

        default:
            printw("%c", ch);
        }

    refresh();
    endwin();
    showScreen();
}

//****************************************************************************************
bool Manager::moveSymbol(int indexSymbolu, enum direction kierunek, int ile) {
    Symbol cos = daneSymboli.at(indexSymbolu);

    switch (kierunek)
    {
    case direction::up:
        cos.setY(cos.getY() - 1);
        break;
    
    case direction::left:
        cos.setX(cos.getX() - 1);
        break;
    
    case direction::right:
        cos.setX(cos.getX() + 1);
        break;
    
    case direction::down:
        cos.setY(cos.getY() + 1);
        break;

    default:
        return false;
    }

    if (!ekran.checkPlace(cos.data(), cos.getX(), cos.getY())) {
        return false;
    }

    daneSymboli.pop_back();
    daneSymboli.push_back(cos);
}

//****************************************************************************************
bool Manager::changeSize(int indexSymbolu, enum rozmiar zwCzyZm) {
    Symbol cos = daneSymboli.at(indexSymbolu);
    cos.zmienRozmiar(zwCzyZm);

    if(!ekran.checkPlace(cos.data(), cos.getX(), cos.getY())) {
        return false;
    }

    daneSymboli.pop_back();
    daneSymboli.push_back(cos);
}