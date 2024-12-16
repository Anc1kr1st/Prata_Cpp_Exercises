/*
Chap_18_Ex_02
2 . Zde je deklarace tridy Cpmv:
class Cpmv
{
    public:
        struct Info
        {
            std::string qcode;
            std::string zcode;
        };
    private:
        Info * pi;
    public:
        Cpmv();
        Cpmv(std::string q, std::string z);
        Cpmv(const Cpmv & cp);
        Cpmv(Cpmv && mv);
        ~Cpmv() {std::cout << "Object "<< (void *)pi <<" Deleted\n";delete pi;}
        Cpmv & operator=(const Cpmv & cp);
        Cpmv & operator=(Cpmv && mv);
        Cpmv operator+(const Cpmv & obj) const;
        void Display() const;
};
Funkce operator+() by mela vytvorit objekt, jehoz
clenove qcode a zcode zretezi odpovidajici
cleny operandu. Dopiste kod, ktery presunovemu
konstruktoru a operatoru prirazeni zajisti
presunovou semantiku. Napiste program ktery pouzije
vsechny uvedene metody. Pro ucely testovani
ponechte metodam rezim s komentarem, abyste videli,
kdy se pouziji.
*/


//main 
#include <iostream>
// #include <utility> nullptr
#include "Cpmv_h.h"

int main()
{

    Cpmv s1;
    s1.Display();

    Cpmv s2("test1", "test2");
    s2.Display();

    Cpmv s3(s2);
    s3.Display();

    Cpmv s4(std::move(s2));
    s4.Display();

    s1 = s3;
    s1.Display();

    Cpmv text("text1", "text2");
    s1 = text + s3;
    s1.Display();

    return 0;

}

