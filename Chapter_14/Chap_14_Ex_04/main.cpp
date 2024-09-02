/*
Chap_14_Ex_04
Trida Person obsahuje krestni jmeno a prijmeni nejake osoby. Krome konstruktoru 
obsahuje metodu Show() zobrazujici obe jmena. Trida Gunslinger je virtualne odvozena 
od tridy Person. Obsahuje metodu Draw(), ktera vraci hodnotu typu double, coz je doba, 
za kterou je pistolnik schopen tasit zbran. Take obsahuje polozku typu int, ktera 
obsahuje pocet zarezu na pistolnikove zbrani. A nakonec ma funkci Show() zobrazujici 
vsechny uvedene informace.

Trida PokerPlayer je virtualne odvozena od tridy Person. Obsahuje metodu Draw(), ktera 
vraci nahodne cislo v intervalu 1 az 52 vyjadrujici hodnotu karty. (Definujte tridu 
Card s hodnotami plozek barvy a karty a vratit hodnotu pro funkci Draw()).

Trida PokerPlayer pouziva funkci Show(). Trida BadDude je verejne odvozena od trid 
Gunslinger a PokerPlayer. Obsahuje metodu Gdraw() vracejici dobu, ve ktere drsnak 
vytasi zbran, a metodu Cdraw() vracejici dalsi vytazenou kartu. Take obsahuje 
odpovidajici funkci Show(). Definujte vsechny tyto tridy a metody spolecne a 
vyzkousejte je v jednoduchem programu podobnem tomu z vypisu 14.12.
*/

// main.cpp
#include <iostream>
#include <cstring>
#include "person.h"

const int SIZE = 5;

int main(void)
{
    using namespace std;
    int ct, i;
    Person* gang[SIZE];
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the gang category:\n"
            << "o: ordinary person  g: gunslinger  "
            << "p: pokerplayer  b: bad dude  q: quit\n";
        cin >> choice;
        while (strchr("ogpbq", choice) == NULL)
        {
            cout << "Please enter an o, g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'o':   gang[ct] = new Person;
            break;
        case 'g':   gang[ct] = new Gunslinger;
            break;
        case 'p':   gang[ct] = new PokerPlayer;
            break;
        case 'b':   gang[ct] = new BadDude;
            break;
        }
        cin.get();
        gang[ct]->set();
    }

    cout << "\nHere is your gang:\n";
    for (i = 0; i < ct; i++)
    {
        cout << '\n';
        gang[i]->show();
    }
    for (i = 0; i < ct; i++)
        delete gang[i];
    cout << "\nBye!\n";
    return 0;
}
