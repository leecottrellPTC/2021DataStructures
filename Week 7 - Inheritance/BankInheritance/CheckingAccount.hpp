#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#pragma once

#include "Account.hpp"
class CheckingAccount : public Account
{
	private:

	protected:
		double fee;

	public:

		//setters and getters
		inline void setFee(double Fee){
			//fee = Fee;
			if(Fee > 0 && Fee < 100){
				fee = Fee;
			}
			else{
				fee = 10;
			}
		}

		double getFee();
		//parameterizrd constructor

		//to_string
		string to_string();
		
		CheckingAccount(string AcctNum, string FirstName, 
			string LastName, double Bal, double Fee);
		CheckingAccount();
		~CheckingAccount();

		void applyFee();

};
#endif