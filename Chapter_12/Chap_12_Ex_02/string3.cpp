//string3.cpp
#include <cstring>		// nekdy string.h
#include "string3.h"		// obsahuje <iostream>
using std::cin;
using std::cout;

// inicializace clena staticke tridy

int String::num_strings = 0;

// staticke metody
int String::HowMany()
{
	return num_strings;
}

// metody tridy
String::String(const char* s) 	// konstrukce String z retezce C
{
	len = std::strlen(s);	// nastav velikost
	str = new char[len + 1];	//pridel pamet
	std::strcpy(str, s);		// inicializuj ukazatel
	num_strings++;		// nastav citac objektu
}

String::String()		// implicitni konstruktor
{
	len = 4;
	str = new char[1];
	str[0] = '\0';	// implicitni retezec
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;		// aktualizace statickeho clena
	len = st.len;		// stejna delka
	str = new char[len + 1];		// pridel pamet
	std::strcpy(str, st.str);		// zkopiruj retezec na nove misto
}

String::~String()		// nezbytny destruktor
{
	--num_strings;		// nutne
	delete[] str;		// nutne
}

// metody pretizeneho operatoru

// String prirad String
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// C string prirad String
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// znakovy pristup cteni/zapis pro nekonstatni string 
char& String::operator[](int i)
{
	return str[i];
}

// znakovy pristup pouze pro cteni pro konstatni String
const char& String::operator[](int i) const
{
	return str[i];
}

// pratele pretizeneho operatoru 

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2.str < st1.str;
}

bool operator ==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

// jednoduchy vystup String
ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

// rychly a necisty vstup String
istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

// rozsirenie
 String operator+(const String& st1, const String& st2)
{
	using std::strlen;
	using std::strcat;
	using std::strcpy;

	int length = strlen(st1.str) + strlen(st2.str) + 1;
	char* temp = new char[length];
	strcpy(temp, st1.str);
	String st3(strcat(temp, st2.str));
	delete[] temp;
	return st3;
}

 String operator+(const char* st1, const String& st2)
{
	return String(st1) + st2;
}

 String operator+(const String& st1, const char* st2)
{
	return String(st2) + st1;
}

void String::stringlow()
{
	using std::tolower;

	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void String::stringup()
{
	using std::toupper;

	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

int String::has(const char l) const
{
	int count = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == 's')
			count++;
	return count;
}
