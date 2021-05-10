#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
#define SIZE 5

void printArray(double list[]);
double avgArray(double list[]);
double geometricMean(double list[]);

int main(){
    //dataType nameOfArray[Size of array];
    double numbers[SIZE] = {4, 36, 45, 50, 75};

   /* for(double val : numbers){
        cout << val;
    }
    */

    printArray(numbers);
    cout << "Average is " << avgArray(numbers) << endl;
    cout << "Geometric mean is " << geometricMean(numbers) << endl;
}//end of main()

double geometricMean(double list[]){
    double product = 1;
    double avg = 0;

    for(int x=0; x < SIZE; x++){
        product *= list[x];
    }
    avg = pow(product, 1.0/SIZE);
    return avg;
}//end of geometricMean function

double avgArray(double list[]){
    double total = 0;
    double avg = 0;

    for(int x=0; x < SIZE; x++){
        total += list[x];
    }
    avg = total / SIZE;
    return avg;
}//end of avgArray
void printArray(double list[]){
    for(int x=0; x < SIZE; x++){
        cout << x << " : " << list[x] << endl;
    }
}