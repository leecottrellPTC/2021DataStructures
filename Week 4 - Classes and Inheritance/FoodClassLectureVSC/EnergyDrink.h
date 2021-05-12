#pragma once
#include "FoodItem.h"
class EnergyDrink :
    public FoodItem
{
protected:
    int caffeine;
    //also have name, calories, cost
private:

public:
    void setCaffeine(int mgs);
    int getCaffeine();
    EnergyDrink();
    EnergyDrink(string Name, int Calories, double Cost, int mgs);
};

