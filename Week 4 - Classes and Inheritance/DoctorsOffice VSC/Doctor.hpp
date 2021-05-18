#ifndef DOCTOR_H
#define DOCTOR_H
#pragma once
	//inherits from person
#include "person.hpp"
#include <string>
class Doctor : public person
{
	private:

	public:

		Doctor();
		~Doctor();
		Doctor(string first, string last, string spec);
		void setSpeciality(string spec);
		string getSpeciality();
		string getId();
		inline void buildId(){
			//Lee Cottrell Programmer
			//id = DrLCottrell-Pro
			id = "Dr" + firstName.substr(0, 1) + lastName + 
				"-" + speciality.substr(0,3);
		}

		inline string to_string(){
			return "Doctor " + person::to_string();
		}
	
	protected:
		string speciality;
		string id;

};
#endif