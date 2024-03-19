/*
Chapter 03 Exercise 01

Napište krátký program, který se zeptá na vaši výšku v celých palcích, a potom ji konvertuje 
na stopy a palce. Podtržítky vyznačte místa pro vepsání zadání. Pro konverzní faktor použijte 
symbolickou konstantu uvozenou klíčovým slovem const.
*/

#include <iostream>

using namespace std;

int main() {

	int inches;
	const int conversion = 12;

	cout << "What is your height in inches?\n";
	cin >> inches;
	cout << "Your height is " << inches / conversion << " feet and " << inches % conversion << " inch(es).";

	return 0;
}