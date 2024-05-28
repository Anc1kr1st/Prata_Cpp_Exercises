/*
Chap_09_Ex_04
Napiste trisouborovy program zalozeny na nasledujicim jmennem prostoru:
namespace SALES
{
const int QUARTERS = 4;
struct Sales
{
double sales[QUARTERS];
double average;
double max;
double min;
};

// zkopiruje 4 nebo n (podle toho, ktere cislo je mensi)
// polozek z pole ar do clenu sales struktury s
// a spocita a ulozi hodnoty average (prumer), maximum a minimum
// zbyle prvky pole sales, pokud budou, nastavi na 0
void setSales(Sales & s, const double ar[], int n);

// ziska informace o prodejich za ctvrteli interaktivne
// ulozi je do clenu sales struktury s a spocita a ulozi hodnoty
void setSales(Sales & s);

// zobrazi vsechny informace struktury s
void showSales(const Sales & s);
}
Prvnim souborem by mel byt hlavickovy soubor obsahujici jmenny prostor. Druhym souborem by mel byt soubor zdrojoveho kodu rozsirujici jmenny prostor o definice odpovidajici trem zadanym prototypum funkci. Treti soubor by mel deklarovat dva objekty typu Sales. Dale by mel pouzit interaktivni verzi funkce setSales() pro ziskani hodnot pro strukturu a neinteraktivni verzi funkce setSales() pro poskutnuti hodnot pro druhou strukturu. Obsah obou struktur byste potom meli zobrazit funkci setSales().
*/

#include "library.h"

using namespace SALES;

int main()
{

	Sales neInteraktivna;
	Sales Interaktivna;

	double sales[3];
	sales[0] = 10.10;
	sales[1] = 20.20;
	sales[2] = 30.30;

	setSales(neInteraktivna, sales, 3);
	setSales(Interaktivna);

	showSales(neInteraktivna);
	showSales(Interaktivna);

	return 0;
}

