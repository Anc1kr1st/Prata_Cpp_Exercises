// Cpmv

#include "Cpmv_h.h"

Cpmv::Cpmv()
{
    std::cout << "Default constructor\n";
    pi = new Info;

    pi->qcode = "0000"; 
    pi->zcode = "0000";
}


Cpmv::Cpmv(std::string q, std::string z)
{
    std::cout << "Constructor\n";
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}


Cpmv::Cpmv(const Cpmv& cp)
{
    std::cout << "Copy constructor \n";
    pi = new Info;
    *pi = *cp.pi;
    
  /*  pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;*/
    
}


Cpmv::Cpmv(Cpmv&& mv) 
{
    std::cout << "Move constructor\n";
   /* mv.pi->qcode = " ";
    mv.pi->zcode = " ";*/

    pi = mv.pi;
    mv.pi = nullptr; // The keyword nullptr denotes the pointer literal.
}


Cpmv & Cpmv ::operator=(const Cpmv& cp)
{
    std::cout << "Copy assignment\n";
    if (this == &cp)
    {
        return *this;
    }
    delete pi;
    pi = new Info;
    *pi = *cp.pi;
    return *this;
}


Cpmv & Cpmv :: operator=(Cpmv&& mv) 
{
    std::cout << "Move assignment\n";
    if (this == &mv)
    {
        return *this;
    }
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}


Cpmv Cpmv :: operator+(const Cpmv& obj) const
{
    std::cout << "Operator+\n";
    
    return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
    
    /*Cpmv temp;
    temp.pi->qcode = pi->qcode + obj.pi->qcode;
    temp.pi->zcode = pi->zcode + obj.pi->zcode;
    return temp;*/
}

void Cpmv::Display() const
{
    std::cout << "qcode = " << pi->qcode << ", zcode = " << pi->zcode << std::endl;
}
