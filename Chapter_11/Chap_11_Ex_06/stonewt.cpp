
// 11.17
// stonewt.cpp -- metody Stonewt
#include <iostream>
using std::cout;
#include "stonewt.h"

// vytvoreni objektu stonewt z hodnoty typu double
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

// vytvoreni objektu Stonewt ze stone, hodnoty double
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}


Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{

}

void Stonewt::show_lbs() const
{
	cout << stone << " kamenu, " << pds_left << " liber\n";
}

void Stonewt::show_stn() const
{
	cout << pounds << " liber\n";
}

bool operator<(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds < s2.pounds;
}

bool operator>(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds > s2.pounds;
}

bool operator>=(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds >= s2.pounds;
}

bool operator<=(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds <= s2.pounds;
}

bool operator==(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds == s2.pounds;
}

bool operator!=(const Stonewt& s1, const Stonewt& s2)
{
	return s1.pounds != s2.pounds;
}

