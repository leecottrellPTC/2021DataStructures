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
	//cout << vomit << endl;
	/*
		batAvg = hits / (atBats - walks)
		Little League formula
	*/

	//check to see if file opened
	//before you use the file

	system("color 5f");//run a DOS command

	if (!fin.is_open()) {
		cout << "file did not open, quitting";
		return 1;
	}

	while (!fin.eof()) {
		fin >> number >> atbats >> hits >> walks;
		//batAvg = hits / (double) (atbats - walks);//typcast

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
	/*fin >> number >> atbats >> hits >> walks;

	cout << "I read " << number << " " << atbats << " " << hits << " "
		<< walks << endl;

	fin >> number >> atbats >> hits >> walks;

	cout << "I read " << number << " " << atbats << " " << hits << " "
		<< walks << endl;
		*/
	fin.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
