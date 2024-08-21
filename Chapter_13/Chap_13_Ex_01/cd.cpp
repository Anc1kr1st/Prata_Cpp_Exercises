//cd.cpp
#include "classic.h" 
#include<iostream> 
#include<cstring> 

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strncpy(performers, s1, 49);
	performers[49] = '\0';
	strncpy(label, s2, 19);
	label[19] = '\0';

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strncpy(performers, d.performers, 50);
	strncpy(label, d.label, 20);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{

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

Cd & Cd::operator=(const Cd& d)
{
	strncpy(performers, d.performers, 50);
	strncpy(label, d.label, 20);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
