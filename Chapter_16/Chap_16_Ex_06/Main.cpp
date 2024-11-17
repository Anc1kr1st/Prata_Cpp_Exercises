/*
Chap_16_Ex_06
6. Prepracujte program z vypisu 12.15 tak, ze misto tridy Queue z kapitoly 12
pouzijete sablonovou tridu queue z knihovny STL.
*/

#include <iostream>
#include <cstdlib>	// pro rand() a srand()
#include <ctime>	// pro time()
#include <queue>


// Tato fronta bude obsahovat polozky tridy Customer
class Customer
{
private:
	long arrive; 		// cas prichodu zakaznika
	int processtime;		// doba odbaveni zakaznika

public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

const int MIN_PER_HR = 60;

bool newcustomer(double x);	// prisel novy zakaznik?


int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting thisngs up

	std::srand(std::time(0)); 	// nahodna inicializace funkce randl()


	cout << "Pripadova studie: Bankomat Bank of Heather\n";
	cout << "Zadejte maximalni delku fronty: ";
	int qs;
	cin >> qs;

	std::queue <Customer> line;		// ve fronte muze byt maximalne qs lidi

	cout << "Zadejte pocet simulovanych hodin: ";
	int hours;		// pocet simulovanych hodin
	cin >> hours;
	// jeden cyklus simulace trva jednu minutu
	long cyclelimit = MIN_PER_HR * hours;	// pocet cyklu

	cout << "Zadejte prumerny pocet zakazniku za hodinu: ";
	double perhour;		// prumerny pocet zakazniku za hodinu
	cin >> perhour;
	double min_per_cust;	// prumerna doba mezi prichodem zakazniku
	min_per_cust = MIN_PER_HR / perhour;

	Customer temp;		// data noveho zakaznika
	long turnaways = 0;		// pocet odmitnutych zakazniku
	long customers = 0;		// pocet zakazniku ve fronte
	long served = 0;		// pocet obslouzenych zakazniku
	long sum_line = 0;		// celkova delka fronty
	int wait_time = 0;		// doba cekani na bankomat
	long line_wait = 0;		// celkova doba cekani ve fronte

	// beh simulace
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) 	// novy zakaznik
		{
			if (line.size() == qs)  // size
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);	// cycle = cas prichodu
				line.push(temp);	// prida noveho zakaznika do fronty
			}
		}
		if (wait_time <= 0 && !line.empty())
		{
			line.pop();	// pop
			wait_time = temp.ptime();	// po wat_time minut
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();	// size
	}
	// vypis vysledku
	if (customers > 0)
	{
		cout << " prijato zakazniku: " << customers << endl;
		cout << " obslouzeno zakazniku: " << served << endl;
		cout << " odmitnuto zakazniku: " << turnaways << endl;
		cout << " prumerna delka fronty: ";

		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " prumerna cekaci doba: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "Nejsou zadni zakaznici!\n";
	cout << "Hotovo!\n";

	return 0;
}



// x = prumerna doba v minutach mezi dvema zakazniky
// navratova hodnota je true, pokud se do teto doby objevi novy zakaznik
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
