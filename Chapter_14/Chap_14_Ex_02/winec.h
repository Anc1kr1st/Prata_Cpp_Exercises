// winec.h

#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <valarray>
#include "pair.h"

typedef std::valarray<int> ArrayInt;		// alias
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private PairArray, private std::string
{
private:
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
};

#endif
