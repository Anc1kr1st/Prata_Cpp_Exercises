// port.h
#ifndef PORT_H_
#define PORT_H_

#include<iostream>
#include <cstring>
using namespace std;

class Port
{
private:
	enum { lengthStyle = 20 };
	char* brand;
	char style[lengthStyle]; 	// tzn. zlatava barva, rubinova barva, rocnik
	int bottles;
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p); 	// kopirovaci instruktor
	virtual ~Port() { delete[] brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b); 	// prida b lahvi
	Port& operator-=(int b); 	// odepise b lahvi, pokud existuji
	int BottleCount() const { return bottles; }
	virtual void Show() const;
	friend ostream& operator<<(ostream& os, const Port& p);
};

#endif