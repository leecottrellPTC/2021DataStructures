#ifndef PATIENT_H
#define PATIENT_H
#pragma once
#include <string>
#include "person.hpp"
//#include "person.cpp"
using namespace std;
	
class patient : public person {
public:
	patient();
	patient(string first, string last, string complaint);
	inline string to_string() {
		return "Patient " + person::to_string() + " complaint " + complaint;
	}
protected:
	string complaint;
};
#endif