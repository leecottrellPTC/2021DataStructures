#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iterator>

using namespace std;
vector <double> numberVec;
int vectorSize = 0;

void fillTheVector(){
    for(int x=0; x < vectorSize; x ++){
        numberVec.push_back(rand() % 5000);
    }
    cout << "Vector size " << numberVec.size() << endl;
    cout << "Vector capacity " << numberVec.capacity() << endl;
}

//parse the vector
//build iterator
void parseVector(){
    vector<double>::iterator itr;
    numberVec.push_back(4200);
    //for(itr = numberVec.begin(); itr != numberVec.begin() + 10; itr++){  
        //hard to find items when youy are only looking at 10 of them :(
    for(itr = numberVec.begin(); itr != numberVec.end() + 10; itr++){  
        if(*itr == 42){
            cout << "Works!\n";
        }   
    }
}
int main()
{
    srand(time(NULL));
    vectorSize = (int) (rand() % 5000) + 4000;

    fillTheVector();
    sort(numberVec.begin(), numberVec.end());

    parseVector();
    cout << endl;
    cout << numberVec.at(100) << endl;  //positional array lookup
}