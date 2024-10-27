#include <iostream>
#include <string> 
#include <cmath> 

using namespace std;

int main() {
    // ## Comparison operators uses normal ones, <, >, <=, >=, !=, ==
    // ## Logical operators uses java notation, !, &&, ||

    // ## For logical comparison we use
    int x,y;
    cout << "Enter x value: " << endl;
    cin >> x;
    cout << "Enter y value: " << endl;
    cin >> y;
    cout << "This are conditionals: " << endl;
    if (x > y) {
        cout << "x > y" << endl;
    } else if (x < y) {
        cout << "x < y" << endl;
    } else {
        cout << "x == y" << endl;
    }

    return 0;
}