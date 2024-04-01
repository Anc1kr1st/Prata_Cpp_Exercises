/*
Ch4EX9
9.  Provedte programové cvičení 3, ale místo deklarace pole tří struktur SladkaTycinka alokujte pamět pro pole 
dynamicky pomocí operátoru new.
*/

#include <iostream>

using namespace std;

struct sweetStick {
	char brand[10];
	float weight;
	int calorie;
};

int main() {

	sweetStick *snack = new sweetStick[3];

	strcpy_s(snack->brand, "Mars");
	snack->weight = 2.5;
	snack->calorie = 300;

	strcpy_s((snack + 1)->brand, "Delli");
	(snack + 1)->weight = 2.0;
	(snack + 1)->calorie = 200;

	strcpy_s((snack + 2)->brand, "3bit");
	(snack + 2)->weight = 1.9;
	(snack + 2)->calorie = 190;

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

	delete [] snack;

	return 0;
}
