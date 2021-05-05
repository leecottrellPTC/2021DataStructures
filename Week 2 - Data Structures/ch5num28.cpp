#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

//another way to do program wide constant
#define MAINT 27
#define INCREASE 40
#define SYS cout

using namespace std;
/*
    ch5num28 - calculate the 'optimum rent'
    we will increase rent by 40, decrease units by 1
    keep looping as long as newProfit > prevProfit
    once out of loop, undo the last change
    print out the results
*/

int main(){
    int rent = 600, units = 50;
    int prevProfit = 0, newProfit = 1;
    //SYS << "Cool it outputs " << MAINT << endl;
    do{
        //guaranteed ONE execution
        //post - check after loop body
        prevProfit = newProfit; //hang onto the last profit
        rent += INCREASE;   //add the rent
        units --;           //subtract the units
        newProfit = (rent - MAINT) * units;

    }while(prevProfit <= newProfit);

    //found the optimum
    units++;            //undone the algorithm
    rent -= INCREASE;   //undone the algorithm
    cout << "Optimum rent is " << rent << " With " << units << " rented" << endl;

   /* while(prevProfit < newProfit){
        //guarantee NO execution
        //pre test - check before loop body
    }
    */

}
