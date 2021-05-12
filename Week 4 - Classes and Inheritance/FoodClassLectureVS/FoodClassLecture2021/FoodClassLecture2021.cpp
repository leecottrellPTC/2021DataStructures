// FoodClassLecture2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "FoodItem.h"
//#include "FoodItem.cpp"
#include "EnergyDrink.h"

using namespace std;

int main()
{
	FoodItem cookie;//instantiation of FoodItem using default constructor
	FoodItem milk("Milk", 150, 2);

	EnergyDrink monster("Monster", 400, 5, 300);

	cout << monster.getName() << " has mgs" << monster.getCaffeine()
		<< " of caffeine\n";

	cookie.setName("Chocolate chip");
	cookie.setCalories(100);
	cookie.setCost(1.5);

	cout << cookie.getName() << " costs " << cookie.getCost();
	cout << " Cost per calorie " << cookie.perCalorieCost() << endl;

	cout << milk.getName() << endl;
	cout << "Total calories " << milk.getCalories() + cookie.getCalories() << endl;
	//cout << milk << " and " << cookies << " has " << milk + cookies << " Calories\n";

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
