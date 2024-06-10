#pragma once
#include<iostream>

using namespace std;

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0); 	// nastavi x, y na a, b
	void showmove() const;
	Move add(const Move& m) const;
	// funkce prida promennou x objektu m do promenne x volajiciho objektu a
	// ziska novou promennou x, prida promennou y objektu m do promenne y
	// volajiciho objektu a ziska novou promennou y, vytvori novy objekt
	// move
	// inicializovany na nove hodnoty x a y a objekt vrati 
	void reset(double a = 0, double b = 0);	// nastavi x, y na a, b
};
