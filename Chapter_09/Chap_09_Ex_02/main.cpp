/*
Chap_09_Ex_02
Upravte vypis 9.8 tak, ze nahradite znakove pole objektem string. Program by nemel zjistovat, 
zda souhlasi vstupni retezce a muze porovnat vstupni retezec s "", jestli neni prazdny.
*/

#include <iostream>
#include <string>

using namespace std;

// prototyp funkce
void strcount(const string str);

int main()
{
	string input;

	cout << "Zadejte radek textu:\n";
	getline(cin, input);
	while (input != "")
	{
		strcount(input);
		cout << "Zadejte dalsi radek textu (prazdny radek na ukonceni):\n";
		getline(cin, input);
	}
	cout << "Sbohem\n";
	return 0;
}

void strcount(const string str)
{

	static int total = 0;  // staticka lokalni promenna
	int count = str.length();            // automaticka lokalni promena
	cout << "\"" << str << "\" obsahuje ";
	total += count;
	cout << count << " znaku\n";
	cout << total << " znaku celkem\n";
}
