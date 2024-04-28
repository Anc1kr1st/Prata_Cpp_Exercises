/*
Chap_07_Ex_07
Prepracujte vypis 7.7 tak, aby tri funkce pracujici s poli pouzivaly dva 
ukazatelove parametry pro oznaceni rozsahu. Funkce fill_array() by mela 
misto skutecneho poctu nactenych polozek vracet ukazatel na misto za 
poslednim naplnenym; ostatni funkce mohou tento ukazatel pouzit jako druhy 
argument pro urceni konce dat.
*/

#include <iostream>

const int Max = 5;

double* fill_array(double* ar, int limit);
void show_array(const double* ar, double* n);
void revalue(double r, double* ar, double* n);

int main()
{
	using namespace std;
	double properties[Max];

	double* size = fill_array(properties, Max);
	show_array(properties, size);
	cout << "Zadajte koeficient prehodnocenia: ";
	double factor;
	cin >> factor;
	revalue(factor, properties, size);
	show_array(properties, size);
	cout << "Hotovo.\n";

	return 0;
}

double* fill_array(double* ar, int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Zadajte hodnotu c." << (i + 1) << ": ";
		cin >> temp;

		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Neplatny vstup, zadavanie ukoncene.\n";
			break;
		}
		else if (temp < 0)
			break;
		*(ar + i) = temp;

	}
	return (ar + i);
}

void show_array(const double* ar, double* n)
{
	using namespace std;
	const double* temp = ar;

	for (int i = 0; temp < n; i++, temp++)
	{
		cout << "Majetek c." << (i + 1) << ": Kc ";
		cout << *temp << endl;
	}
}

void revalue(double r, double* ar, double* n)
{
	double* temp = ar;
	for (int i = 0; temp < n; i++, temp++)

		*(ar + i) *= r;

}
