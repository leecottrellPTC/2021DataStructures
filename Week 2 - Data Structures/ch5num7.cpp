#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

/*
    ch5num7
    build a sequence that walks backwards through a number and does math on the number
    mathematic algorithm
*/

int main(){
    int number = 8784205;//book number
    int digit;
    int total = 0;
    int count = 0;
    int origNumber = number;    //hold on to the original number

    while(number > 0){
        digit = number % 10;
        number = number /10;
        if(count %2 == 0){
            //add digit to the total
            total += digit;
        }
        else if(count %2 == 1){
            //subtract digit from the total
            total -= digit;
        }
        //cout << "Digit " << digit << " number " << number << endl;
        count ++;
    }
   // cout << "Total after algorithm is " << total << endl;
    if(total % 11 == 0){
        cout << origNumber << " is divisible by 11" << endl;
    }
    else if(total %11 != 0){
        cout << origNumber << " is NOT divisible by 11" << endl;
    }
}