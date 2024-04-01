/*
Ch4EX5
5. Struktura Sladka Tycinka má tři členy. První člen uchovává značku sladké tyčinky, druhý člen váhu
(která může mít desetinnou část) a třetí člen počet kalorií (celé číslo). Napište program, který 
takovouto strukturu deklaruje a vytváří proměnnou typu Sladka Tycinka nazvanou svacina. Inicializujte 
každý její člen postupně na „Mocha Munch“, 2.3 a 350. Inicializace by měla být součástí deklarace proměnné 
snack. Nakonec by měl program obsah proměnné svacina vypsat.
*/

#include <iostream>

using namespace std;

struct sweetStick {
	char brand[20];
	float weight;
	int calorie;
};

int main() {

	sweetStick snack =
	{
		"Mocha Munch",
		2.3,
		350
	};

	cout << snack.brand << endl;
	cout << snack.weight << endl;
	cout << snack.calorie << endl;

	return 0;
}
