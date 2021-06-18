#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Customer.h"
#include <queue>


using namespace std;
queue<customer> checkoutLine;
int curCustTime = 0;
int custCount = 0;
int itemsSold = 0;
void addCustomer();
void checkout();

int main()
{
    srand(time(NULL));

    int RUNS = 15000;
    int totCustTime = 0;
    int totCustCount = 0;
    int totItemsSold = 0;
    int totLeftInLine = 0;
    for (int trial = 1; trial <= RUNS; trial++)
    {
        for (int minutes = 1; minutes <= 120; minutes++)
        {
            addCustomer();
            if (checkoutLine.empty() == false)
            {
                checkout();
            }
        }//enfd of minute for

        // cout << "After 2 hours\n";
        // cout << "Left in line " << checkoutLine.size() << endl;
        // cout << "Items sold " << itemsSold << endl;
        // cout << "Customers served " << custCount << endl;
        // cout << "Time per customer " << 120.0 / custCount << endl;
        //total the values

        totCustCount += custCount;
        totCustTime += 120.0 / custCount;
        totItemsSold += itemsSold;
        totLeftInLine += checkoutLine.size();

        itemsSold = 0;
        custCount = 0;
        //clear the queue
        while(checkoutLine.empty() == false){
            checkoutLine.pop();
        }
    }//end of trial for
    cout << "After " << RUNS << " trials you have these averages \n";
    cout << "Left in line " << totLeftInLine / RUNS << endl;
    cout << "Items sold " << totItemsSold / RUNS << endl;
    cout << "Customers served " << totCustCount / RUNS << endl;
    cout << "Time per customer " << totCustTime /RUNS << endl;

}

void addCustomer()
{
    //add one per minute
    //checkoutLine.push(customer());
    int newCust = int(rand() % 50);
    //smaller numbers --> busier times
    //1 way that 3 customer enter line
    //2 way that 2 customer enter line
    //4 ways that 1 customer enter line
    //50 - (1 + 2 + 4) ways for no customer
    switch (newCust)
    {
    case 0:
        //three customers
        checkoutLine.push(customer());
        checkoutLine.push(customer());
        checkoutLine.push(customer());
        break;
    case 1:
    case 2:
        checkoutLine.push(customer());
        checkoutLine.push(customer());
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        checkoutLine.push(customer());
        break;
    default:
        break;
        //no customers
    }
}

void checkout()
{
    //checkoutLine.pop();
    customer current = checkoutLine.front();
    curCustTime++;
    if (curCustTime >= current.getCheckoutTime())
    {
        //cust is done
        custCount++;
        curCustTime = 0;
        itemsSold += current.getItemsInBuggy();
        checkoutLine.pop();
    }
}