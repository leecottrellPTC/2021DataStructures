#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"

using namespace std;

int main()
{
    //unorderedLinkedList<string> words;
    orderedLinkedList<string> words;

    words.insertLast("hi");
    words.insertLast("there");
    words.insertLast("class");
    words.insertLast("this");
    words.insertLast("this");
    words.insertLast("is");
    words.insertLast("easy");

    words.deleteNode("this");

    words.print();

    cout << endl;

    cout << " length " << words.length() << endl;

    if (words.search("there"))
    {
        cout << "word is in the list\n";
    }
    else
    {
        cout << "wword is not in the list\n";
    }

}