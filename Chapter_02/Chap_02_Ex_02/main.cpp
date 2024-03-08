/*
Chapter 02 Exercise 02

Napište program v jazyce C++, který se vás zeptá na vzdálenost v jednotkách furlong a zadanou hodnotu p?evede na yardy (jeden furlong je 220 yardú).
*/

#include <iostream>

using namespace std;

int main() {
	int distance;
	int result;
	cout << "Enter distance in furlong: \n";
	cin >> distance;
	cout << endl;
	result = distance * 220;
	cout << result;

	return 0;
}
