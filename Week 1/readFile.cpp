// readFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>  //file stream

using namespace std;

int main()
{
	ifstream fin;	//input file stream
	int atbats, hits, walks, number, vomit;
	double batAvg;

	//fin.open("c:\\data\\stats.txt");//open a path
	fin.open("stats.txt");//open in same folder
    //system("color 5f");//run a DOS command
    //if you want color output on screen
        
    //check that the file opend
    //if not, then quit
	if (!fin.is_open()) {
		cout << "file did not open, quitting";
		return 1;
	}

	while (!fin.eof()) {
		fin >> number >> atbats >> hits >> walks;
		//batAvg = hits / (double) (atbats - walks);//typcast
        /*
            batAvg = hits / (atBats - walks)
            Little League formula
	   */
		if (atbats - walks == 0) {
			batAvg = 0;
		}
		else {
			batAvg = hits / static_cast<double>(atbats - walks); //typcast - preferred way
		}

		cout << "I read " << number << " " << atbats << " " << hits << " "
			<< walks << " Bat Avg " << setprecision(3) << fixed << batAvg << endl;
									//force 3 decimal places
	}
	
	fin.close();
}
