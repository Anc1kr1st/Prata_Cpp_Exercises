/*
Chap_07_Ex_04
Mnoho statnich loterii provozuje obmenu jednoduche loterie predvedene na vypise 7.4. 
V techto obmenach vybirate nekolik cisel ze sady a nazyvate je cisla z pole. Muzete 
napriklad vybrat 5 cisel z pole 1-47. Dale vybirate jedno cislo (rika se mu megacislo) 
z druheho rozsahu, napriklad 1-27. Abyste vyhrlai hlavni vyhru, musite uhadnout vsechna 
cisla. Pravdepodobnost vyhry je vysledkem soucinu pravdepodobnosti uhodnuti vsech cisel 
z pole a pravdepodobnosti spravneho vyberu megacisla. Napriklad pravdepodobnost vyhry ve 
zde popsanem pripadu je vysledkem soucinu pravdepodobnosti spravneho vyberu 5 cisel ze 47 
a pravdepodonosti spravneho vyberu jednoho cisla z 27. Upravte vypis 7.4 pro vypocet 
pravdepodobnosti vyhry v tomto druhu loterie.
*/

#include <iostream>

long double probability(unsigned numbers, unsigned picks);
using namespace std;

int main()
{
	double total = 47;
	double choices = 5;
	probability(total, choices);

	double total2 = 27;
	double choices2 = 1;
	probability(total2, choices2);

	double pravdepodobnost;
	pravdepodobnost = (probability(total, choices)) * (probability(total2, choices2));
	cout << "Probability that you will win is 1 to ";
	cout << pravdepodobnost << endl;

	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}
