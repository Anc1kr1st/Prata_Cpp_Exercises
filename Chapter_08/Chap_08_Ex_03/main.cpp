/*
Chap_08_Ex_03
Napiste funkci, ktera se odkazuje na objekt string jako na parametr a ktera 
prevede obsah retezce na velka pismena. Pouzijte funkci toupper() popsanou 
v tabulce 6.4. Napiste program s cyklem, ktery otestuje funkci s jinym vstupem.
*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

void funkcia(const string& parameter);

int main()
{
	cout << "Enter a string (q to quit): \n";
	string robota;
	int i = 0;

	getline(cin, robota);
	while (robota[i] != 'q')
	{
		funkcia(robota);

		cout << "Next string (q to quit): \n";
		getline(cin, robota);
	}
	cout << "Bye.\n";

	return 0;
}

void funkcia(const string& parameter)
{
	string fin;
	string a;

	for (int i = 0; parameter[i] != '\0'; i++)
	{
		a = toupper(parameter[i]);

		fin = fin + a;
	}

	cout << fin << endl;

}
