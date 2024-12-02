// emp.h -- hlavickovy soubor tridy employee a jejich potomku

#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>

class abstr_emp
{
private:
    std::string fname;    // jmeno abstr_emp
    std::string lname;    // prijmeni abstr_emp
    std::string job;
public:
    enum classkind { Employee, Manager, Fink, Highfink };
    abstr_emp() : fname("NONE"), lname("NONE"), job("NONE") {}
    abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);
    virtual void ShowAll() const;    // vsechna data labels a shows
    virtual void SetAll();        // vyzadej hodnoty od uzivatele
    virtual void writeall(std::ofstream& ofs) const;
    virtual void getall(std::ifstream& ifs);
    friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
    // vypis jmeno a prijmeni
    virtual ~abstr_emp() = 0;         // virtualni zakladni trida
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string& fn, const std::string& ln, const std::string& j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream& ofs) const;
    virtual void getall(std::ifstream& ifs);
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;        // pocet zpracovavanych abstr_emps 
protected:
    int InChargeOf() const { return inchargeof; } // vypis
    int& InChargeOf() { return inchargeof; }      // vstup
public:
    manager();
    manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
    manager(const abstr_emp& e, int ico);
    manager(const manager& m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream& ofs) const;
    virtual void getall(std::ifstream& ifs);
};

class fink : virtual public abstr_emp
{
private:
    std::string reportsto;        // komu fink hlasi
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string& ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
    fink(const abstr_emp& e, const std::string& rpo);
    fink(const fink& e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream& ofs) const;
    virtual void getall(std::ifstream& ifs);
};

class highfink : public manager, public fink // zpracovani fink
{
public:
    highfink();
    highfink(const std::string& fn, const std::string& ln,
        const std::string& j, const std::string& rpo,
        int ico);
    highfink(const abstr_emp& e, const std::string& rpo, int ico);
    highfink(const fink& f, int ico);
    highfink(const manager& m, const std::string& rpo);
    highfink(const highfink& h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream& ofs) const;
    virtual void getall(std::ifstream& ifs);
};
#endif
