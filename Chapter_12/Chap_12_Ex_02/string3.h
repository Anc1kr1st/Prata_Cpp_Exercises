//string3.h
#include <iostream>
#include "ctype.h"
using std::ostream;
using std::istream;

#ifndef STRING3_H_
#define STRING3_H_

class String
{
private:
	char* str;  	// ukazatel na retezec
	int len; 	// delka retezce
	static int num_strings;	// pocet objektu
	static const int CINLIM = 80; 	// vstupni limit cin

public:
	// konstruktory a dalsi metody
	String(const char* s);
	String(); 	//implicitni konstruktor
	String(const String&);		//kopiruj konstruktor
	~String(); 		//destruktor
	int length() const { return len; }
	// metody pretizeneho operatoru
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;
	// pratele pretizeneho operatoru
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);
	// staticka funkce
	static int HowMany();

	// rozsirenie triedy
	friend String operator+(const String& st1, const String& st2);
	friend String operator+(const char* st1, const String& st2);
	friend String operator+(const String& st1, const char* st2);
	void stringlow();
	void stringup();
	int has(const char l) const;  

};
#endif
