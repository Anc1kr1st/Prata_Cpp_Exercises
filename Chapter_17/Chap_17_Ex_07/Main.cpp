/*
Chap_17_Ex_07
7. Zde je cast programu, ktery cte vstup z klavesnice do vektoru objektu typu string,
ulozi obsahy retezcu (nikoli objekty) do souboru a zkopiruje obsah souboru zpet do
vektoru objektu typu string:

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

// ziskani retezcu
    cout << "Zadejte retezce (prazdny radek ukonci program):\n";
    while (getline(cin,temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Zde je vas vstup.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

// ulozeni do souboru
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

// obnova obsahu souboru
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Nelze otevrit soubor pro cteni.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nZde jsou retezce nactene ze souboru:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}


Poznamenejme, ze soubor je otevren v binarnim tvaru s umyslem provest V/V operace
pomoci read() a write(). K dokonceni uz zbyvaji jen malickosti:
- Napiste funkci void ShowStr(const string &), ktera vypise objekt string nasledovany
znakem novy radek.
- Napiste funktor Store, ktery zapise data z retezce do souboru. Kontruktor Store
necht specifikuje objekt ifstream a pretizeny operator operator()(const string &)
necht indikuje retezec, ktery se ma zapsat. Pracovni plan je takovy, ze nejdrive
zapiseme do souboru delku retezce a pak jeho obsah. Je-li napriklad delka v promenne
len, muzeme napsat:
os.write((char *)&len, sizeof(std::size_t));	// uloz delku
os.write(s.data(), len);	// uloz znaky
Clen data() vrati ukazatel na pole, jez obsahuje znaky retezce. Je podobny clenu
c_str() s tim rozdilem, ze ten druhy pripojuje k retezci prazdny znak.
- Napiste funkci GetStrs(), ktera obnovi data ze souboru. Pro zjisteni dely retezce
muzete pouzit read(), pak tento pocet znaku precist ze soubouru cyklem a znaky postupne
pripojovat k puvodne prazdnemu docasnemu retezci. Vzhledem k tomu, ze jsou data
soukroma, bylo by lepe jezapisovat do rezetce pomoci metody tridy, nikoli primo.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

void ShowStr(const std::string& s);
void GetStrs(std::istream& is, std::vector<std::string>& vs);

class Store
{
public:
    std::ostream& os;
    Store(std::ostream& o) : os(o) {}
    void operator()(const std::string& s);
};


int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    // ziskani retezcu
    cout << "Zadejte retezce (prazdny radek ukonci program):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Zde je vas vstup.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    // ulozeni do souboru
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // obnova obsahu souboru
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Nelze otevrit soubor pro cteni.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nZde jsou retezce nactene ze souboru:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}



void ShowStr(const std::string& s)
{
    std::cout << s << std::endl;
}

void Store::operator()(const std::string& s)
{
    std::size_t len = s.size();
    os.write((char*)&len, sizeof(std::size_t));
    os.write(s.data(), len);
}

void GetStrs(std::istream& is, std::vector<std::string>& vs)
{
    std::string temp;
    size_t len;

    while (is.read((char*)&len, sizeof(size_t)) && len > 0)
    {
        char ch;
        temp = "";
        for (int j = 0; j < len; j++)
        {
            if (is.read(&ch, 1))
            {
                temp += ch;
            }
            else
                break;
        }
        if (is)
            vs.push_back(temp);
    }
}


