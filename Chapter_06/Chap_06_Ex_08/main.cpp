/*
Chap_06_Ex_08
Napiste program, ktery otevre tectovy soubor, cte z neho znak po znaku az 
na konec souboru a vypise pocet znaku v souboru.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

int main()
{
	const int SIZE = 20;
	char filename[SIZE];
	int pocet = 0;
	int vstup;

	ifstream inFile;    // musi byt zadefinovany objekt

	cout << "Zadajte meno text. suboru.\n";
	cin.getline(filename, SIZE);
	inFile.open(filename);

	if (!inFile.is_open())  // ci sa otvorilo spravne
	{
		cout << "Nepodarilo sa otvorit. Program sa zavre.\n";
		exit(EXIT_FAILURE);
	}

	inFile >> vstup;

	while (!inFile.eof())
	{
		++pocet;
		inFile >> vstup;
	}

	cout << "Pocet znakov v subore: " << pocet << endl;

	inFile.close();

	return 0;
}

