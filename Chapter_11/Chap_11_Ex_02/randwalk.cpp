/*
Chap_11_Ex_02
Upravte hlavicku tridy Vector a implementacni souboury (vypisy 11.13  11.14 tak, 
aby se velikost a uhel neukladaly jako datove komponenty. Misto toho se budou pri 
kazdem volani metod magval() a angval() pocitat. Verejne rozhrani by melo zustat 
nezmenene (stejne verejne metody se stejnymi argumenty), avsak zmente privatni 
cast a metody, ktere obsahuje, a take implemetacni metody. Otestujte upravenou 
verzi s vypisem 11.15, ktera by mela zustat nezmenena, nebot verejne rozhrani 
tridy Vector se take nezmenilo.
*/
// randwalk.cpp 11.15
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << " Zadej cilovou vzdalenost (q pro ukonceni): ";
	while (cin >> target)
	{
		cout << "Zadej delku kroku : ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		cout << "Po " << steps << " krocich ma subjekt tuto pozici:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " nebo\n" << result << endl;
		cout << " Prumerna vzdalenost na jeden krok = " << result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << " Zadajte cilovou vzdalenost (q pro ukonceni): ";
	}
	cout << " Nasledanou!\n";

	return 0;
}