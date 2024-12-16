/*
Chap_18_Ex_03
3. Napiste a vyzkoustejte funkci variadicke sablony
sum_values(), ktera prijme libovolne dlouhy
seznam argumentu s numerickymi hodnotami (mohou byt
ruznych typu) a vrati jejich sumu v podobe
hodnoty long double.
*/

#include <iostream>

template<typename T>
long double sum_values(const T & var1)
{
    return var1;
}


template <typename T, typename...Types>
long double sum_values(const T& var1, const Types&...var2)
{
    return (long double)var1 +  sum_values(var2...);
}

int main()
{
    std::cout << sum_values(1, 2, 3.14, 3.86) << std::endl;
    return 0;
}
