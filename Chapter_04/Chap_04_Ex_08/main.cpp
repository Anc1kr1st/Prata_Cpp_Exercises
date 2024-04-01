/*
Ch_04_EX_08
8.  Provedte programové cvičení 4, ale místo deklarace strukturní proměnné alokujte pamět  pro strukturu 
pomocí operátoru new. Program by měl nejprve požádato poloměr pizzy a potom o jméno společnosti, která pizzu 
vyrábí.
*/

#include <iostream>

using namespace std;

struct pizza {
	char name[20];
	int diameter;
	int weight;
};

int main() {

	pizza* snack = new pizza;

	cout << "Please enter diameter of pizza in mm: ";
	cin >> snack->diameter;
	cin.get();
	cout << "Please enter name of pizza: ";
	cin.get(snack->name, 20);
	cout << "Please enter weight of pizza in g: ";
	cin >> snack->weight;

	cout << "Name of pizza: " << snack->name << endl;
	cout << "Diameter of pizza: " << snack->diameter << endl;
	cout << "Weight of pizza: " << snack->weight << endl;

	delete snack;

	return 0;
}
