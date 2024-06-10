/*
Chap_10_Ex_08
Jednoduchy seznam muzeme popsat nasledovne:
- Jednoduchy seznam muze obsahovat zadnou az nekolik polozek konkretniho typu.
- Muzete vytvorit prazdny seznam.
- Muzete pridat polozku do seznamu.
- Muzete zjistit, zda je seznam prazdny.
- Muzete zjistit, zda je seznam plny.
- Muzete si prohlednout kazdou polozku v seznamu a provest s ni nejakou cinnost.
Jak vidite, jedna se skutecne o jednoduchy seznam, ktery neumoznuje napriklad vkladani nebo mazani.
Navrhnete tridu List, ktera bude reprezentovat tento abstraktni typ. Vysledke, by mel byt hlavickovy 
soubor list.h s deklaraci tridy a soubor list.cpp s implementaci metod tridy. Nakonec vytvorte 
kratky programek, ktery tento narvrh vyuzije.
Hlavni vyznam taktoveho seznamu je poskytnout zjednoduseny programovy projekt. V takovem pripade 
vytvorte tridu odpovidajici tomuto popisu. Seznam muzete implementovat jako pole nebo, pokud znate 
datove typy, jako spojovy seznam.
Verejne rozhrani by to vsak ovlivnit nemelo. To znamena, ze by nemelo  mit indexy poli, ukazatele 
na uzly a pod. Melo by byt vyjadreno v obecnych koncepcich prvku a provedeni nejake cinnosti pouzije 
funkce, ktera ma jako parametr ukazatel na funkci:
void visit(void (*pf)(Item &));
Zde pf ukazuje na funkci (ne na clenskou funkci), ktera ma jako parametr referenci na parametr Item, 
kde Item je typ polozek v seznamu. Funkce visit() pouzije tuto funkci na vsechny polozky seznamu. Meli 
byste take napsat kratky program pouzivajici tento navrh. Reseni by melo vychazet z tridy Stack.
*/

#include "list.h"

inline void doubleValue(double& x) { x = 2 * x; }
inline void square(double& x) { x = x * x; }
inline void halve(double& x) { x = x / 2; }
inline void reciprocal(double& x) { x = 1 / x; }

int main(void) {

	List zoznam;

	cout << "Enter a number - max 10 (q to quit): ";

	double d;
	while (cin >> d && zoznam.isFull() == 0)
	{
		zoznam.add(d);
		if (zoznam.isFull() == 0)
			cout << "Enter a number - max 10 (q to quit): ";
	}
	cin.clear();
	cin.ignore(256, '\n');
	cout << "You have entered " << zoznam.numberOfItems() << " items." << endl;

	cout << "Here is your list: " << endl;
	zoznam.printList();

	cout << "Please choose (q to quit): " << endl;
	cout << "1. doubleValue()          2. square()     \n"
		<< "3. halve()                4. reciprocal() \n";
	int choice;
	while (cin >> choice)
	{
		switch (choice)
		{
		case 1:
			zoznam.visit(doubleValue);
			break;
		case 2:
			zoznam.visit(square);
			break;
		case 3:
			zoznam.visit(halve);
			break;
		case 4:
			zoznam.visit(reciprocal);
			break;
		default:
			cout << "Not an option" << endl;
			break;
		}
		cout << "Here is your new list: " << endl;
		zoznam.printList();
		cout << "Choose from the following (q to quit): " << endl;
		cout << "1. doubleValue()          2. square()     \n"
			<< "3. halve()                4. reciprocal() \n";
	}

	cout << "Bye!" << endl;
	return 0;
};
