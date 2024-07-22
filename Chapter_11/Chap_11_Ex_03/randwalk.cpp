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
	int N;
	unsigned long najvetsi = 0, najmensi = 0, priemer = 0;
	// pomocne
	unsigned long spolu = 0;

	cout << "Zadejte pocet pokusu: ";
	cin >> N;

	

	for (int i = 0; i < N; i++)
	{
		cout << "Zadej cilovou vzdalenost: ";
		cin >> target;
	
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

		if (steps > najvetsi)
		{
			najvetsi = steps;
		}

		if (najmensi == 0)
		{
			najmensi = steps;
		}
		else if (steps < najmensi)
		{
			najmensi = steps;
		}

		spolu += steps;
		/*
		cout << "Po " << steps << " krocich ma subjekt tuto pozici:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " nebo\n" << result << endl;
		cout << " Prumerna vzdalenost na jeden krok = " << result.magval() / steps << endl;
		*/
		steps = 0;
		result.set(0.0, 0.0);
	}

	priemer = spolu / N;

	cout << "Najvetsi pocet krokov: " << najvetsi << endl;
	cout << "Najmensi pocet krokov: " << najmensi << endl;
	cout << "Priemerny pocet krokov: " << priemer << endl;

	cout << " Nasledanou!\n";

	return 0;
}