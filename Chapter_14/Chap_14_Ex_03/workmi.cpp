/*
Chap_14_Ex_03
Definujte sablonu QueueTp simulujici frontu. Otestuje ji vytvorenim fronty ukazatelu 
na objekt tridy Worker (vypis 14.10) a dale ji pouzijte v programu, ktery bude podobny 
programu z vypisu 14.12.
*/

// workmi.cpp -- vícenásobná dedicnost
// preložit se souborem workermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	QueueTp<Worker*> q;
	Worker* pw;
	pw = NULL;

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Zadejte kategorii zamestnance:\n"
			<< "c: cisnik p: pevec "
			<< "t: zpivajici cisnik k: konec\n";
		cin >> choice;
		while (strchr("cptk", choice) == NULL)
		{
			cout << "Zadejte prosim c, p, t nebo k: ";
			cin >> choice;
		}
		if (choice == 'k')
			break;
		switch (choice)
		{
		case 'c': pw = new Waiter;
			break;
		case 'p': pw = new Singer;
			break;
		case 't': pw = new SingingWaiter;
			break;
		}
		cin.get();
		// lolas[ct]->Set();
		pw->Set();
		q.enqueue(pw);

	}

	cout << "\nZde je vas tym:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		q.dequeue(pw);
		pw->Show();


	}
	for (i = 0; i < ct; i++)
		delete pw;

	cout << "Nashledanou.\n";
	return 0;
}

