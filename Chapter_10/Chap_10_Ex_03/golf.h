#ifndef GOLF_H_
#define GOLF_H_

#include<cstring>
#include<iostream>

using namespace std;

class Golf {
private:
    static const int Len = 40;
    int counter;
    char fullname[Len];
    int handicap;

public:
    Golf(const char* name = "", int hc = 0) {
        strncpy_s(fullname, name, Len - 1);
        fullname[Len - 1] = '\0';
        handicap = hc;
    };

        int setgolf();
        void sethandicap(int hc);
        void showgolf() const;
};
#endif 