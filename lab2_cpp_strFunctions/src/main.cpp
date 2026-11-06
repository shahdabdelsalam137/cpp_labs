#include <iostream>
#include "../include/stringImp.h"
using namespace std;
#define IGNORECASE 1
#define CASESENSITIVE 0
int main()
{
    char name[100];
    char name2[100];
    char copiedName[100];

    // toUpper test
    cout << "Enter a name: ";
    cin >> name;

    toUpper(name,name);
    cout << "Uppercase: " << name << endl;

    // toLower test
    cout << "\nEnter another name: ";
    cin >> name2;

    toLower(name2,name2);
    cout << "Lowercase: " << name2 << endl;

    // strCopy test
    strCopy( name,copiedName);
    cout << "\nCopied name: " << copiedName << endl;

    // strComp test
    cout << "\nComparison result: "
         << strComp(name, name2, IGNORECASE) << endl;

    return 0;
}