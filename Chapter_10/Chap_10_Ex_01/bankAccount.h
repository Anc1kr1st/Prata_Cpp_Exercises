#pragma once
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
	string name;
	string account;
	double balance;
public:
	void CreateAccount(string meno, string ucet, double zostatok);
	void BalanceEnquiry();
	void Deposit(double vklad);
	void Withdraw(double vyber);
};
