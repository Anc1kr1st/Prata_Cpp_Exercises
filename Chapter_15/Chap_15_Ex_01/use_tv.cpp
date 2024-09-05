/*
Chap_15_Ex_01
1. Upravte tridy Tv a Remote podle nasledujicich pokynu:
a) vytvorte z nich vzajemne pratele
b) pridejte do tridy Remote stavovou polozku, ktera bude popisovat,
zda se ovladac nahazi v normalnim nebo interaktivnim rezimu
c) pridejte tride Remote metodu zobrazujici rezim ovladace
d) doplnte do tridy Tv metodu pro prepinani rezimu dalkoveho ovladace.
Tato metoda by mela fungovat pouze tehdy, kdyz je televize zapnuta.
Napiste kratky program testujici tyto nove vlastnosti.
*/
//use_tv.cpp -- použití tríd Tv a Remote
#include <iostream>
#include "tv.h"

int main()
{
	using std::cout;
	Tv s27;
	cout << "Pocatecni nastaveni 27\" televize:\n";
	s27.settings();
	s27.onoff();
	s27.chanup();
	cout << "\nUpravene nastaveni 27\" televize:\n";
	s27.settings();

	Remote grey;

	grey.set_chan(s27, 10);
	grey.volup(s27);
	grey.volup(s27);
	cout << "\n27\" nastaveni pro pouziti dalkoveho ovladace:\n";
	s27.settings();

	Tv s32(Tv::On);
	s32.set_mode();
	grey.set_chan(s32, 28);
	cout << "\n32\" nastaveni:\n";
	s32.settings();

	Tv s30(Tv::On);
	s30.set_mode();
	grey.set_chan(s30, 28);
	cout << "\n30\" settings:\n";
	s30.settings();
	grey.show_style();    // check mode
	s30.style_turn(grey);         // change mode
	grey.show_style();    // recheck mode
	s30.onoff();            // turn set off
	s30.style_turn(grey);        // try changing mode again
	grey.show_style();     // check result

	return 0;
}
