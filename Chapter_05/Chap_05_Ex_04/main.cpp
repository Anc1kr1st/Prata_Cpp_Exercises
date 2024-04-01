/*
Chap_05_Ex_04
Predstavte si, ze prodavate knihu C++ pro kazdeho. Napiste program, do ktereho bude mozne 
zadat mesicni prodeje za rok (v poctu knih, ne v penezich). Program by mel v cyklu postupne 
vyzvat uzivatele k zadani vstupu pomoci jmen mesicu ziskanych z pole typu char * inicializovaneho 
retezci se jmeny mesicu. Vstupni data by program ukladal do pole typu int. Dale by vypocital 
soucet hodnot pole a zobrazil celkovy prodej za rok.
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
	int inputs[12];
	int sum = 0;

	for (int i = 0; i < 12; i++) {

		cout << "Enter the number of books sold per month " << months[i] << ": ";
		cin >> inputs[i];
		sum = sum + inputs[i];

	}

	cout << "Total sales for the year is " << sum << " books.";

	return 0;
}
