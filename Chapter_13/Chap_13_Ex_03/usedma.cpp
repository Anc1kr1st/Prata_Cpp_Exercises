/*
Chap_13_03
Upravte tridy baseDMA-lacksDMA-hasDMA tak, aby vsechny tri byly odvozeny od stejne
abstraktni zakladni tridy. Vysledek overte pomoci programu podobneho tomu z vypisu
13.10. To znamena, ze by mel mit pole ukazatelu na abstraktni zakladni tridu a umoznit
uzivateli cinit rozhodnuti v dobe behu programu v tom smyslu, jakeho typu jsou
vytvarene objekty. K definici tridy pridejte virtualni metody View() na vypis dat.
*/
// usedma.cpp -- dedicnost, prátelé a DMA
// preložit s dma.cpp
#include <iostream>
#include "dma.h"

const int TRIEDY = 3;
const int LEN = 40;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	basebaseDMA* base_Triedy[TRIEDY];

	for (int i = 0; i < TRIEDY; i++)
	{
		char temp[LEN];
		char farba[LEN];
		char styl[LEN];
		int tempNum;
		int choice;

		cout << "Zadajte oznacenie: " << endl;
		cin.getline(temp, LEN);
		cout << "Zadajte hodnotenie: " << endl;
		cin >> tempNum;
		cin.get();
		cout << "Vyberte miesto ulozenia: \n1. baseDMA\n 2. lacksDMA \n3. hasDMA" << endl;
		while (cin >> choice)
		{
			if (choice == 1)
			{
				cin.get();
				base_Triedy[i] = new baseDMA(temp, tempNum);
				break;
			}
			else if (choice == 2)
			{
				cin.get();
				cout << "Zadajte aj farbu: " << endl;
				cin.getline(farba, LEN);
				base_Triedy[i] = new lacksDMA(farba, temp, tempNum);
				break;
			}
			else if (choice == 3)
			{
				cin.get();
				cout << "Zadajte aj styl: " << endl;
				cin.getline(styl, LEN);
				base_Triedy[i] = new hasDMA(styl, temp, tempNum);
				break;
			}
			else
				cin.get();
				cout << "Zly vyber. Zadajte znovu." << endl;
		}
	}

	cout << "Vypis: " << endl;

	for (int i = 0; i < TRIEDY; i++)
	{
		cout << i + 1 << ": " << endl;
		base_Triedy[i]->View();
		delete base_Triedy[i];
	}

	return 0;
}

