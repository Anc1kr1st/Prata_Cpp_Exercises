/*
Chap_10_Ex_03
Vypracujte cviceni 1 z kapitoly 9, avsak nahradte v nem kod deklaraci tridy golf. Nahradte setgolf (golf &, const char *, int) 
konstruktorem s prislusnym argumentem pro nastaveni pocatecnich hodnot. Ponechte interaktivni verzi setgolf(), avsak 
implementujte ji pomoci konstruktoru. (Napriklad ziskejte data pro setgolf(), predejte je konstruktoru k vytvoreni docasneho 
objektu, a ten pak priradte volajicimu objektu *this.)
*/

#include "golf.h"

const int SIZE = 3;

int main() {

	Golf golfData{"Tiger Woods", 5};

	golfData.showgolf();

	golfData.sethandicap(10);

	golfData.showgolf();

	Golf golfData2[SIZE];

	int players = 0;

	while (players < SIZE && golfData2[players].setgolf())
		players++;

	for (int i = 0; i < players; i++) {
		golfData2[i].showgolf();
	}

	return 0;
}
