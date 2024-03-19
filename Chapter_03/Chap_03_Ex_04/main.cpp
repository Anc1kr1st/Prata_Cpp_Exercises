/* 4.  Napište program, který si vyžádá vstup počtu sekund jako celočíselnou hodnotu (použijte typ long) a pak 
vypíše ekvivalent ve dnech, hodinách, minutách a sekundách.Počty hodin ve dni, minut v hodině a sekund v minutě 
nech  jsou dány symbolickými konstantami. Po spuštění by se mělo vypsat :
Zadejte počet sekund : 31600000
31600000 sekund = 365 dní, 46 minut, 40 sekund
*/

#include <iostream>

using namespace std;

int main() {

	long input, days, hours, minutes, seconds;
	int const cHours = 24;
	int const cMinutes = 60;
	int const cSeconds = 60;

	cout << "Enter number of seconds: ";
	cin >> input;
	days = ((input / cSeconds) / cMinutes) / cHours;
	hours = ((input / cSeconds) / cMinutes) % cHours;
	minutes = (input / cSeconds) % cMinutes;
	seconds = input % cSeconds;

	cout << input << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";

	return 0;
}

