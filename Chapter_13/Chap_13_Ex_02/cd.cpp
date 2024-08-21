//cd.cpp
#include "classic.h" 
#include<iostream> 
#include<cstring> 

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	strncpy(performers, s1, strlen(s1) + 1);

	label = new char[strlen(s2) + 1];
	strncpy(label, s2, strlen(s2) + 1);

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	int docas1 = strlen(d.performers);
	performers = new char[docas1 + 1];
	strncpy(performers, d.performers, docas1 + 1);

	int docas2 = strlen(d.label);
	label = new char[docas2 + 1];
	strncpy(label, d.label, docas2 + 1);

	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = NULL;
	label = NULL;
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	using std::cout;
	using std::endl;

	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Play time: " << playtime << endl;
}

Cd & Cd :: operator=(const Cd& d)
{
	int docas1 = strlen(d.performers);
	performers = new char[docas1 + 1];
	strncpy(performers, d.performers, docas1 + 1);

	int docas2 = strlen(d.label);
	label = new char[docas2 + 1];
	strncpy(label, d.label, docas2 + 1);

	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
