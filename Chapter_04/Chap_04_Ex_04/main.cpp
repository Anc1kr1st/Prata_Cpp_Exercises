/*
Ch4EX4

4.  Napište program, který si vyžádá od uživatele křestní jméno a  příjmení a  poté vytvoří, 
uloží a vypíše třetí řetězec, který se bude skládat z příjmení, čárky, mezery a křestního jména.
Použijte k tomu objekty string a metody z hlavičkového souboru string. Výpis po spuštění by mohl 
vypadat například takto :
Zadejte krestni jmeno : Flip
Zadejte prijmeni : Fleming
Zde jsou oba udaje spojeny do jednoho retezce : Fleming, Flip
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

	string firstName;
	string lastName;

	cout << "Enter first name: ";
	cin >> firstName;
	cout << "Enter last name: ";
	cin >> lastName;

	string fullName = lastName + ", " + firstName;
	cout << fullName;

	return 0;
}
