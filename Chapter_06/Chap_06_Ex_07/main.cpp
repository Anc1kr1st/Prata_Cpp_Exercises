/*
Chap_06_Ex_07
Napiste program, ktery cte na vstupu naraz cela slova, dokud nenarazi na samotne pismeno q. 
Program by pak mel vypsat pocet slov zacinajicich samohlaskou, pocet slov zacinajicich 
souhlaskou a pocet slov, ktere nepatri do zadne z techto kategorii. Jednim z moznych pristupu 
je metoda isalpha(), kterou rozlisime mezi slovy zacinajicimi pismenem a ostatnimi a k dalsi 
identifikaci slov, ktera projdou testem isalpha(), muzeme pro hledani samohlasek na zacatku 
slov pouzit prikaz switch.
*/

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char vstup;
	int samohlasky = 0;
	int spoluhlasky = 0;
	int ostatne = 0;
	bool isready = true;

	cout << "Zadavajte slova (q pre ukoncenie):\n";

	cin.get(vstup);

	while (vstup != 'q')
	{

		// isspace(vstup)
		if (isready)
		{

			if (isalpha(vstup))
			{
				switch (vstup)
				{
				case 'a': samohlasky++;
					isready = false;
					break;
				case 'e': samohlasky++;
					isready = false;
					break;
				case 'i': samohlasky++;
					isready = false;
					break;
				case 'o': samohlasky++;
					isready = false;
					break;
				case 'u': samohlasky++;
					isready = false;
					break;
				case 'y': samohlasky++;
					isready = false;
					break;
				default: spoluhlasky++;
					isready = false;
					break;
				}
			}
			else
			{
				switch (vstup)
				{
				default: ostatne++;
					isready = false;
					break;
				}
			}
		}
		else
		{
			if (isspace(vstup))
			{
				switch (vstup)
				{
				default: isready = true;
					break;
				}
			}
			else
			{
				switch (vstup)
				{
				default: isready = false;
					break;
				}
			}
		}
		cin.get(vstup);
	};

	cout << endl;
	cout << samohlasky << " slova zacinajuce samohlaskou.\n";
	cout << spoluhlasky << " slova zacinajuce na spoluhlasky.\n";
	cout << ostatne << " ostatne.";

	return 0;
}
