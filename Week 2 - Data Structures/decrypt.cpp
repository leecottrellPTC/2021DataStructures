#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ostream>
#include <cmath>

using namespace std;

int main(){
    string line;
    string encrypted;
    int rotation = 5;

    ifstream fin;   //file input
    ofstream fout;  //file output

    fin.open("frost.enc");
    if(fin.fail()){
        cout << "Frost.txt did not open, quitting\n";
        return -1;
    }

    fout.open("frost2.txt");
    if(fout.fail()){
        cout << "Frost.enc did not open, quitting\n";
        return -2;
    }


    while(getline(fin, line)){
        //read one line at a tiome
        //will quit when it reaches the end
       // cout << line << endl;
       encrypted = "";
       //walk through each char in the line
       for(int c=0; c < line.length(); c++){
           encrypted += line.at(c) - rotation;
       }
       fout << encrypted << endl;
    }

    fout.close();//close the second opened first
    fin.close();

    cout << "File is encrypted!"<< endl;

}