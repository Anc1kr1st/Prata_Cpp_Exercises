/*
Chap_06_Ex_06
Vasim ukolem je vytvorit program, ktery bude udrzovat prehled o peneznich prispevcich 
Spolecnosti pro zachovani spravneho vlivu. Tento program by mel pozadat uzivatele o zadani 
poctu prispevatelu a potom o jmeno a castku prispevku kazdeho darce. Tyto informace by mely 
byt ulozeny v dynamicky alokovanem poli struktur. Kazda struktura by mela mit dva cleny: 
znakove pole pro ulozeni jmena a clen typu double pro ulozeni castky prispevku. Po nacteni 
vsech dat by mel program zobrazit jmena a castky prispevku vsech prispevatelu, kteri darovali 
10 000 KC a vice. V zahlavi tohoto vypisu by melo byt poznamenano, ze se jedna o Velke patrony. 
Potom by mel program vypsat zbyvajici darce se zahlavim Patroni. Pokud nejsou v zadne z techto 
kategorii prispevatele, program by mel vypsat poznamku "bez prispevku". Krome zobrazovani dvou 
kategorii nemusi program provadet zadne trideni.
*/

#include <iostream>
#include <string>

using namespace std;

struct contributions
{
	string name;
	double money;
};

int main()
{
	int numCon;
	const int bigCon = 10000;
	int bPat = 0, Pat = 0, nonPat = 0;

	cout << "Enter the number of contributors: \n";
	cin >> numCon;
	cin.get();

	contributions* ps = new contributions[numCon];

	for (int i = 0; i < numCon; i++)
	{
		cout << i + 1 << ". Name of contributor: ";
		getline(cin, (ps + i)->name);
		cout << "Contribution: ";
		cin >> (ps + i)->money;
		cin.get();
		cout << endl;

		if ((ps + i)->money >= bigCon)
		{
			bPat++;
		}
		else if ((ps + i)->money < bigCon)
		{
			Pat++;
		}
	}

	if (bPat > 0)
	{
		cout << "Big patrons\n";
	}

	for (int i = 0; i < numCon; i++)
	{
		if ((ps + i)->money >= bigCon)
		{
			cout << "Name: " << (ps + i)->name << endl;
			cout << "Contribution: " << (ps + i)->money << endl;
		}

	}

	if (Pat > 0)
	{
		cout << "Patrons\n";
	}

	for (int i = 0; i < numCon; i++)
	{
		if ((ps + i)->money < bigCon)
		{
			cout << "Name: " << (ps + i)->name << endl;
			cout << "Contribution: " << (ps + i)->money << endl;
		}
	}

	if (numCon == 0)
	{
		cout << "Without contributions.";
	}

	delete [] ps;
	return 0;
}