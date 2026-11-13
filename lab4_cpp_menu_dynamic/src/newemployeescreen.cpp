#include <iostream>
#include <limits>
#include "../include/employee_actions.h"
// #include "../include/"
void addNewEmployee(COLL_Employee& employees) {
    int age;
    double salary;
    std::string name;
  
    std::cout << "\033[2J\033[H";
    std::cout<<"Enter the name of employee: ";
    std::cin>>name;
    std::cout<<std::endl;
    std::cout<<"Enter the age of employee: ";
    std::cin>>age;
    std::cout<<std::endl;
    std::cout<<"Enter the salary of employee: ";
    std::cin>>salary;
    std::cout<<std::endl;
    employees.addEmployee(name,age,salary);
}
