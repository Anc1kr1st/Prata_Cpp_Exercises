/*
Chap_18_Ex_01
1. Nize vidite cast kratkeho programu:
int main()
{
    using namespace std;

    // seznam hodnot double odvozeny z obsahu seznamu
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;

    // seznam hodnot int odvozeny z obsahu seznamu
    cout << average_list({20,30,19,45,38}) << endl;

    // vynuceny seznam hodnot double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}

Dokoncete program tak, ze nahradite funkci average_list(). Melo
by se jednat o funkci sablony.
Typ parametru urci typ sablony initialized_list pouzite jako
funkci parametr a take k urceni navratoveho typu.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <initializer_list>

template <typename T>
T average_list(std::initializer_list<T> val);

int main()
{
    using namespace std;

    // seznam hodnot double odvozeny z obsahu seznamu
    auto q = average_list({ 15.4, 10.7, 9.0 });
    cout << q << endl;

    // seznam hodnot int odvozeny z obsahu seznamu
    cout << average_list({ 20,30,19,45,38 }) << endl;

    // vynuceny seznam hodnot double
    auto ad = average_list<double>({ 'A', 70, 65.33 });
    cout << ad << endl;
    return 0;
}

template <typename T>
T average_list(std::initializer_list<T> val)
{
    T sum = 0;
    int count = 0;
    for (auto iter = val.begin(); iter != val.end(); iter++, ++count)
    {
        sum += (*iter);
    }
    return sum / count;

}
