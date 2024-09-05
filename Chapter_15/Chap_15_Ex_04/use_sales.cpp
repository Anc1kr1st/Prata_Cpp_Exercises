/*
Chap_15_Ex_04
Ve vypise 15.16 jsou po kazdem bloku try pouzity dva bloky catch tak, aby vyjimka 
nbad_index vedla k vyvolani metody label_val(). Program upravte tak, aby po kazdem 
bloku try pouzil samostatny block catch a k vyvolani label_val() pouzil RTTI pouze 
tehdy, je-li to vhodne.
*/

// use_sales.cpp -- vnoøené výjimky
#include <iostream>
#include "sales.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2004, vals1, 12);
	LabeledSales sales2("Blogstar", 2005, vals2, 12);

	cout << "Prvni blok try:\n";
	try
	{
		int i;
		cout << "Rok = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{

			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Rok = " << sales2.Year() << endl;
		cout << "Navesti = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{

			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Konec 1. bloku try\n";
	}

	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		if (typeid(LabeledSales::nbad_index&) == typeid(bad))
		{
			LabeledSales::nbad_index& temp = dynamic_cast<LabeledSales::nbad_index&>(bad);
			cout << "Spolecnost: " << temp.label_val() << endl;
		}
		cout << "chybny index: " << bad.bi_val() << endl;
	}

	cout << "\nDalsi blok try:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "Konec 2. bloku try \n";
	}

	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		if (typeid(LabeledSales::nbad_index&) == typeid(bad))
		{
			LabeledSales::nbad_index& temp = dynamic_cast<LabeledSales::nbad_index&>(bad);
			cout << "Spolecnost: " << temp.label_val() << endl;
		}
		cout << "chybny index: " << bad.bi_val() << endl;
	}

	cout << "hotovo\n";

	return 0;
}
