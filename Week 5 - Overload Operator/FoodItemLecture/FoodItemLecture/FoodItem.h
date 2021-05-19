#pragma once
#include <string>

using namespace std;
class FoodItem
{
public:
	FoodItem();
	FoodItem(string Name, int Calories, double Cost);
	~FoodItem();
	void setName(string Name);
	void setCalories(int Cal);
	void setCost(double Cost);
	string to_string();

	string getName();
	int getCalories();
	double getCost();

	//overloaded operators
	FoodItem operator + (FoodItem& item);
								//address of item after the +
	friend ostream& operator <<(ostream& out, const FoodItem& item);
	friend istream& operator >>(istream& in, FoodItem& item);


protected:
	string name;
	int calories;
	double cost;
};


