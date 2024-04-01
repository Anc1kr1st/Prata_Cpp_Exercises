/*
Ch4EX6
6. Struktura SladkaTycinka obsahuje tři členy, jak je popsáno v programovém cvičení 5. Napište program, 
který vytvoří pole tří struktur SladkaTycinka, inicializuje jehodnotkami podle vašeho výběru, a potom 
zobrazí obsah každé struktury.
*/

#include <iostream>

using namespace std;

struct sweetStick {
	char brand[10];
	float weight;
	int calorie;
};

int main() {

	sweetStick snack[3] = { {"Mars", 2.5, 300}, {"Delli", 2.0, 200}, {"3bit", 1.9, 190} };

	cout << "Brand: " << snack[0].brand << endl;
	cout << "Weight: " << snack[0].weight << endl;
	cout << "Calorie: " << snack[0].calorie << endl;
	cout << endl;
	cout << "Brand: " << snack[1].brand << endl;
	cout << "Weight: " << snack[1].weight << endl;
	cout << "Calorie: " << snack[1].calorie << endl;
	cout << endl;
	cout << "Brand: " << snack[2].brand << endl;
	cout << "Weight: " << snack[2].weight << endl;
	cout << "Calorie: " << snack[2].calorie << endl;
	cout << endl;

	return 0;
}
