/*
Chap_14_Ex_05
Zde je nekolik deklaraci trid:
// emp.h -- hlavickovy soubor tridy employee a jejich potomku

#include <iostream>
#include <string>

class abstr_emp
{
private:
    std::string fname;    // jmeno abstr_emp
    std::string lname;    // prijmeni abstr_emp
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string &  ln,
             const std::string &  j);
    virtual void ShowAll() const;    // vsechna data labels a shows
    virtual void SetAll();        // vyzadej hodnoty od uzivatele
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    // vypis jmeno a prijmeni
    virtual ~abstr_emp() = 0;         // virtualni zakladni trida
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string &  ln,
             const std::string &  j);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager:  virtual public abstr_emp
{
private:
    int inchargeof;        // pocet zpracovavanych abstr_emps
protected:
    int InChargeOf() const { return inchargeof; } // vypis
    int & InChargeOf(){ return inchargeof; }      // vstup
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink: virtual public abstr_emp
{
private:
    std::string reportsto;        // komu fink hlasi
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo(){ return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink: public manager, public fink // ypracovani fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

Vsimnete si, ze hierarchie trid pouziva vicenasobnou dedicnost s virtualni zakladni tridou, pamatujte tedy na specialni pravidla pro inicializacni seznamy konstruktoru v takovem pripade. Vsimnete si take, ze datove polozky jsou deklarovany jako chranene a ne jako soukrome. Tim se zjednodusi kod pro nekterou z metod tridy highfink. (Vsimnete si napriklad, ze metoda highfink::ShoAll() vola jen metody fink::ShoAll() a manager::ShoAll() a zaverem zavola dvakrat metodu abstr_emp::ShowAll().) Vytvorte implementace metod trid a vyzkousejte je v programu. Zde je minimalni testovaci program.
// pe14-5.cpp
// useempl.cpp -- using the abstr_emp classes

#include <iostream>
using namespace std;
#include "emp.h"

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();


    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");  // nabor?
    hf.ShowAll();
    cout << "Pro dalsi fazi stisknete klavesu:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Pouziti ukazatele abstr_emp *:\n";
    abstr_emp  * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();

    return 0;
}

Proc neni definovan operator prirazeni?
Proc jsou metody Showall() a Setall() virtualni?
Proc je trida abstr_emp virtualni zakladni tridou?
Proc nema trida highfink zadnou datovou cast?
Proc staci pouze jedna verze funkce operator<<()?
Co by se stalo, kdyby kod na konci programu byl zamenen nasledujicim kodem?
employee tri[]4 = {th, db, mo, hf};
for (int i = 0; i < 4; i++)
tri[i].showall();
*/


// pe14-5.cpp
// useempl.cpp -- using the abstr_emp classes

#include <iostream>
using namespace std;
#include "emp.h"

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();


    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");  // nabor?
    hf.ShowAll();
    cout << "Pro dalsi fazi stisknete klavesu enter:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Pouziti ukazatele abstr_emp *:\n";
    abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();

    return 0;
}
