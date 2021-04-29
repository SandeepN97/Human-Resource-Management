/*The Employee class Implementation(hrm.cpp)*/
/* */
//user-defined header in the same directory
#include "Employee.h"
#include "HRM.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//Constructior
//default values shall only be specified int eh declaration,
//cannot be repeated in definition



//default constructor with the default parameter
Employee::Employee()
{
	employeeID = 1001;
	firstName = "No Name";
	lastName = "No Name";
	wrokingHours = 0.0;
	costPerHour = 0.0;
	deduction = 0.0;
	annualSalary = 0.0;
}


//parameterized constructor
Employee::Employee(int eid, string fName, string lName, float wHours, float cpHours, float ded, double aSal)
{
	this -> employeeID = eid;
	this -> firstName = fName;
	this-> lastName = lName;
	this-> wrokingHours = wHours;
	this-> costPerHour = cpHours;
	this-> deduction = ded;
	this-> annualSalary = aSal;
}

//defining setter methods
void Employee::set_employeeId(int eid)
{
	this -> employeeID = eid;
}

void Employee :: set_firstName(string fName)
{
	this -> firstName = fName;
}

void Employee :: set_lastName(string lName) 
{
	this -> lastName = lName;
}

void Employee::set_workingHours(float wHours)
{
	this -> wrokingHours = wHours;
}
 
void Employee::set_costPerHours(float cpHours)
{
	this -> costPerHour = cpHours;
}

void Employee::set_deduction(float ded) 
{
	this -> deduction = ded;
}

void Employee::set_annualSalary(double aSal)
{
	this -> annualSalary = aSal;
}

//getter function defination 
int Employee::get_employeeID() 
{
	return this -> employeeID;
}

string Employee :: get_firstName()
{
	return  this -> firstName;
}

string Employee :: get_lastName()
{
	return this -> lastName;
}

float Employee :: get_workingHours()
{
	return this -> wrokingHours;
}

float Employee::get_costPerHour()
{
	return this -> costPerHour;
}

float Employee :: get_deduction()
{
	return this -> deduction;
}

double Employee::get_annualSalary()
{
	return this -> annualSalary;
}

int main()
{
	
	HRM hrm;
	string word;
	fstream empFile;
	int recordCount = 0;
	//To read a file in the text mode
	//ifstream employee { "employee.txt" };
	//employee << "File can be tricky, but it is fun enough!";
	empFile.open("employee.txt");
	if (empFile.is_open())
	{
		string myLine;
		while (getline(empFile,myLine))
		{
			//int eid;
			string fName;
			string lName;
			
			cout << myLine << endl;
			
			recordCount++;
		}
		empFile.close();

	}
	//hrm.setCount(recordCount);
	while (true) 
	{
		int choice;

		cout << "Welcome to Human Resource Management (HRM)." << endl;
		cout << "Main Menu" << endl;
		cout << "1. Add new employee" << endl;
		cout << "2.Delete an Employee" << endl;
		cout << "3.Update Employee Information" << endl;
		cout << "4.Search for an Employee" << endl;
		cout << "5. Quit\n Please enter your choice 1..5 :" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			hrm.addEmployee();
			break;
		case 2:
			hrm.deleteEmployee();
			break;
		case 3:
			hrm.updateEmployee();
			break;
		case 4:
			hrm.searchEmployee();
			break;
		default:
			exit(0);
			cout << endl;
		}
	}
}

/*
 string line;
	ifstream myfile;
	myfile.open("myfile.txt");

   if(!myfile.is_open()) {
	  perror("Error open");
	  exit(EXIT_FAILURE);
   }
	while(getline(myfile, line)) {
	 cout << line << endl;
	}
*/