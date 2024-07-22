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

	char stav;  // v kamenech, v librach celym cislem nebo 
	//  v librach cislem s pohyblivou radovou carkou

public:
	Stonewt(double lbs, char st = '1');  // konstruktor typu double pro libry
	Stonewt(int stn, double lbs, char st = '1');  // konstruktor pro kameny, libry
	Stonewt();  //implicitni konstruktor
	~Stonewt();
	void set_stav(char st);
	Stonewt operator+(const Stonewt& b) const;
	Stonewt operator-(const Stonewt& b) const;
	friend Stonewt operator*(const Stonewt& s, double n);
	friend Stonewt operator*(double n, const Stonewt& s);

	friend std::ostream& operator<<(std::ostream& os, const Stonewt& b);

	/*
	void show_lbs() const;
	void show_stn() const;
	*/
};
#endif

