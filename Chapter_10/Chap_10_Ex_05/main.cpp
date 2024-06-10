/*
Chap_10_Ex_05
Uvazujte nasledujici deklaraci struktury:
struct customer {
char fullname[35];
double payment;
};
Napiste program, ktery pridava struktury uzivatele do zasobniku predstavovaneho deklaraci tridy 
Stack a odebira je odtud. Kdyz je zakaznik odebran, pridejte jeho platbu k mezisouctu a vypiste 
jej. Poznamka: Tridu Stack byste meli pouzit beze zmeny; pouze zmente deklaraci typedef tak, aby 
Item mela misto typu unsigned long typ customer.
*/

#include "stack.h"

int main(void)
{
	double total = 0.0;
	customer Roman = { "Roman", 20.20 };
	customer Ivan = { "Ivan", 30.30 };
	customer Beka = { "Beka", 40.40 };


	cout << "We have three customers: " << endl;
	cout << Roman.fullname << ", " << Roman.payment << " EUR." << endl;
	cout << Ivan.fullname << ", " << Ivan.payment << " EUR." << endl;
	cout << Beka.fullname << ", " << Beka.payment << " EUR." << endl;

	Stack temporary;

	cout << "Push Ivan. " << endl;
	// Stack temporary;

	if (temporary.push(Ivan))
		cout << Ivan.fullname << " pushed successfully!"
		<< endl;
	else
		cout << Ivan.fullname << " not pushed successfully"
		<< endl;

	cout << "Let's pop Ivan." << endl;

	customer out;
	if (temporary.pop(out))
	{
		cout << "Customer " << out.fullname << " popped."
			<< endl;
		total += out.payment;
	}
	else
		cout << "No customers to pop." << endl;
	cout << "Subtotal: " << total;

	return 0;
};
