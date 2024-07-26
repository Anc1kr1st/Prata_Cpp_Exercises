// stack.cpp -- clenske funkce tridy Stack
#include "stack.h"
Stack::Stack(int n) 		// vytvoreni zasobniku
{
    size = n;
    pitems = new Item[size];

    top = 0;
}

Stack::Stack(const Stack& st)
{
    pitems = new Item[st.size];
    for (int i = 0; i < st.size; i++)
        pitems[i] = (st.pitems)[i];
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item& item)
{
    if (top < MAX)
    {
        pitems[top++] = item;
        size++;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item& item)
{
    if (top > 0)
    {
        item = pitems[--top];
        size--;
        return true;
    }
    else
        return false;
}

Stack & Stack::operator=(const Stack& st)
{
    if (this == &st)
        return *this;
    delete[] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < size; i++)
        pitems[i] = (st.pitems)[i];
    return *this;
}
