// 11.13
// vector.h -- Trida Vector s operatorem << a rezimem stavu (mode)
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
	class Vector
	{
	private:
		double x;  // horizontalni hodnota
		double y;  // vertikalni hodnota
		char mode;  // 'r' = pravouhly, 'p' = polarni
		// soukrome metody pro nastaveni hodnot
		// void set_mag();
		// void set_ang();
		void set_x(double, double);
		void set_y(double, double);

	public:
		Vector();
		Vector(double n1, double n2, char form = 'r');
		void set(double n1, double n2, char form = 'r');
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const;
		double angval() const;
		void polar_mode();
		void rect_mode();
		// funkce pro pretizen operatoru
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		// spratelene funkce
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};

} // konec jmenneho prostoru VECTOR
#endif