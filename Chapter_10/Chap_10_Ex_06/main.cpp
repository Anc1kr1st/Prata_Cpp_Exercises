/*
Chap_10_Ex_06
Zde je deklarace tridy:
class Move
{
private:
double x;
double y;
public:
Move(double a = 0, double b = 0); 	// nastavi x, y na a, b
showmove() const;
Move add(const Move & m) const;
// funkce prida promennou x objektu m do promenne x volajiciho objektu a
// ziska novou promennou x, prida promennou y objektu m do promenne y
// volajiciho objektu a ziska novou promennou y, vytvori novy objekt
// move
// inicializovany na nove hodnoty x a y a objekt vrati
reset(double a = 0, double b = 0);	// nastavi x, y na a, b
};
Pridejte definice clenskych funkci a program pozivajici tuto tridu.
*/

#include "move.h"

int main(void) {

	Move pohyb;
	cout << "Default values: " << endl;

	pohyb.showmove();

	cout << "Own values: " << endl;
	Move pohyb2(1, 2);
	pohyb2.showmove();

	cout << "Reset default values. New values: \n";
	pohyb.reset(3, 3);
	pohyb.showmove();

	cout << "Values together: \n";
	pohyb = pohyb.add(pohyb2);
	pohyb.showmove();

	return 0;
};
