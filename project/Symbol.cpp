#include "Symbol.h"
#include <iterator>
#include <vector>

using namespace std;

void Symbol::zmienRozmiar(enum rozmiar co) {
    if(co == rozmiar::powieksz) {
        Symbol symb(symbol::A, rozmiarX + 2, rozmiarY + 1);
        symbolData = symb.symbolData;
        rozmiarX += 2;
        rozmiarY += 1;
    }
    else if (co == rozmiar::zmniejsz)
    {
        if(rozmiarX > 2 && rozmiarY > 1) {
            Symbol symb(symbol::A, rozmiarX - 2, rozmiarY - 1);
            symbolData = symb.symbolData;
            rozmiarX -= 2;
            rozmiarY -= 1;
        }
    }
    else
    {
        return;
    }
}

//////////////////////////////////////////////////////////////

void Symbol::tworz(enum symbol jakiSymbol, int rozX, int rozY) {
    screenVecDat_t dane;

    int dystans = 0;
    if (jakiSymbol == symbol::A)
    {
        for (int y = 0; y < rozY; y++)
        {
            dane.push_back(vector<char>());
            int rozmiar = rozX;
            for (int x = 0; x < rozX / 2 - dystans-1; x++, rozmiar--)
            {
                dane[y].push_back(' ');
            }

            
            dane[y].push_back('/');
            rozmiar--;

            
                for (int i = 0; i < dystans; i++, rozmiar--)
                {
                    if (y != rozY / 2) {
                        dane[y].push_back(' ');
                        dane[y].push_back(' ');
                    } else {
                        dane[y].push_back('-');
                        dane[y].push_back('-');
                    }
                    
                }
            

            dane[y].push_back('\\');
            rozmiar--;

            for (int x = 0; x < rozmiar; x++) {
                dane[y].push_back(' ');
            }
            dystans++;
        }
    }
    else
    {
        return;
    }

    symbolData = dane;
}