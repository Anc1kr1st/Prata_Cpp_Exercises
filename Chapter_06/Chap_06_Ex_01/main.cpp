/*
Chap_06_Ex_01
Napiste program, ktery cte vstupni data z klavesnice az po symbol @, zobrazuje vstupni 
data krome cislic a konvertuje male znaky na velke a naopak. (Nezapomente na knihovnu cctype.)
*/

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char ch;

	cout << "Type your text, for quit enter @.\n";

	cin.get(ch);
	cin.get();
	while (ch != '@')
	{
		if (isdigit(ch))
		{
			cin.get(ch);
			cin.get();
			continue;
		}
		else if (isupper(ch))
		{
			ch = tolower(ch);
		}
		else if(islower(ch))
		{
			ch = toupper(ch);
		}

		cout << "Here is changed character: " << ch << endl;

		cin.get(ch);
		cin.get();
	}

	cout << "Bye!";

	return 0;
}
