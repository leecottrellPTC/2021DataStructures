#ifndef SCHEDULE_H
#define SCHEDULE_H
#pragma once

#include "Patient.hpp"
#include "Doctor.hpp"
	
class Schedule  
{
	protected:
		patient thePatient;
		Doctor theDoc;
		int hour;

	public:

		Schedule();
		Schedule(patient pat, Doctor doc, int hr);
		void setPatient(patient pat);
		void setDoctor(Doctor doc);
		void setHour(int hr);
		int getHour();
		patient getPatient();
		Doctor getDoctor();
		~Schedule();
		inline string to_string(){
			return thePatient.to_string() + " will see " + theDoc.to_string() +
				" at " + std::to_string(hour) + " o:clock";
		}

};
#endif