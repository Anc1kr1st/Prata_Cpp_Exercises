#pragma once
#include<iostream>

using namespace std;

namespace SALES
{
	class Sales
	{
	private:
		enum { QUARTERS = 4 };
		double sales[QUARTERS];
		double average;
		double max;
		double min;

	public:
		Sales() { max = min = average = 0; }
		Sales(const double ar[], int n);
		void setSales();
		void showSales() const;
	};
}
