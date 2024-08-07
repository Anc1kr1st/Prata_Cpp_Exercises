/*
Chap_12_Ex_05
5. Bank of Heather provedla vyzkum ukazujici, ze zakaznici u bankomatu nechteji 
ve fronte cekat dele nez jednu minutu. S pouzitim simulace z vypisu 12.10 zjistete 
hodnotu poctu zakazniku za hodinu, ktera vede k prumerne cekaci dobe v delce jedne 
minuty. (Pokusny cas necht je aspon 100 hodin.)
*/
//12.12
// bank.cpp -- pouziti rozhrani tridy Queue
#include <iostream>
#include <cstdlib>	// pro rand() a srand()
#include <ctime>	// pro time()
#include "queue.h"

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

	int hours = 100;		// pocet simulovanych hodin
	// jeden cyklus simulace trva jednu minutu

	long cyclelimit = MIN_PER_HR * hours;	// pocet cyklu

	double perhour;		// prumerny pocet zakazniku za hodinu
	double min_per_cust;	// prumerna doba mezi prichodem zakazniku

	Item temp;		// data noveho zakaznika

	long turnaways;		// pocet odmitnutych zakazniku
	long customers;     //  pocet zakazniku ve fronte
	long served;        //  pocet obslouzenych zakazniku
	long sum_line;      //  celkova delka fronty
	int wait_time;      // doba cekani na bankomat
	long line_wait;     //   celkova doba cekani ve fronte

	int i = 60; 	

	do
	{
		perhour = i--;	
		Queue line(hours * perhour);
		
		min_per_cust = MIN_PER_HR / perhour;
		turnaways = 0;		
		customers = 0;    
		served = 0;        
		sum_line = 0;      
		wait_time = 0;     
		line_wait = 0;     

		// beh simulace
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // novy zakaznik
			{
				if (line.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);    // cycle = cas prichodu
					line.enqueue(temp); //  prida noveho zakaznika do fronty
				}
			}
			if (wait_time == 0 && !line.isempty())
			{
				line.dequeue(temp);      // vyrizuje dalsiho zakaznika
				wait_time = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}
		line.~Queue();
	} while ((double)line_wait / served > 1.0);
	i++; 

	// vypis vysledku
	if (customers > 0)
	{
		cout << " prijato zakazniku: " << customers << endl;
		cout << " obslouzeno zakazniku: " << served << endl;
		cout << " odmitnuto zakazniku: " << turnaways << endl;
		cout << "prumerna delka fronty: ";
		

		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " prumerna cekaci doba: "
			<< (double)line_wait / served << " minutes\n";

		cout << " Cycle limit: " << cyclelimit << endl;
		cout << " Line wait: " << line_wait << endl;
		cout << " Sum line: " << sum_line << endl;

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

