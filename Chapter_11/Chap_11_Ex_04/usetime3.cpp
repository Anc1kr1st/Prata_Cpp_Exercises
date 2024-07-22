/*
Chap_11_Ex_04
Prepiste posledni priklad tridy Time (vypisy 11.10, 11.11 a 11.12) tak, aby 
vsechny pretizene operatory byly implementovany jako pratelske funkce.
*/
// 11.12
// usetime3.cpp -- pouziti ctvrteho navrhu tridy Time
// spolecna kompilace soboru usetime3.cpp a mytime3.cpp
#include <iostream>
#include "mytime3.h"
int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;
	cout << "Aida a Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10 * Tosca: " << 10 * tosca << endl;

	return 0;
}