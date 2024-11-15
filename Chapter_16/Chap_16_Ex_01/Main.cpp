/*
Chap_16_Ex_01
1. Palindrom je retezec, ktery se cte stejne zezadu i zepredu. Palindromy jsou
napriklad retezce "mam" nebo "nepochopen". Napiste program, ktery si od uzivatele
vyzada retezec a odkaz na nej preda booleovske funkci. Jestlize bude retezec
palindromem, vrati funkce hodnotu true, jinak vrati false. Zatim se nemusite
zabyvat komplikacemi vyplyvajicimi z velkych pismen, mezer, interpunkce nebo
pismene "ch". V teto verzi retezce typu "Otto" nebo "Kobyla ma maly bok" za
palindrom nepovazujte. Aby si ukozl zjednodusili, klidne se muzete podivat do
prilohy F na seznam metod tridy string.
*/

#include <iostream>
#include <string>


bool isPal(const std::string& s);

int main()
{
	std::string Input;

	std::cout << "Enter palindrome: \n";
	std::getline(std::cin, Input);



	if (isPal(Input))
	{
		std::cout << Input << " is palindrome.\n";
	}
	else
	{
		std::cout << Input << " is not palindrome.\n";
	}

	return 0;
}

bool isPal(const std::string& s)
{

	std::string rev(s.rbegin(), s.rend());

	if ((rev == s))
	{
		return true;
	}
	else
	{
		return false;
	}
}