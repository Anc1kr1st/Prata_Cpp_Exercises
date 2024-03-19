/*
Ch4 Ex3
3.  Napište program, který si vyžádá od uživatele křestní jméno a  příjmení a  poté vytvoří, 
uloží a vypíše třetí řetězec, který se bude skládat z příjmení, čárky, mezery a křestního jména.
Použijte k tomu pole char a funkce z hlavičkového souboru cstring.Výpis po spuštění by mohl vypadat 
například takto :
Zadejte krestni jmeno : Flip
Zadejte prijmeni : Fleming
Zde jsou oba udaje spojeny do jednoho retezce : Fleming, Flip
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char firstName[20];
	char lastName[20];

	cout << "Enter first name: ";
	cin >> firstName;
	cout << "Enter last name: ";
	cin >> lastName;

	strcat_s(lastName, ", ");
	strcat_s(lastName, firstName);
	cout << "Here, both data are combined into one string: " << lastName;

	return 0;
}
