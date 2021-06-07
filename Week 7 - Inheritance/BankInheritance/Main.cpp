#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <array>

using namespace std;
#include "Account.cpp"
//#include "Account.h"// for Visual Studio users
#include "Loan.cpp"
#include "CheckingAccount.cpp"

array<Account, 2> bankAccounts;
int main()
{
  //  Account lee;
    Account laurie("12345", "Laurie", "Cottrell", 500);
    CheckingAccount lecture("11111", "Demo", "Class", 1500, 25);

  //  bankAccounts[0] = lee;
 //   bankAccounts[1] = laurie; 

  //  for(int x=0; x < 2; x++){
  //      cout << bankAccounts[x].to_string() << endl;
  //  }

 //   Loan school;
 //   Loan creditCard("11111", "Some", "Poor Soul", 12345, "Credit Card", .18, 50000);

  //  cout << "Loan output \n" << creditCard.to_string() << endl;

  ///  lee.setAcctNum("54321");
  //  lee.setBalance(100);
 //   lee.setFname("Lee");
 //   lee.setLname("Cottrell");

    //check methods
 //   laurie.transfer(250, lee);

 /*   if(laurie.deposit(-10000) == false){
        cout << "Deposit failed\n";
    }
    if(laurie.withdraw(444444) == false){
        cout << "Withdraw failed\n";
    }

    cout << fixed << setprecision(2);
    cout << lee.to_string() << endl;
    */
    cout << laurie.to_string() << endl;

    lecture.deposit(500);
    lecture.applyFee();
    cout << lecture.to_string() << endl;
    
}