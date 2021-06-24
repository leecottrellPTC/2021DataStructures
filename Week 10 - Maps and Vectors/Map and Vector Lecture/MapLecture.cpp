#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Food.h"
#include <map>
#include <fstream>
#include <set> //multiset allows repetitions, but sorts it
#include <iterator>

using namespace std;

map<string, double> gradePoints;

void basic_map()
{
    //fill the map
    gradePoints["A+"] = 4.25;
    gradePoints["A"] = 4.00;
    gradePoints["A-"] = 3.75;

    gradePoints["B+"] = 3.5;
    gradePoints["B"] = 3.00;
    gradePoints["B-"] = 2.75;

    gradePoints["C+"] = 2.5;
    gradePoints["C"] = 2.00;
    gradePoints["C-"] = 1.75;

    gradePoints["D+"] = 1.5;
    gradePoints["D"] = 1.00;
    gradePoints["D-"] = 0.75;

    gradePoints["F"] = 0.00001;
    gradePoints["X"] = -1; //kick out score
}

void calcGrades()
{
    double totalScore = 0;
    int count = 0;
    string grade = "";

    do
    {
        cout << "Enter a letter grade from A - F, including g+ or -, X to quit \n";
        cin >> grade;

        if (gradePoints[grade] > 0)
        {
            totalScore += gradePoints[grade];
            count++;
        }
    } while (grade != "X");
    cout << "GPA " << totalScore / count << endl;
}

map<string, FoodItem> foodMap;
void fillTheMap()
{
    ifstream fin("foodlist.txt");
    string foodName;
    FoodItem someFood;
    int calories, cost;
    if (fin.fail())
    {
        cout << "foodlist did not open\n";
        exit(-1);
    }
    while (!fin.eof())
    {
        fin >> foodName >> calories >> cost;
        someFood = FoodItem(foodName, calories, cost);
        foodMap[foodName] = someFood;
    }
    fin.close();
    cout << foodMap.size() << " records read\n";
}

void useFood()
{
    string foodName;
    multiset<FoodItem, less<FoodItem>> eaten;
    int totalCalories = 0;

    do
    {
        cout << "Enter food name you ate, done to quit\n";
        cin >> foodName;
        if (foodMap[foodName].getName() != "No name")
        {
            eaten.insert(foodMap[foodName]);
            totalCalories += foodMap[foodName].getCalories();
        }
    } while (foodName != "done");

    cout << "You ate " << totalCalories << endl;
}
//how to search a map for non key
void searchMap()
{
    //find food with calories < 50
    map<string, FoodItem>::iterator foodItr;
    for (foodItr = foodMap.begin(); foodItr != foodMap.end(); foodItr++)
    {
        //map key      value
        //    first    second
        if (foodItr->second.getCalories() < 50)
        {
            cout << foodItr->second << endl;
        }
        //brute force search O(n)
    }
}
int main()
{
    fillTheMap();
    //useFood();
    searchMap();

    //play with map
    //  cout << "Carrot " << foodMap["carrot"] << endl;

    // cout << "blood " << foodMap["blood"] << endl;
    //basic_map();
    //calcGrades();

    //run it with A, B == should get 3.5 GPA
    //cout << gradePoints["A+"] << endl;
}