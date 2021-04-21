#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    //human years * 7 == dog years

    int age = 51;
    int dogAge = age * 7;
    string yourName = "lee";
    cout << "Enter your name ";
    //cin >> yourName;
    //get string with spaces
    getline(cin,yourName);

    cout << yourName << " how old are you? ";
    cin >> age;

    dogAge = age * 7;


    //basic output uses cout
    //console output
    //write using insertion operators << 

    cout << "Human age " << age << " in dog years you are " << dogAge << endl;
    //endl is the same as \n


}