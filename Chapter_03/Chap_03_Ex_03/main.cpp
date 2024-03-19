/* 3.  Napište program, který si vyžádá vstup zeměpisné šířky ve stupních, minutách a vteřinách a 
poté ji zobrazí v dekadickém tvaru.Úhlová minuta má 60 úhlových vteřin, úhlový stupeň má 60 úhlových minut; 
tyto hodnoty zadejte jako symbolické konstanty. Pro každou vstupní hodnotu použijte jinou proměnnou.
Po spuštění by se mělo vypsat :
Zadejte zeměpisnou šířku ve stupních, minutách a vteřinách :
Nejdříve stupně : 37
Dále úhlové minuty : 51
Nakonec úhlové vteřiny : 19
37 stupňů, 51 minut a 19 vteřin = 37, 8553 stupňů
*/

#include <iostream>

using namespace std;

int main() {

	float degrees, minutes, seconds, decDegree;
	float const decMin = 60;
	float const decDeg = 60;

	cout << "Enter latitude in degrees, minutes and seconds.\n";
	cout << "First degrees: ";
	cin >> degrees;
	cout << "Next minutes: ";
	cin >> minutes;
	cout << "Finally seconds: ";
	cin >> seconds;

	decDegree = degrees + (minutes / decDeg) + ((seconds / decMin) / decDeg);

	cout << degrees << " degrees, " << minutes << " minutes and " << seconds << " seconds = " << decDegree << " degrees";

		return 0;
}

