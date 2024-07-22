// 11.10
//mytime3h -- Trida Time se spratelenymi funkcemi
#ifndef MYTIME_h_3
#define MYTIME_h_3
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time& t1, const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend Time operator*(const Time& t, double mult);
	friend Time operator*(double mult, const Time& t)
	{
		return t * mult;
	}  // inline definice
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};
#endif
