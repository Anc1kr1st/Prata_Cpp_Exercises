/*
Chap_17_Ex_06
6. Uvazujte definice trid z programovaciho cviceni 5 v kapitole 14. Pokud jste
cviceni dosud neprovedli, ucinte tak nyni. Potom postupujte nasledovne:
Napiste program, ktery pouziva standartni V/V zarizeni a vstupni a vystupni soubory
spolecne s daty typu employee, manager, fink a highfink tak, jak byla definovana
v programovacim cviceni 5 v kapitole 14. Program by mel po vzoru programu z vypisu
17.17 umoznit pridavat do souboru nova data. Pri prvnim spusteni by si mel vyzadat
data od uzivatele, vsechny polozky zobrazit a ulozit do souboru. Pri naslednem
pouziti by mel program data nejdrive precist a zobrazit, potom uzivateli umoznit
nejaka data pridat a nakonec je vsechna zobrazit. Jediny rozdil by mel spocivat
v tom, ze data budou spravovana pomoci pole ukazatelu na typ employee. Ukazatel muze
ukazovat na objekt employee nebo na objekty kterehokoli ze tri slozenych typu. Pro
lepsi kontrolu programu pouzijte male pole:
const int MAX = 10;  // ne vic nez 10 objektu
...
employee * pc[MAX];
Pri vstupu z klavesnice by mel program pouzit nabidku a nabidnout uzivateli vyber
z typu objektu, ktery chce vytvorit. Nabidka pouzije pro vytvoreni objektu
pozadovaneho typu prepinac s nabidkou new a adresu objektu priradi ukazateli
v poli pc. Objekt potom pouzije vitualni funkci setall() a pozada uzivatele o zadani
nalezitych udaju:
pc[i]->setall();  // vyvola funkci odpovidajijci typu objektu
Pro ulozeni dat do souboru napiste virtualni funkci writeall():
for (i = 0; i < index; i++)
pc[i]->writeall(fout);  // fout je objekt tridy ostream spojeny s vystupnim souborem

POZNAMKA
V tomto cviceni pouzijte pro vstup a vystup textove soubory, nikoli binarni.
(Virtualni objekty obsahuji bohuzel ukazatele na tabulky ukazatelu na virtualni
funkce a funkce write() kopiruje tyto informace do souboru. Objekt naplneny ze
souboru pomoci funkce read() ziska pro ukazatele na funkce podivne hodnoty,
ktere v chovani virtualnich funkci vytvori dokonaly zmatek.)  Kazde pole dat
oddelte od nasledujicho pomoci znaku noveho radku; pri vstupu budou pole snaze
identifikovatelna. Pokud byste prece jen chteli pouzit binarni souboury,
nezapisujte objekty jako celky. Misto toho napiste metody trid, ktere pouziji
pro kazdou jednotlivou polozku tridy funkce write() a read(). Timto zpusobem
program ulozi do soubouru pouze urcena data.

Obtiznou cast predstavuje nacteni dat ze souboru. Problemem je, jak ma program
poznat, ze pristi ctenou polozkou bude objekt typu employee, manager, fink nebo
highfink? Jednim z moznych reseni je oznacit data celociselnou polozkou, urcujici
typ nasledujiciho objektu. Pri vstupu ze soubouru potom program cislo precte
a pomoci prikazu switch vytvori pro ziskana data objekt odpovidajici typu:
enum classkind[Employee, Manager, Fink Highfink};  // v hlavicce tridy
...
int classtype;
while ((fin >> classtype).get(ch)) {	// znak noveho radku od dat oddeluje int
switch(classtype) {
case Employee : pc[i] = new employee;
: break;
Potom muzete pomoci ukazatele vyvolat virtualni funkci getall() a informace precist:
pc[i++]->getall();
*/
// pe14-5.cpp
// useempl.cpp -- using the abstr_emp classes

#include <iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;
#include "emp.h"

const int MAX = 10;

void displayMenu(void);
void eatline(void);

int main(void)
{
	/*
		employee em("Trip", "Harris", "Thumper");
		cout << em << endl;
		em.ShowAll();

		manager ma("Amorphia", "Spindragon", "Nuancer", 5);
		cout << ma << endl;
		ma.ShowAll();


		fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
		cout << fi << endl;
		fi.ShowAll();
		highfink hf(ma, "Curly Kew");  // nabor?
		hf.ShowAll();
		cout << "Pro dalsi fazi stisknete klavesu:\n";
		cin.get();
		highfink hf2;
		hf2.SetAll();

		cout << "Pouziti ukazatele abstr_emp *:\n";
		abstr_emp  * tri[4] = {&em, &fi, &hf, &hf2};
		for (int i = 0; i < 4; i++)
			tri[i]->ShowAll();
	*/

	// On first use, the program should solicit data from user, show all entries, and save into in a file. On subsequent uses, the program should first read and display the file data, let the user add data, and show all the data. 
	abstr_emp* pc[MAX];
	cout << "You may enter of to " << MAX << " employees" << endl;
	int count = 0;
	char ch;

	// Read from employeeList.dat file
	ifstream fin;
	fin.open("employeeList.dat");
	if (fin.is_open())
	{
		int classtype;
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
			case abstr_emp::Employee:
				cout << "Creating an employee object" << endl;
				pc[count] = new employee;
				pc[count++]->getall(fin);
				break;
			case abstr_emp::Manager:
				cout << "Creating an manager object" << endl;
				pc[count] = new manager;
				pc[count++]->getall(fin);
				break;
			case abstr_emp::Fink:
				cout << "Creating an fink object" << endl;
				pc[count] = new fink;
				pc[count++]->getall(fin);
				break;
			case abstr_emp::Highfink:
				cout << "Creating an highfink object" << endl;
				pc[count] = new highfink;
				pc[count++]->getall(fin);
				break;
			default:
				cerr << "It looks like an error has occurred" << endl;
				break;
			}
		}
		cout << "Here is your current employee list: " << endl;
		for (int i = 0; i < count; i++)
		{
			pc[i]->ShowAll();
			cout << endl;
		}
		fin.close();
	}

	// Allow user to enter more data
	while (count < MAX)
	{
		displayMenu();
		cin >> ch;
		eatline();
		switch (ch)
		{
		case 'a':
			pc[count] = new employee;
			pc[count]->SetAll();
			count++;
			break;
		case 'b':
			pc[count] = new manager;
			pc[count]->SetAll();
			count++;
			break;
		case 'c':
			pc[count] = new fink;
			pc[count]->SetAll();
			count++;
			break;
		case 'd':
			pc[count] = new highfink;
			pc[count]->SetAll();
			count++;
			break;
		case 'q':
			break;
		default:
			cout << "Error input not recognized" << endl;
			continue; // this should apply to while loop
			break;
		}
		if (ch == 'q')
			break;
	}

	// write data to file and display data
	ofstream fout;
	fout.open("employeeList.dat");
	if (!fout.is_open())
	{
		cerr << "Error, cannot open employeeList.dat" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Here's our updated list: " << endl;
	for (int i = 0; i < count; i++)
	{
		pc[i]->ShowAll();
		cout << endl;
		pc[i]->writeall(fout);
	}

	fout.close();


	return 0;
}

void displayMenu(void)
{
	cout << "Select one of the following:" << endl;
	cout << left;
	cout << setw(20) << "a. Employee"
		<< setw(20) << "b. Manager"
		<< endl
		<< setw(20) << "c. Fink"
		<< setw(20) << "d. Highfink"
		<< endl
		<< "(q to quit)" << endl;
}

void eatline(void)
{
	char ch;
	while (cin.get(ch) && ch != '\n')
		continue;
}
