#pragma once


/*The Employee class Header(Employee.h)*/
#ifndef Employee_H
#define Employee_H
#include <string>

using namespace std;

//blueprint fo Employee class
class Employee
{
private: //Accessible for member of the class only
//private data member(veriable)
	int employeeID;
	string firstName;
	string lastName;
	float wrokingHours;
	float costPerHour;
	float deduction;
	double annualSalary;
public:
	//member function for the class employee
	//setter (mutator) function
	void set_employeeId(int);
	void set_firstName(string);
	void set_lastName(string);
	void set_workingHours(float);
	void set_costPerHours(float);
	void set_deduction(float);
	void set_annualSalary(double);

	//getter(accessor) function
	int get_employeeID();
	string get_firstName();
	string get_lastName();
	float get_workingHours();
	float get_costPerHour();
	float get_deduction();
	double get_annualSalary();
	Employee();
	Employee(int, string, string, float, float, float, double);
};
#endif // !employee header included 
