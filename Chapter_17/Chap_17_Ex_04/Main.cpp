/*
Chap_17_Ex_04
4. Napiste program, ktery otevre dva textove souboury pro vstup a jeden pro
vystup. Program zretezi odpovidajici radky vstupnich souboru, pricemz jako
oddelovac pouzije mezeru, a vysledek zapise do vystupniho souboru. Pokud
bude jeden ze souboru kratsi, zkopiruji se do v  ystupniho souboru i zbyvajici
radky delsiho souboru. Predpokladejte napriklad, ze prvni vstupni soubour ma
tento obsah:
eggs kites donuts
balloons hammers
stones
Druhy vstupni soubour bude mit nasledujici obsah:
zero lassitude
finance drama
Obsah vysledneho souboru pak bude nasledujici:
eggs kites donuts zero lassitude
balloons hammers finance drama
stones
*/

#include <iostream>
#include <fstream>
#include <cstdlib>


int main()
{
    using namespace std;

    ifstream fin1("text1.txt");
    if (!fin1.is_open())
    {
        cerr << "Can't open text1.txt file.\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin2("text2.txt");
    if (!fin2.is_open())
    {
        cerr << "Can't open text2.txt file.\n";
        exit(EXIT_FAILURE);
    }

    ofstream fout("text3.txt");
    if (!fout.is_open())
    {
        cerr << "Can't open text3.txt file.\n";
        exit(EXIT_FAILURE);
    }

    char ch;
    while (!fin1.eof() && !fin2.eof())
    {
        while (fin1.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << ' ';
        while (fin2.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << endl;
        fin1.peek();           
        fin2.peek();
    }

    if (fin1.eof() && !fin2.eof())
    {
        while (fin2.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << '\n';
    }
    else if (!fin1.eof() && fin2.eof())
    {
        while (fin1.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << '\n';
    }
    fin1.close();
    fin2.close();
    fout.close();
    cout << "Done!\n";
    return 0;

}
