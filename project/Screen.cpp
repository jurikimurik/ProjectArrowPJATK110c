#include "Screen.h"
using namespace std;

//************************************************************************************************************************************************************************
void Screen::odswiez() {
    screenVecDat_t dane = getData();

    for (int y = 0; y < getHeight(); y++) {
        for (int x = 0; x < getWidth(); x++) {
            cout << dane[y][x];
        }
        cout << endl;
    }
}

//************************************************************************************************************************************************************************
void Screen::initialize(char znak) {
    screenVecDat_t dane = getData();
    for (int y = 0; y < getHeight(); y++)
    {
        vector<char> nowyWiersz;
        dane.push_back(nowyWiersz);

        for (int x = 0; x < getWidth(); x++) {
            dane[y].push_back(znak);
        }
    }

    setData(dane);
}

//************************************************************************************************************************************************************************
bool Screen::checkPlace(screenVecDat_t dane, int obj_x, int obj_y) {
    if (obj_x < 0 || obj_y < 0 || dane.size() + obj_y > getHeight() || dane[0].size() + obj_x > getWidth())
    {
        return false;
    } else {
        return true;
    }
}


//************************************************************************************************************************************************************************
bool Screen::addObject(screenVecDat_t dane, int obj_x, int obj_y) {
    if(!checkPlace(dane, obj_x, obj_y)) {
        return false;
    }
    

    screenVecDat_t daneEkranu = getData();

    int addObj_y = obj_y;
    int addObj_x = obj_x;

    for (int y = 0; y < dane.size(); y++, addObj_y++)
    {
        for (int x = 0; x < dane[0].size(); x++, addObj_x++)
        {
            daneEkranu[addObj_y][addObj_x] = dane[y][x];
        }
        addObj_x = obj_x;
    }

    setData(daneEkranu);
    return true;
}

//************************************************************************************************************************************************************************
void Screen::oczyszcz(char znak) {
    system("clear");
    screenVecDat_t dane = getData();
    
    for(auto & wiersz: dane) {
        for(auto & zn: wiersz) {
            zn = znak;
        }
    }

    setData(dane);
}