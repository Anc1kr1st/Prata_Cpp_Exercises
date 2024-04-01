/*
Ch4EX7
7.  William Wingate poskytuje službu analýzy pizz. Pro každou pizzu musí zaznamenat následující informaci : 
Jméno společnosti vyrábějící pizzu, které se může skládat z více než jednoho slova. Průměr pizzy. Váha pizzy.
Navrhněte strukturu pro uložení požadovaných informací a  proměnnou tohoto typu použijte v programu. Tento 
program by měl požádat uživatele o zadání všech informací a poté by je měl zobrazit. Použijte objekty cin 
(nebo jeho metody) a cout.
*/

#include <iostream>

using namespace std;

struct pizza {
	char name[20];
	int diameter;
	int weight;
};

int main() {

	pizza snack;

	cout << "Please enter name of pizza: ";
	cin.getline(snack.name, 20);
	cout << "Please enter diameter of pizza in mm: ";
	cin >> snack.diameter;
	cout << "Please enter weight of pizza in g: ";
	cin >> snack.weight;

	cout << "Name of pizza: " << snack.name << endl;
	cout << "Diameter of pizza: " << snack.diameter << endl;
	cout << "Weight of pizza: " << snack.weight << endl;

	return 0;
}
