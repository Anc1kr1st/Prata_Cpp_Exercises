/*Chap_05_Ex_02
Napiste program, ktery bude pozadovat zadavani cisel a po kazdem vstupu vpise narustajici soucet 
vsech doposud zadanych cisel. Program ukonci svou cinnost po zadani cisla 0.
*/

#include <iostream>

using namespace std;

int main() {

	int input;
	int result = 0;
	const int zero = 0;

	cout << "Enter number.\n";
	cout << "0 for exit.\n";

	while (cin >> input && input != zero) {

		result = result + input;

		cout << "Sum of all entered numbers is: " << result << endl;
		cout << "Enter number.\n";
		cout << "0 for exit.\n";
	}

	cout << "Goodbye!";

	return 0;
}
