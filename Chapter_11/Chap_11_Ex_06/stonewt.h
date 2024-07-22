// 11.16
// stonewt.h -- definice tridy Stonewt
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;

public:
	Stonewt(double lbs);  // konstruktor typu double pro libry
	Stonewt(int stn, double lbs);  // konstruktor pro kameny, libry
	Stonewt();  //implicitni konstruktor
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;

	friend bool operator<(const Stonewt& s1, const Stonewt& s2);
	friend bool operator>(const Stonewt& s1, const Stonewt& s2);
	friend bool operator>=(const Stonewt& s1, const Stonewt& s2);
	friend bool operator<=(const Stonewt& s1, const Stonewt& s2);
	friend bool operator==(const Stonewt& s1, const Stonewt& s2);
	friend bool operator!=(const Stonewt& s1, const Stonewt& s2);
};
#endif
