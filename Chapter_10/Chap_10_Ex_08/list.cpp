#include "list.h"

List::List()
{
	index = 0;
}

void List::add(const Item& item)
{
	if (isFull() == 0)
		items[index++] = item;
	else
		cout << "List is full. Cannot add more items." << endl;
}

bool List::isEmpty() const
{
	if (0 == index)
		return true;
	else
		return false;
}
bool List::isFull() const
{
	if (MAX == index)
		return true;
	else
		return false;
}
void List::visit(void (*pf)(Item&))
{
	for (int i = 0; i < index; i++)
		(*pf)(items[i]);
}
void List::printList(void) const
{

	if (isEmpty())
	{
		cout << "No list to print." << endl;
		return;
	}
	else
	{

		for (int i = 0; i < index; i++)
			cout << "Item " << i + 1 << ": " << items[i] << endl;
	}
}
