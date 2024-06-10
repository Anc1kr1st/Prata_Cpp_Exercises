#include "golf.h"

int counter = 0;

int Golf::setgolf()
{
	// interaktivni verze
	// funkce si od uzivatele vyzada jmeno a handicap
	// a nastavuje cleny g na zadane hodnoty
	// vraci 1 - bylo zadane jmeno, 0 - jmeno je prazdny retezec int setgolf(golf & g);

	char docasMeno[Len];
	int docasHandicap;

	cout << "Enter name of golfist. Nothing to quit: ";
	cin.get(docasMeno, Len);
	cin.get();

	if ((docasMeno[0]) == '\0') {

		cin.clear();

		return 0;
	}
	else
	{
		strcpy_s(fullname, docasMeno);

		cout << "Enter handicap: ";
		cin >> docasHandicap;
		cout << endl;
		cin.get();

		Golf docas{ docasMeno, docasHandicap };
		*this = docas;

		return 1;
	}
}

void Golf::sethandicap(int hc)
{
	// funkce nastavuje handicap na novou hodnotu
	handicap = hc;
}

void Golf::showgolf() const
{
	// funkce zobrazuje obsah struktury golf
	cout << "Name: " << fullname << endl;
	cout << "Handicap: " << handicap << endl;
}
