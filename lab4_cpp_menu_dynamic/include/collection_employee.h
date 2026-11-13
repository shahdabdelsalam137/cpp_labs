#ifndef COLL_EMPLOYEE_H
#define COLL_EMPLOYEE_H

#include "employee.h"
#include <iostream>
#include <string>

// Linked List Node
struct DynamicEmployeeList {
    Employee data;
    DynamicEmployeeList* next;
};

struct COLL_Employee {

private:
    DynamicEmployeeList* employeeHead = nullptr;
    int employeeCount = 0;

public:

    // Add Employee
    void addEmployee(std::string name, int age, double salary) {

        // Data validation
        if (employeeCount >= 100) {
            std::cout << "The employee collection is full." << std::endl;
            return;
        }

        if (age <= 0) {
            std::cout << "The entered age is invalid." << std::endl;
            return;
        }

        if (salary <= 0) {
            std::cout << "The entered salary is invalid." << std::endl;
            return;
        }

        DynamicEmployeeList* newNode = new DynamicEmployeeList{
            Employee(employeeCount, name, age, salary),
            nullptr
        };

        if (employeeHead  == nullptr) {
            employeeHead = newNode;
        }
        else {

            DynamicEmployeeList* current = employeeHead ;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
        }

        employeeCount++;
    }
    DynamicEmployeeList* getEmployees() {
        return employeeHead;
    }

    const DynamicEmployeeList* getEmployees() const {
        return employeeHead;
    }

    int getCount() const {
        return employeeCount;
    }



};

#endif