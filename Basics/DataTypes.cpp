#include <iostream>
#include <string> // Used to include string type
#include "DataTypes.h"

using namespace std; // Used to shorten std::cout -> cout

int dataTypes() {
    cout << "This are all variable types!" << endl; // endl is used to end line

    int a = 4; // Saves 4 bytes
    cout << "Integer: " << a << endl;
    long long b = 8; // Saves 8 bytes
    cout << "Long long: " << b << endl;
    float c = 0.4; // Saves 4 bytes
    cout << "Float: " << c << endl;
    double d = 0.8; // Saves 8 bytes
    cout << "Double: " << d << endl;
    bool e = true; // Saves 0 or 1
    cout << "Bool: " << e << endl;
    string f = "text"; // Saves a string
    cout << "String: " << f << endl;
    char g = 'c'; // Saves 1 byte
    cout << "Char: " << g << endl;

    return 0;
}