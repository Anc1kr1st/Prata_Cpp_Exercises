// winec.cpp
#include"winec.h"
using std::string;

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) :
	PairArray(ArrayInt(y), ArrayInt(y)), string(l)
{
	years = y;

	for (int i = 0; i < years; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}

}

Wine::Wine(const char* l, int y) :
	PairArray(ArrayInt(y), ArrayInt(y)), string(l)
{
	years = y;
}

Wine::~Wine()
{

}

void Wine::GetBottles()
{
	// pro objekt Wine rocniku y vyzada od uzivatele, aby zadal pocet rocniku a pocty lahvi
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Enter " << Label() << " data for " << years << " year(s):\n";
	int input;
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> input;
		PairArray::first()[i] = input;
		cout << "Enter bottles for that year: ";
		cin >> input;
		PairArray::second()[i] = input;
	}
}

const string& Wine::Label() const
{
	// vratit odkaz na nazev vina
	return (const string&)(*this);
}

int Wine::sum() const
{
	// vracet celkovy pocet lahvi v druhem objektu valarray<int> v objektu Pair
	int sum = 0;
	for (int i = 0; i < years; i++)
		sum += PairArray::second()[i];
	return sum;

}

void Wine::Show() const
{
	using std::cout;
	using std::endl;

	cout << "Wine: " << Label() << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "Year: " << PairArray::first()[i] << endl;
		cout << "Bottles: " << PairArray::second()[i] << endl;
	}
	cout << endl;
}
