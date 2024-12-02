/*
Chap_17_Ex_02
2. Napiste program, ktery zkopiruje vstup z klavesnice (az do simulovaneho
konce souboru) do souboru, jehoz nazev zadate na prikazovem radku.
*/

#include<iostream>
#include<fstream>
#include<cstdlib>

int main(int argc, char* argv[])
{
	using namespace std;

	if (argc == 1)
	{
		cerr << "Error, a filename must be an argument on the command line.";
		exit(EXIT_FAILURE);
	}

	for (int file = 1; file < argc; file++)
	{
		ofstream fout;
		fout.open(argv[file]);
		if (!fout.is_open())
		{
			cerr << "Can't open " << argv[file] << " file.\n";
			exit(EXIT_FAILURE);
		}

		cout << "Enter integer to file <q to quit>: ";
		int number;
		while (cin >> number)
		{
			fout << number << " ";
			cout << "Enter another integer <q to quit>:";
		}
		fout.close();
	}
	cout << "Bye!\n";
	return 0;
	
}
