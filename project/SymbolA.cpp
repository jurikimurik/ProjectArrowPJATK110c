#include "SymbolA.h"
#include <iterator>
#include <vector>
using namespace std;
//****************************************************************************************************
// Pomocnicza metoda zmieniajaca rozmiar calego symbolu(tworzy nowy i zamienia się miejscami ze starym symbolem)
void SymbolA::zmienRozmiar(enum rozmiar co)
{
    if (co == rozmiar::powieksz)
    {
        SymbolA symb(rozmiarX + 2, rozmiarY + 1);
        symbolData = symb.symbolData;
        rozmiarX += 2;
        rozmiarY += 1;
    }
    else if (co == rozmiar::zmniejsz)
    {
        if (rozmiarX > 2 && rozmiarY > 1)
        {
            SymbolA symb(rozmiarX - 2, rozmiarY - 1);
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

// Metoda inicjalizujaca wyglad symbolu wedlug zadanego algorytmu dla poszczegolnych symboli.
void SymbolA::tworz(int rozX, int rozY)
{
    screenVecDat_t dane;

    int dystans = 0;
    if (jakiSymbol == symbol::A)
    {
        // Tworzy symbol wiersz po wierszu
        for (int y = 0; y < rozY; y++)
        {
            // Czesc poczatkowa (do pierwszego wystapienia jakiegos znaku)
            dane.push_back(std::vector<char>());
            int rozmiar = rozX;
            for (int x = 0; x < rozX / 2 - dystans - 1; x++, rozmiar--)
            {
                dane[y].push_back(' ');
            }

            // Czesc srodkowa (od /)
            dane[y].push_back('/');
            rozmiar--;

            for (int i = 0; i < dystans; i++, rozmiar--)
            {
                if (y != rozY / 2)
                {
                    dane[y].push_back(' ');
                    dane[y].push_back(' ');
                }
                else
                {
                    dane[y].push_back('-');
                    dane[y].push_back('-');
                }
            }

            // Czesc koncowa (od \ i do konca)
            dane[y].push_back('\\');
            rozmiar--;

            for (int x = 0; x < rozmiar; x++)
            {
                dane[y].push_back(' ');
            }
            dystans++;
        }
    }
    else
    {
        // Gdyby jakis niewiadomy symbol, to zwracamy nic
        return;
    }

    symbolData = dane;
}