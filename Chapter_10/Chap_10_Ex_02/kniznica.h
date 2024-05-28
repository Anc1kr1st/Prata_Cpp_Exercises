#ifndef KNIZNICA_H_
#define KNIZNICA_H_


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person {
private:
	static const int LIMIT = 25;
	string lname;		// Prijmeni
	char fname[LIMIT];		// Krestni jmeno
public:
	Person();	// #1
	Person(const string& ln, const char* fn = "Heyyou");  	//#2
	// nasledujici metody zobrazi lname a fname
	void Show() const;	// Format Krestni jmeno Prijmeni
	void FormalShow() const;	// Format Prijmeni Krestni jmeno
};

#endif // !KNIZNICA_H_