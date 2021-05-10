#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
#define SIZE 1000

using namespace std;
int numbers[SIZE];  //global to speed access to the array
int bincounts[5] = {0,0,0,0,0};
int ranges[7];//this will be the limits avg + std or avg - std

void fillArrayRand();
void headArray(int howMany = 10);//default value parameter
void stats (int &mean, double &std);    //pass the variable address in
                                        //pass by reference
void bins(int mean, double std);

int main()
{
    srand(time(0));//seed the random generator by passing in the current time
    //start in a different place in the random list on the CPU
    fillArrayRand();
    //headArray();
    int mean = 0;
    double std = 0;
    stats(mean, std);
    cout << "mean " << mean << " std " << std << endl;

    bins(mean, std);
   // cout << bincounts[10] << endl;
}

void bins(int mean, double std){
    ranges[0] = mean - 3*std;
    ranges[1] = mean - 2*std;
    ranges[2] = mean - 1*std;
    ranges[3] = mean;
    ranges[4] = mean + 1*std;
    ranges[5] = mean + 2*std;
    ranges[6] = mean + 3*std;

    for(int x=0; x < SIZE; x++){
        if(numbers[x] >= ranges[0] && numbers[x] < ranges[1]){
            bincounts[0] ++;
        }
        else if(numbers[x] >= ranges[1] && numbers[x] < ranges[2]){
            bincounts[1] ++;
        }
        else if(numbers[x] >= ranges[2] && numbers[x] < ranges[4]){
            bincounts[2] ++;
        }
        else if(numbers[x] >= ranges[4] && numbers[x] < ranges[5]){
            bincounts[3] ++;
        }
        else if(numbers[x] >= ranges[5] && numbers[x] < ranges[6]){
            bincounts[4] ++;
        }
    }//end of for loop
    for(int x=0; x < 5; x++){
        cout << "Bin " << x << " has " << bincounts[x] << endl;
    }

}
void stats(int &mean, double &std){
    //mean = 100;
    //std = -75;
    //average
    int total = 0;
    for(int x=0; x < SIZE; x++){
        total += numbers[x];
    }
    mean = total / SIZE;

    total = 0;
    for(int x=0; x < SIZE; x++){
        total += pow(numbers[x] - mean, 2);
    }
    std = sqrt(total / (SIZE - 1.0));
}

void headArray(int howMany){
    //defaulted to 10
    for(int x=0; x < howMany; x++){
        cout << x + 1 << " " << numbers[x] << endl;
    }
}

void fillArrayRand(){
    //rand() returns a number between 1 and 65,535
    //between 1 and 100 var = rand() % 100 + 1;
    for(int x=0; x < SIZE; x++){
        numbers[x] = rand() % 100 + 1;
       // numbers[x] = rand() % 70 + 30;
    }
}