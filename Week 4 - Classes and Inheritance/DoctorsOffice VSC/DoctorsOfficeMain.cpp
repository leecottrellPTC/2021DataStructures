#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Person.cpp"
//#include "Person.hpp"
#include "Patient.cpp"
//#include "Patient.hpp"
#include "Doctor.cpp"
#include "Schedule.cpp"

#define SIZE 10
//Doctor doctors[SIZE];
Schedule appointments[SIZE];
int apptBookSize = 0;
Doctor house("Gregory", "House", "Jerkiness");
int hours = 8;//use to add to appt book
              //start at 8, add one for each person added to book

void fillApptBook();
void printApptBook();
void searchByLname(string lname);
int searchByHour(int hour);
void addSchedule();

using namespace std;
void menu();
int main()
{

    /*  cout << lee.to_string() << endl;
    cout << joeBob.to_string() << endl;
    cout << house.to_string() << endl;
    cout << house.getId() << endl;
    */
    // cout << house << endl;
    fillApptBook();
    menu();
}

void addSchedule() {
    string fname, lname, complaint;
    cout << "Enter first and last name ";
    cin >> fname >> lname;

    cout << "Enter " << fname << "'s complaint ";
    //clear the enter
    cin.ignore(100, '\n');//clear the enter in the keyboard buffer
    getline(cin, complaint);

    patient pat = patient(fname, lname, complaint);
    appointments[apptBookSize] = Schedule(pat, house, hours);
    hours++;        //add one to hours, I am controlling when they see me
    apptBookSize++;     //next position in the array
}//end of addSchedule


int searchByHour(int hour)
{
    for (int x = 0; x < apptBookSize; x++)
    {
        if (appointments[x].getHour() == hour)
        {
            return x; //return the int
        }
    }
    return -1; //not found
}
//brute force search
//starts at the begining of the data
//keeps looking until it finds what it wants
void searchByLname(string lname)
{
    for (int a = 0; a < apptBookSize; a++)
    {
        if (appointments[a].getPatient().getLastName() == lname)
        {
            cout << appointments[a].to_string() << endl;
        }
    }
}

void printApptBook()
{
    for (int a = 0; a < apptBookSize; a++)
    {
        //use the size of the array that is populated
        cout << appointments[a].to_string() << endl;
    }
}
void fillApptBook()
{
    patient kate("kate", "Upton", "back ache");
    patient joeBob("Joe", "Bob", "Headache");
    patient spongeBob("Sponge", "Bob", "split his pants");
    hours = 8;
    
    appointments[0] = Schedule(kate, house, hours);
    apptBookSize++;
    hours++;

    appointments[1] = Schedule(joeBob, house, hours);
    apptBookSize++;
    hours++;

    appointments[2] = Schedule();
    appointments[2].setDoctor(house);
    appointments[2].setPatient(spongeBob);
    appointments[2].setHour(hours);
    apptBookSize++;
    hours++;
}

void menu()
{
    char choice;
    int hourToFind;
    string lname;
    int found;
    int pos;
    do
    {
        cout << "Enter 1 to print schedule\n";
        cout << "Enter 2 to add to the schedule\n";
        cout << "Enter 3 to search by hour\n";
        cout << "Enter 4 to search by patient lastname\n";
        cout << "Enter 9 to quit\n";
        cin >> choice;
        switch (choice)
        {
        case '2':
            //2 = add to schedule
            if (apptBookSize < SIZE)
            {
                addSchedule();
            }
            else
            {
                cout << house.to_string() << " has no open appointments\n";
            }
            // break;
            //pass through to the next case
        case '1':
            //1 = print schedule
            printApptBook();
            break;
        case '3':
            //3 = search by hour
            cout << "Enter hour to find -> ";
            cin >> hourToFind;
            found = searchByHour(hourToFind);
            if (found > -1)
            {
                cout << appointments[found].to_string() << endl;
            }
            else
            {
                cout << "Hour " << hourToFind << " not scheduled" << endl;
            }

            break;
        case '4':
            //4 = search by last name
            cout << "Enter a last name to search for -> ";
            cin >> lname;
            searchByLname(lname);
            break;
        case '9':
            //9 = quit
            cout << "Bye Bye\n";
            break;
        default:
            cout << choice << " is invalid, enter 1, 2, or 9\n";
            break;
        }

    } while (choice != '9');
} //end of menu
