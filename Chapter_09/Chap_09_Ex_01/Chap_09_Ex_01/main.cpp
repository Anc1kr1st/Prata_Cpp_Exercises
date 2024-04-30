/*
Chap_09_Ex_01
// golf.h -- pro pe8-3.cpp

const int Len = 40;
struct golf
{
char fullname[Len];
int handicap;
};

// neinteraktivni verze
// funkce nastavuje strukturu golf na poskytnute jmeno a handicap
// pouzitim hodnot predanych jako parametry funkci void setgolf(golf & g, const char * name, int hc);
// interaktivni verze
// funkce si od uzivatele vyzada jmeno a handicap
// a nastavuje cleny g na zadane hodnoty
// vraci 1 - bylo zadane jmeno, 0 - jmeno je prazdny retezec int setgolf(golf & g);

// funkce nastavuje handicap na novou hodnotu
void handicap(gofl & g);

// funkce zobrazuje obsah struktury golf
void showgolf(const golf & g);

Vsimnete si, ze funkce setgolf() je pretizena.

Vytvorte vicesouborovy program zalozeny na teto hlavicce. Prvni soubor nazvany golf.cpp , by mel obsahovat 
vhodne definice funkci, ktere vyhovu prototypum v hlavickovem souboru. Druhy soubor by mel obsahovat funkci 
main() a predvadet vsechny vlastnosti funkci, jejichz prototypyu jsou uvedeny. Napriklad cyklus by mel zadat 
o zadavani vstupu do pole struktur typu golf a ukoncit se, kdyz je pole plne nebo uzivatel zada prazdny 
retezec jmena hrace golfu. Funkce main() by mela pro pristup ke strukturam golf pouzivat pouze vyse uvedene 
funkce.
*/

// main.cpp
#include "golf.h"

using namespace std;

const int SIZE = 3;


int main() {

	golf golfData;

	setgolf(golfData, "Tiger Woods", 5);

	showgolf(golfData);

	handicap(golfData, 10);

	showgolf(golfData);

	golf golfData2[SIZE];

	int players = 0;
	for (int i = 0; counter < SIZE; i++)
	{
		setgolf(golfData2[i]);
		players++;
	}
	
	for (int i = 0; i < players-1; i++) {
		showgolf(golfData2[i]);
	}

	return 0;
}
