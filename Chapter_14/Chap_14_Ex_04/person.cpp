// person.cpp 
#include "person.h"
#include <iostream>
#include <cstring>

Person::Person(const char* fn, const char* ln)
{
    std::strncpy(fname, fn, Len - 1);
    fname[Len - 1] = '\0';
    std::strncpy(lname, ln, Len - 1);
    lname[Len - 1] = '\0';
}

void Person::set()
{
    std::cout << "Enter first name: ";
    std::cin.getline(fname, Len);
    std::cout << "Enter last name: ";
    std::cin.getline(lname, Len);
}
void Gunslinger::set()
{
    Person::set();
    std::cout << "Enter draw time: ";
    std::cin >> drawtime;
    std::cout << "Enter number of notches: ";
    std::cin >> notches;
}

void Gunslinger::show() const
{
    Person::show();
    std::cout << ": " << drawtime << " drawtime, " << notches
        << " notches\n";
}
