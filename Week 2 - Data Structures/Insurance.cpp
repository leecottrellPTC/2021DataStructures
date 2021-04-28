#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int age;
    double perHundred;
    double totalMonthly;
    string name;
    int desiredAmount;
    const double hundred = 100000.0;

    char smoke;
    char overweight;

    cout << "What is your name? ";
    getline(cin, name);

    do
    {
        cout << name << " Between 10 and 99, how old are you? ";
        cin >> age;
    } while (age < 10 || age >= 100);

    cout << name << " how much insurance do you want? ";
    cin >> desiredAmount;

    cout << name << " do you smoke <Y/N>? ";
    cin >> smoke;

    cout << name << " are you overweight <Y/N>? ";
    cin >> overweight;

    //cin.ignore(200, '\n');  //only needed if the getline follows a numeric input
    /*
    10 to 20	6.54
    20 to 30	7.77
    30 to 40	9.65
    40 to 50	10.21
    50 to 60	12.45
    60 to 100	14.45
    Otherwise	-1 (error condition)

    */

    if (age >= 10 && age < 20)
    {
        perHundred = 6.54;
    }
    else if (age >= 20 && age < 30)
    {
        perHundred = 7.77;
    }
    else if (age >= 30 && age < 40)
    {
        perHundred = 9.65;
    }
    else if (age >= 40 && age < 50)
    {
        perHundred = 10.21;
    }
    else if (age >= 50 && age < 60)
    {
        perHundred = 12.45;
    }
    else if (age >= 60 && age < 100)
    {
        perHundred = 14.45;
    }
    else
    {
        perHundred = -1;
    }

    if (perHundred < 0)
    {
        cout << "There is something wrong with your age input " << age << " is invalid\n";
        return -1;
    }
    cout << setprecision(2) << fixed;
    cout << "Per Hundred Thousand is $" << perHundred << endl;
    totalMonthly = perHundred * (desiredAmount / hundred);

    overweight = tolower(overweight);
    smoke = tolower(smoke);

    if(smoke == 'y'){
        totalMonthly += .02 * (100 - age);//formula from business
    }

    //do modifiers here
    if(overweight == 'n'){
        //reduce totalMonthly by 10%
        totalMonthly *= .9;  //(100 - 10% == 90%)
    }


    cout << "Your cost per month is $" << totalMonthly << endl;
}