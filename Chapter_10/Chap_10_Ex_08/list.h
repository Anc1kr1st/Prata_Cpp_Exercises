#pragma once
#include<iostream>
// #include<cstring>

using namespace std;
typedef double Item;

class List {
private:
	enum { MAX = 10 };
	Item items[MAX];
	int index;
public:
	List();
	void add(const Item& item);
	bool isEmpty(void) const;
	bool isFull(void) const;
	void visit(void (*pf)(Item&));
	int numberOfItems(void) const { return index; }
	void printList(void) const;
};
