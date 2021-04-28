#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int choice = 5; //have 10 choices

    if (choice == 1)
    {
    }
    else if (choice == 2)
    {
    }
    //switches run faster than if statements
    //can swtitch on int, char, enum
    switch (choice) //can be a variable or formula, nut must return int, char, enum
    {
    case 1:
        //do your code here
        break;
    case 2:
        //do code here
        break;
    case 3:
    case 4:
        //do code for 3 and 4 here
        //pass through case
        break;

    default:
        //error code here
        break;
    } //end of switch(choice)

    //ternary operator ?
    //logical test ? code for true : code for false;
    choice = 6;
    choice %2 == 0 ? cout << choice << " is even\n" : cout << choice << " is odd\n";

} //end of main