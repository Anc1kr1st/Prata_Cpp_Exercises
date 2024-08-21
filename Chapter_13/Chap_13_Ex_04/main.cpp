/*
Chap_13_04
V nejmenovane firme maji sklad alkoholu. K jeho popisu vytvoril spravce tridu Port
s nasledujici deklaraci:

#include<iostream>
using namespace std;
class Port
{
private:
	char * brand;
	char style[20]; 	// tzn. zlatava barva, rubinova barva, rocnik
	int bottles;
public:
	Port(const char * br = "none", const char * st = "none", int b = 0);
	Port(const Port & p); 	// kopirovaci instruktor
	virtual ~Port() { delete [] brand; }
	Port & operator=(const Port & p);
	Port & operator+=(int b); 	// prida b lahvi
	Port & operator-=(int b); 	// odepise b lahvi, pokud existuji
	int BottleCount() const { return bottles; }
	virtual void Show() const;
	friend ostream & operator<<(ostream & os, const Port & p);
};

Metoda Show() prezentuje informace v nasledujicim tvaru:
Brand: Gallo
Kind: tawny
Bottles: 20
Funkce operator<<() vypisuje informace v nasledujicim formatu (bez znaku noveho radku
na konci):
Gallo, tawny, 20

Spravce dokoncil definice metod tridy Port a potom odvodil nasledujici tridu VintagePort.
Potom vsak byl ze sveho mista propusten, nebot omylem poslal jednu lahev Cockburnu rocnik 1945 osobe pripravujici pokusnou omacku na opekani masa.

#include "port.h"
class VintagePort : public Port // polozka style musi mit hodnotu "vintage"
{
private:
	char * nickname;	// napriklad "The Neble" nebo "Old Velvet" atd.
	int year; 	// rocnik
public:
	VintagePort();
	VintagePort(const char * br, int b, const char * nn, int y);
	VintagePort(const VintagePort & vp);
	~VintagePort() { delete [] nickname; }
	VintagePort & operator=(const VintagePort & vp);
	void Show() const;
	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

Vasim ukolem je dokonceni tridy VintagePort:
a. Prvnim ukolem je vytvorit znovu definice metod trid Port, protoze drivejsi spravce
sve definice pri propusteni znicil.
b. Dalsim ukolem je vysvetlit, proc jsou nektere metody predefinovany a jine ne.
c. Tretim ukolem je vysvetlit, proc funkce operator=() a operator<<() nejsou virtualni.
d. Ctvrtym ukolem je vytvorit definice metod tridy VintagePort.
*/

#include<iostream>
#include "port.h"
#include "vintageport.h"

const int LEN = 50;
const int arrSize = 2;

int main()
{
	using namespace std;

	char brand[LEN];
	char style[LEN];
	int bottles;
	char nickname[LEN];
	int year;
	int choice;
	Port* arr[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cout << "Object " << i + 1 << endl;
		cout << "Enter the brand: ";
		cin.getline(brand, LEN);
		cout << "Enter the number of bottles: ";
		cin >> bottles;
		cin.get(); 
		cout << "Enter 1 if you would like this to be a Port object" << endl;
		cout << "Enter 2 if you would like this to be a Vintage Port object";
		cout << endl;
		cin >> choice;
		cin.get(); 

		switch (choice)
		{
		case 1:
			cout << "Enter the style: ";
			cin.getline(style, LEN);
			arr[i] = new Port(brand, style, bottles);
			break;
		case 2:
			cout << "Enter the nickname: ";
			cin.getline(nickname, LEN);
			cout << "Enter the year: ";
			cin >> year;
			cin.get(); 	
			arr[i] = new VintagePort(brand, bottles, nickname, year);
			break;
		default:
			cout << "Wrong input. Making a default Port object";
			cout << endl;
			arr[i] = new Port();
			break;
		}
	}

	cout << "\nList:" << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << "Element " << i+1 << endl;
		arr[i]->Show();
	}

	for (int i = 0; i < arrSize; i++)
	{
		cout << "Element " << i+1 << endl;
		cout << *arr[i] << endl;
	}
	cout << "Bye!" << endl;


	return 0;
}