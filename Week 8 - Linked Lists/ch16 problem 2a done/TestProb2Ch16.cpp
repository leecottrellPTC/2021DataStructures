#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "linkedList.h"
#include "unorderedLinkedList.h"

using namespace std;

int main()
{
    unorderedLinkedList<int> numbers;
    numbers.insertLast(10);
    numbers.insertLast(3);
    numbers.insertLast(5);
    numbers.insertLast(-2);
    numbers.insertLast(1);
    numbers.insertLast(11);
    numbers.insertLast(15);
    numbers.insertLast(32);


    
    cout << "Before Deletion\n";
    numbers.print();

    //call delete smallest here

    numbers.deleteSmallest();

    cout << "\n\nAfter Deletion\n";
    numbers.print();

}