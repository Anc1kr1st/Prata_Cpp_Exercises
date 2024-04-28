/*
Chap_07_Ex_06
Napiste program, ktery pouziva nasledujici funkce:
fill_arr() prebira jako argumenty jmeno pole typu double a jeho velikost. Tato funkce pozada 
uzivatele o zadani hodnot typu double, ktere budou ulozeny do pole. Zadavani vstupu se zastavi, 
kdyz je pole plne nebo kdyz uzivatel zada neciselnou hodnotu. Funkce bude vracet skutency pocet 
vlozenych cisel.
Show_array() prebira jako argumenty jmeno pole typu double a jeho velikost a zobrazi obsah pole.
Reverse_array() prebira jako argumenty jmeno pole typu double a jeho velikost a obrati poradi 
hodnot ulozenych v poli.
Vlastni program by mel naplnit pole, vypsat je, zamenit poradi vsech prvku krome prvniho a 
posledniho a znovu pole vypsat.
*/

#include <iostream>

double Fill_arr(double arr[], int x);
void Show_array(double arr[], int j);
void Reverse_array(double arr[], int j);

using namespace std;

const int maxA = 5;
int real = 0;

int main()
{
	double pole[maxA];


	Fill_arr(pole, maxA);

	Show_array(pole, real);
	Reverse_array(pole, real);
	Show_array(pole, real);

	return 0;
}

double Fill_arr(double arr[], int x)
{
	double z;
	cout << "Enter values. Max 5. Enter  non-numeric value for early termination: \n";

	int n;
	for (int n = 0; n < x; n++)
	{
		cin >> z;
		cin.get();

		if (cin.fail())
		{
			break;
		}

		arr[n] = z;

		real++;
	}

	return 0;
}

void Show_array(double arr[], int j)
{
	cout << "Show array: \n";

	for (int i = 0; i < j; i++)
	{
		cout << arr[i] << endl;
	}
}

void Reverse_array(double arr[], int j)
{

	// cout << "Reverse array: \n";

	int newJ = j - 1;
	double A, B;

	for (int i = 0; i < j; i++)
	{
		A = arr[i];
		B = arr[newJ];

		arr[i] = B;
		arr[newJ] = A;

		newJ--;
		j--;
	}
}
