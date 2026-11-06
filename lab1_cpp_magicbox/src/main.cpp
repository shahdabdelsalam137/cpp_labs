#include <iostream>
#include "../include/magicbox.h"
int main(){
    int odd;
    std::cout<<"Enter an odd number : ";
     std::cin>>odd;
     std::cout<<"\033[2J";
    magicBoxOdd(odd);


    return 0;

}