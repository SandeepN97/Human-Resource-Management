#pragma once
#ifndef HRM_H
#define HRM_H
#include "Employee.h"
class HRM 
{
private: 
	Employee emp[100];
	int empCount;
	int nextEmpCount;
public:
	void addEmployee();
	void deleteEmployee();
	void updateEmployee();
	int  searchEmployee();
	//void setCount(int);
	HRM();
};
#endif // !HRM_H
