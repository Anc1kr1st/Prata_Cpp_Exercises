// 11.17
// stonewt.cpp -- metody Stonewt
#include <iostream>
using std::cout;
#include "stonewt.h"

// vytvoreni objektu stonewt z hodnoty typu double
Stonewt::Stonewt(double lbs, char st)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;

	if ('1' == st || '2' == st || '3' == st)
		stav = st;
	else
	{
		cout << "Stav musi byt 1, 2 alebo 3. \n";
		cout << "Nastavuje sa na 1.\n";
		stav = '1';
	}
}

// vytvoreni objektu Stonewt ze stone, hodnoty double
Stonewt::Stonewt(int stn, double lbs, char st)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;

	if ('1' == st || '2' == st || '3' == st)
		stav = st;
	else
	{
		cout << "Stav musi byt 1, 2 alebo 3. \n";
		cout << "Nastavuje sa na 1.\n";
		stav = '1';
	}
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	stav = '1';
}

Stonewt::~Stonewt()
{

}

void Stonewt::set_stav(char st)
{
	if ('1' == st || '2' == st || '3' == st)
		stav = st;
	else
	{
		cout << "Stav musi byt 1, 2 alebo 3. \n";
		cout << "Nastavuje sa na 1.\n";
		stav = '1';
	}
}


Stonewt Stonewt::operator+(const Stonewt& b) const
{
	double res_pounds = b.pounds + pounds;
	return Stonewt(res_pounds);
}


Stonewt Stonewt::operator-(const Stonewt& b) const
{
	double res_pounds = b.pounds - pounds;
	return Stonewt(res_pounds);
}

Stonewt operator*(const Stonewt& s, double n)
{
	double tot_pounds = s.pounds * n;
	return Stonewt(tot_pounds);
}

Stonewt operator*(double n, const Stonewt& s)
{
	return n * s;
}
// nvm preco 2x opeator*

/*
void Stonewt::show_lbs() const
{
cout << stone << " kamenu, " << pds_left << " liber\n";
}
void Stonewt::show_stn() const
{
cout << pounds << " liber\n";
}
*/

std::ostream& operator<<(std::ostream& os, const Stonewt& b)
{
	if (b.stav == '1')
		os << b.stone << " stone, " << b.pds_left << " pounds";
	else if (b.stav == '2')
	{
		os << int(b.pounds) << " pounds";
	}
	else if (b.stav == '3')
	{
		os << b.pounds << " pounds";
	}
	else
		os << "neplatny rezim objektu Stonewt";
	return os;
}
