#ifndef SCREEN
#include "DataTypes.h"
#include <iostream>

//Klasa Screen odpowiada jedynie za wypisywanie ciagu znaku na ekranie uzytkownika
class Screen {
    public:

        ////////////////////////////////////////////////

        //Konstruktor z domniemanymi parametrami
        Screen(int toW = 30, int toH = 20) {
            width = toW;
            height = toH;

            initialize();
        }

        ////////////////////////////////////////////////

        //Zajmuje się wyłącznie odświezaniem ekranu
        void odswiez();

        ////////////////////////////////////////////////

        //Zajmuje się oczyszczaniem ekranu od ciagu znakow
        //(Zeruje wszystkie znaki ekranu na domnimany)
        void oczyszcz(char znak = ' ');

        ////////////////////////////////////////////////

        //Sprawdza czy wyslane dane nadaja się do wyswietlania
        bool checkPlace(screenVecDat_t dane, int obj_x, int obj_y);

        ////////////////////////////////////////////////

        //Probuje umiescic obiekt na ekranie
        bool addObject(screenVecDat_t dane, int x, int y);

        ////////////////////////////////////////////////

        int getWidth() {
            return width;
        }

        ////////////////////////////////////////////////

        int getHeight() {
            return height;
        }

    private:
        int width = 0;
        int height = 0;

        ////////////////////////////////////////////////

        screenVecDat_t data;

        screenVecDat_t& getData()
        {
            return data;
        }

        void setData(screenVecDat_t dane) {
            data = dane;
        }

        ////////////////////////////////////////////////

        //Zajmuje sie poczatkowa inicjalizacja i tworzeniem ekranu
        void initialize(char znak = ' ');

        ////////////////////////////////////////////////

       
};

#endif