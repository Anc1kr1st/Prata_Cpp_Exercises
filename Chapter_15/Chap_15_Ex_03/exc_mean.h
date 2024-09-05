// exc_mean.h -- trídy výjimek pro hmean(), gmean()
#include <iostream>
#include <string>
#include <stdexcept> 

class bad_hmean : public std::invalid_argument
{
private:
	double hv1;
	double hv2;
public:
	explicit bad_hmean(const std::string& what_arg, double val1 = 0.0, double val2 = 0.0)
		: std::invalid_argument(what_arg), hv1(val1), hv2(val2) {}
	void mesg() const;
};

inline void bad_hmean::mesg() const
{
	std::cout << "hmean(" << hv1 << ", " << hv2 << "): "
		<< "chybne argumenty: a = -b\n";
}

class bad_gmean : public std::domain_error
{
public:
	double gv1;
	double gv2;

	explicit bad_gmean(const std::string& what_arg, double val1, double val2)
		: std::domain_error(what_arg), gv1(val1), gv2(val2) {}
	void mesg() const;
};

inline void bad_gmean::mesg() const
{
	std::cout << "argumenty gmean() musi byt >= 0\n";
}

