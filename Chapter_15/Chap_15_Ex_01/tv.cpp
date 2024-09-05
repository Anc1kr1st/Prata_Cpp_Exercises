// tv.cpp -- metody trídy Tv (metody trídy Remote jsou vložené)
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "Televize je " << (zap_vyp == Off ? "vypnuta" : "zapnuta") << endl;
	if (zap_vyp == On)
	{
		cout << "Nastaveni hlasitosti = " << volume << endl;
		cout << "Nastaveni programu = " << channel << endl;
		cout << "Rezim = "
			<< (mode == Antenna ? "antenni" : "kabelovy") << endl;
		cout << "Vstup = "
			<< (input == TV ? "TV" : "VCR") << endl;
	}
}

void Remote::show_style()
{
	if (style == Normal)
		std::cout << "Normal mode\n";
	else
		std::cout << "Interactive mode\n";
}
