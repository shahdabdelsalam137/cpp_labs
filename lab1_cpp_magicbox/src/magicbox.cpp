#include <iostream>
#include <iomanip>
#include "../include/reuseable.h"
#include "../include/magicbox.h"

void MovePosIndex(int &row, int &col, int n, int value) {

    if (value % n == 0) {
        row = (row + 1) % n;
    }
    else {
     row=(row-1+n)%n;
     col=(col+1)%n;
    }
}

void magicBoxOdd(int n) {

    int M = n * (n * n + 1) / 2;

    int mp = (n - 1) / 2;

    int row = 0;
    int col = mp;

    for (int i = 1; i <= n * n; i++) {
          goToXY(col * 4 + 1, row + 1);
          std::cout<<std::setw(3)<<i;
          std::cout.flush();
        delay(200);
        MovePosIndex(row, col, n, i);
    }

    std::cout<<std::endl;
    std::cout<<"Magic Constant: "<<M<<std::endl;
}