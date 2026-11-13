#include <iostream>
#include <iomanip>
#include "../include/employee_actions.h"

void displayEmployees(const COLL_Employee& employees) {
    std::cout << "\033[2J\033[H";
    const int count = employees.getCount();
    std::cout << "Employees (" << count << ")\n\n";

    if (count == 0) {
        std::cout << "No employees have been added yet.\n";
        return;
    }

    std::cout << std::left << std::setw(8) << "ID"
              << std::setw(24) << "Name"
              << std::setw(8) << "Age"
              << "Salary\n";
    std::cout << std::string(52, '-') << '\n';

    for (int i = 0; i < count; ++i) {
        const Employee* employeeptr=employees.getEmployees();
        const Employee& employee = employeeptr[i];
        std::cout << std::left << std::setw(8) << employee.getID()
                  << std::setw(24) << employee.getName()
                  << std::setw(8) << employee.getAge()
                  << employee.getSalary() << '\n';
    }
}