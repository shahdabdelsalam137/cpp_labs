#include <iostream>
#include "../include/useable.h"
#include "../include/tc.h"
#include "../include/collection_employee.h"
#include "../include/employee.h"
using namespace std;
// here we will create the array of employees that exist in the system

int main() {
    COLL_Employee employees;


    std::cout << "\033[2J\033[H";
    goToXY(10, 7);
    cout << " New Employee" << endl;
    goToXY(10, 9);
    cout << " Display Employees" << endl;
    goToXY(10, 11);
    cout << " Exit" << endl;
    goToXY(8, 7);
    cout << ">> " << std::flush;

    while (readArrowKey(employees)) {
    
    }

    return 0;
}
