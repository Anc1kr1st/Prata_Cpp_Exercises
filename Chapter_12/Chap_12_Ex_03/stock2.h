// 10.7
// stock2.h -- vylepsena verze
#ifndef _STOCK2_H_
#define _STOCK2_H_

class Stock
{
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(){ total_val = shares * share_val; }
public:
	Stock();		// implicitni konstruktor
	Stock(const char* co, int n = 0, double pr = 0.0);
	~Stock();		// prazdny destruktor

	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;
	friend std::ostream& operator<<(std::ostream& os, const Stock& s);
};

#endif
