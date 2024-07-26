/*
Chap_12_Ex_03
Prepiste tridu Stock, popsanou ve vypisech 10.7 a 10.8 tak, aby pro ukladani 
nazvu firem pouzivala misto pevnych poli dynamicky pridelenou pamet. Nahradte 
take clenskou funkci show() definici pretizene funkce operator()<<. Novou 
definici vyzkousejte v programu z vypisu 10.9.
*/
//10.9
// usestok2.cpp -- pouziti tridy Stock
// predkladat se souborem stock2.cpp
#include <iostream>
#include "stock2.h"

const int STKS = 4;
int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	// create an array of initialized objects
	Stock stocks[STKS] = {
	Stock("NanoSmart", 12, 20.0),
	Stock("Boffo Objects", 2, 2.0),
	Stock("Monolithic Obelisks", 130, 3.25),
	Stock("Fleep Enterprises", 60, 6.5)
	};

	cout.precision(2);		// #.## format
	cout.setf(ios_base::fixed, ios_base::floatfield);	// #.## format
	cout.setf(ios_base::showpoint);		// #.## format

	cout << "Drzitele akcii:\n";
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st] << endl;

	Stock top = stocks[0];
	for (st = 1; st < STKS; st++)
		top = top.topval(stocks[st]);
	cout << "\nNejvetsi akcionar:\n";
	cout << top;

	return 0;
}
