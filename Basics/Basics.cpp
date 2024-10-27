#include <iostream>
#include <string> // Used to include string type
#include <cmath> // Used to power numbers

using namespace std; // Used to shorten std::cout -> cout

int main() {

    // ## Data Types

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

    // ## User input output

    cout << "\nThis is for user input/output: " << endl;
    int x;
    int y;
    cout << "Enter x value: " << endl;
    cin >> x;
    cout << "Enter y value: " << endl;
    cin >> y;

    // ## Arithmetic operators

    cout << "\nThis are the arithmetic operators: " << endl;
    cout << "x+y = " << x + y << endl;
    cout << "x-y = " << x - y << endl;
    cout << "x*y = " << x * y << endl;
    cout << "x/y = " << x / y << endl;
    cout << "x%y = " << x % y << endl; // Can result in negative if x is negative, to fix add y
    cout << "(Python like) x%y = " << (x%y + y)%y<< endl;
    // Order is BEDMAS (Brackets Exponents Divisions Multiplications Additions Subtraction)
    cout << "x++ = " << x++ << endl; // Out: x, x += 1
    cout << "++x = " << ++x << endl; // Out: x + 1, x += 1
    cout << "2^3 = " << pow(2,3) << endl; // Power from cmath

    // ## String operations

    cout << "\nThis are string operators: " << endl;
    string abc = "abc";
    cout << abc[0] << endl;
    cout << abc.size() << endl;
    cout << abc.substr(1,abc.size()) << endl; // Excludes end

    // ## Type conversion

    cout << "\nThis are type conversions: " << endl;
    string ten = "10";
    long long num = stoi(ten); // Convert string to number
    cout << "This is num*10: " + to_string(num*10) << endl; // Convert number to string

    return 0;
}