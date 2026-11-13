#include <iostream>
#include "../include/useable.h"
#include "../include/color.h"
void goToXY(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void applyColor(int color) {
    std::cout << "\033[" << color << "m";
}

void moveCursor(int x, int y){
  goToXY(x, y);
  applyColor(Colors::Yellow);

}
