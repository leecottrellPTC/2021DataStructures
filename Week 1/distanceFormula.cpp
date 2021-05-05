// distanceFormula.cpp : 
//demonstrate how to use sqrt and pow
//calculate a complicated program
//

#include <iostream>
#include <iomanip>
#include <cmath>//need for sqrt and pow

using namespace std;

int main()
{
    double x1=5, x2=0, y1=10, y2=20;//(x1, y1)...(x2, y2)
    //hard code my test values
    //then write the algorithm until it works
    //once it works, then get user input

    //get input
    cout << "Enter x1 and y1->";
    cin >> x1 >> y1;

    cout << "Enter x2 and y2->";
    cin >> x2 >> y2;

    //create variables for steps in your code
    //reduces complexity of your algorithm
    double xsub = x1 - x2;
    double ysub = y1 - y2;

    //test intermediate values
  //  cout << "xsub is " << xsub << endl;
  //  cout << "ysub is " << ysub << endl;

    double dist = sqrt(pow(xsub, 2) + pow(ysub, 2));

    cout << setprecision(1) << fixed;   //sticky manipulators, turn on they stay on
    cout << "Point 1 (" << x1 << ", " << y1 << ") ";
    cout << "Point 2 (" << x2 << ", " << y2 << ") " << endl;
    cout << "Distance is " << dist << endl;
}
