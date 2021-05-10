#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
int temps[365][2];//rows and columns
//data name[rowNum][colNum];
//data name[rowNum][colNum][depth];
int recordsRead=-1;
int readFile(string path);
void showArray(int howMany = 365);
void processArray();
//find low temp and high temp for each column
int lowOfLow=100, lowOfHigh=100, highOfHigh=0, highOfLow = 0;
//force the current low to be larger than most values
//force the current high to be bigger than most values

int main()
{
    cout << readFile("temps.txt") << " records read " << endl;
    //showArray(20);
    processArray();

}
void processArray(){
    int row, col;
     for(row = 0; row < 365; row++){
        /*for(col = 0; col < 2; col++){
            
         }//end of for col
         */
        if(temps[row][1] > highOfHigh){
            //current temp is bigger than the current max
            highOfHigh = temps[row][1];
        }
        if(temps[row][1] < lowOfHigh){
            //min of a columns
            lowOfHigh = temps[row][1];
        }
     }//end of for row

     cout << "High of High column " << highOfHigh << endl;
     cout << "Low of High column " << lowOfHigh << endl;
}

void showArray(int howMany){
    int row, col;
    //for(row = 0; row < 365; row++){//process entire array
    for(row = 0; row < howMany; row++){
        for(col = 0; col < 2; col++){
            cout << temps[row][col] << " ";
        }
        cout << endl;
    }
}

int readFile(string path){
    ifstream fin;
    int day;
    fin.open(path);
    if(fin.fail()){
        cerr << path << " not opened" << endl;
        exit(1); 
    }

    cout << "File opened\n";
    while(!fin.eof()){
        recordsRead++;
        fin >> day >> temps[recordsRead][0] >> temps[recordsRead][1];
       
    }

    fin.close();
    return recordsRead;
}