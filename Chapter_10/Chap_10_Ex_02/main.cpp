/*
Chap_10_Ex_02
Zde je pomerne jednoducha definice tridy:
class Person {
private:
static const LIMIT = 25;
string lname;		// Prijmeni
char fname[LIMIT];		// Krestni jmeno
public:
Person() {lname = ""; fname[0] = '\0'; }  	// #1
Person(const string & ln, const char * fn = "Heyyou");  	//#2
// nasledujici metody zobrazi lname a fname
void Show() const;	// Format Krestni jmeno Prijmeni
void FormalShow() const;	// Format Prijmeni Krestni jmeno
};

Napiste program, ktery doplni implemetaci kodem pro nedefinovane metody. Program, v nemz tyto tridy pouzivate, by mel take pouzit tri mozna volani konstruktoru (bez argumentu, s jednim argumentem a se dvema argumenty) a dve metody pro vypisovani. Zde je priklad, kterz pouziva tyto konstruktory a metody:
Person one;		// Pouzije defaultni konstruktor
Person two("Smythecraft"); 		// Pouzije #2 s jednim defaultnim argumentem
Person three("Dimwiddy", "Sam");	//Pouzije #2, zadne defaultni argumenty
one.Show();
cout << endl;
oneFormalShow();
// atd. pro dva a pro tri
*/

#include "kniznica.h"

int main() {

	Person one;		// Pouzije defaultni konstruktor
	Person two("Smythecraft"); 		// Pouzije #2 s jednim defaultnim argumentem
	Person three("Dimwiddy", "Sam");	//Pouzije #2, zadne defaultni argumenty

	one.Show();
	one.FormalShow();
	cout << endl;

	two.Show();
	two.FormalShow();
	cout << endl;

	three.Show();
	three.FormalShow();
	cout << endl;

	return 0;
}
