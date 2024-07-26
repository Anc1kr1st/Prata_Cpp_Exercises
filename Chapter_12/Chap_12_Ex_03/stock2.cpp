//10.8
// stock2.cpp -- Vylepsena verze
#include <iostream>
#include "stock2.h"

// konstruktory 
Stock::Stock()	// implicitni konstuktor
{
    company = new char[std::strlen("bezejmenna") + 1];
    std::strcpy(company, "bezejmenna");

    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char* co, int n, double pr)
{
    int length = std::strlen(co);
    company = new char[length + 1];
    std::strcpy(company, co);


    if (n < 0)
    {
        std::cerr << "Pocet akcii nemuze byt zaporny; akcie "
            << company << " nastaveni shares na 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// destruktor tridy
Stock::~Stock() 	// tichy destruktor tridy
{
}

// ostatni metody
void Stock::buy(int num, double price)
{
    if (num < 0)
    {
        std::cerr << "Pocet nakupovanych akcii nemuze byt zaporny. "
            << "Transakce ukoncena.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    using std::cerr;
    if (num < 0)
    {
        cerr << "Pocet prodavanych akcii nemuze byt zaporny. "
            << "Transakce ukoncena.\n";
    }
    else if (num > shares)
    {
        cerr << "Nemuzete prodat vic akcii nez mate! "
            << "Transakce ukoncena.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream& operator<<(std::ostream& os, const Stock& s)
{
    using std::endl;

    os << "Spolecnost: " << s.company
        << " Akcie: " << s.shares << endl
    << " Cena akcie: $" << s.share_val
        << "  Celkova hodnota: $" << s.total_val << endl;
    return os;
}

/*
void Stock::show()const
{
using std::cout;
using std::endl;
cout << "Spolecnost: " << company
<< " Akcie: " << shares << endl
<< " Cena akcie: $" << share_val
<< " Celkova hodnota: $" << total_val << endl;
}
*/

const Stock& Stock::topval(const Stock& s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
