// TimingLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <fstream>
#include <windows.h>	//need for timing
#include <random>		//need to finish shuffle
#include <vector>
#include <set>
#include <map>

//stl array

using namespace std;
//array<string, 370099> manyWords;
//vector <string> manyWords;
//set <string> manyWords;
map <string, string> manyWords;
int WORDS = 0;


void swap(string* xp, string* yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}
// A function to implement bubble sort  
/*void bubbleSort()
{
	int i, j;
	for (i = 0; i < WORDS - 1; i++) {
		// Last i elements are already in place  
		for (j = 0; j < WORDS - i - 1; j++) {
			if (manyWords[j] > manyWords[j + 1])
				swap(&manyWords[j], &manyWords[j + 1]);
		}
		//cout << i << " ";
	}
}*/
/*
court
courter
*/

void fillStructure() {
	//int counter = 0;
	string aWord = "";
	ifstream fin("words.txt");
	if (fin.fail()) {
		cout << "words failed\n";
		exit(1);
	}

	while (!fin.eof()) {
		fin >> aWord;
		//manyWords[WORDS] = aWord;//array
		//manyWords.push_back(aWord);//vector
		//manyWords.insert(aWord);//set
		manyWords[aWord] = aWord;	//map
		WORDS++;
	}
	fin.close();
	cout << WORDS << " words read\n";
	
}
int main()
{

	long afterMS;
	long beforeMS;
	long elapsedMS;

	SYSTEMTIME time;
	
	GetSystemTime(&time);	//gets the exact time when called
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	
	fillStructure();

	GetSystemTime(&time);
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	elapsedMS = afterMS - beforeMS;
	cout << "Time to read file " << elapsedMS << " MS " << endl;

	//search the set

	//manyWords.find("computer");//search the set is instant (0ms)

	//search the array
	//binary search depends on sorted file
/*
	GetSystemTime(&time);	//gets the exact time when called
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	
	binary_search(manyWords.begin(), manyWords.end(), "computer");

	GetSystemTime(&time);
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	elapsedMS = afterMS - beforeMS;
	cout << "Time to search array " << elapsedMS << " MS " << endl;

*/
	//linear or brute force search

/*
	random_device rnd;	//real random
	shuffle(manyWords.begin(), manyWords.end(), rnd);

	GetSystemTime(&time);	//gets the exact time when called
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	
	vector<string>::iterator word;
	for(word = manyWords.begin(); word != manyWords.end(); word++){
		if(*word == "computer"){
			break;
		}
	}


	GetSystemTime(&time);
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	elapsedMS = afterMS - beforeMS;
	cout << "Time to linear search array " << elapsedMS << " MS " << endl;

*/

/*
	//sort array
	random_device rnd;	//real random
	shuffle(manyWords.begin(), manyWords.end(), rnd);
	GetSystemTime(&time);	//gets the exact time when called
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	
	sort(manyWords.begin(), manyWords.end());

	GetSystemTime(&time);
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	elapsedMS = afterMS - beforeMS;
	cout << "Time to sort array " << elapsedMS << " MS " << endl;
	*/
}
