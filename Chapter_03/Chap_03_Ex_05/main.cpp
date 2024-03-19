/*
CH 3 EX 5
5.  Napište program, který se zeptá, kolik mil jste ujeli a kolik galonů benzinu jste spotřebovali 
a potom vypíše zprávu o spotřebě vašeho auta v mílích na galon.Nebo se program může dotázat na 
vzdálenost v  kilometrech a  na benzin v  litrecha potom vypsat zprávu o výsledku v evropském stylu, 
v litrech na 100 kilometrů.
*/

#include <iostream>

using namespace std;

int main() {

	float gasoline, distance, consumption;

	cout << "How many km did you drive? ";
	cin >> distance;
	cout << "How much gasoline in l did you use? ";
	cin >> gasoline;

	consumption = (100 / distance) * gasoline;
	cout << "Your consumption is " << consumption << " l / 100 km.";

	return 0;
}
