#ifndef ACCOUNT_H
#define ACCOUNT_H
#pragma once
#include <string>
using namespace std;
	
class Account  
{
	private:
	//these are NOT inherited by child classes
	protected:
	//these are inherited by child classes
		string acctNum;
		string fname;
		string lname;
		double balance;
	public:
	//inherited by child classes
		void setAcctNum(string AcctNum);
		void setFname(string FirstName);
		void setLname(string LastName);
		void setBalance(double Bal);

		string getAcctNum();
		string getFname();
		string getLname();
		double getBalance();

		string to_string();

		bool deposit(double amt);
		bool withdraw(double amt);
		bool transfer(double amt, Account toAccount);


		Account(string AcctNum, string FirstName, string LastName, double Bal);
		Account();
		~Account();

};
#endif