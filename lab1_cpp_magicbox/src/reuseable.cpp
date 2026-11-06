#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>


void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


void goToXY(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}
