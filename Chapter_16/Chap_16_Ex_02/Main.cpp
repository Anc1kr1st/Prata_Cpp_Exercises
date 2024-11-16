/*
Chap_16_Ex_02
2. Reste problem jako v programovacim cviceni c. 1, avsak tentokrat vezmete
v uvahu velka pismena, mezery i interpunkci. Retezec "Vedu utop v potu u dev"
bude tedy palindrom. Testovaci funkce by napriklad mohla retezec zredukovat
na "veduutopvpoptuudev" a potom overit, zda se cte stejne zepredu i zezadu.
Nezapomente na uzitecnou knihovnu cctype. Vhodne, i kdyt nikoli nezbytne
funkce muzete najit take v knihovne STL.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool isPal(std::string& s);

int main()
{
    std::cout << "Enter palindrome (q for quit): ";
    std::string word;
    while (std::getline(std::cin, word) && word != "q")
    {
        if (isPal(word) == true)
        {
            std::cout << word << " is a palindrome!\n";
        }
        else {
            std::cout << word << " is not a palindrome!\n";
        }
    }
    std::cout << "Bye!\n";
    return 0;
}

bool isPal(std::string& s)
{

    std::string temp;

    for (int i = 0; i < s.size(); i++)
    {

        if (isalpha(s[i]))                              
        {
            temp.push_back(tolower(s[i]));             
        }
    }


    for (int i = 0, j = temp.size() - 1; i <= j; i++, j--)      
    {
        if (temp[i] != temp[j])         
        {
            return false;
        }
    }
    return true;

}
