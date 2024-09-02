/*
Chap_14_Ex_02
Toto cviceni je stejne jako cviceni 1 s tim rozdilem, ze misto kompozice pouzijte 
soukromou dedicnost. Muze se hodit i nekolik typedef. Take muzete zvazit, k cemu 
by mohly byt vhodne nasledujici prikazy:
PairArray::operator=(PairArray(ArrayInt(), ArrayInt()));
cout << (const string &)(*this);
Trida by mela pracovat se stejnym testovacim programem jako ve cviceni 1.
*/

// pe14-1.cpp -- pouziti tridy Wine s kompozici
#include<iostream>
#include"winec.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Zadejte nazev vina: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Zadejte pocet rocniku: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs); // uloz label, years, poskytni arrays yrs elements
	holding.GetBottles(); 	//vyzadej rok, pocet lahvi
	holding.Show(); 		// vypis obsah objektu

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };
	// create new object, initialize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Celkem lahvi " << more.Label() // pouzije metodu Label()
		<< ": " << more.sum() << endl;		// pouzije metodu sum()
	cout << "Nashledanou\n";
	return 0;
}
