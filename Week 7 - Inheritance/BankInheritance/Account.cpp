#include "Account.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>

Account::Account()
{
    //set to a default value
    acctNum = "no account";
    balance = 0;
    fname = "";
    lname = "";
}

Account::Account(string AcctNum, string FirstName, string LastName, double Bal)
{
    acctNum = AcctNum;
    fname = FirstName;
    lname = LastName;
    balance = Bal;
}

Account::~Account()
{
}

//getters
#pragma region getters
string Account::getAcctNum()
{
    return acctNum;
}

string Account::getFname()
{
    return fname;
}

string Account::getLname()
{
    return lname;
}

double Account::getBalance()
{
    return balance;
}

#pragma endregion

#pragma region setters
//setters
void Account::setAcctNum(string AcctNum)
{
    acctNum = AcctNum;
}

void Account::setFname(string FirstName)
{
    fname = FirstName;
}

void Account::setLname(string LastName)
{
    lname = LastName;
}

void Account::setBalance(double bal)
{   //ensure setting a balance will stay above 0
    if (bal >= 0)
    {
        balance = bal;
    }
    else
    {
        balance = 0;
    }
}
#pragma endregion

#pragma region methods

string Account::to_string(){
   std::stringstream ss;
    //thanks Mason for the ss to string trick


    ss << "Account " << acctNum << ": " << fname << " " << lname << " ($" << fixed << setprecision(2) << balance << ")";



    return ss.str();
}

bool Account::deposit(double amt){
    if(amt > 0){
        balance += amt;
        return true;
    }
    return false;
}

bool Account::withdraw(double amt){
    if(amt <=0){
        return false;
    }
    else if(amt < balance){
        balance -= amt;
        return true;
    }
    else{
        return false;
    }
}

bool Account::transfer(double amt, Account &toAccount){
    if(withdraw(amt) == false){
        return false;
    }

    if(toAccount.deposit(amt) == false){
        return false;
    }

    return true;    //if I get here, then the tranfer worked

}


#pragma endregion
