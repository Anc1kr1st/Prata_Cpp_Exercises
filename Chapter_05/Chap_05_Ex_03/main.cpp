/*
Chap_05_Ex_03
Daphne investuje 100 Kc na jednoduchy urok 10 % .To znamena, ze jeji investice vzroste kazdy 
rok o 10 % puvodni investice, neboli kazdy rok o 10 Kc: urok = 0, 10 x puvodni zustatek
Ve stejnou dobu investuje Cleo 100 Kc na slozeny urok 5 % .To znamena, ze urok je 5 % z bezneho 
zustatku vcetne predchoziho prirustku uroku : urok = 0, 05 % x bezny zustatek
Cleo vydela 5 % ze 100 Kc prvni rok, coz znamena, ze bude mit 105 Kc. Dalsi rok vydela 5 % ze 105 Kc, 
tedy 5, 25 Kc atd.Napiste program, ktery zjisti, za kolik let Cleina investice predstihne Daphninu a 
potom zobrazte hodnoty obou investic v te dobe.
*/
#include <iostream>

using namespace std;

int main() {

	int daphne = 100;
	int cleo = 100;
	int year = 0;

	while (daphne >= cleo) {

		year++;
		daphne = daphne + 10;
		cleo = cleo + (cleo * 0.05);

	}

	cout << "Cleo investment overtook Daphne investment in " << year << " years.\n";
	cout << "Cleo investment: " << cleo << " Kc.\n";
	cout << "Daphne investment: " << daphne << " Kc.\n";

	return 0;
}
