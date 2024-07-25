// cow.cpp
#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow()             // konstruktor
{
    name[0] = '/0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)      // explicitny konstruktor
{

    strcpy_s(name, nm);

    /*
    strncpy(name, nm, 19);
    name[19] = '\0';
    */

    hobby = new char[strlen(ho) + 1];
    strcpy_s(hobby, strlen(ho) + 1, ho);

    weight = wt;

}

Cow::Cow(const Cow & c)
{

    strcpy_s(name, c.name);

    hobby = new char[strlen(c.hobby) + 1];
    strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);

    weight = c.weight;

}

Cow::~Cow()
{
    delete[] hobby;
}

Cow & Cow::operator=(const Cow& c)
{
    if (this == &c)
        return *this;

    delete[] hobby;
    strcpy_s(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);

    weight = c.weight;

    return *this;
}

void Cow::ShowCow() const
{
    cout << " Name: " << name << endl;
    cout << "Hobby: " << (NULL == hobby ? "NULL" : hobby) << endl;
    cout << " Weight: " << weight << endl;
}

