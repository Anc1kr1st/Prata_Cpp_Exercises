/*
Chapter 02 Exercise 06

Napište program, který si vyžádá hodnotu hodiny a hodnotu minuty. Funkce main() pak tyto hodnoty předá funkci typu void, 
která je vypíše v následujícím tvaru:
Enter the number of hours: 9
Enter the number of minutes: 28
Time 9:28
*/

#include <iostream>

using namespace std;

int hours;
int minutes;

void time() {
	cout << "Time: " << hours << ":" << minutes;
}

int main() {
	cout << "Enter the number of hours: ";
	cin >> hours;
	cout << "Enter the number of minutes: ";
	cin >> minutes;

	time();

	return 0;
}