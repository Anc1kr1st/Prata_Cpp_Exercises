/*
Chap_07_Ex_01
Napiste program, ktery opakovane zada zadani dvojice cisel, doku alespon jedno cislo 
neni nulove. Pro kazdy par by mel program volat funkci na vypocet jeho harmonicke 
stredni hodnoty. Funkce by mela vratit odpoved funkci main(), kde vysledek vypise. 
Harmonicka stredni hodnota je prevracena hodnota prumeru prevracenych hodnot a muze se 
pocitat nasledovne:
harmonicka stredni hodnota = 2.0*x*y/(x+y).
*/

#include <iostream>

using namespace std;

double funkcia(double y, double x);

int main()
{
	double jedna;
	double dva;

	cout << "Zadaj dve cisla: \n";

	while ((cin >> jedna >> dva) && !jedna == 0 && !dva == 0)
	{
		cout << "Harmonicka stredna hodnota: ";
		cout << funkcia(jedna, dva) << endl;
		cout << "Zadajte dalsie dve cisla. 0 pre ukoncenie.\n";
	}

	return 0;
}


double funkcia(double y, double x)
{
	double hsh = 0;

	hsh = 2.0 * x * y / (x + y);
	return hsh;
}