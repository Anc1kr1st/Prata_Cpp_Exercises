/*
Chap_08_Ex_06
Napiste sablonu funkce maxn(), ktera prijima jako argumenty pole polozek typu T a cele cislo 
reprezentujici pocet prvku pole a jez vraci jeho nejvetsi prvek. Sablonu otestujte v programu, 
ktery pouziva sablonu funkce s poli o sesti hodnotach typu int a styrech typu double. Progrtam 
by mel take obsahovat specializaci, ktera prebira pole ukazatelu na char jako jeden argument a 
pocet ukazatelu jako druhy argument a jez vraci adresu  nejdelsiho retezce. Jestlize existuje 
vice nejdelsich retezcu, funkce vrati adresu prvniho nejdelsiho. Otestujte specializaci pomoci 
pole o peti retezcovych ukazatelich.

*/
#include <iostream>
#include <cstring>

using namespace std;

const int n = 10;
const int m = 5;


template <typename T>
T maxn(T pole[], int);

template <> 
const char* maxn(const char * pole2[], int);

int main()
{

	int j = 1;
	cout << "Enter 6 whole numbers and 4 double numbers.\n";
	double ar[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Number " << j << ": \n";
		cin >> ar[i];
		j++;
	}

	cout << "Largest number is: " << maxn(ar, n) << endl;

	char jedna[] = "Jednasto";
	char dva[] = "Dva";
	char tri[] = "Tri";
	char styri[] = "Styristo";
	char pat[] = "Pat";

	const char* dlzka[5] = {jedna, dva, tri, styri, pat};


	cout << "Largest element is: " << maxn(dlzka, m) << endl;


	return 0;
}

template <typename T>
T maxn(T pole[], int n)
{

	T large = pole[0];

	for (int i = 0; i < n; i++)
	{
		if (large < pole[i])
		{
			large = pole[i];
			continue;
		}
		else
		{
			continue;
		}
	}
	return large;
}

template <> 
const char* maxn(const char* pole2[], int n)
{
	const char* longest = pole2[0];

	for (int i = 0; i < n; i++)
	{
		if (strlen(pole2[i]) > strlen(longest))
		{
			longest = pole2[i];
		}
		
	}
	return longest;
}
