#ifndef FULL_NAME
#define FULL_NAME
using namespace std;
#include <iostream>

class fullName {
protected:
	string fname;
	string lname;
public:
	friend ostream& operator <<(ostream& out, const fullName& person) {
		out <<  person.lname << ", " << person.fname;
		return out;
	}

	fullName& operator = (const fullName rhs) {

		fname = rhs.fname;
		lname = rhs.lname;
		return *this;
	}

	fullName() {
		fname = "";
		lname = "";
	}
	fullName(string First, string Last) {
		fname = First;
		lname = Last;
	}
	void setFname(string First) {
		fname = First;
	}
	void setLname(string Last) {
		lname = Last;
	}
	string getFname() {
		return fname;
	}
	string getLname() {
		return lname;
	}

	friend istream& operator >>(istream& in, fullName& person) {
		in >> person.fname >> person.lname;
		return in;
	}
	friend bool operator <(fullName lhs, fullName rhs) {
		return lhs.lname < rhs.lname;	//simple cheesy sort by last name, might have problems with 
	}

	friend bool operator >(fullName lhs, fullName rhs) {
		return lhs.lname > rhs.lname;	//simple cheesy sort by last name, might have problems with 
	}

	friend bool operator ==(const fullName lhs, const fullName rhs) {
		return (lhs.lname == rhs.lname) && (lhs.fname == rhs.fname);	//simple cheesy sort by last name, might have problems with 
	}

};

#endif
