/*
Chap_06_Ex_05
Kralovstvi Neutronie, kde je jednotkou meny chechtak, ma nasledujici pravidla 
pro vypocet dane z prijmu:
prvnich 5000 chechtaku: 0% dan
dalsich 10000 chechtaku: 10% dan
dalsich 20000 chechtaku: 15% dan
chechtaky nad 35000: 20% dan
Napiste program, ktery se bude v cyklu ptat na prijem a vypisovat vypocitanou dan. 
Cyklus skonci, kdyz uzivatel zada zaporne cislo nebo nenumericky vstup.
*/
#include <iostream>

int main()
{
	using namespace std;

	double x;
	double d;

	cout << "Enter the tax to pay. Enter a negative or non-numeric number to exit.\n";

	while (cin >> x && x > 0)
	{
		if (x <= 5000)
		{
			d = x * 0;
		}
		else if (x > 5000 && x <= 15000)
		{
			d = (x - 5000) * 0.10;
		}
		else if (x > 15000 && x <= 35000)
		{
			d = (5000 * 0) + (10000 * 0.10) + ((x - 15000) * 0.15);
		}
		else
		{
			d = (5000 * 0) + (10000 * 0.10) + (20000 * 0.15) + ((x - 35000) * 0.20);
		}
		cout << "Tax to pay is : " << d << " chechtak.\n";
		cout << "Enter the tax to pay. Enter a negative or non-numeric number to exit.\n";
	}
	return 0;
}
