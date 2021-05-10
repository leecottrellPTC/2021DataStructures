#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//function prototypes
//declare the function
void printMyAddress();  //function prototype
double calcGrossPay(double hours, double rate);
//default parameter
//parameter you do not have to pass in
double calcTax(double grossPay, double taxRate = 0.035);//local tax is default
//must default values on the right
//should be the 'later parameters'
/*
int someFunction(int a = 1, int b = 3, int c= 5);
someFunction();
someFunction(5, 15);
someFunction(1, 2, 3);
someFunction(6);
//invalid call
someFunction( , 5, );
*/

int main(){
    printMyAddress();
    double myPay = calcGrossPay(41, 10.5);
    double stateTax;
    double localTax;
    double fedTax;
    double netpay;
    stateTax = calcTax(myPay, .01);
    localTax = calcTax(myPay);  //use the dafualt value
    fedTax = calcTax(myPay, .40);

    netpay = myPay - stateTax - localTax - fedTax;
    cout << setprecision(2) << fixed;
    cout << "Gross Pay $" << myPay << endl;
    cout << "State Tax $" << stateTax << endl;
    cout << "Local Tax $" << localTax << endl;
    cout << "Fed Tax   $" << fedTax << endl;
    cout << "Net Pay   $" << netpay << endl;
}

/*
    functions are named chunks of code that return values
    procedures are named named chunks of code that DO NOT return values
    methods are generic terms for functions/procedures
*/
double calcTax(double grossPay, double taxRate){
    return grossPay * taxRate;
}
double calcGrossPay(double hours, double rate){
    double grossPay = 0;
    if(hours > 40){
        grossPay = rate * 40 + rate * 1.5 * (hours - 40);
    }
    else if(hours >0 && hours <= 40){
        grossPay = hours* rate;
    }
    else{
        //bad hours data
        grossPay = 0;
    }
     //dothe math here   
    return grossPay;
}

void printMyAddress(){
    cout << "Lee Cottrell\n";
    cout << "1434 Justine Street\n";
    cout << "Pittsburgh, PA 15204\n";
}

//function body
//create the function

