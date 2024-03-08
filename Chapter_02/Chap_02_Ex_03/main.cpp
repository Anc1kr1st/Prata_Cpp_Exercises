/*
Chapter 02 Exercise 03

Napište program v jazyce C++ se t?emi uživatelsky definovanými funkcemi (main() se po?íta za jednu), jehož výstup je následujúcí: 
Tri slepe mysi
Tri slepe mysi
Divejte se, jak utikaji
Divejte se, jak utikaji
Prvni funkce, která je volána dvakrát, by m?la vypsat první dva ?ádky a druhá funkce, která je také volána dvakrát, by m?la obstarat zbývajíci výstup.
*/

#include <iostream>

using namespace std;

void f1() {
	cout << "Tri slepe mysi\n";
}
void f2() {
	cout << "Divejte se, jak utikaji\n";
}

int main() {
	f1();
	f1();
	f2();
	f2();

	return 0;
}