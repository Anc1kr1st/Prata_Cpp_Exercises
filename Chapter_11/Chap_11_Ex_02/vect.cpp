// 11.14
// vect.cpp -- metody tridy Vector
#include <cmath>
#include "vector.h"
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR
{

	const double Rad_to_deg = 57.2957795130823;

	// soukrome metody 
	// vypocti velikost z x a y
	/*void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	*/
	//  nastav x z polarni souradnice
	void Vector::set_x(double mag, double ang)
	{
		x = mag * cos(ang);
	}

	//  nastav y z polarni souradnice
	void Vector::set_y(double mag, double ang)
	{
		y = mag * sin(ang);
	}

	// verejne metody 
	Vector::Vector()  // implicitni konstruktor
	{
		x = y = 0.0;
		mode = 'r';
	}

	// vytvor vektor z pravouhlych souradnic, je-li tvar r (implicitne) nebo 
	// z polarnich souradnic, je-li tvar p 
	Vector::Vector(double n1, double n2, char form)
	{
		mode = form;
		if (form == 'r')
		{
			x = n1;
			y = n2;
		}
		else if (form == 'p')
		{
			set_x(n1, n2 / Rad_to_deg);
			set_y(n1, n2 / Rad_to_deg);
		}
		else
		{
			cout << "nespravny 3. argument ve Vector() -- vector nastaven na 0\n";
			x = y = 0.0;
			mode = 'r';
		}
	}

	// nastav vektor z pravouhlych souradnic, je-li forma r (implicitni), jinak z polarnich souradnic, je-li forma p 
	void Vector::set(double n1, double n2, char form)
	{
		mode = form;
		if (form == 'r')
		{
			x = n1;
			y = n2;
		}
		else if (form == 'p')
		{
			set_x(n1, n2 / Rad_to_deg);
			set_y(n1, n2 / Rad_to_deg);
		}
		else
		{
			cout << "nespravny 3. argument ve Vector() -- vektor nastaven na 0\n";
			x = y = 0.0;
			mode = 'r';
		}
	}
	Vector::~Vector()  // destruktor
	{
	}

	void Vector::polar_mode()  // nastav polarni rezim
	{
		mode = 'p';
	}

	void Vector::rect_mode()  // nastav pravouhly rezim
	{
		mode = 'r';
	}

	double Vector::magval() const
	{
		return sqrt(x * x + y * y);
	}

	double Vector::angval() const
	{
		if (x == 0.0 && y == 0.0)
			return 0.0;
		else
			return atan2(y, x);
	}

	// pretizeni operatoru
	// pridej dva operatory Vector
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	// odecti Vector b od a
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	// obrat znamenko Vector
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	// vynasob Vector krat n
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	// pratelske metody
	// vynasob n krat Vector a
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	// je-li rezim r, vypis pravouhle souradnice, jinak vypis polarni souradnice (rezim p)
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == 'r')
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == 'p')
		{
			os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
		}
		else
			os << "neplatny rezim objektu Vector";
		return os;
	}
} // konec jmenneho prostoru VECTOR