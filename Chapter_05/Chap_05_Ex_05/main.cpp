/*
Chap_05_Ex_05
Provedte Programatorske cviceni 4, ale pouzijte dvojrozmerne pole na ulozeni vstupnich 
hodnot mesicnich prodeju za tri roky. Zobrazte celkove prodeje za kazdy jednotlivy rok 
a za vsechny roky.
*/

#include <iostream>

using namespace std;

int main() {

	const char* months[] =
	{
		"january",
		"february",
		"march",
		"april",
		"may",
		"june",
		"july",
		"august",
		"september",
		"october",
		"november",
		"december"
	};
	int inputs[3][12];
	int years[3] = {0, 0, 0};
	int sum = 0;
	int counter = 0;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 12; i++) {
			cout << "Enter the number of books sold per month " << months[i] << ": ";
			cin >> inputs[j][i];
			years[j] = years[j] + inputs[j][i];
		}
		sum = sum + years[j];
	}
	cout << endl;

	for (int j = 0; j < 3; j++) {
		counter++;
		cout << "Total sales of books for " << counter << ". year is " << years[j] << " books.\n";
	}

	cout << "\nTotal sales of books for all three years is " << sum << " books.";

	return 0;
}
