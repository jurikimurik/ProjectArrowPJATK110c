#ifndef SYMBOL

#include "DataTypes.h"

// Pomocnicze enum dla poprawienia czytelności programu
enum class rozmiar
{
    zmniejsz = -1, powieksz = 1
};

enum class symbol
{
    A = 1
};

//Klasa Symbol reprezentuje kazdy symboliczny obiekt w programie w postaci ciagu znakow. Miesci w sobie
//zmienne dotycznace rozmiaru (rozX, rozY) oraz miejsca na monitorze (x, y)
class Symbol {
public:
        Symbol(enum symbol co, int rozX, int rozY, int toX = 0, int toY = 0) {
            tworz(co, rozX, rozY);

            x = toX;
            y = toY;

            rozmiarX = rozX;
            rozmiarY = rozY;
        }

/// @brief ///////////////////////////////////////////////////////////////////

        void zmienRozmiar(enum rozmiar co);

//////////////////////////////////////////////////////////////////////////////

        screenVecDat_t data() {
            return symbolData;
        }

        void tworz(enum symbol jakiSymbol, int rozX, int rozY);

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

    private:

        screenVecDat_t symbolData;

        int rozmiarX = 0;
        int rozmiarY = 0;

        int x = 0;
        int y = 0;
};

#endif