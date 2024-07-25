/*
Chap_12_01
1. Uvazujte nasledujici deklaraci tridy:
class Cow {
char name[20];
char * hobby;
double weight;
public:
Cow();
Cow(const char * nm, const char * ho, double wt);
Cow(const Cow c&);
~Cow();
Cow operator=(const Cow & c);
void ShowCow();
};
Vytvorte implementaci teto tridy a napiste kratky program vyuzivajici vsechny tyto clenske funkce.
*/
// main.cpp
#include "cow.h"

int main()
{

	Cow cow1;
	Cow cow2("Mooo", "Eating", 150);
	Cow* cow3 = new Cow("Milka", "Milking", 115);

	cout << "Cow Nm. 1: ";
	cout << endl;
	cow1.ShowCow();
	cout << "\nCow Nm. 2: "; 
	cout << endl;
	cow2.ShowCow();
	cout << "\nCow Nm. 3: "; 
	cout << endl;
	cow3->ShowCow();

	Cow cow4(cow2);

	cout << "\nCow Nm. 4 (or 2?): "; 
	cout << endl;
	cow4.ShowCow();

	Cow* cow5 = new Cow;
		*cow5 = cow2;

	cout << "\nCow Nm. 5 (or 2?): "; 
	cout << endl;
	cow5->ShowCow();

	delete cow3;

	return 0;
}
