#include "CheckingAccount.hpp"  
	
CheckingAccount::CheckingAccount() :Account()
{
	fee = 5;
}
	
CheckingAccount::~CheckingAccount()
{
	
}

CheckingAccount::CheckingAccount(string AcctNum, 
    string FirstName, string LastName,
    double Bal, double Fee) : Account(AcctNum, FirstName, LastName, Bal ){
        if(Fee > 0 && Fee < 100){
            fee = Fee;
        }
        else{
            fee = 5;
        }

    }

double CheckingAccount::getFee(){
    return fee;
}

void CheckingAccount::applyFee(){
    balance -= fee;
}

string CheckingAccount::to_string(){
    string output;
    output = Account::to_string();
    output += "\nFee is $" + std::to_string(fee);
    
    return output;
}