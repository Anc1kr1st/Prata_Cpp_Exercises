/*
CH 3 EX 6
6.  Napište program, který vás požádá o zadání spotřeby benzinu v evropském stylu (litry na 100 kilometrů) a převede 
ji na americký styl v mílích na galon. Všimněte si, že kromě použití jiných jednotek je americký styl (vzdálenost / palivo) 
obrácený oproti evropskému (palivo / vzdálenost). Sto kilometrů je 62, 14 mil a jeden galon má 3, 875 litru. Z čehož vyplývá, 
že 19 mpg(miles per gallon – mil na galon) je zhruba 12, 4 l / 100 km a 27 mpg je asi 8, 7 l / 100 km.
*/

#include <iostream>

using namespace std;

int main() {

	float literCon, galonCon;

	cout << "What is your consumption in liters per 100 km? ";
	cin >> literCon;

	galonCon = 62.14 / (literCon / 3.875);

	cout << "Your constumpion in miles per gallon is: " << galonCon;

	return 0;
}
