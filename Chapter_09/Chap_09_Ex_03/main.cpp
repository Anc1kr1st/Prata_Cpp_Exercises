/*
Chap_09_Ex_03
Nejdrive deklarujte nasledujici strukturu:
struct chaff
{
char dross[20];
int slag;
};

Pote napiste program, ktery pouziva operator new s umistnenim, na umisteni pole do dvou 
takovych struktur v poli buffer. Dale priradte clenum struktury hodnoty (pro pole typu 
char nezapomente pouzit strcpy()) a k vypisu obsahu vytvorte cyklus. Volba 1 je pouziti 
statickeho pole pro buffer podobne jako ve vypisu 9.9. Volba 2 je k alkokaci pole buffer 
pouzit normalni operatoru new.
*/

#include <iostream>
#include <new>
#include<cstring>

using namespace std;

struct chaff
{
	char dross[20];
	int slag;
};

const int BUF = 500;
char buffer[BUF];

int main()
{

	chaff* p1;
	p1 = new (buffer) chaff[2];

	int i = 0;

	cout << "Enter name of dross " << i + 1 << ": ";
	char dross[20];
	cin.get(dross, 20);
	cin.get();

	strcpy_s(p1[i].dross, dross);

	cout << "Enter value of dross " << i + 1 << ": ";
	cin >> p1[i].slag;
	cin.get();

	i++;

	cout << "Enter name of dross " << i + 1 << ": ";
	cin.get(dross, 20);
	cin.get();

	strcpy_s(p1[i].dross, dross);

	cout << "Enter value of dross " << i + 1 << ": ";
	cin >> p1[i].slag;
	cin.get();

	for (int j = 0; j < i + 1; j++)
	{
		cout << "Dross " << j + 1 << ": "
			<< p1[j].dross << endl;
		cout << "Slag : " << p1[j].slag << endl;
	}

	return 0;
}
