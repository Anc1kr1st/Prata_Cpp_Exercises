/*
Chap_06_Ex_04
Kdyz vstoupite do Radu vlidnych programatoru, muzete byt na setkanich RVP znam pod svym skutecnym jmenem, 
pracovnim zarazenim, tajnym clesnkym jmenem RVP. Vytvareny program zalozte na nasledujici strukture:
// struktura jmena v Radu vlidnych programatoru
struct rvp {
char celejmeno[velretezce];  // skutecne jmeno
char praczaraz[velretezce];  // pracovni zarazeni
char rvpjmeno[velretezce];   // tajne jmeno RVP
int volba;		     // 0 = celejmeno, 1 = praczaraz, 2 = rvpjmeno
};
V programu vytvorte male pole techto struktur a inicializujte ho vhodnymi hodnotami. Do programu vlozte cyklus, 
ktery uzivatelum umozni vybirat z ruznych moznosti:
a. vypis jmen            b. vypis pracovnich zarazeni
c. vypis jmen RVP        d. vypis podle volby
k. konec
Vsimnte si, ze "vypis podle volby" neznamena vypsani clenu struktury volba, ale vypis clenu struktury, ktery 
odpovida cislu ulozenemu v clenu volba. Pokud ma napriklad clen volba hodnotu 1, zadani pismene d zobrazi 
programatorovo pracovni zarazeni.

*/

#include <iostream>

using namespace std;

void showMenu();
void optionA();
void optionB();
void optionC();
void optionD();

const int velretezce = 50;

struct rvp {
	char celejmeno[velretezce];  // skutecne jmeno
	char praczaraz[velretezce];  // pracovni zarazeni
	char rvpjmeno[velretezce];   // tajne jmeno RVP
	int volba;		     // 0 = celejmeno, 1 = praczaraz, 2 = rvpjmeno
};

rvp list[5] =
{
	{"Wimp Macho", "Junior Programmer", "MIPS", 1},
	{"Raki Rhodes", "Analyst Trainee", "Loopy", 0},
	{"Celia Laiter", "Scrum master", "Scruffy", 2},
	{"Hoppy Hipman", "Senior Programmer", "Mops", 0},
	{"Pat Hand", "Tester", "Boot", 2}
};

int main()
{
	int j;
	char choice;

	showMenu();
	cin >> choice;

	while (choice != 'k')
	{
		switch (choice)
		{
		case 'a': optionA();
			cout << endl;
			break;
		case 'b': optionB();
			cout << endl;
			break;
		case 'c': optionC();
			cout << endl;
			break;
		case 'd': optionD();
			cout << endl;
			break;
		}
		showMenu();
		cin >> choice;
	}

	return 0;
}

void showMenu()
{
	cout << "Menu\n";
	cout << "a. vypis jmen            b. vypis pracovnich zarazeni\n";
	cout << "c. vypis jmen RVP        d. vypis podle volby\n";
	cout << "k.konec\n\n";
}

void optionA()
{
	for (int i = 0; i < 5; i++)
	{
		cout << list[i].celejmeno << endl;
	}
}

void optionB()
{
	for (int i = 0; i < 5; i++)
	{
		cout << list[i].praczaraz << endl;
	}
}

void optionC()
{
	for (int i = 0; i < 5; i++)
	{
		cout << list[i].rvpjmeno << endl;
	}
}

void optionD()
{
	for (int i = 0; i < 5; i++)
	{
		if (list[i].volba == 0)
		{
			cout << list[i].celejmeno << endl;
		}
		else if (list[i].volba == 1)
		{
			cout << list[i].praczaraz << endl;
		}
		else
		{
			cout << list[i].rvpjmeno << endl;
		}
	}
}