/*
Chap_07_Ex_08
Toto cviceni je zamereno na ziskani prace v psani funkci, ktere zachazeji 
s poli a retezci. Nasleduje kostra programu. Dokoncete rozepsany program 
podle popisu funkci:
*/

#include <iostream>
#include <cstring>

using namespace std;
const int SLEN = 30;
int real;

struct student {
	char fulname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(const student st);
void display2(const student* ps);
void display3(const student pa[], int n);


int main()
{
	cout << "Zadejte velikost tridy: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);

	cout << "Entered: " << entered << endl;


	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);

	delete[] ptr_stu;
	cout << "Hotovo\n";

	return 0;
}

int getinfo(student pa[], int n)
{
{}

	for (int i = 0; i < n; i++)
	{
		cout << "Zadajte udaje o studentoch. Prazdny riadok pre ukoncenie.\n";
		cout << "Meno: ";

		cin.get(pa[i].fulname, SLEN);

		if (0 == strlen(pa[i].fulname))
		{
			break;
		}
		cin.get();
		cout << "Hobby: ";
		cin.get(pa[i].hobby, SLEN);
		cin.get();
		cout << "Ooplvl: ";
		cin >> pa[i].ooplevel;
		cin.get();

		real = 1 + i;
	}
	return real;
}


void display1(const student st)
{
	cout << "Display1 \n";
	cout << st.fulname << endl;
	cout << st.hobby << endl;
	cout << st.ooplevel << endl;
	return;
}

void display2(const student* ps)
{
	cout << "Display2 \n";
	cout << ps->fulname << endl;
	cout << ps->hobby << endl;
	cout << ps->ooplevel << endl;
	return;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Display3 \n";
		cout << pa[i].fulname << endl;
		cout << pa[i].hobby << endl;
		cout << pa[i].ooplevel << endl;
		cout << n << endl;
	}
	return;
}

