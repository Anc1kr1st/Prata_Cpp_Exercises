/*
Chap_05_Ex_01
Napiste program, ktery pozada uzivatele o vstup dvou celuch cisel. Program by potom mel vypocitat soucet 
celych cisel mezi temito cisly vcetne a oznamit vysledek.Prozatim predpokladame, ze bude mensi cele cislo 
zadano jako prvni.Kdyz uzivatel napriklad zada 2 a 9, program oznami, ze soucet vsech celych cisel mezi 2 
a 9 je 44.
*/

#include <iostream>

using namespace std;

int main() {

	int lower;
	int higher;
	int result;

	cout << "Please, enter 2 intigers.\n";
	cout << "Enter the lower number first: ";
	cin >> lower;
	cout << "Now enter higher number: ";
	cin >> higher;
	result = 0;

	//or while
	for (int i = lower; i <= higher; i++) {
		result = result + i; "\n";
	}
	cout << "Sum of all numbers between " << lower << " and " << higher << " is " << result;

	return 0;
}