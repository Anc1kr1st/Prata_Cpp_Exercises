// golf.cpp
#include "golf.h"
#include<cstring>
#include<iostream>

using namespace std;
int counter = 0;

void setgolf(golf& g, const char* name, int hc)
{
	// neinteraktivni verze
	// funkce nastavuje strukturu golf na poskytnute jmeno a handicap
	// pouzitim hodnot predanych jako parametry funkci void setgolf(golf & g, const char * name, int hc);

	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	// interaktivni verze
	// funkce si od uzivatele vyzada jmeno a handicap
	// a nastavuje cleny g na zadane hodnoty
	// vraci 1 - bylo zadane jmeno, 0 - jmeno je prazdny retezec int setgolf(golf & g);

	char docasMeno[Len];

	cout << "Enter name of golfist. Nothing to quit: ";
	cin.get(docasMeno, Len);
	cin.get();
	
	if ((docasMeno[0]) == '\0') {

		cin.clear();  	
		// cin.get();	
		counter = 3;
		cout << counter << endl;

		return 0;
	}
	else
	{
		strcpy_s(g.fullname, docasMeno);

		cout << "Enter handicap: ";
		cin >> g.handicap;
		cout << endl;
		cin.get();
		counter++;
		cout << counter << endl;

		return 1;
	}
}

void handicap(golf& g, int hc)
{
	// funkce nastavuje handicap na novou hodnotu
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	// funkce zobrazuje obsah struktury golf
	cout << "Name: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}
