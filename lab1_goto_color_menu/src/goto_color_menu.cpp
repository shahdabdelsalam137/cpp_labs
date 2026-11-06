#include <iostream>
#include "../include/color.h"
#include "../include/goto_color_menu.h"
#include "../include/useable.h"

void printXYColor(const std::string& text, int x, int y, int color) {
    goToXY(x, y);
    applyColor(color);
    std::cout << text << std::endl;
    applyColor(Colors::White);
}

