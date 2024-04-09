/*
Chap_06_Ex_02
Napiste program, ktery nacte az 10 hodnot do pole typu double. Tento program by mel ukoncit 
vstup po zadani nenumericke hodnoty. Dale by mel vypsat zpravu o prumeru zadanych cisel a 
kolik cisel v poli ma vetsi hodnotu nez prumer.
*/

#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
	
	double arr[10];
	double avg = 0;
	int hV = 0;
	int j = 0;

	for (int i = 0; i < 10; i++)
	{
		j++;
		cout << "Enter numerical values (max 10). Non-numerical value for quit.\n";
		cout << j << ": ";
		
		cin >> arr[i];

		if (cin.good() == false)
		{
			j--;
			break;
		}

		avg = avg + arr[i];
	}

	avg = avg / j;

	for (int i = 0; i < j; i++)
	{
		if (arr[i] > avg)
		{
			hV++;
		}
	}

	cout << "Average value is " << avg << ".\n";
	cout << hV << " number(s) is bigger than average.";

	return 0;
}