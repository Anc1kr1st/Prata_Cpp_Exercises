// classic.cpp
#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic(const char* initial, const char* s1,
	const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	strncpy(initialWork, initial, 19);
	initialWork[19] = '\0';
}

Classic::Classic(const char* initial, Cd& d) : Cd(d)
{
	strncpy(initialWork, initial, 19);
	initialWork[19] = '\0';
}
/*
Classic::Classic(const Classic & c) : Cd(c)
{
	strncpy(primary_work, c.primary_work, len_primary-1);
	primary_work[len_primary-1] = '\0';
}
*/

Classic::Classic() : Cd()
{
	initialWork[0] = '\0';
}

Classic::~Classic()
{

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
	strncpy(initialWork, d.initialWork, 19);
	initialWork[19] = '\0';
	return *this;
}
