// classic.cpp
#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic(const char* initial, const char* s1,
	const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	int docas = strlen(initial);
	initialWork = new char[docas + 1];
	strncpy(initialWork, initial, docas + 1);
}

Classic::Classic(const char* initial, const Cd& d) : Cd(d)
{
	strncpy(initialWork, initial, 19);
	initialWork[19] = '\0';
}
/*
Classic::Classic(const Classic & c) : Cd(c)
{
int docas = strlen(c.primary_work);
initialWork = new char[docas + 1];
strncpy(primary_work, c.primary_work);
}
*/

Classic::Classic() : Cd()
{
	initialWork = NULL;
}

Classic::~Classic()
{
	delete[] initialWork;
}

void Classic::Report() const
{
	using std::cout;
	using std::endl;

	Cd::Report();
	cout << "Initial Work: " << initialWork << endl;
}

Classic & Classic :: operator=(const Classic& d)
{
	Cd::operator=(d);
	int docas = strlen(d.initialWork);
	initialWork = new char[docas + 1];
	strncpy(initialWork, d.initialWork, docas + 1);
	return *this;
}

