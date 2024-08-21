//classic.h
#include "cd.h" 
#include<iostream> 


class Classic : public Cd {
private:
	char *initialWork;

public:
	Classic(const char * initial, const char* s1, const char* s2, int n, double x);
	Classic(const char * initial, const Cd& d);
	Classic();
	~Classic();
	virtual void Report() const; 	// vypise vsechna data na CD
	Classic& operator=(const Classic& d);


	// pridate znakove pole pro retezec, ktery
	// bude identifikovat prvotni praci na disku

};
