/*
Chap_06_Ex_03
Napiste predchudce programu rizeneho nabidkou. Program by mel zobrazit nabidku se ctyrmi 
volbami oznacenymi pismeny. Pokud uzivatel zada jine pismeno, nez urcuji tyto ctyri platne 
volby, mel by ho program vyzyvat, aby vlozil platnou odpoved, dokud tak neucini. Potom by 
mel program pouzit prepinac na vyber jednoduche akce zalozene na uzivatelove vyberu. Beh 
programu by mohl vypadat nasledovne:
Prosim, vyberte jednu z nasledujicich moznosti:
m) masozravec    p) pianista
s) strom         h) hra
f
Prosim, zadejte m, p, s, nebo h: k
Prosim, zadejte m, p, s, nebo h: s
Javor je strom.
*/

#include <iostream>

using namespace std;

void showmenu();

int main()
{
	showmenu();
	char choice;
	cin >> choice;

	while (choice != 'm' && choice != 'p' && choice != 's' && choice != 'h')
	{
		cout << "Please, enter m, p, s, or h: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 'm': cout << "Lion is carnivore.";
		break;
	case 'p': cout << "Beethoven was pianist.";
		break;
	case 's': cout << "Oak is three.";
		break;
	case 'h': cout << "Hockey is game.";
		break;
	}

	return 0;
}

void showmenu()
{
	cout << "Please, choose one of the following options: \n";
	cout << "m) carnivore   p) pianist \n";
	cout << "s) three       h) game \n";
}
