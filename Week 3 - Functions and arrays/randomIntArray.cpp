#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <time.h>

using namespace std;
#define SIZE 100

int main(){
    srand(time(NULL));
    int theArray[SIZE];
    for(int x=0; x < SIZE; x++){
        //generate a number between 0 and 100
        theArray[x] = rand() % 101;
    }
    //double theArray[10] = {3.14, .2, 13.7, -6.4, 5.4, -3.6, 2.77, 80.1, 99, .10};
    for(int val : theArray){
        cout << setw(6) << val <<" ";
    }
}