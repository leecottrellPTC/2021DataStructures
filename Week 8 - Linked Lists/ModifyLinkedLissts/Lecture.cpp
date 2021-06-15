#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "linkedList.h"
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
using namespace std;

int main()
{
    orderedLinkedList <string> words, newlist;
    words.initializeList();
    words.insertLast("hi");
    words.insertLast("there");
    words.insertLast("class");
    words.insertLast("apple");
    words.insertLast("hungry");
    words.print();
   
   cout << endl << "New list" << endl;
   newlist.insertLast("Data");
   
   words.divideMid(newlist);        //what happpens to list with data?
   //newlist.divideMid(words);    //how do you split an empty list?
   newlist.print();

}