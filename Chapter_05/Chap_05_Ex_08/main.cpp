/*
Chap_05_Ex_08
Napiste program, ktery je shodny s programem ve cviceni 7, avsak misto pole pouzijte objekt tridy string. 
Pridejte hlavickovy soubour string a porovnani provedte pomoci relacniho operatoru.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

	string word;
	string exit = "done";
	int count = 0;

	cout << "Enter words (for exit write the word done): ";

	do {

		cin >> word;
		count++;

	} while (exit != word);

		count--;

	cout << "You entered a total of " << count << " words.";

	return 0;
}
