/*
Chap_11_Ex_01
1. Upravte program z vypisu 11.15 tak, aby zapisoval nasledujici misto nahodneho chodce do souboru. 
Kazdou polohu opatrete cislem kroku. Necht program vypise pocatesni podminky (cilovou vzdalenost a 
delku kroku) a vysledny soucet ulozi do souboru. Obsah souboru by mohl vypadat napr. takto:
Cilova vzdalenost: 100, Delka kroku: 20
0: (x,y) = (0, 0)
1: (x,y) = (-11.4715, 16.383)
2: (x,y) = (-8.68807, -3.42232)
...
26: (x,y) = (42.2919, -78.2594)
27: (x,y) = (58.6749, -89.7309)
Subjekt ma po 27 krocich toto umisteni:
(x,y) =  (58.6749, -89.7309)
resp.
(m,a) = (107.212, -56.8194)
Prumerna vzdalenost na krok = 3.97081
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
	double target = 100;
	double dstep = 20;

	cout << "Cielova vzdialenost: 100, ";
	do
	{
		cout << "Delka kroku: 20\n";

		while (result.magval() < target)
		{
		cout << steps << ": " << result << endl;
				direction = rand() % 360;
		step.set(dstep, direction, 'p');
		result = result + step;
		steps++;
		}

	cout << steps << ": " << result << endl;
	cout << "Po " << steps << " krocich ma subjekt tuto pozici:\n";
	cout << result << endl;
	result.polar_mode();
	cout << " nebo\n" << result << endl;
	cout << " Prumerna vzdalenost na jeden krok = " << result.magval() / steps << endl;
	steps = 0;
	result.set(0.0, 0.0);
	cout << " Zadajte q pro ukonceni: ";
	} while (cin >> target);

cout << " Nasledanou!\n";

return 0;
}
