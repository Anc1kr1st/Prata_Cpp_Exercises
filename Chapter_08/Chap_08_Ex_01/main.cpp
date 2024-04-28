/*
Chap_08_Ex_01
Napiste funkci, ktera normalne prijima jako jeden argument adresu 
retezce a jednou ho vytiskne. Pokud je vsak dodan druhy nenulovy 
argument typu int, funkce vytiskne retezec tolikrat, kolikrat byla 
do tohoto okamziku zavolana. (Vsimnete si, ze pocet, kolikrat se 
retezec tiskne, neni roven hodnote druheho argumentu; je roven poctu 
volani funkce.) Ano, je to nesmyslna funkce, ale prinuti vas pouzit 
nektere postupy probrane v teto kapitole. Funkci pouzijte v 
jednoduchem programu, ktery ukazuje, jak pracuje.
*/

#include<iostream>

using namespace std;

char stringAdd[15] = "Hello world!";

void echoFun(char *hello, int zero = 0);

int main()
{

	echoFun(stringAdd);
	echoFun(stringAdd);
	echoFun(stringAdd);
	echoFun(stringAdd);
	echoFun(stringAdd, 1);

	return 0;
}

void echoFun(char *hello, int zero)
{
	static int abacus = 0;

	if (zero == 0)
	{
		cout << hello << endl;
		abacus++;
	}
	else
	{
		for (int i = 0; i < abacus; i++)
		{
			cout << hello << endl;
		}
	}

	return;
}