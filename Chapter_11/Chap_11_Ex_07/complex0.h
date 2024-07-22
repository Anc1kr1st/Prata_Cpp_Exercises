// complex0.h
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include<iostream>

class Complex
{
private:
	double a;
	double b;

public:
	Complex();
	Complex(double a, double b = 0);
	~Complex() {}
	// void set(double a, double b);
	friend Complex operator+(const Complex& c1, const Complex& c2);
	friend Complex operator-(const Complex& c1, const Complex& c2);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend Complex operator*(double d, const Complex& c2);
	friend Complex operator~(const Complex& c);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istream& os, Complex& c);
};
#endif
