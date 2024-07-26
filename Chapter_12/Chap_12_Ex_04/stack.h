// stack.h -- deklarace tridy pro zasobnik ADT

#ifndef _STACK_H_
#define _STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };	// specificka konstanta tridy
	Item* pitems;		// obsahuje polozky zasobniku
	int size;		// pocet prvku v zasobniku
	int top;		// index polozky na vrcholu zasobniku 

public:
	Stack(int n = 10);	// vytvori zasobnik s n prvky
	Stack(const Stack& st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	// push() vrati False, jestlize je zasobnik jiz plny, jinak True 
	bool push(const Item& item); 	//prida polozky do zasobniku
	// pop() vrati False, jestlize je zasobnik jiz prazdny, jinak True
	bool pop(Item& item);
	// do promenne item
	Stack & operator=(const Stack& st);
};
#endif
