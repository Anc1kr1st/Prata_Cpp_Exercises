/*
Chap_16_Ex_04
4. Mate za ukol napsat funkci podle rozhrani ve starem stylu. Prototyp
je nasledujici:
int reduce(long ar[], int n);
Parametry tvori nazev pole a pocet prvku v poli. Funkce pole se tridi,
odstrani duplicitni hodnoty a vrati hodnotu odpovidajici poctu prvku ve
zredukovanem poli. Pri psani teto funkce vyuzijte funkci knihovny STL.
(Pokud se rozhodnete pozit generickou funkci unique(), nezapomente, ze
vraci konec vysledneho rozsahu). Funkci vyzkousejte v kratkem programu.
*/


#include <algorithm>
#include <iostream>
#include <vector>

long array[] = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 };
int max_num = 12;

int reduce(long ar[], int n);


int main()
{

	reduce(array, max_num);

	return 0;
}

int reduce(long ar[], int n)
{

	std::vector<long> v;
	std::vector<long>::iterator ip;

	for (int i = 0; i < n; i++)
		v.push_back(ar[i]);

	std::sort(v.begin(), v.end());

	ip = std::unique(v.begin(), v.begin() + n);
	v.resize(std::distance(v.begin(), ip));

	for (ip = v.begin(); ip != v.end(); ++ip) {
		int i = 0;
		i++;
		std::cout << *ip << " ";
		ar[i] = *ip;
	}
	return v.size();
}
