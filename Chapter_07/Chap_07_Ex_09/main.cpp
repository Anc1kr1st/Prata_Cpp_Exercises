/*
Chap_07_Ex_09
Navrhnete funkci calculate(), ktera prebira dve hodnoty typu double a ukazatel 
na funkci, jez prebira dva argumenty typu double a vraci double. Funkce 
calculate() by take mela mit typ double a mela by vracet hodnotu, kterou jako 
ukazatel predana funkce spocita z argumentu typu double funkce calculate(). 
Predpokladejme, ze mame nasledujici definici funkce add():
double add(double x, double y)
{
return x + y;
}
Potom toto volani funkce double q = calculate(2.5, 10.4, add);
by melo zpusobit, ze funkce calculate() preda hodnoty 2.5 a 10.4 funkci add() a 
potom vrati navratovou hodnotu funkce add() (12.9).
V programu pouzijte tyto funkce a alespon jeste jednu dalsi funkci podobnou add(). 
Program by mel v cyklu uzivateli umoznit zadavani dvojic cisel. Pro kazdou dvojici 
vyvolejte prostrednictvim funkce calculate() funkci add() a alespon jednu dalsi 
funkci. Mate-li odvahu, pokuste se vytvorit pole ukazatelu na funkce stylu add() a 
pomoci cyklu aplikujte funkci calculate() na radu funkci s pouzitim techto ukazatelu. 
Napoveda: Zde vidite deklaraci takoveho pole tri ukazatelu:
double (*pf[3])(double, double);
Vyse uvedene pole muzete inicializovat pomoci obvykle syntaxe pro inicializaci pole a 
jmen funkci jako adres.
*/

#include <iostream>

using namespace std;

double add(double x, double y);
double noadd(double m, double n);
double odcitanie(double j, double k);
void calculate(double s, double t, double(*ukazatel[3])(double, double));


int main()
{
	double jedna;
	double dva;

	double(*ukazatel[3])(double, double) = { add, noadd, odcitanie };

	cout << "Zadajte 2 cisla. Nieco ine pre koniec. " << endl;

	while ((cin >> jedna >> dva) && (jedna != '\n' || dva != '\n'))
	{

		calculate(jedna, dva, ukazatel);

		cout << "Zadajte 2 cisla. Nieco ine pre koniec. " << endl;
	}

	return 0;
}

double add(double x, double y)
{
	return x + y;
}

double noadd(double m, double n)
{
	return m * n;
}

double odcitanie(double j, double k)
{
	return j - k;
}

void calculate(double s, double t, double (*ukazatel[3])(double, double))
{

	for (int i = 0; i < 3; i++)
	{

		(*ukazatel[i])(s, t);
		cout << (*ukazatel[i])(s, t) << endl;

	}
	return;
}
