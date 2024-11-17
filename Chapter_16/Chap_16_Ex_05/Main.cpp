/*
Chap_16_Ex_05
5. Reste stejny problem jako v programovacim cviceni c. 3, ale z funkce
udelejte sablonu:
template<class T>
int reduce(T ar[], int n);
Vyzkoustejte funkci v kratkem programu s instancemi typu long a string.
*/


#include <algorithm>
#include <iostream>
#include <set>

template <class T>
int reduce(T ar[], int n);

int main()
{
    long array[] = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 };
    int max_num = 12;
    std::string words[] = { "hello", "friend", "socks", "ball", "hello", "pen", "glasses", "pen", "lamp", "cookies", "hello" ,"apple" };

    int display = reduce(array, max_num);
    std::cout << "Count: " << display << std::endl;

    display = reduce(words, max_num);
    std::cout << "Count: " << display << std::endl;

    return 0;
}

template <class T>
int reduce(T ar[], int n)
{
    int num_amount = 0;

    std::set<T> v(ar, ar + n);
    typename std::set<T>::iterator ip;

    for (ip = v.begin(); ip != v.end(); ip++)
    {
        std::cout << *ip << " ";
        num_amount++;
    }

    return num_amount;
}
