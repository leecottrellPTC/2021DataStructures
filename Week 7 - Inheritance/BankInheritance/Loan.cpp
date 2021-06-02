#include "Loan.hpp"  
	
Loan::Loan():Account()  //call the parent constructor
{
	type = "Credit Card";
    interest = .18;
    creditLimit = 1000;
}

Loan::Loan(string AcctNum, string FirstName, string LastName, double Bal,
			string Type, double Rate, double CreditLimit):Account(AcctNum, FirstName, LastName, Bal){
                                                            //call to parent parameterized constructor
    type = Type;
    interest = Rate;
    creditLimit = CreditLimit;
}

//use parent to_string in the child to_string
string Loan::to_string(){
    string output;

    output = Account::to_string();  //calls parent version of to_string
                                    //set it to my output variable

    output += "\n";
    output += "Type " + type + " " + std::to_string(interest) + " Credit Limit $"
    + std::to_string(creditLimit); 

    return output;
}
	
Loan::~Loan()
{
	
}