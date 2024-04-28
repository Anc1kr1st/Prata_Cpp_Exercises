/*
Chap_07_Ex_02
Napiste program, ktery pozada o zadani az deseti vysledku golfu a ulozi je do pole. 
Uzivatel by mel mit prostredky na ukonceni vstupu pred zadanim deseti vysledku. Progam 
by mel zobrazit vsechny vysledky na jednom radku a oznamit prumernou hodnotu vysledku. 
Pro zpracovani vstupu, zobrazeni a vypocet prumerne hodnoty pouzijte tri oddelene 
funkce pracuji s polem.
*/

#include <iostream>

double vstup(double pole[], int pocetVstupu);
void priemer(double pole[], int x);
void zobrazenie(const double pole[], int x);

using namespace std;
double celkPriemer = 0;
const int maxV = 10;
int x = 0;

int main()
{
	double vstupy[maxV];

	cout << "Enter golf scores. Max 10. Any letter for exit.\n";

	vstup(vstupy, maxV);

	priemer(vstupy, x);

	zobrazenie(vstupy, x);

	return 0;
}

double vstup(double pole[], int pocetVstupu)
{
	double skore;
	int i;
	int cVstupu = 1;
	for (i = 0; i < pocetVstupu; i++)
	{
		cout << cVstupu << ". ";
		cVstupu++;

		cin >> skore;
		cin.get();

		if (!cin)
		{
			cin.clear();
			break;
		}
		x++;
		pole[i] = skore;
	}

	return i;
}

void priemer(double pole[], int x)
{
	for (int i = 0; i < x; i++)
	{
		celkPriemer = celkPriemer + pole[i];
	}
	celkPriemer = celkPriemer / x;
}

void zobrazenie(const double pole[], int x)
{
	cout << "Scores: ";

	for (int i = 0; i < x; i++)
	{
		cout << pole[i] << " ";
	}
	cout << endl;
	cout << "Average golf scores: " << celkPriemer;
}
