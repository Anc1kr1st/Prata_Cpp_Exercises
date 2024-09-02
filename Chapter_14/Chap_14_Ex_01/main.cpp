/*
Chap_14_Ex_01
Trida Wine obsahuje objekt tridy string (viz kapitola 4), ktery obsahuje nazev vina,
a objekt tridy Pair (viz tato kapitola) objektu valarray<int> (viz tato kapitola).
Prvni clen kazdeho objektu Pair obsahuje rocniky a druhy clen pocet lahvi daneho rocniku.
Napriklad prvni objekt valarray objekutu Pair obsahuje rocniky 1988, 1992 a 1996 a druhy objekt valarray pocty lahvi 24, 48 a 144. Dale by bylo vhodne, aby trida Wine obsahovala clen typu int, v nemz bude ulozen pocet rocniku. Pro zjednoduseni kodovani mohou byt vhodne typedef:
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
Typ PairArray tez predstavuje typ Pair<std::valarray<int>, std::valarray<int> >. Implementujte tridu Wine pomoci kompozice. Trida by mela mit implicitni konstruktor a nejmene tyto konstruktory:
// inicializace label na l, pocet rocniku do y,
// rocniky do yr[], lahve do bot[]
Wine(const char * l, int y, const int yr[], const int bot[]);
// inicializace label na l, pocet rocniku do y,
// vytvor objekty pole delky y
Wine(const char * l, int y);
Trida Wine by mela mit metodu GetBottles(), ktera pro objekt Wine rocniku y vyzada od uzivatele, aby zadal pocet rocniku a pocty lahvi. Metoda Label() by mela vratit odkaz na nazev vina. Metoda sum() by mela vracet celkovy pocet lahvi v druhem objektu valarray<int> v objektu Pair.

Program by si mel od uzivatele vyzadat nazev vina, pocet prvku pole, rocnik a pocet lahvi pro kazdy prvek pole. Pak by mel z techto dat zkonstruovat objekt Wine a dale vypsat informace ulozene v objektu. Zde je vzor testovaciho programu:
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
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = { 48, 60, 72};
	// create new object, initialize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Celkem lahvi " << more.Label() // pouzije metodu Label()
		<< ": " << more.sum() << endl;		// pouzije metodu sum()
	cout << "Nashledanou\n";
	return 0;
}
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
