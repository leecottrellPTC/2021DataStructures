#include "EnergyDrink.h"

void EnergyDrink::setCaffeine(int mgs)
{
	caffeine = mgs;
}

int EnergyDrink::getCaffeine()
{
	return caffeine;
}

EnergyDrink::EnergyDrink()
{
	name = "nameless energy drink";
	calories = 0;
	cost = 0;
	caffeine = 0;
}

EnergyDrink::EnergyDrink(string Name, int Calories, double Cost, int mgs)
{
	name = Name;
	calories = Calories;
	cost = Cost;
	caffeine = mgs;
}
