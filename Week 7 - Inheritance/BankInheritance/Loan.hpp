#ifndef LOAN_H
#define LOAN_H
#pragma once
#include "Account.hpp"
#include <string>
	
class Loan : public Account 
{
	protected:
		string type;
		double interest;
		double creditLimit;
	public:
		//setters, getters

		Loan(string AcctNum, string FirstName, string LastName, double Bal,
			string Type, double Rate, double CreditLimit);
			//parameterized constructor must include all of the parameters from the parent
		string to_string();
		Loan();
		~Loan();

};
#endif