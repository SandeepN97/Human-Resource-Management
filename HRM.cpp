
#include<iostream>
#include"HRM.h"
#include"Employee.h"

using namespace std;
HRM::HRM()
{
    empCount = 0;
    nextEmpCount = 1001;
}
/*
void HRM::setCount(int c)
{
    this->empCount = c;
}
*/

void HRM :: addEmployee()
{
    while (1)
    {
        cout << "Please enter the first name of an employee? ";
        string fname;
        cin >> fname;

        cout << "Please enter the last name of an employee? ";

        string lname;
        cin >> lname;

        cout << "How many hours a week is his/her work? ";
        float hours;
        cin >> hours;
        if (hours < 1 || hours > 60)
        {
            cout << "Error /n" << "Please enter hours between 1 and 60." << endl;
            cin >> hours;
        }
        cout << "How much per hour is his/her wage? ";
        float wage;
        cin >> wage;

        cout << "How much total deduction? ";
        float deduction;
        cin >> deduction;

        double salary = (hours * wage * 52) - deduction;


        Employee e(nextEmpCount, fname, lname, hours, wage, deduction, salary);

        //cout << e.get_firstName();
        emp[empCount] = e;
        emp[empCount].set_firstName(fname);
        emp[empCount].set_lastName(lname);
        emp[empCount].set_workingHours(hours);
        emp[empCount].set_costPerHours(wage);
        emp[empCount].set_deduction(deduction);
        emp[empCount].set_annualSalary(salary);
        HRM::empCount++;
        nextEmpCount++;
        //setCount(empCount);
        cout << endl;
        cout << "The employee with the following information has been added to the system :" << endl;
        cout << "Employee ID\t\tFirst Name\tLast Name\t\tSalary per year ($)" << endl;
        cout << "-----------------\t--------------\t-----------------\t--------------------------" << endl;
        cout << emp[empCount].get_employeeID() << "\t\t\t" << emp[empCount].get_firstName() << "\t\t" << emp[empCount].get_lastName() << "\t\t\t" << emp[empCount].get_annualSalary() << endl;
        cout << "Do you want to add another employee (y/n)? " << endl;
        string ans;
        cin >> ans;
        if (ans == "Y" || ans == "y")
        {
            continue;
        }
        else
            break;
    }
    
}

int HRM::searchEmployee()
{
    cout << "Please enter the employee ID?";
    int eid;
    cin >> eid;
        for (int i = 0; i < empCount; i++) {
            if (eid == emp[i].get_employeeID())
            {
                // we did find it..
                //right here 
                return eid;
                cout << "Employee ID\tFirst Name\tLast Name\tSalary per year ($)";
                cout << "-----------------\t--------------\t-----------------\t--------------------------";
                cout << emp[i].get_employeeID() << emp[i].get_firstName() << emp[i].get_lastName() << emp[i].get_annualSalary();
                cout << "Do you want to do new search (y/n)?" <<endl;
                string ans;
                cin >> ans;
                if (ans == "Y" || ans == "y")
                {
                    continue;
                }
                else
                    break;
            }
        }
    return -1;
}

void HRM :: deleteEmployee()
{
    //asking user for the employee id to be deleted
    //cout << "Please enter the employee ID? ";
    int eid = searchEmployee();
    //taking id from the user
    //cin >> eid;
    //int empid = HRM :: searchEmployee();
    //checking if user given empid is equal to the other
    
    //getting the index of the employee id
    for (int i = 0; i < empCount; i++)
    {
        //checking if the given id by user matches the id in the file. 
        if (eid = emp[i].get_employeeID())
        {
            //storing the index of the the employee id in another veribale.
            int epos;
            epos = i;
            //checking if the the user given employee id matches the id in file. 
            //if (eid == empid)
           //{
               //loop to iterate from the index that the id that is matched to the end of array
                for (int i = epos; i < empCount; i++)
                {
                   
                    cout << "Do you really want to delete employee" << emp[i].get_firstName() << " " << emp[i].get_lastName() << "(y / n)?" << endl;
                    string ans;
                    cin >> ans;
                    if (ans == "Y" || ans == "y")
                    {
                        emp[i] = emp[i + 1];
                        continue;
                    }
                    else
                        break;
                    //increasing the index to store the other value 
                    //deleting the employee information from the index that matches. 
                   // emp[i] = emp[i + 1];
                }
                //as we delete number of employee decreases. 
                empCount--;
           //}
        }
    }
}


void HRM :: updateEmployee()
{
    while (1)
    {
        cout << "Please enter the employee ID?";
        int eid;
        cin >> eid;
        for (int i = 0; i < empCount; i++) 
        {
            if (eid == emp[i].get_employeeID()) 
            {
                // we did find it....  ready to upddate
                while (1)
                {
                    cout << "Please enter the related number of field which you would like to update ?" << endl;
                    //menu for the user
                    cout << "1. First name" << endl;
                    cout << "2. Family name" << endl;
                    cout << "3. Working hours per week" << endl;
                    cout << "4. Payment for one hour" << endl;
                    cout << "5. deduction" << endl;
                    //getting choice from the user. 
                    int num;
                    cin >> num;
                    switch (num)
                    {
                            case 1:
                            {
                                cout << "Please enter the first name of an employee? ";
                                string fname;
                                cin >> fname;
                                this->emp[i].set_firstName(fname);
                                break;
                            }
                            case 2:
                            {
                                cout << "Please enter the last name of an employee? ";
                                string lname;
                                cin >> lname;
                                this->emp[i].set_lastName(lname);
                                break;
                            }
                            case 3:
                            {
                                cout << "How many hours a week is his/her work";
                                float hours;
                                cin >> hours;
                                if (hours < 1 || hours > 60)
                                {
                                    cout << "Error /n" << "Please enter hours between 1 and 60." << endl;
                                    cin >> hours;
                                }
                                this->emp[i].set_workingHours(hours);
                                break;
                            }
                            case 4:
                            {
                                cout << "Please enter new payment for one hour in $ for " << emp[i].get_firstName() << "?";
                                float wage;
                                cin >> wage;
                                this->emp[i].set_costPerHours(wage);
                                break;
                            }
                            case 5:
                            {
                                cout << "How much total deduction?";
                                float deduction;
                                cin >> deduction;
                                this->emp[i].set_deduction(deduction);
                                break;
                            }
                    }
                    float salary= emp[i].get_workingHours() * emp[i].get_costPerHour() * 52 - emp[i].get_deduction();
                    emp[i].set_annualSalary(salary);
                    // 1. First name, 2. Family name, 3. Working hours per week, 4. Payment for one hour, 5. deduction 
                    cout << "The information for " << emp[i].get_firstName() << " has been updated." << endl;
                    cout << "Do you want to update any other field (y/n)? ";
                    string ans;
                    cin >> ans;
                    if (ans == "Y" || ans == "y")
                    {
                        continue;
                    }
                    else
                        break;
                }
            }
            else
            {
                cout << "Sorry, there is no employee with this ID?" << endl;
            }      
        }
        cout << "Do you want to repeat update by entering new employee ID (y/n)?" << endl;
        string ans;
        cin >> ans;
        if (ans == "y" || ans == "Y")
        {
            continue;
        }
        else
            break;
    }
}

