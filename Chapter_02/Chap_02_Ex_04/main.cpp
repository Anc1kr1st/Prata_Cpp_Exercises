/*
Chapter 02 Exercise 04

Napište program, v jehož funkci main() je volána uživatelksy definovaná funkce, která jako argument p?ijímá teplotu ve stupních Celsia 
a vrací stejnou hodnotu ve stupních Fahrenheita. Program by m?l požádat uživatele o vstup hodnoty ve stupních Celsia a zobrazit výsledek, 
viz následujíci kód: 
Zadejte prosim hodnotu ve stupnich Celsia: 20
20 stupnu Celsia je 68 stupnu Fahrenheita.
Zde je vzorec pro p?evod: 
Fahrenheit = 1.8 x stupn? Celsia + 32.0
*/

#include <iostream>

using namespace std;

int main() {
	int enter;
	int fahrenheit;

	cout << "Please, enter value in degrees celsium: ";
	cin >> enter;
	fahrenheit = 1.8 * enter + 32;

	cout << endl;
	cout << enter << " degrees celsium is " << fahrenheit << " degrees fahrenheit.";

	return 0;
}