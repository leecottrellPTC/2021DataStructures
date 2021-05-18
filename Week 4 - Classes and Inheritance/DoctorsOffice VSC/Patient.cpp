#include "Patient.hpp"  
	
patient::patient() :person() {
	complaint = "";
}
patient::patient(string first, string last, string concern) : person(first, last) {
	complaint = concern;
}