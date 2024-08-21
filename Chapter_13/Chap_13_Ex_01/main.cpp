/*
Chap_13_01
1. Nejdirve deklarujte nasledujici tridu:
// zakladni trida
class Cd { 		// reprezentuje CD disk
private:
char performers[50];
char label[20];
int selections;		// pocet volieb
double playtime;		// hraci doba v minutach
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	~Cd();
	void Report() const; 	// vypise vsechna data na CD
	Cd & operator=(const Cd & d);
};

Vytvorte odvozenou tridu Classic, do ktere pridate znakove pole pro retezec, ktery
bude identifikovat prvotni praci na disku. Pokud bude nutne, aby v zakladni tride
byly nektere funkce virtualni, upravte deklaraci zakladni tridy. Vyzkousejte vysledek
pomoci nasledujiciho programu:
#include<iostream>
using namespace std;
#include "classic.h" 	// obsahuje #include cd.h
void Bravo(const Cd & disk);
int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano sonata in b flat, Fantasia in C", "Alfred Brendel", "Phillips", 2, 57.17);
	Cd * pcd = &c1;
cout << "Using object directly:\n";
	c1.Report(); 	// pouzije metodu tridy Cd
	c2.Report(); 	// pouzije metodu tridy Classic

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); 	// pouzije pro objekt tridy Cd metodu tridy Cd
	pcd = &c2;
	pcd->Report(); 	// pouzije pro objekt tridy Classic metodu tridy Classic

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: \n";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}

*/

//main.cpp

#include<iostream>
using namespace std;
#include "classic.h" 	// obsahuje #include cd.h
void Bravo(const Cd& disk);
int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano sonata in b flat, Fantasia in C", "Alfred Brendel", "Phillips", 2, 57.17);
	Cd* pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report(); 	// pouzije metodu tridy Cd
	c2.Report(); 	// pouzije metodu tridy Classic

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); 	// pouzije pro objekt tridy Cd metodu tridy Cd
	pcd = &c2;
	pcd->Report(); 	// pouzije pro objekt tridy Classic metodu tridy Classic

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: \n";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk)
{
	disk.Report();
}
