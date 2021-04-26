// ch2num11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    double gallons = 20;
    double mpg = 10;
    double numOfMiles;

    //get input
    cout << "Enter the gallons of your car ";
    cin >> gallons;

    cout << "Enter the MPG of your car ";
    cin >> mpg;

    //logical checks
    if (gallons <= 0 || gallons > 100) {
        cout << "Gallons must be greater than 0 and less than 100\n";
        return 1;
    }
    if (mpg <= 0 || mpg > 50) {
        cout << "MPG must be greater than 0 and less than 50\n";
        return 1;
    }
    
    //processing
    numOfMiles = gallons * mpg;
    //output here

    cout << setfill('_') << setw(21) << left << "Gallons" << setw(6) << right << gallons << endl;
    cout << setfill('_') << setw(21) << left << "MPG" << setw(6) << right << mpg << endl;
    cout << setfill('_') << setw(21) << left << "Miles you can drive" << setw(6) << right << numOfMiles << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
