#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int seconds = 0, hours = 0, minutes = 0;
    //constants - use for magic numbers, conversion rates...
    const int secInMin = 60;
    const int secInHour = 60 * 60;

    //input, processing, output

    //input
    cout << "Enter the number of seconds ";
    cin >> seconds;

    //processing
    hours = seconds / secInHour;
    seconds -= hours * secInHour;  //remove number of hours in seconds

    minutes = seconds / secInMin;
    seconds = seconds % secInMin;   //get remainder of integer division

    //output

    //manipulators
    cout << hours << ":";
    cout << setfill('0') << setw(2) << minutes << ":";
    //setw(2) forces the following variable to be displayed in 2 spaces
    cout << setfill('0') << setw(2) << seconds << endl;
}