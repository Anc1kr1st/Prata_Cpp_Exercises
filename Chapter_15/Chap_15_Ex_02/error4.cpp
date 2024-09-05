/*
Chap_15_Ex_02
Upravte program ve vypisu 15.11 tak, aby typy dvou vyjimek byly
tridy odvozene od tridy logic_error s hlavickovym souborem <stdexcept>.
Necht vsechny metody what() vypisuji jmeno funkce a povahu problemu.
Objekty exception nemusi obsahovat chybne hodnoty; musi pouze podporovat
metodu what().
*/
//error4.cpp
#include <iostream>
#include <cmath> // nebo math.h, v Unixu možná -lm
#include "exc_mean.h"

// function prototypes
double hmean(double a, double b) throw(hmeanexcp);
double gmean(double a, double b) throw(gmeanexcp);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Zadejte dve cisla: ";
	while (cin >> x >> y)
	{
		try { 												// zacátek bloku try
			z = hmean(x, y);
			cout << "Harmonicky prumer cisel " << x << " a " << y
				<< " je " << z << endl;
			cout << "Geometricky prumer cisel " << x << " a " << y
				<< " je " << gmean(x, y) << endl;
			cout << "Zadejte dalsi mnozinu cisel <k pro ukonceni>: ";
		} 															// konec bloku try
		catch (hmeanexcp& bg) // zacátek záchytného bloku
		{
			cout << bg.what();
			cout << "Opakujte.\n";
			continue;
		}
		catch (gmeanexcp& hg)
		{
			cout << hg.what();
			cout << "Bohuzel, dal se nedostanete. ";
			break;
		} // konec záchytného bloku
	}
	cout << "Nashledanou!\n";
	return 0;
}

double hmean(double a, double b) throw(hmeanexcp)
{
	if (a == -b)
		throw hmeanexcp();
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) throw(gmeanexcp)
{
	if (a < 0 || b < 0)
		throw gmeanexcp();
	return std::sqrt(a * b);
}

