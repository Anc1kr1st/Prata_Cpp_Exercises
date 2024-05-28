/*
Chap_10_Ex_01
Vytvorte definice metod tridy popsane v otazce cislo 5 a napiste kratky program, ilustrujici moznosti teto tridy.
5. Definujte tridu predstavujici bankovni ucet. Datove polozky by mely obsahovat jmeno vkladatele, cislo uctu (pouzijte retezec) a zustatek. Clenske funkce by mely umoznovat:
- Vytvorit objekt a inicializovat ho.
- Priradit datovym slozkam pocatecni hodnoty.
- Zobrazit jmeno vkladatele, cislo uctu a zustatek na uctu.
- Ulozit castku penez zadanou jako parametr.
- Vybrat castku penez zadanou jako parametr.
...
*/

#include "bankAccount.h"

int main() {

	BankAccount myAcc;

	myAcc.CreateAccount("Jozko Mrkvicka", "1234567890", 100);
	myAcc.BalanceEnquiry();
	myAcc.Deposit(5000);
	myAcc.BalanceEnquiry();
	myAcc.Withdraw(10000);
	myAcc.BalanceEnquiry();
	myAcc.Withdraw(450);
	myAcc.BalanceEnquiry();

	return 0;
}
