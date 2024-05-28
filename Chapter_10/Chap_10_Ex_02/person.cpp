#include "kniznica.h"

Person::Person() {
	lname = "";
	fname[0] = '\0';
}

Person::Person(const string& ln, const char* fn) {
	lname = ln;
	strncpy_s(fname, fn, LIMIT - 1);
	fname[LIMIT - 1] = '\0';
}

void Person::Show() const {
	cout << "Informal \n";
	cout << "Vorname: " << fname << endl;
	cout << "Name: " << lname << endl;
}
void Person::FormalShow() const {
	cout << "Formal \n";
	cout << "Name: " << lname << endl;
	cout << "Vorname: " << fname << endl;
}
