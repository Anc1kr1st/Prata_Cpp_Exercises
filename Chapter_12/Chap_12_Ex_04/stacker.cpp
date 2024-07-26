/*
Chap_12_Ex_04
Uvazujte nasledujici variantu tridy Stack, definovane ve vypisu 10.10:
// stack.h -- deklarace tridy pro zasobnik ADT
typedef unsigned long Item;

class Stack
{
private:
enum {MAX = 10};	// specificka konstanta tridy
Item * pitems;		// obsahuje polozky zasobniku
int size;		// pocet prvku v zasobniku
int top;		// index polozky na vrcholu zasobniku
public:
Stack(int n = 10);	// vytvori zasobnik s n prvky
Stack(const Stack & st);
~Stack();
bool isempty() const;
bool isfull() const;
// push() vrati False, jestlize je zasobnik jiz plny, jinak True
bool push(const Item & item); 	//prida polozky do zasobniku
// pop() vrati False, jestlize je zasobnik jiz prazdny, jinak True
bool pop(Item & item);
// do promenne item
Stack operator=(const Stack & st);
};

Jak napovidaji soukrome datove polozky, pouziva tato trida pro ulozeni polozek dynamicky 
vytvorene pole. Prepiste  metody podle teto nove reprezentace a napiste program demonstrujici 
vsechny tyto metody vcetne kopirovaciho konstruktoru a operatoru prirazeni.
*/

// stacker.cpp -- Stack
#include <iostream>
#include <cctype>	// nebo ctype.h
#include "stack.h"

int main()
{
	using std::cout;
	using std::cin;

	Stack st(3);	// vytvori prazdny zasobnik
	char ch;
	unsigned long po;

	cout << "Pro pridani objednavky zadejte P,\n"
		<< "Pro zpracovani Z, pro ukonceni K.\n";

		while (cin >> ch && toupper(ch) != 'K')
		{
			while (cin.get() != '\n')
				continue;
			if (!isalpha(ch))
			{
				cout << '\a';
				continue;
			}
			switch (ch)
			{
			case 'P':
			case 'a': cout << "Zadejte cislo objednavky: ";
				cin >> po;
				if (st.isfull())
					cout << " zasobnik je jiz plny \n";
				else
					st.push(po);
				break;
			case 'Z':
			case 'z': if (st.isempty())
				cout << " zasobnik je jiz prazdny \n";
					else {
				st.pop(po);
				cout << " Objednavka c. " << po << " byla"
					" zpracovana\n";
			}
					break;
			}
			cout << "Pro pridani objednavky zadejte P,\n"
				<< "Pro zpracovani Z, pro ukonceni K.\n";
		}
	cout << "Nashledanou\n";
	return 0;
}
