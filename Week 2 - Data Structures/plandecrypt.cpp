// Lecture1Rotation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
   string line;
   string decrypted;
   string encChar;
   char encValue;
   ifstream fin;
   ofstream fout;
   int rotation = 5;
   fin.open("frost.enc");//open the file
   fout.open("frost2.txt");
   if (fin.fail()) {//ensure file is opened
       cout << "Could not open the file. Quitting. Have a nice day:)";
       return 1;//error
       //fix or die
   }//file fails

   if (fout.fail()) {//ensure file is opened
       cout << "Could not open the output file. Quitting. Have a nice day:)";
       return 2;//error
       //fix or die
   }//file fails

   //process the file

   while (getline(fin, line)) {
       //cout << line << endl;
       //encrypt each char in the line
       decrypted = ""; //reset the string to empty
       for (int c = 0; c < line.length(); c++) {
           //encrypted += line.at(c) + rotation;
           
           
           
           encChar = line.at(c) - rotation;
           encValue = static_cast<int> (encChar[0]);
           cout << (int)encValue << " " << encChar << endl;
         
           if(encValue > 92 && encValue < 97){
               encValue += rotation;            
           }
           else if(encValue > 59 && encValue <64){
                encValue += rotation;
           }
           
          // cout << encValue << " ";
           decrypted += encValue;
       }
       fout << decrypted << endl;
       //cout << encrypted << endl;
   }

  // cout << "File is opened" << endl;
   fin.close();//close the file
   fout.close();

}

