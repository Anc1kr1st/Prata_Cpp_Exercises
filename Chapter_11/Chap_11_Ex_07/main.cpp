/*
Chap_11_Ex_07
Komplexni cislo ma dve casti: realnou a imaginarni. Jednim zpusobem,
jak napsat imaginarni cislo, je (3.0, 4.0i). Zde je 3.0 realnou casti
a 4.0i casti imaginarni. Predpokladejme, ze plati a = (A,Bi) a c =
(C,Di). Zde jsou nektere operace s komplexnimi cisly:
- Scitani: a + c = (A + C, (B + D)i)
- Odcitani: a - c = (A - C, (B - D)i)
- Nasobeni: a * c = (A * C - B*D, (A*D + B*C)i)
- Konjugace: -a = (A, - Bi)
Definujte komplexni tridu tak, aby nasledujici program daval spravne vysledky.
*/

#include <iostream>
using namespace std;
#include "complex0.h"      // zamezi konfliktu s complex.h
int main()
{
	Complex a(3.0, 4.0);  // inicializace na hodnotu (3,4i)
	Complex c;
	cout << "Zadejte komplexni cislo (k pro ukonceni):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "komplexni sdruzene cislo je " << ~c << '\n';
		cout << "a je " << a << '\n';
		cout << "a + c je " << a + c << '\n';
		cout << "a - c je " << a - c << '\n';
		cout << "a * c je " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Zadejte komplexni cislo (k pro ukonceni):\n";
	}
	cout << "Hotovo!\n";
	return 0;
}

