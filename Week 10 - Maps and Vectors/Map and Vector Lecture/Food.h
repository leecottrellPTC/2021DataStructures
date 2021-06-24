#ifndef FOOD_CLASS// build this fir
#define FOOD_CLASS
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
class FoodItem {
	
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

	FoodItem operator + (FoodItem& item);
	FoodItem operator * (double amt);		//scalar multiplication
	friend ostream& operator <<(ostream& out, const FoodItem& item);
	friend istream& operator >>(istream& in, FoodItem& item);
	//comparison
	friend bool operator <(FoodItem lhs, FoodItem rhs);
	friend bool operator >(FoodItem lhs, FoodItem rhs);
	friend bool operator ==(FoodItem& lhs, FoodItem& rhs);

	FoodItem operator++();	//prefix ++
	FoodItem operator++(int); //postfix
protected:
	string name;
	int calories;
	double cost;
};
//define friend function
//friend functions know protected and private items
//need for many copying funtions, swap functions, ==, << >>
FoodItem FoodItem::operator++() {
	//returns the item with the math done to it
	this->calories * 2;
	this->cost *= 2;
	return FoodItem(this->getName(), this->getCalories(), this->getCost());

}
FoodItem FoodItem::operator++(int) {
	//++ returns the orignal item and then does the math
	FoodItem orig(this->getName(), this->getCalories(), this->getCost());

	this->calories *= 2;
	this->cost *= 2;
	return orig;

}

bool operator <(FoodItem lhs, FoodItem rhs) {
	return (lhs.calories < rhs.calories);
}

bool operator >(FoodItem lhs, FoodItem rhs) {
	return (lhs.calories > rhs.calories);
}

bool operator ==(FoodItem& lhs, FoodItem& rhs) {
	if (lhs.getName() == rhs.getName()
		&& lhs.getCalories() == rhs.getCalories()
		&& lhs.getCalories() == rhs.getCalories()){

		return true;
	}
	else {
		return false;
	}
	
}

ostream& operator <<(ostream& out, const FoodItem& item) {
	out << fixed << setprecision(2);
	out << item.name << " has " << item.calories << " calories and costs $" << item.cost;

	return out;
}

istream& operator >>(istream& in, FoodItem& item) {
	cout << "Enter the name ";
	getline(in, item.name);
	cout << "Enter the calories ";
	in >> item.calories;
	cout << "Enter the cost ";
	in >> item.cost;

	return in;
}

FoodItem FoodItem::operator + (FoodItem& item) {
	FoodItem sum;

	sum.calories = this->calories + item.calories;
	sum.cost = this->cost + item.cost;
	sum.name = this->name + ", " + item.name;

	return sum;
}
FoodItem FoodItem::operator *(double amt) {
	FoodItem product;
	char outnum[20];
	sprintf_s(outnum, 20, "%.2f of ", amt);
	product.name = outnum + this->name;
	product.calories = this->calories * amt;
	product.cost = this->cost * amt;
	return product;
}


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

string FoodItem::to_string() {
	string output = "";
							//why type std??
	output = name + " has " + std::to_string(calories) + " calories "
		+ "and costs $" +  std::to_string(cost);

	//we will do this better next week
	return output;
}

#endif	//end of the define