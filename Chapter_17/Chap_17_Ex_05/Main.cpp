/*
Chap_17_Ex_05
5. Petr a Pavel chteji pozvat pratele na vecirek podobne jako v kapitole 16,
cviceni 8, ale nyni chteji program, ktery bude pouzivat souboury. Pozadaji
vas o program, ktery bude provadet nasledujici cinnost:
- Precte seznam Petrovych pratel z textoveho souboru petr.dat. Kazde jmeno
v seznamu bude na jinem radku. Jmena se ulozi do kontejneru a vypisi se
setridena.
- Precte seznam Pavlovych pratel z textoveho souboru pavel.dat. Kazde jmeno
v seznamu bude na jinem radku. Jmena se ulozi do kontejneru a vypisi se
setridena.
- Oba seznamy slouci, vylouci duplicity a vysledek ulozi do souboru
matnpat.dat, kazde jmeno na jiny radek.
*/

// pe17-5.cpp
#include <iostream>
#include <fstream>
#include <set>	// ignoruje duplicity
#include <algorithm>	// uzitocne funkcie
#include <iterator>
#include <cstdlib>
#include <string>

int main()
{
    using namespace std;
    ifstream petr("petr.dat");
    if (!petr.is_open())
    {
        cerr << "Can't open petr.dat.\n";
        exit(1);
    }

    ifstream pavel("pavel.dat");
    if (!pavel.is_open())
    {
        cerr << "Can't open pavel.dat.\n";
        exit(1);
    }

    ofstream petrPav("petrPav.dat");
    if (!petrPav.is_open())
    {
        cerr << "Can't open petrPav.dat.\n";
        exit(1);
    }

    string temp;

    set<string> petrovi;
    while (getline(petr, temp))
        petrovi.insert(temp);
    ostream_iterator<string, char> out(cout, "\n");
    cout << "Petrov zoznam hosti:\n";
    copy(petrovi.begin(), petrovi.end(), out);

    set<string> pavlovi;
    while (getline(pavel, temp))
        pavlovi.insert(temp);
    cout << "\nPavlov zoznam hosti:\n";
    copy(pavlovi.begin(), pavlovi.end(), out);

    ostream_iterator<string, char> fout(petrPav, "\n");
    set<string> spolu;
    set_union(petrovi.begin(), petrovi.end(), pavlovi.begin(), pavlovi.end(),
        insert_iterator<set<string> >(spolu, spolu.begin()));
    cout << "\nSpolocny list hosti:\n";
    copy(spolu.begin(), spolu.end(), out);
    copy(spolu.begin(), spolu.end(), fout);

    return 0;
}
