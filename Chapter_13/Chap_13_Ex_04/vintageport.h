// vintageport.h
#ifndef VINTAGEPORT_H_
#define VINTAGEPORT_H_

#include "port.h"
class VintagePort : public Port // polozka style musi mit hodnotu "vintage"
{
private:
	char* nickname;	// napriklad "The Neble" nebo "Old Velvet" atd.
	int year; 	// rocnik
public:
	VintagePort();
	VintagePort(const char* br, int b, const char* nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort() { delete[] nickname; }
	VintagePort& operator=(const VintagePort& vp);
	void Show() const;
	friend ostream& operator<<(ostream& os, const VintagePort& vp);
};

#endif