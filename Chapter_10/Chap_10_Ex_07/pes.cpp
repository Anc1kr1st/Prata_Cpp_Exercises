#include "pes.h"

Pes::Pes(const char* name)
{
	strncpy_s(this->name, name, MAX);
	IS = 50;
}

void Pes::varIS(int IS)
{
	this->IS = IS;
	return;
}

void Pes::show(void) const
{
	cout << "Name of dog: \n";
	cout << name << endl;
	cout << "IS of dog: \n";
	cout << IS << endl;
	return;
}
