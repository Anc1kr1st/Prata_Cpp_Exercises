// vintageport.cpp
//#include "port.h"
#include "vintageport.h"

VintagePort::VintagePort()
	: Port("Old Velvet", "vintage")
{
	nickname = NULL;
	year = 1950;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
	: Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strncpy(nickname, nn, strlen(nn) + 1);

	year = y;
}

VintagePort::VintagePort(const VintagePort& vp)
	: Port(vp)
{
	int length = strlen(vp.nickname);
	nickname = new char[length + 1];
	strcpy(nickname, vp.nickname);

	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	Port::operator=(vp);

	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);

	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{

	Port::Show();
	cout << "Prezyvka: " << nickname << endl;
	cout << "Rocnik: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << (const Port&)vp;
	// if (NULL == vp.nickname)
	os << vp.nickname << ", " << vp.year;
	return os;
}
