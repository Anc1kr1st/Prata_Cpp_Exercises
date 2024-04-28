/*
Chap_08_Ex_07
Upravte program z vypisu 8.14 tak, aby sablonove funkce vracely soucet obsahu pole 
namisto zobrazovani obsahu. Program by mel zobrazovat celkovy pocet veci a soucet dluhu.
*/

#include <iostream>
#include <cstring>

template <typename T>
T ShowArray(T arr[], int n);

template <typename T>
T ShowArray(T* arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
		{ "Ima Wolfe", 2400.0 },
		{ "Ura Foxe", 1300.0 },
		{ "Iby Stout", 1800.0 }
	};
	double* pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Vypis souctu veci pana E:\n";

	cout << ShowArray(things, 6) << endl;
	cout << "Vypis souctu dluhu pana E:\n";
	cout << ShowArray(pd, 3) << endl;

	return 0;
}

template <typename T>
T ShowArray(T arr[], int n)
{
	using namespace std;

	T spolu = 0;
	for (int i = 0; i < n; i++)
	{
		spolu = spolu + arr[i];
	}
	return spolu;
}

template <typename T>
T ShowArray(T* arr[], int n)
{
	using namespace std;

	T spolu2 = 0;
	for (int i = 0; i < n; i++)
	{
		spolu2 = spolu2 + *arr[i];
	}

	return spolu2;
}