// FoodItemLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "FoodItem.h"

using namespace std;

int main()
{
    FoodItem lunchmeat("Ham", 100, 1.5);
    FoodItem cheese("Swiss", 150, 2);
    FoodItem bread("Rye", 100, .5);
    FoodItem sandwich;

    int x=8, y=7, ans;
    
    ans = x + y + x + x + y + x + y;

    //lhs     rhs
    cout << "What type of cheese?";
    cin >> cheese;

    sandwich = cheese + lunchmeat + bread + bread + bread + cheese + lunchmeat;
    //this     item
    cout << "Your sandwich " << sandwich << " yummy!" << endl;

    cout << cheese << " " << lunchmeat << endl;

    cout << "Welcome to the food lecture part 2" << endl;
    //sandwich = 2 * bread + lunchmeat + cheese;
}
