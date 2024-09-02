// emp.cpp
#include <iostream>
#include "emp.h"


// class abstr_emp

abstr_emp::abstr_emp() : fname(""), lname(""), job("")
{

}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
: fname(fn), lname(ln), job(j)
{
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::ShowAll() const    // vsechna data labels a shows
{
	using std::cout;
	using std::endl;

	cout << "First Name: " << fname << endl;
	cout << "Last Name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()        // vyzadej hodnoty od uzivatele
{
	using std::cout;
	using std::string;
	using std::cin;
	using std::endl;

	cout << "Enter the first name: ";
	getline(cin, fname);
	//cin.get();
	cout << "Enter the last name: ";
	getline(cin, lname);
	//cin.get();
	cout << "Enter job: ";
	getline(cin, job);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.lname << ", " << e.fname;
	return os;
}

abstr_emp ::~abstr_emp()          // virtualni zakladni trida
{
}

// class employee : public abstr_emp
employee::employee() : abstr_emp()
{

}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
 : abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
	using std::cout;
	using std::endl;
	cout << "Employee" << endl;
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

// class manager:  virtual public abstr_emp
manager::manager()
	: abstr_emp()
{
	inchargeof = 0;
}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
	: abstr_emp(fn, ln, j)
{
	using std::cout;
	using std::endl;
	inchargeof = ico;
}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e)
{
	using std::cout;
	using std::endl;
	inchargeof = ico;
}

manager::manager(const manager& m)
	: abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	using std::cout;
	using std::endl;
	cout << "Manager" << endl;
	abstr_emp::ShowAll();
	cout << "In charge of " << inchargeof << " people." << endl;
}

void manager::SetAll()
{
	using std::cout;
	using std::cin;
	using std::endl;

	abstr_emp::SetAll();

	cout << "Enter the number of people the manager is in charge of: ";
	cin >> inchargeof;
}


// class fink: virtual public abstr_emp

fink::fink()
	: abstr_emp(), reportsto("")
{

}

fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{

}

fink::fink(const abstr_emp& e, const std::string& rpo)
	: abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink& e)
	: abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	using std::cout;
	using std::endl;

	cout << "Fink" << endl;
	abstr_emp::ShowAll();
	cout << "Reports to " << reportsto << endl;
}

void fink::SetAll()
{
	using std::cout;
	using std::endl;
	using std::cin;

	abstr_emp::SetAll();
	cout << "Reported to: ";
	getline(cin, reportsto);
}


// class highfink: public manager, public fink // zpracovani fink

	highfink::highfink()
		: abstr_emp(), manager(), fink()
	{
	}

	highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j,
		const std::string & rpo, int ico)
		: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
	{
	}

	highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
		: abstr_emp(e), manager(e, ico), fink(e, rpo)
	{
	}

	highfink::highfink(const fink & f, int ico)
		: abstr_emp(f), manager(f, ico), fink()
	{
	}

	highfink::highfink(const manager & m, const std::string & rpo)
		: abstr_emp(m), manager(m), fink(m, rpo)
	{
	}

	highfink::highfink(const highfink & h)
		: abstr_emp(h), manager(h), fink(h)
	{
	}

	void highfink::ShowAll() const
	{
		using std::cout;
		using std::endl;

		cout << "Highfink" << endl;
		abstr_emp::ShowAll();
		cout << "In charge of " << InChargeOf() << " people." << endl;
		cout << "Reports to " << ReportsTo() << endl;
	}

	void highfink::SetAll()
	{
		using std::cout;
		using std::endl;
		using std::cin;

		abstr_emp::SetAll();

		cout << "Enter the number of people managed: ";
		cin >> InChargeOf();
		cin.get();

		cout << "Enter whomever is reported to: ";
		getline(cin, ReportsTo());
	}
