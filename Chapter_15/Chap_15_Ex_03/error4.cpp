/*
Chap_15_Ex_03
Toto cviceni je stejne jako cviceni 2 s tim rozdilem, ze vyjimky musi byt
odvozeny ze zakladni tridy (ta je odvozena z logic_error), jez uchovava
tyto dve hodnoty argumentu, vyjimky musi mit metodu, ktera ohlasuje tyto
hodnoty a jmeno funkce, a samostatny blok catch, ktery zachyti vyneti ze
zakladni tridy, jez se musi pouzit pro obe vyjimky, pricemz kazda z nich
musi ukoncit cyklus.
*/

//error4.cpp
#include <iostream>
#include <cmath> // nebo math.h, v Unixu možná -lm
#include <exception>
#include "exc_mean.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

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
		catch (std::logic_error& le)
		{
			if (typeid(bad_hmean) == typeid(le))
			{
				bad_hmean& temp = dynamic_cast<bad_hmean&>(le);
				temp.mesg();
				cout << temp.what() << endl;
				break;
			}
			else if (typeid(bad_gmean) == typeid(le))
			{
				bad_gmean& temp = dynamic_cast<bad_gmean&>(le);
				temp.mesg();
				cout << temp.what() << endl;
				cout << "Bohuzel, dal se nedostanete.\n";
				break;
			}
		}
	}
		cout << "Nashledanou!\n";
		return 0;
}

	double hmean(double a, double b)
	{
		if (a == -b)
		{
			throw bad_hmean("chybne argumenty: a = -b ", a, b);
		}
		return 2.0 * a * b / (a + b);
	}
	double gmean(double a, double b)
	{
		if (a < 0 || b < 0)
		{
			throw bad_gmean("argumenty gmean() musi byt >= 0 ", a, b);
		}
		return std::sqrt(a * b);
	}
