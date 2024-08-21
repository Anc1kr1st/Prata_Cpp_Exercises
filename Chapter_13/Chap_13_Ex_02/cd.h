//cd.h 

#ifndef CD_h_
#define CD_h_
#include <iostream>

class Cd { 		// reprezentuje CD disk
private:
	char *performers;
	char *label;
	int selections;		// pocet volieb
	double playtime;		// hraci doba v minutach 

public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	~Cd();
	virtual void Report() const; 	// vypise vsechna data na CD
	Cd& operator=(const Cd& d);
};

#endif
