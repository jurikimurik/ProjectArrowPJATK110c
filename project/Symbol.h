#ifndef SYMBOL

#include "DataTypes.h"

//Klasa Symbol reprezentuje kazdy symboliczny obiekt w programie w postaci ciagu znakow. Miesci w sobie
//zmienne dotycznace rozmiaru (rozX, rozY) oraz miejsca na monitorze (x, y)
struct Symbol {
public:
        Symbol(int rozX, int rozY, int toX = 0, int toY = 0) {

            x = toX;
            y = toY;

            rozmiarX = rozX;
            rozmiarY = rozY;
        }

/// @brief ///////////////////////////////////////////////////////////////////

        virtual void zmienRozmiar(enum rozmiar co) = 0;

//////////////////////////////////////////////////////////////////////////////

        screenVecDat_t data() {
            return symbolData;
        }

        virtual void tworz(int rozX, int rozY) = 0;

        //////////////////////////////////////////////////////////////////////////////

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        void setX(int toX) {
            x = toX;
        }

        void setY(int toY) {
            y = toY;
        }

        screenVecDat_t symbolData;

        int rozmiarX = 0;
        int rozmiarY = 0;

        int x = 0;
        int y = 0;
        
};

#endif