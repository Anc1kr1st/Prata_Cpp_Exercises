
/*
Chap_12_02
2. Rozsirte deklaraci tridy String (to znamena zmente string2.h na string3.h) takto:
a. pretezte operator scitani tak, aby bylo mozno spojit dva retezce do jednoho
b. vytvorte clenskou funkci stringlow() prevadejici vsechny alfabeticke znaky v retezci na mala pismena
c. vytvorte clenskou funkci stringup() prevadejici vsechny alfabeticke znaky v retezci na velka pismena
d. vytvorte clenskou funkci s parametrem typu char a vracejici pocet vyskytu tohoto znaku v retezci.

Overte svou praci pomoci nasledujicho programu:
//pe12_2.cpp
#include <iostream>
using namespace std;
#include "string2.h"
int main()
{
String s1(" a studuji C++.");
String s2 = "Zadejte prosim jmeno: ";
String s3;
cout << s2;	// pretizeny operator <<
cin >> s3;	// pretizeny operator >>
s2 = "Jmenuji se " + s3;	// pretizene operatory =, +
cout << s2 << ".\n";
s2 = s2 + s1;
s2.stringup();	// prevod na velka pismena
cout << "Retezec\n" << s2 << "\neobsahuje " << s2.has('A') << " 'A' znaku.\n";
s1 = "cervena";
// then String & operator=(const String&)
String rgb[3] = { String(s1), String("zelena"), String("modra")};
cout << "Zadejte jmeno primarni barvy pro namichani svetla: ";
String ans;
bool success = false;
while (cin >> ans)
{
ans.stringlow();	// prevod na mala pismena
for (int i = 0, i < 3; i++)
{
if (ans == rgb[i]) 	// pretizeny operator ==
{
cout << "Spravne!\n";
success = true;
break;
}
}
if (success)
break;
else cout << "Zkuste to znovu!\n";
}
cout << "Nashledanou!\n";
return 0;
}
*/

#include <iostream>
using namespace std;
#include "string3.h"

int main()
{
	String s1(" a studuji C++.");
	String s2 = "Zadejte prosim jmeno: ";
	String s3;
	cout << s2;	// pretizeny operator <<
	cin >> s3;	// pretizeny operator >>
	s2 = "Jmenuji se " + s3;	// pretizene operatory =, +
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();	// prevod na velka pismena
	cout << "Retezec\n" << s2 << "\nneobsahuje " << s2.has('A') << " 'A' znaku.\n";
	s1 = "cervena";
	// then String & operator=(const String&)
	String rgb[3] = { String(s1), String("zelena"), String("modra") };
	cout << "Zadejte jmeno primarni barvy pro namichani svetla: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();	// prevod na mala pismena
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) 	// pretizeny operator ==
			{
				cout << "Spravne!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else cout << "Zkuste to znovu!\n";
	}
	cout << "Nashledanou!\n";
	return 0;
}
