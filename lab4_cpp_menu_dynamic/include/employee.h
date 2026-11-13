#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <utility>

struct Employee {
private:
    int id = 0;
    std::string name;
    int age= 0;
    double salary= 0.0;
public:
    Employee() = default;

    Employee(int id, std::string name, int age, double salary)
         {
            this->id=id;
            this->name=name;
            this->age=age;
            this->salary=salary;
         }

    int getID() const {
        return id;
    }

    const std::string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getSalary() const {
        return salary;
    }


};

#endif
