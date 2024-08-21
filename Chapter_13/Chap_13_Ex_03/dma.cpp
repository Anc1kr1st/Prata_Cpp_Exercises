// dma.cpp -- metody tríd DMA

#include "dma.h"
#include <cstring>

// metody basebaseDMA
basebaseDMA::basebaseDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

basebaseDMA::basebaseDMA(const basebaseDMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

 void basebaseDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "Oznaceni: " << label << endl;
	cout << "Hodnoceni: " << rating << endl;
}

basebaseDMA::~basebaseDMA()
{
	delete[] label;
}



basebaseDMA& basebaseDMA::operator=(const basebaseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const basebaseDMA& rs)
{
	os << "Oznaceni: " << rs.label << std::endl;
	os << "Hodnoceni: " << rs.rating << std::endl;
	return os;
}


// metody baseDMA
baseDMA::baseDMA(const char* l, int r) : basebaseDMA(l, r)
{

}

baseDMA::baseDMA(const baseDMA& rs)
{

}

baseDMA::~baseDMA()
{

}

/*
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
	
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "Oznaceni: " << rs.label << std::endl;
	os << "Hodnoceni: " << rs.rating << std::endl;
	return os;
}
*/
// metody lacksDMA 
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: basebaseDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
	: basebaseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const basebaseDMA&)ls;
	os << "Barva: " << ls.color << std::endl;
	return os;
}

// metody hasDMA 
hasDMA::hasDMA(const char* s, const char* l, int r)
	: basebaseDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
	: basebaseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
	: basebaseDMA(hs) 		// volání kopírovacího konstruktoru základní tøídy
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	basebaseDMA::operator=(hs); // kopírování základní èásti
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const basebaseDMA&)hs;
	os << "Styl: " << hs.style << std::endl;
	return os;
}
