/*
Chap_05_Ex_06
Navrhnete strukturu, ktera by se jmenovala auto a obsahovala by nasledujici informace 
o automobilu : znacku jako retezec ve znakovem poli a rok vyroby jako cele cislo. Napiste 
program, ktery se zepta uzivatele, kolik aut ma vlozit do katalogu. Program by mel potom 
pouzit metodu new na vytvoreni dynamickeho pole odpovidajiciho mnozstvi struktur typu auto.
Dale by mel pozadat uzivatele, aby zadal znacku(ktera se muze skladat z nekolika slov) a 
informaci o roku pro kazdou strukturu. Vsimnete si, ze to vyzaduje urcitou peclivost, 
protoze se strida cteni retezcu s ciselnymi daty(viz kapitola 4).Nakonenec byste meli 
zobrazit obsah kazde struktury.
*/

#include <iostream>

using namespace std;

struct car {
	char brand[30];
	int year;
};

int main() {

	int count;

	cout << "How many cars you want to add to the catalog?\n";
	cin >> count;
	cin.get();

	car* data = new car[count];

	for (int i = 0; i < count; i++) {
		cout << "Enter brand of car: ";
		cin.get(data[i].brand, 30);

		cout << "Enter year of manufacture: ";
		cin >> data[i].year;
		cin.get();
	}

	for (int i = 0; i < count; i++) {
		cout << "\nBrand of car: " << data[i].brand << endl;
		cout << "Year of manufacture: " << data[i].year << endl << endl;
	}

	delete[]data;
	return 0;
}
