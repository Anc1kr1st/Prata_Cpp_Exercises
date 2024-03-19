/*
Ch4 Ex2
2.  Přepište výpis 4.4., místo polí char použijte třídy string jazyka C++.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

	string name;
	string dessert;

	cout << "Zadejte vase jmeno:\n";
	getline(cin, name);
	cout << "Zadejte vas oblubeny zakusek:\n";
	getline(cin, dessert);
	cout << "Mam vyborny " << dessert;
	cout << ", ktery si zaslouzi jen " << name << ".";

	return 0;
}
