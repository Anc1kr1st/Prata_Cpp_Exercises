#include "stack.h"

Stack::Stack()
{
	top = 0;
}

bool Stack::isempty() const
{
	if (0 == top)
		return true;
	else
		return false;
}
bool Stack::isfull() const
{
	if (MAX == top)
		return true;
	else
		return false;
}
bool Stack::push(const Item& item)
{
	if (0 == isfull())
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}
bool Stack::pop(Item& item)
{
	if (0 == isempty())
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
