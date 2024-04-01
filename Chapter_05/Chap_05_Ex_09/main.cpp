/*
Chap_05_Ex_09
Pomoci vnorenych cyklu napiste program, ktery pozada uzivatele o zadani poctu zobrazovanych radku. 
Potom tento pocet radku zobrazi s jednou hvezdickou na prvnim radku, se dvema na druhem atd. 
V kazdem radku bude pred hvezdickami umisteno tolik tecek, aby vsechny radky zobrazovaly celkovy 
pocet znaku, ktery bude roven poctu radku. Priklad behu programu by mel vypadata nasledovne:
....*
...**
..***
.****
*****
*/

#include <iostream>

using namespace std;

int main() {

	int count;

	cout << "Enter the number of rows to display: ";
	cin >> count;

	int dot = 1;
	int star = count - 1;

	for (int i = 0; i < count; i++) {

		for (int j = dot; j < count; j++)
		{
			cout << ".";
		}
		dot++;

		for (int k = star; k < count; k++)
		{
			cout << "*";
		}
		star = star - 1;
		
		cout << endl;
	}

	return 0;
} 
