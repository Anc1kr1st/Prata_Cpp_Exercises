/*
Chap_13_02
Zopakujte cviceni 1 s tim, ze tentokrat pro ruzne retezce techto dvou trid pouzijete
misto poli pevne delky dynamicky pridelenou pamet.
*/
//main.cpp

#include<iostream>
using namespace std;
#include "classic.h" 	// obsahuje #include cd.h
void Bravo(const Cd& disk);
int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano sonata in b flat, Fantasia in C", "Alfred Brendel", "Phillips", 2, 57.17);
	Cd* pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report(); 	// pouzije metodu tridy Cd
	c2.Report(); 	// pouzije metodu tridy Classic

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); 	// pouzije pro objekt tridy Cd metodu tridy Cd
	pcd = &c2;
	pcd->Report(); 	// pouzije pro objekt tridy Classic metodu tridy Classic

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: \n";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk)
{
	disk.Report();
}
