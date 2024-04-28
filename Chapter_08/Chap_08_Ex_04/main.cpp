/*
Chap_08_Ex_04
Dokoncit program.
*/

#include <iostream>
#include <cstring>
using namespace std;

struct stringy {
	char* str;
	int ct;
};

void set(stringy& odkaz, char test[]);
void show(const stringy& odkaz, int pocet = 1);
void show(const char test[], int pocet = 1);

int main()
{
	stringy beany;
	char testing[] = "Opravdu neni, co byval.";


	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Hotovo!");

	return 0;
}

void set(stringy& odkaz, char test[])
{
	int dlzka;

	dlzka = strlen(test);

	char* doc = new char[dlzka + 1];
	strcpy_s(doc, (dlzka + 1), test);

	odkaz.str = doc;
	odkaz.ct = dlzka;

}

void show(const stringy& odkaz, int pocet)
{
	for (int i = 0; i < pocet; i++)
	{
		cout << odkaz.str << endl;
	}
	return;
}

void show(const char test[], int pocet)
{
	for (int i = 0; i < pocet; i++)
	{
		cout << test << endl;
	}
	return;
}
