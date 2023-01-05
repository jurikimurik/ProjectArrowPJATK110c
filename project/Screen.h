#ifndef SCREEN
#include "DataTypes.h"
#include <iostream>

class Screen {
    public:

        ////////////////////////////////////////////////

        Screen(int toW = 30, int toH = 20) {
            width = toW;
            height = toH;

            initialize();
        }

        ////////////////////////////////////////////////

        void odswiez();

        ////////////////////////////////////////////////

        void oczyszcz(char znak = ' ');

        ////////////////////////////////////////////////

        bool checkPlace(screenVecDat_t dane, int obj_x, int obj_y);

        ////////////////////////////////////////////////

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

        void initialize(char znak = ' ');

        ////////////////////////////////////////////////

       
};

#endif