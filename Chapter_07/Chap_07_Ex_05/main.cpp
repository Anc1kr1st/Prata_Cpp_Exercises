/*
Chap_07_Ex_05
Definujte rekurzivni funkci, ktera prijima celociselny argument a vraci jeho faktorial. 
Vzpomente si, ze 3 faktorial, psano 3!, se rovna 3 x 2! atd., kde 0! je definovan jako 1. 
Obecne plati n! = n*(n-1)!. Funkci otestujte v programu, ktery pomoci cyklu umoznuje 
uzivateli zadavat ruzne hodnoty, jejichz faktorial je potom vypocitan.
*/

#include <iostream>
using namespace std;

int vypocet(int x);

int faktorial;
int vysledok = 0;
int n;

int main()
{
	cout << "Enter a number to calculate the factorial. Any letter for exit: \n";

	while (cin >> n)
	{
		faktorial = n;
		vypocet(n);

		cout << "Factorial: \n";
		cout << faktorial << endl;

		cout << "Enter a number to calculate the factorial. Any letter for exit: \n";
	}

	return 0;
}

int vypocet(int x)
{

	if (x > 1)
	{
		faktorial = faktorial * (x - 1);
		x = x - 1;
		vypocet(x);
	}
	return faktorial;
}

