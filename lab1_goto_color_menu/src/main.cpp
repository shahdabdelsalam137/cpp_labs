
#include <iostream>
#include "../include/color.h"
#include "../include/goto_color_menu.h"

int main() {
  printXYColor("Main menu",10,5,Colors::Yellow);
 printXYColor("New Screen",10,7,Colors::Blue);
 printXYColor("Display Screen",10,9,Colors::Cyan);
  printXYColor("Exit",10,11,Colors::Magenta );
    return 0;
}