/*
Chapter 02 Exercise 05
Napište program, v jehož funkci main() je volána uživatelsky definovaná funkce, která jako argument přijímá 
vzdálenost ve světelných letech a vrací vzdálenost v astronomických jednotkách. Program by měl požádat uživatele
o vstup hodnoty ve světelných letech a zobrazit výsledek, jak je ukázáno v následujícím kódu: 
Zadejte vzdalenost ve svetelnych letech: 4.2
4.2 svetelnych let je 265608 astronomickych jednotek.
Astronomická jednotka odpovídá prúměrné vzdálenosti Země od Slunce (přibližně 150 000 000 km nebo 93 000 000 mil) 
a světelný rok představuje vzdálenost, kterou světlo urazí za jeden rok (přibližne 10 bilionú km nebo 6 bilionú mil). 
(Nejbližší hvězda po Slunci je vzdálená 4,2 světelných let.) Použijte typ double (jako ve výpisu 2.40 a následujíci 
převodní vzorec:
1 světelný rok = 63n240 astronomických jednotek
*/

#include <iostream>

using namespace std;

int main() {
	double input;
	double result;

	cout << "Zadejte vzdalenost ve svetelnych letech: ";
	cin >> input;
	result = input * 63240;
	cout << input << " svetelnych let je " << result << " astronomickych jednotek.";

	return 0;
}