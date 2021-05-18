#include "Schedule.hpp"  
	
Schedule::Schedule()
{
	hour = 0;

}

Schedule::Schedule(patient pat, Doctor doc, int hr){
    thePatient = pat;
    theDoc = doc;
    hour = hr;
}

void Schedule::setPatient(patient pat){
    thePatient = pat;
}
	
patient Schedule::getPatient(){
    return thePatient;
}

void Schedule::setDoctor(Doctor doc){
    theDoc = doc;
}

Doctor Schedule::getDoctor(){
    return theDoc;
}

void Schedule::setHour(int hr){
    hour = hr;
}
int Schedule::getHour(){
    return hour;
}
Schedule::~Schedule()
{
	
}