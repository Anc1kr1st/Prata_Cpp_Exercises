/*
Chap_11_Ex_05
Prepiste tridu Stonewt tak, aby obsahovala stavovou polozku urcujici,
zda bude objekt reprezentovan v kamenech, v librach celym cislem nebo
v librach cislem s pohyblivou radovou carkou. Definujte pretizeny
operator <<, ktery nahradi metody show_stn() a show_lbs(). Definujte
pretizene operatory scitani, odcitani a nasobeni tak, aby umely scitat,
odecitat a nasobit hodnoty typu Stonewt. Vyzkousejte tridu pomoci
kratkeho programu.
*/
// 11.18
// stone.cpp - uzivatelem definovane konverze
// prelozit se souborem stonewt.cpp
#include <iostream>
using std::cout;
using std::endl;
#include "stonewt.h"

int main()
{
	Stonewt pavarotti = 260;
	Stonewt wolfe(285.7, '2');
	Stonewt taft(21.0, '3');

	cout << "Tenor vazil " << pavarotti << endl;
	cout << "Detektiv vazil " << wolfe << endl;
	cout << "Prezident vazil " << taft << endl;

	pavarotti + 18;
	wolfe - 15.2;
	taft * 2;
	cout << "Po veceri tenor vazil " << pavarotti << endl;
	cout << "Po veceri iba detektiv schudol " << wolfe << endl;
	cout << "Po veceri prezident vazil " << taft << endl;

	return 0;
}
