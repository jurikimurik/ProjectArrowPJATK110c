#ifndef SYMBOL_A
#define SYMBOL_A 1
#include "Symbol.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SymbolA : public Symbol
{
    public:
    
    void tworz(int rozX, int rozY);

    void zmienRozmiar(enum rozmiar co);

    SymbolA(int rozX, int rozY, int toX = 0, int toY = 0) : Symbol(rozX, rozY, toX, toY)
    {
        jakiSymbol = symbol::A;

        tworz(rozX, rozY);
    }

    private:
        enum symbol jakiSymbol;
};

#endif