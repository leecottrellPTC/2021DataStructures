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
		//inline because they are SO small
		inline string getType(){
			return type;
		}

		inline double getInterest(){
			return interest;
		}

		inline double getCreditLimit(){
			return creditLimit;
		}

		//standard setters
		inline void setType(string Type){
			type = Type;
		}

		inline void setCreditLimit(double Limit=100){
			//defaulted to 100 in both the param and if
			if(Limit > 0){
			creditLimit = Limit;
			}
			else{
				creditLimit = 100;
			}
		}

		inline void setInterest(double rate = .05){
			if(rate >=0 && rate < .3){
				interest = rate;
			}
			else{
				interest = .05;
			}
		}
		
		Loan(string AcctNum, string FirstName, string LastName, double Bal,
			string Type, double Rate, double CreditLimit);
			//parameterized constructor must include all of the parameters from the parent
		string to_string();
		Loan();
		~Loan();

};
#endif