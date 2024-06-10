/*
Chap_10_Ex_07
Vas pes ma nasledujici vlastnosti:
Data
- Ma jmeno, jehoz delka nepresahuje 19 znaku.
- Pes ma index spokojenosti (IS), ktery je reprezentovan celym cislem.
Operace
- Novy pes zacina s urcenym jmenem a IS hodnoty 50.
- Hodnota IS se muze zmenit.
- Pes muze vypsat sve jmeno a IS.
- Implicitni jmeno psa je "Punta".
Vytvorte deklaraci tridy Pes (datove cleny a prototypy clenskych funkci reprezentujici psa. Napiste definice clenskych funkci a vytvorte kratky program, ktery demonstruje vsechny rysy tridy Pes.
*/

#include "pes.h"

int main(void) {

	cout << "Default values \n\n";
	Pes punta;

	punta.show();

	punta.varIS(100);

	cout << "Changed values \n\n";
	punta.show();

	return 0;
};