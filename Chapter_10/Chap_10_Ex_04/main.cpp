/*
Chap_10_Ex_04
Udelejte cviceni cislo 4 z kapitoly 9, prevedte strukturu Sales a jeji funkce na tridu s metodami. 
Funkci setSales(Sales &, double [], int) nahradte konstruktorem. Interaktivni metodu setSales(Sales &) 
implementujte pomoci konstruktoru. Tridu ponechte v jmennem prostoru SALES.
*/

#include "library.h"

int main(void)
{
	SALES::Sales Interaktivna;

	double ar[3] = {10.10, 20.20, 30.30};

	SALES::Sales neInteraktivna(ar, 3);
	

	Interaktivna.setSales();

	neInteraktivna.showSales();
	Interaktivna.showSales();

	return 0;
}
