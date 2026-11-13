#include "../include/tc.h"
#include "../include/useable.h"
#include "../include/employee_actions.h"
#include <cstdio>
#include <iostream>
#include <unistd.h>

class Cursor{
private:
     int x;
     int y;
public:
     Cursor(int x,int y)
     {
        this->x=x;
        this->y=y;
     };

     void SetCursorPosition(char arrow){
                  switch (arrow) {
                case 'A':
                    y-=2;
                    break;

                case 'B':
                    y+=2;
                    break;
            }
      if(y>11){
         y=7;
      }
       else if(y<7){
        y=11;
      }
      getCursor();
     };

     void getCursor(){
        goToXY(x,y);
        std::printf(">> ");
        std::fflush(stdout);
     }
     int getPosition(){
        return y;
     }

};

namespace {

void drawMenu(int selectedY) {
    std::cout << "\033[2J\033[H";
    goToXY(10, 7);
    std::cout << " New Employee";
    goToXY(10, 9);
    std::cout << " Display Employees";
    goToXY(10, 11);
    std::cout << " Exit";
    goToXY(8, selectedY);
    std::cout << ">> " << std::flush;
}

}

char getch_linux() {
    char buf = 0;

    struct termios old{};
    struct termios raw = old;

    if (tcgetattr(0, &old) == -1) {
        return buf;
    }

    raw = old;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &raw) == -1) {
        return buf;
    }

    read(0, &buf, 1);

    tcsetattr(0, TCSADRAIN, &old);
    return buf;
}


bool readArrowKey(COLL_Employee& employees) {
    static Cursor cursor(8, 7);  // will not die with readArrow key function and will always be local variable 
    
        char byte1 = getch_linux();
        if (byte1 == 'q' || byte1 == 'Q') {
            goToXY(10,13);
            return false;
        }
       else  if (byte1 == '\033') {
            char byte2 = getch_linux();
            char byte3 = getch_linux();

            if (byte2 == '[' && (byte3 == 'A' || byte3 == 'B')) {
                goToXY(8, cursor.getPosition());
                std::printf("   ");
                cursor.SetCursorPosition(byte3);
            }
        }
        else if(byte1 == '\r'||byte1 == '\n'){
            goToXY(1, 13);
            switch (cursor.getPosition()) {
            case 7:
                addNewEmployee(employees);
                goToXY(1, 13);
                std::cout << "\nPress any key to return to the menu."
                          << std::flush;
                getch_linux();
                drawMenu(cursor.getPosition());
                break;
            case 9:
                displayEmployees(employees);
                goToXY(1, 13);
                std::cout << "\nPress any key to return to the menu."
                          << std::flush;
                getch_linux();
                drawMenu(cursor.getPosition());
                break;
            case 11:
                std::cout << "Exiting menu.                          "
                          << std::flush;
                return false;
            }
        }
    return true;
}