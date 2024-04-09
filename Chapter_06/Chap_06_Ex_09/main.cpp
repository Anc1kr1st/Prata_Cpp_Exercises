/*
Chap_06_09
Vratte se k cviceni 6, avsak zmente je tak, ze budete cist data ze souboru. Prvni polozkou v souboru 
by mel byt pocet darcu a zbytek souboru by mel obsahovat dvojice radku, kde na prvnim radku v kazde 
dvojici je jmeno darce a na druhem radku je prispevek.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

struct Zoznam
{
	string darcovia;
	double dary;
};


int main()
{
	char name[] = "Darci.txt";
	ifstream inFile;
	ifstream fin;
	inFile.open(name);

	if (!inFile.is_open())
	{
		cout << "Nepodarilo sa otvorit subor " << name << endl;
		cout << "Program sa ukonci.\n";
		exit(EXIT_FAILURE);
	}

	int pocetDarcov;
	inFile >> pocetDarcov;
	inFile.get();

	Zoznam* ps = new Zoznam[pocetDarcov];

	for (int i = 0; i < pocetDarcov; i++)
	{
		getline(inFile, ps[i].darcovia);
		inFile >> ps[i].dary;
		inFile.get();
	}

	double const velkePrispevky = 10000;

	/*
		if (inFile.eof())
		{
			cout << "Koniec suboru.\n";
		}
		else if (inFile.fail())
		{
			cout << "Nespravne data.\n";
		}
		else
			cout << "Ukoncilo sa z neznameho dovodu.\n";

	*/

	for (int i = 0; i < pocetDarcov; i++)
	{
		if (ps[i].dary >= velkePrispevky)
		{
			cout << "Velky patroni\n";
			break;
		}
	}

	for (int i = 0; i < pocetDarcov; i++)
	{
		if (ps[i].dary >= velkePrispevky)
		{
			cout << ps[i].darcovia << endl;
			cout << ps[i].dary << endl;
		}
	}

	for (int i = 0; i < pocetDarcov; i++)
	{
		if (ps[i].dary < velkePrispevky)
		{
			cout << "Patroni\n";
			break;
		}
	}

	for (int j = 0; j < pocetDarcov; j++)
	{
		if (ps[j].dary < velkePrispevky)
		{
			cout << ps[j].darcovia << endl;
			cout << ps[j].dary << endl;
		}
	}

	if (pocetDarcov == 0)
	{
		cout << "Bez prispevkov\n";
	}

	inFile.close();
	return 0;
}


