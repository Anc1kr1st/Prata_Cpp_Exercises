/*
Chap_12_06
6. Bank of Heather by rada vedela, co se stane po pridani druheho bankomatu. 
Upravte simulaci pro dve fronty. Predpokladejte, ze je-li v prvni fronte mene 
lidi, zakaznik se postavi do prvni fronty, v opacnem pripade se pripoji ke 
druhe fronte. Opet zjistete hodnotu poctu zakazniku za jednu hodinu, vedouci 
k prumerne cekaci dobe v delce jedne minuty. (Poznamka: Nejedna se o linearni 
problem, pri kterem by dvojnasobny pocet bankomatu odbavil za hodinu 
dvojnasobny pocet zakazniku pri maximalni cekaci dobe v delce jedne minuty.)
*/

#include <iostream>
#include <ctime>    // for time()
#include <cstdlib>    // for rand() and srand()
#include "queue.h"

const long MIN_PER_HR = 60L;

bool newcustomer(double x);      

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    // setting things up
    std::srand(std::time(0));    

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of each queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);           
    Queue line2(qs);           

    cout << "Enter the number of simulation hours: ";
    int hours;                
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours; 

    Item temp;            
    long turnaways;        
    long customers;         
    long served;        
    long sum_line;       
    int wait_time1;        
    int wait_time2;       
    long line_wait;        
    double min_per_cust;    

    cout << "Enter the average number of customers per hour: ";
    double perhour;        
    cin >> perhour;
    while (perhour > 0) 
    {
        min_per_cust = MIN_PER_HR / perhour;
        turnaways = 0;
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time1 = wait_time2 = 0;
        line_wait = 0;

        for (long cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))    
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else 
                {
                    customers++;
                    temp.set(cycle);    

                    if (line1.queuecount() <= line2.queuecount())
                        line1.enqueue(temp);  
                    else
                        line2.enqueue(temp);    
                }
            }

            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);      
                wait_time1 = temp.ptime(); 
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line += line1.queuecount();

            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);     
                wait_time2 = temp.ptime(); 
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line += line2.queuecount();
        }

        if (customers > 0)
        {
            cout << "customers accepted: " << customers << '\n';
            cout << "  customers served: " << served << '\n';
            cout << "         turnaways: " << turnaways << '\n';
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout.setf(ios_base::showpoint);
            cout << (double)sum_line / cyclelimit << '\n';
            cout << " average wait time: "
                << (double)line_wait / served << " minutes\n";
        }
        else
            cout << "No customers!\n";

        while (!line1.isempty())
            line1.dequeue(temp);
        while (!line2.isempty())
            line2.dequeue(temp);

       cout << "Enter new value for customers per hour (0 to quit): ";
       cin >> perhour;
    } 
    cout << "Bye\n";

    return 0;
}

bool newcustomer(double x)
{
    if (std::rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}
