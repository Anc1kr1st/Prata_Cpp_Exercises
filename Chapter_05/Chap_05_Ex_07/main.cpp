/*
Chap_05_Ex_07
Napiste program, ktery pouziva znakove pole a cyklus k precteni celeho jednoho slova, 
dokud nenarazi na slovo hotovo. Program by pak mel vypsat pocet prectenych slov (bez 
slova konec). Po spusteni by se mohl chovat napriklad takto:
Zadavajte slova (program ukoncite zadanim slova hotovo):
agina babicka celebrita drahota
erb frantik geometrie hotovo inkoust jalovec
Celkem jste zadal 7 slov.
Program musi obsahovat hlavickovy soubor cstring a porovnani by mel delat pomoci funkce strcmp().
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char word[20];
	char done[5] = "done";
	int count = 0;

	cout << "Enter words (for exit write the word done): ";

	do {

		cin >> word;
		count++;

	} while (strcmp(done, word) != 0);

	count--;
	cout << "You entered a total of " << count << " words.";

	return 0;
}

