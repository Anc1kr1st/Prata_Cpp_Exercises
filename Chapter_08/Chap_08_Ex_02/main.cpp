/*
Chap_08_Ex_02
Struktura CandyBar ma cleny. Prvni clen  obsahuje znacku cukrove tycinky. 
Druhy jeji vahu (ktera muze mit desetinnou cast) a treti pocet kalorii 
(cele cislo). Napiste program, ktery pouziva funkci, jez ma jako argumenty 
odkaz na CandyBar, ukazatel na char, double a init a posledni tri hodnoty 
pouziva pro nastaveni odpovidajicich clenu struktury. Posledni tri argumenty 
by mely mit implicitni hodnoty "Millennium Munch", 2.85 a 350. Tento program 
by mel take volat funkci, ktera prebira odkaz na CandyBar a zobrazuje obsah 
struktury. Pouzijte const, kde je to vhodne.
*/
#include <iostream>
#include <cstring>


using namespace std;
const int maxLength = 30;

struct CandyBar {
	char znacka[maxLength];
	double vaha;
	int kalorie;
};

void implic_fun(CandyBar& BarCraft, const char* znacka = "Millennium Munch", double vaha = 2.85, int kalorie = 350);
void druha_fun(CandyBar BarCraft);

int main()
{
	CandyBar Pokus;

	implic_fun(Pokus);
	druha_fun(Pokus);

	return 0;
}

void implic_fun(CandyBar& BarCraft, const char* znacka, double vaha, int kalorie)
{
	strcpy_s(BarCraft.znacka, znacka);
	BarCraft.vaha = vaha;
	BarCraft.kalorie = kalorie;
}

void druha_fun(const CandyBar BarCraft)
{
	cout << BarCraft.znacka << endl;
	cout << BarCraft.vaha << endl;
	cout << BarCraft.kalorie << endl;
}
