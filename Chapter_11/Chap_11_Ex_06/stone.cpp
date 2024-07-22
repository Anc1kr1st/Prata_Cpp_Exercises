/*
Chap_11_Ex_06
Prepiste tridu Stonewt tak, aby pretezovala relacni operatory.
Napiste program, ktery bude deklarovat pole sesti objektu Stonewt
a inicializuje prvni tri objekty v deklaraci pole. Potom by mel
pomoci smycky nacist hodnoty pro nastaveni zbyvajicich tri prvku
pole. Dale by mel vypsat nejmensi a nejvetsi prvek, a pocet prvku,
jejichz hodnota je vetsi nebo rovna 11 kamenum.
*/
// 11.18
// stone.cpp - uzivatelem definovane konverze
// prelozit se souborem stonewt.cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "stonewt.h"

int main()
{
    const int SIZE = 6;
    Stonewt pole[SIZE] = { Stonewt(260), Stonewt(285.7), Stonewt(21) };
    double pounds;
    Stonewt stones(11,0);
    int min = 0, max = 0, count = 0;

    for (int i = 3; i < SIZE; i++)
    {
        cout << "Enter pound: ";
        cin >> pounds;
        pole[i] = Stonewt(pounds);
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (pole[min] > pole[i]) min = i;
        if (pole[max] < pole[i]) max = i;
        if (pole[i] >= stones) count++;
    }

    cout << "Najmensi prvok: ";
        pole[min].show_lbs();
        cout << endl;
        cout << "Najvacsi prvok: ";
        pole[max].show_lbs();
        cout << endl;
    cout << "Pocet prvkov vacsich alebo rovnych 11 kamenum je " << count << endl;

    return 0;
}
