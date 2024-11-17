/*
Chap_16_Ex_08
8. Petr a Pavel chteji pozvat pratele na vecirek. Pozadaji vas o napsani programu,
ktery bude provadet nasledujici cinnost:
- Petr zada seznam jmen svych pratel. Jmena budou ulozena do kontrejneru a po
setrideni zobrazena.
- Pavel zada seznam jmen svych pratel. Jmena budou ulozna do kontrejneru a po
setrideni zobrazena.
- Vytvorte treti kontejner, ve kterem budou oba seznamy slouceny a po vylouceni
duplicit se zobrazi jeho obsah.
*/


#include <iostream>     // std::cout
#include <algorithm>
#include <iterator>
#include <list>
#include <set>
#include <string>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    std::list<string> peter;
    std::list<string> pavol;
    std::list<string> zoznam;

    std::string name;
    int count;

    std::cout << "How many people would Peter like to add?\n";
    std::cin >> count;
    cin.get();

    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter the name who you would like to add: \n";
        getline(std::cin, name);
        peter.push_back(name);
    }

    std::set<std::string> tempPet(peter.begin(), peter.end());       // vytriedi a zoradi
    peter.assign(tempPet.begin(), tempPet.end()); 		// vrati s5


    std::cout << "How many people would Pavol like to add?\n";
    std::cin >> count;
    cin.get();

    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter the name who you would like to add: \n";
        getline(std::cin, name);
        pavol.push_back(name);
    }

    std::set<std::string> tempPav(pavol.begin(), pavol.end());       // vytriedi a zoradi
    pavol.assign(tempPav.begin(), tempPav.end()); 		// vrati s5

    zoznam.merge(peter);
    zoznam.merge(pavol);

    std::set<std::string> t_merge(zoznam.begin(), zoznam.end());                       
    zoznam.assign(t_merge.begin(), t_merge.end());
    std::cout << "Merged List:\n";

    std::list<std::string>::iterator l_iter;
    for (l_iter = zoznam.begin(); l_iter != zoznam.end(); l_iter++)
    {
        std::cout << (*l_iter) << std::endl;
    }


    return 0;
}


