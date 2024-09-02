// winec.h

#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <valarray>

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;		// alias
	typedef std::pair<ArrayInt, ArrayInt> PairArray;

	std::string label;
	PairArray data;
	int years;

public:

	// inicializace label na l, pocet rocniku do y, 
	// rocniky do yr[], lahve do bot[]
	Wine(const char* l, int y, const int yr[], const int bot[]);
	// inicializace label na l, pocet rocniku do y, 
	// vytvor objekty pole delky y
	Wine(const char* l, int y);
	~Wine();
	void GetBottles();
	const std::string& Label() const;
	int sum() const;
	void Show() const;

	// Trida Wine by mela mit metodu GetBottles(), ktera pro objekt Wine rocniku y vyzada od uzivatele, aby zadal pocet rocniku a pocty lahvi.Metoda Label() by mela vratit odkaz na nazev vina.Metoda sum() by mela vracet celkovy pocet lahvi v druhem objektu valarray<int> v objektu Pair.
};


#endif
