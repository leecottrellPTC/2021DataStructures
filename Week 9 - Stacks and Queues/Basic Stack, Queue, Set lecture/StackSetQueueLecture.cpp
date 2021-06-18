#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "FullName.h"
#include <stack>
#include <queue>
#include <set>
#include <fstream>
#include <iterator>

using namespace std;

void stringStack()
{
    stack<string> words;
    string aWord;

    //populating the stack
    words.push("word 1");
    words.push("word 2");
    words.push("word 3");
    words.push("word 4");
    words.push("word 5");

    cout << "Words in the stack " << words.size() << endl;

    //build interface to work with stack
    cout << "Word on the top of the stack-->" << words.top() << endl;
    aWord = words.top(); //get the word from the stack
    //do somethign with aWord
    words.pop();
    cout << "Words in the stack after pop " << words.size() << endl;
    cout << "Word on the top of the stack-->" << words.top() << endl;
}

void stackOfClass(){
    stack <fullName> clownCar;

    clownCar.push(fullName("Lee", "Cottrell"));
    clownCar.push(fullName("Dustin", "Dell"));
    clownCar.push(fullName("Lee", "McCready"));
    clownCar.push(fullName("Mason", "Dunkle"));
    clownCar.push(fullName("Vashti", "Overmiller"));

    fullName person;

    //walk through entire stack
    while(!clownCar.empty()){
        //person = clownCar.top();
        cout << clownCar.top().getFname() << " gets out"<< endl;
        clownCar.pop();
    }

}

queue <string> vocabWords;

void fillTheQueue(){
    vocabWords.push("computer");
    vocabWords.push("RAM");
    vocabWords.push("storage");
    vocabWords.push("CPU");
    vocabWords.push("motherboard");
}
void learnTheWords(){
    char again;
    while(!vocabWords.empty()){
        cout << "what is definition of " << vocabWords.front() << "?\n";
        cout << "Ready for next word? ";
        cin >> again;
        vocabWords.pop();
    }
}

set <string, less<string>> wordList;

void setOfWords(){
    wordList.insert("food");
    wordList.insert("candy");
    wordList.insert("apple");
    wordList.insert("chocolate");
    wordList.insert("chicken");
    wordList.insert("waffles");
    wordList.insert("food");

    cout << "Size of set " << wordList.size() << endl;

    //walk through the set
    //build an iterator, use a for loop
    set <string>::iterator itr; //this is a pointer into the set
    for(itr = wordList.begin(); itr != wordList.end(); itr++){
        //must derefence the pointer
        cout << *itr << endl;//give me value at the location of itr
    }
}

set <fullName, less<fullName>> people;

void fillTheSet(set <fullName, less <fullName>> &theSet){
    ifstream fin("fullnames.txt");
    if(fin.fail()){
        cout << "File not opened, dying\n";
        exit(1);
    }
    string fname, lname;
    while(!fin.eof()){
        fin >> fname >> lname;
        theSet.insert(fullName(fname, lname));
    }
    fin.close();
    cout << theSet.size() << " names read\n"; 
}

void printTheSet(set <fullName, less <fullName>> theSet){
    ostream_iterator<fullName> screen(cout, "\n");

    copy(theSet.begin(), theSet.end(), screen);
}

fullName findAPerson(set <fullName, less<fullName>> theSet, fullName person){
    set<fullName>::iterator found;

    found = theSet.find(person);

    if(found != theSet.end()){
        return *found;
    }
    else{
        return fullName("not", "found");
    }

}
int main()
{
    fillTheSet(people);
   // printTheSet(people);

    fullName peepToFind("sdfdasfaf", "Tirte");
    fullName found;

    found = findAPerson(people, peepToFind);
    cout << "I found " << found << endl;


   // setOfWords();
    //stringStack();
    //stackOfClass();
    //fillTheQueue();
    //learnTheWords();
  

}
