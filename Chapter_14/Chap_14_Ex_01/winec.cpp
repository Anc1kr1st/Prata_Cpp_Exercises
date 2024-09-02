// winec.cpp
#include"winec.h"

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	label = l;
	years = y;

	data.first.resize(years);
	data.second.resize(years);

	for (int i = 0; i < years; i++)
	{
		data.first[i] = yr[i];
		data.second[i] = bot[i];
	}

}

Wine::Wine(const char* l, int y)
{
	label = l;
	years = y;
	data.first.resize(years);
	data.second.resize(years);
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

	cout << "Enter " << label << " data for " << years << " year(s):\n";
	int input;
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> input;
		data.first[i] = input;
		cout << "Enter bottles for that year: ";
		cin >> input;
		data.second[i] = input;
	}
}

const std::string& Wine::Label() const
{
	// vratit odkaz na nazev vina
	return label;
}

int Wine::sum() const
{
	// vracet celkovy pocet lahvi v druhem objektu valarray<int> v objektu Pair
	int sum = 0;
	for (int i = 0; i < years; i++)
		sum += data.second[i];
	return sum;

}

void Wine::Show() const
{
	using std::cout;
	using std::endl;

	cout << "Wine: " << label << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "Year: " << data.first[i] << endl;
		cout << "Bottles: " << data.second[i] << endl;
	}
	cout << endl;
}
