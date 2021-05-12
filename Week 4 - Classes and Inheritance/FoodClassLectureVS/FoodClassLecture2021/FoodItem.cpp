#include "FoodItem.h"
#include <iostream>
#include <iomanip>

//constructors
//:: is scope resolution operator
FoodItem::FoodItem() {
	name = "no name";
	calories = 0;
	cost = 0;
}

FoodItem::FoodItem(string Name, int Calories, double Cost) {
	name = Name;
	calories = Calories;
	cost = Cost;
}

//setters and getters
double FoodItem::getCost() {
	return FoodItem::cost;
}

int FoodItem::getCalories() {
	return this->calories;
}

string FoodItem::getName() {
	return name;
}

void FoodItem::setName(string Name) {
	this->name = Name;
}

void FoodItem::setCalories(int Calories) {
	calories = Calories;
}

void FoodItem::setCost(double Cost) {
	FoodItem::cost = Cost;
}

//functionality
double FoodItem::perCalorieCost() {
	return cost / calories;
}
