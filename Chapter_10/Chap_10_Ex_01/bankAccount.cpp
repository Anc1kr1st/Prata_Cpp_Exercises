#include "bankAccount.h"

void BankAccount::CreateAccount(string meno, string ucet, double zostatok) {
	name = meno;
	account = ucet;
	balance = zostatok;
}

void BankAccount::BalanceEnquiry() {
	cout << "Account owner: " << name << endl;
	cout << "Account number: " << account << endl;
	cout << "Balance: " << balance << endl << endl;
}

void BankAccount::Deposit(double vklad) {
	balance = balance + vklad;
}

void BankAccount::Withdraw(double vyber) {
	if (vyber > balance) {
		cout << "You cannot withdraw more than the balance." << endl << endl;
	}
	else {
		balance = balance - vyber;
	}
}
