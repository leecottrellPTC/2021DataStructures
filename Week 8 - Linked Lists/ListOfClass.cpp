#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"
#include "FoodItem.cpp"

using namespace std;

int main()
{
    //unorderedLinkedList<FoodItem> foodList;

    orderedLinkedList<FoodItem> foodList;

    foodList.insertLast(FoodItem("Eggs", 500, 1));
    foodList.insertLast(FoodItem("Bacon", 150, 3));
    foodList.insertLast(FoodItem("Toast", 200, 4));

    FoodItem cookie("Cookies", 350, 3);
    foodList.insertLast(cookie);

    foodList.print();
    
}