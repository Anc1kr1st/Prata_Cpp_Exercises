#include "library.h"

// zkopiruje 4 nebo n (podle toho, ktere cislo je mensi)
// polozek z pole ar do clenu sales struktury s
// a spocita a ulozi hodnoty average (prumer), maximum a minimum
// zbyle prvky pole sales, pokud budou, nastavi na 0

namespace SALES
{

void setSales(Sales& s, const double ar[], int n)
{
	double docAverage = 0;
	double docMax = ar[0];
	double docMin = ar[0];

	for (int i = 0; i < n; i++) {

		s.sales[i] = ar[i];

		docAverage = docAverage + ar[i];
		s.average = docAverage / (i+1);

		if (docMax <= ar[i])
		{
			docMax = ar[i];
			s.max = ar[i];
		}

		if (docMin >= ar[i])
		{
			double docMin = ar[i];
			s.min = ar[i];
		}
	}

	while (n < 4)
	{
		s.sales[n] = 0;
		n++;
	}

}


// ziska informace o prodejich za ctvrteli interaktivne
// ulozi je do clenu sales struktury s a spocita a ulozi hodnoty

void setSales(Sales& s)
{

	for (int i = 0; i < 4; i++) {
		cout << "Enter sales " << i+1 << ": ";
		cin >> s.sales[i];
		cin.get();
	}

	double docAverage = 0;
	double docMax = s.sales[0];
	double docMin = s.sales[0];

	for (int i = 0; i < 4; i++) {
		docAverage = docAverage + s.sales[i];
		s.average = docAverage / (i+1);

		if (docMax <= s.sales[i])
		{
			docMax = s.sales[i];
			s.max = s.sales[i];
		}

		if (docMin >= s.sales[i])
		{
			docMin = s.sales[i];
			s.min = s.sales[i];
		}
	}

}
	// zobrazi vsechny informace struktury s

	void showSales(const Sales & s)
	{
		for (int i = 0; i < 4; i++) {
			cout << "Sale " << i+1 << ": " << s.sales[i] << endl;
		}

		cout << "Min " << s.min << endl;
		cout << "Max " << s.max << endl;
		cout << "Average " << s.average << endl << endl;
	}
}