#include <iostream>
using namespace std;


int getSize(char Input[]) {
    int counter = 0;

    while (Input[counter] != '\0') {
        counter++;
    }

    return counter;
}

// toUpper
void toUpper(char Input[], char result[]) {
    int counter = 0;

    while (Input[counter] != '\0') {

        if (Input[counter] >= 'a' && Input[counter] <= 'z') {
            result[counter] = Input[counter] - 32;
        }
        else {
            result[counter] = Input[counter];
        }

        counter++;
    }

    result[counter] = '\0';
}

// toLower
void toLower(char Input[], char result[]) {
    int counter = 0;

    while (Input[counter] != '\0') {

        if (Input[counter] >= 'A' && Input[counter] <= 'Z') {
            result[counter] = Input[counter] + 32;
        }
        else {
            result[counter] = Input[counter];
        }

        counter++;
    }

    result[counter] = '\0';
}

// strCopy
void strCopy(char Input[], char result[]) {

    int counter = 0;

    while (Input[counter] != '\0') {
        result[counter] = Input[counter];
        counter++;
    }

    result[counter] = '\0';
}

// strComp
bool strComp(char Input1[], char Input2[], bool ignoreCase) {

    char temp1[100];
    char temp2[100];

    if (ignoreCase) {
        toLower(Input1, temp1);
        toLower(Input2, temp2);
    }
    else{
     strCopy(Input1, temp1);
     strCopy(Input2, temp2);
    }

    if (getSize(temp1) != getSize(temp2)) {
        return false;
    }

    int counter = 0;

    while (temp1[counter] != '\0') {

        if (temp1[counter] != temp2[counter]) {
            return false;
        }

        counter++;
    }

    return true;
}

