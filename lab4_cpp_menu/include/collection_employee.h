#ifndef COLL_EMPLOYEE_H
#define COLL_EMPLOYEE_H

#include "employee.h"

#include <iostream>
#include <string>

class COLL_Employee {
private:
        Employee employees[100];
        int employeeCount = 0;


public:
        void addEmployee(std::string name,int age,double salary){
        // data validation 
        if (employeeCount >= 100) {
            std::cout << "The employee collection is full." << std::endl;
            return;
        }
        if(age<=0){
            std::cout<<"the entered age is invalid "<<std::endl;
            return ;
            
        }
        if (salary<=0){
            std::cout<<"the entered salary is invalid "<<std::endl;
            return ;
        }
        employees[employeeCount]=Employee(employeeCount,name,age,salary);
        employeeCount++;

        }

         int getCount() const {
            return employeeCount;

        }

        const Employee* getEmployees() const {
            return employees;
        }
};

  

#endif
