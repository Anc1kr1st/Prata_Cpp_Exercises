// sales.h -- výjimky a dedicnost
#ifndef SALES_H_
#define SALES_H_
#include <stdexcept>
#include <cstring>

class Sales
{
public:
	enum { MONTHS = 12 }; // mùže být statická konstanta
	class bad_index : public std::logic_error
	{
	private:
		int bi; // chybná hodnota indexu
	public:
		explicit bad_index(int ix, const char* s = "Chyba indexu v objektu Sales\n");
		int bi_val() const { return bi; }
		virtual ~bad_index() throw() {}
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() { }
	int Year() const { return year; }
	virtual double operator[](int i) const;
	virtual double& operator[](int i);
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales
{
public:
	static const int STRLEN = 50; // mùže být enum
	class nbad_index : public Sales::bad_index
	{
	private:
		char lbl[STRLEN];
	public:
		nbad_index(const char* lb, int ix,
			const char* s = "Chyba indexu v objektu LabeledSales\n");
		const char* label_val() { return lbl; }
		virtual ~nbad_index() throw() {}
	};
	explicit LabeledSales(const char* lb = "none", int yy = 0);
	LabeledSales(const char* lb, int yy, const double* gr, int n);
	virtual ~LabeledSales() { }
	const char* Label() const { return label; }
	virtual double operator[](int i) const;
	virtual double& operator[](int i);
private:
	char label[STRLEN];
};
#endif
