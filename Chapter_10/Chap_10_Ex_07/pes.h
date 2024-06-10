#pragma once
#include<iostream>
#include<cstring>

using namespace std;

class Pes {
private:
	enum { MAX = 20 };
	char name[MAX];
	int IS;
public:
	Pes(const char* name = "Punta");
	void varIS(int IS);
	void show(void) const;
};
