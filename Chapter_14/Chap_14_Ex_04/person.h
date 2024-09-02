// person.h 
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <cstring>
#include <cstdlib>

const int Len = 20;
class Person
{
private:
    char fname[Len];
    char lname[Len];
public:
    Person() { fname[0] = lname[0] = '\0'; }
    Person(const char* fn, const char* ln);
    virtual ~Person() {}
    virtual void show() const { std::cout << fname << " " << lname; }
    virtual void set();
};

class Gunslinger : virtual public Person
{
private:
    double drawtime;
    int notches;
public:
    Gunslinger() : Person("Joe", "Doe"), drawtime(0.0),
        notches(0) { }
    Gunslinger(const char* fn, const char* ln,
        double d = 1.0, int n = 0) : Person(fn, ln),
        drawtime(d), notches(n) { }
    Gunslinger(const Person& p, double d = 1.0, int n = 0) :
        Person(p), drawtime(d), notches(n) { }
    virtual ~Gunslinger() {}
    // Person(p) is the default copy constructor
    double draw() const { return drawtime; }
    void show() const;
    void set();
};

class PokerPlayer : virtual public Person
{
public:
    PokerPlayer() : Person("Busted", "Strait") {}
    PokerPlayer(const char* fn, const char* ln) : Person(fn, ln) {}
    PokerPlayer(const Person& p) : Person(p) {}
    virtual ~PokerPlayer() {}
    int draw() const { return std::rand() % 52 + 1; }
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude() : Person("Bad", "Dude"), Gunslinger() {}
    BadDude(const char* fn, const char* ln,
        double d = 1.0, int n = 0) : Person(fn, ln),
        Gunslinger(fn, ln, d, n) { }
    BadDude(const Person& p, double d = 1.0, int n = 0) :
        Person(p), Gunslinger(p, d, n) { }
    double gdraw() const { return Gunslinger::draw(); }
    int cdraw() const { return PokerPlayer::draw(); }
    void show() const { Gunslinger::show(); }
    void set() { Gunslinger::set(); }
};


#endif
