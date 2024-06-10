#include "move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << "x = " << this->x << endl;
	cout << "y = " << this->y << endl;
	return;
}

Move Move::add(const Move& m) const
{
	Move o(m.x + this->x, m.y + this->y);
	return o;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
	return;
}
