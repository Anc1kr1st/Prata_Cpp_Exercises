/*
Chap_08_Ex_05
Napiste sablonu funkce max5(), ktera prijima jako argument pole o peti polozkach 
typu T a vraci jeho nejvetsi prvek. (Protoze je velikost pevna, muze byt zadana 
v kodu cyklu a nemusi byt predavana jako argument.) Sablonu otestujte v programu, 
ktery pouziva funkci s poli o peti hodnotach typu int a double.
*/

#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
int max5(T pole[]);

const int maxFive = 5;
int p1[maxFive];
int pMax;

int main()
{

	cout << "Zadajte 5 cisiel.\n";

	int j = 1;
	for (int i = 0; i < 5; i++)
	{

		cout << j << ". cislo.\n";
		j++;
		cin >> p1[i];

	}

	max5(p1);

	cout << "Najvyssie cislo je: " << pMax << endl;

	return 0;
}

template <typename T>
int max5(T pole[])
{
	if (pole[0] > pole[1] && pole[0] > pole[2] && pole[0] > pole[3] && pole[0] > pole[4])
	{
		pMax = pole[0];
	}
	else if (pole[1] > pole[0] && pole[1] > pole[2] && pole[1] > pole[3] && pole[1] > pole[4])
	{
		pMax = pole[1];
	}
	else if (pole[2] > pole[1] && pole[2] > pole[0] && pole[2] > pole[3] && pole[2] > pole[4])
	{
		pMax = pole[2];
	}
	else if (pole[3] > pole[1] && pole[3] > pole[2] && pole[3] > pole[0] && pole[3] > pole[4])
	{
		pMax = pole[3];
	}
	else if (pole[4] > pole[1] && pole[4] > pole[2] && pole[4] > pole[3] && pole[4] > pole[0])
	{
		pMax = pole[4];
	}
	return pMax;
}
