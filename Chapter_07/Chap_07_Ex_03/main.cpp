/*
Chap_07_Ex_03
Zde je sablona struktury:
struct box {
char znacka[40];
float vyska;
float sirka;
float delka;
float objem;
};
a) napiste funkci, ktera po predani struktury box hodnotou zobrazi hodnotu kazdeho clenu
b) napiste funkci, ktera po predani adresy struktury box nastavi clen volume na soucin ostatnich tri rozmeru
c) napiste jednoduchy program, ktery predchozi dve funkce pouzije
*/

#include <iostream>

using namespace std;

void zobrazenie();
void celObjem();

struct box
{
	char znacka[40];
	float vyska;
	float sirka;
	float delka;
	float objem;
};

box vec =
{
	"Thing",
	1.9,
	0.8,
	2.0,
	1.0
};

int main()
{

	zobrazenie();
	celObjem();

	return 0;
}

void zobrazenie()
{
	cout << "Content of structure: \n";
	cout << vec.znacka << endl;
	cout << vec.vyska << endl;
	cout << vec.sirka << endl;
	cout << vec.delka << endl;
	cout << vec.objem << endl;
}

void celObjem()
{
	vec.objem = vec.vyska * vec.sirka * vec.delka;
	cout << "Volume: " << vec.objem;
}

