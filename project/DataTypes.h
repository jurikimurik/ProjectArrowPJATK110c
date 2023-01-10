#ifndef DATATYPES
#define DATATYPES 1
//Pomocniczy plik .h z inna (skroconą) nazwą dwuwymiarowego wektora, w ktorym mieszczą sie znaki char

#include <vector>
using screenVecDat_t = std::vector<std::vector<char>>;

// Pomocnicze enum dla poprawienia czytelności programu
enum class rozmiar
{
    zmniejsz = -1,
    powieksz = 1
};

enum class symbol
{
    A = 1
};

#endif