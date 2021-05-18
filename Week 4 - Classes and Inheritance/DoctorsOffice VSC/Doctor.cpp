#include "Doctor.hpp"  
	
Doctor::Doctor():person()//call the person default constructor
{
	speciality = "";
    id = "";
}

Doctor::Doctor(string first, string last, string spec):person(first, last){
    speciality = spec;
    buildId();//call my function to set an ID
}

void Doctor::setSpeciality(string spec){
    speciality = spec;
    buildId();
}

string Doctor::getSpeciality(){
    return speciality;
}

string Doctor::getId(){
    return id;
}

Doctor::~Doctor()
{
	
}