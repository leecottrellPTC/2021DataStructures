#ifndef PERSON_H
#define PERSON_H
#pragma once
	
#include <string> 

using namespace std;

class person
{
public:
	//inline to_string - makes the function call faster - only with short methods
	inline string to_string() {

		return lastName + ", " + firstName;;
	}
    void setName(string first, string last);
	void setFirstName(string first);
	void setLastName(string last);
    string getFirstName() ;
    string getLastName() ;
    person(string first, string last);
	person();
        

 protected:
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name
};

#endif