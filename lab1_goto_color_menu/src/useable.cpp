#include <iostream>
#include "../include/useable.h"

void goToXY(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void applyColor(int color) {
    std::cout << "\033[" << color << "m";
}