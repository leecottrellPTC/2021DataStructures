#pragma once
#include <string>
using namespace std;
class FoodItem
{
protected:
	//create variables here
	//inherited variables
	string name;
	int calories;
	double cost;

private:
	//not inherited

public:
	//prototypes
	//Constructors
	FoodItem();//default constructor
	FoodItem(string Name, int Calories, double Cost);
	//setters - one per variable
	void setName(string Name);
	void setCalories(int Calories);
	void setCost(double Cost);
	//getters - one per variable
	string getName();
	int getCalories();
	double getCost();
	//other functionality

	double perCalorieCost();
};

