#include "FoodItem.h"
#include <iomanip>
#include <iostream>
//constructors
#pragma region Constructors and Destructors
FoodItem::FoodItem() {
	name = "No name";
	calories = 0;
	cost = 0;
}

FoodItem::FoodItem(string Name, int Calories, double Cost) {
	name = Name;
	calories = Calories;
	cost = Cost;
}

FoodItem::~FoodItem() {
	//destructor
	//only needed to clean up memory
}

#pragma endregion 

#pragma region Setters and Getters

void FoodItem::setName(string Name) {
	name = Name;
}

void FoodItem::setCalories(int Cal) {
	calories = Cal;
}

void FoodItem::setCost(double Cost) {
	cost = Cost;
}

string FoodItem::getName() {
	return name;
}
int FoodItem::getCalories() {
	return calories;
}

double FoodItem::getCost() {
	return cost;
}
#pragma endregion

FoodItem FoodItem::operator + (FoodItem& item) {
	FoodItem sum;

	sum.calories = this->calories + item.calories;
	sum.cost = this->cost + item.cost;
	sum.name = this->name + ", " + item.name;

	return sum;
}

ostream& operator <<(ostream& out, const FoodItem& item) {
	//build the output the way you would like
	out << fixed << setprecision(2);
	out << item.name << endl;
	out << item.calories << " calories "
		<< "and costs $" << item.cost;

	return out;
}

istream& operator >>(istream& in, FoodItem& item) {
	cout << "Enter the name of the food ";
	getline(in, item.name);//solves problem of space in food name
	cout << "Enter the calories for " << item.name << " ";
	in >> item.calories;
	cout << "Enter the cost for " << item.name << " ";
	in >> item.cost;

	return in;
}

string FoodItem::to_string() {
	string output = "";
	//why type std??
	output = name + " has " + std::to_string(calories) + " calories "
		+ "and costs $" + std::to_string(cost);

	//we will do this better next week
	return output;
}

