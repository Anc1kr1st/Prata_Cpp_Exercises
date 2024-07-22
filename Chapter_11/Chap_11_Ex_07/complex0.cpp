// complex0.cpp 
#include "complex0.h"
#include<iostream>
using std::cout;

Complex::Complex()
{
	a = 0;
	b = 0;
}

Complex::Complex(double a, double b)
{
	this->a = a;
	this->b = b;
}
/*
void Complex::set(double a, double b)
{
	this->a = a;
	this->b = b;
}
*/
Complex operator+(const Complex& c1, const Complex& c2)
{
	Complex sum;
	sum.a = c1.a + c2.a;
	sum.b = c1.b + c2.b;
	return sum;
}

Complex operator-(const Complex& c1, const Complex& c2)
{
	Complex diff;
	diff.a = c1.a - c2.a;
	diff.b = c1.b - c2.b;
	return diff;
}

Complex operator*(const Complex& c1, const Complex& c2)
{
	Complex multi;
	multi.a = c1.a * c2.a - c1.b * c2.b;
	multi.b = c1.a * c2.b + c1.b * c2.a;
	return multi;
}

Complex operator*(double d, const Complex& c)
{
	Complex multi;
	multi.a = c.a * d;
	multi.b = c.b * d;
	return multi;
}

Complex operator~(const Complex& c)
{
	Complex conj;
	conj.a = c.a;
	conj.b = -c.b;
	return conj;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "(" << c.a << ", " << c.b << "i)";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
	is >> c.a;
	is >> c.b;
	return is;
}