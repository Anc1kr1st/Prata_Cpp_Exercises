/*
Chap_16_Ex_07
7. Beznou hrou je loterijni listek. Obsahuje cislovane puntiky, z nichz je
nahodne vybran urcity pocet. Napiste funkci Lotto() obsahujici dva parametry.
Prvnim je pocet puntiku na loterijnim listku a druhym pocet nahodne vybranych
puntiku. Funkce vrati objekt tridy vector<int>, v nemz budou nahodne vybrana
cisla setridena. Funkci byste mohli pouzit napriklad nasledujicim zpusobem:
vector<int> winners;
winners = Lotto(51, 6);
Zde je objektu winners prirazen objekt tridy vector s sesti nahodne vybranymi
cisly z intervalu od 1 do 51. Vsimnete si, ze proste pouziti funkce rand()
nestaci, nebot se mohou objevit duplicitni hodnoty. Navrh: vytvorte ve funkci
objekt tridy vector s ruznymi hodnotami, pouzijte funkci random_shuffle() a
potom tyto hodnoty ctete ze zacatku takto upraveneho vektoru. Napiste take
kratky program, ktery funkci overi.
*/


#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand

std::vector<int> Lotto(int m, int n);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    std::vector<int> winners;
    winners = Lotto(51, 6);

    // print out content:
    std::cout << "Victory nummers:";
    std::vector<int>::iterator it;
    for (it = winners.begin(); it != winners.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}

std::vector<int> Lotto(int m, int n)
{
    std::srand(unsigned(std::time(0)));

    // set some values:
    std::vector<int> values;
    for (int i = 1; i < m + 1; ++i) 
        values.push_back(i);

    // using built-in random generator:
    std::random_shuffle(values.begin(), values.end());

    // pick numbers
    std::vector<int> random;
    for (int i = 0; i < n; i++)
        random.push_back(values[i]);

    return random;
}
