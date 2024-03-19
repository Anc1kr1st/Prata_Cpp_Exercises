/*
Ch4 Ex1

1.  Napište program v  C++, který požádá o  informaci a  zobrazí ji, jak je ukázánov následujícím příkladu výstupu.
Jake je vase krestni jmeno ?
Betty Sue
Jake je vase prijmeni ?
Yew
Jakou znamku si zaslouzite ?
B
Kolik je vam let ?
22
Jmeno : Yew, Betty Sue
Znamka : C
Vek : 22
Všimněte si, že by si program měl poradit s křestními jmény, která se skládají z vícenež jednoho slova. Také si všimněte, 
že program snižuje známku směrem dolů, což znamená o jedno písmeno nahoru.Předpokládejte, že uživatel požádá o známky A, B 
nebo C, takže si nemusíte dělat starosti s mezerou mezi D a F.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

	string firstName;
	string lastName;
	char mark;
	int age;

	cout << "What s your first name? ";
	getline(cin, firstName);
	cout << "What s your last name? ";
	getline(cin, lastName);
	cout << "What mark do you deserve? ";
	cin >> mark;
	mark = ++mark;
	cout << "How old are you? ";
	cin >> age;

	cout << "Name: " << lastName << ", " << firstName << endl;
	cout << "Mark: " << mark << endl;
	cout << "Age: " << age;

	return 0;
}
