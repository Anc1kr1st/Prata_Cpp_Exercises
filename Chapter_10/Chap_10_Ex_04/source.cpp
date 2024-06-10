#include "library.h"

// zkopiruje 4 nebo n (podle toho, ktere cislo je mensi)
// polozek z pole ar do clenu sales struktury s
// a spocita a ulozi hodnoty average (prumer), maximum a minimum
// zbyle prvky pole sales, pokud budou, nastavi na 0

namespace SALES
{
	Sales::Sales(const double ar[], int n)
	{
		double docAverage = 0;
		double docMax = ar[0];
		double docMin = ar[0];

		for (int i = 0; i < n; i++) {

			sales[i] = ar[i];

			docAverage = docAverage + ar[i];
			average = docAverage / (i+1);

			if (docMax <= ar[i])
			{
				docMax = ar[i];
				max = ar[i];
			}

			if (docMin >= ar[i])
			{
				docMin = ar[i];
				min = ar[i];
			}
		}

		while (n < 4)
		{
			sales[n] = 0;
			n++;
		}

	}

	// ziska informace o prodejich za ctvrteli interaktivne
	// ulozi je do clenu sales struktury s a spocita a ulozi hodnoty

	void Sales::setSales()
	{

		for (int i = 0; i < QUARTERS; i++) {
			cout << "Enter sales: ";
			cin >> sales[i];
			cin.get();
		}

		double docAverage = 0;
		double docMax = sales[0];
		double docMin = sales[0];

		for (int i = 0; i < QUARTERS; i++) {
			docAverage = docAverage + sales[i];
			average = docAverage / (i+1);

			if (docMax <= sales[i])
			{
				docMax = sales[i];
				max = sales[i];
			}

			if (docMin >= sales[i])
			{
				docMin = sales[i];
				min = sales[i];
			}
		}
	}

		// zobrazi vsechny informace struktury s

		void Sales::showSales() const
		{
			for (int i = 0; i < QUARTERS; i++) {
				cout << "Sale " << i+1 << ": " << sales[i] << endl;
			}
			cout << "Min " << min << endl;
			cout << "Max " << max << endl;
			cout << "Average " << average << endl << endl;
		}
	
}