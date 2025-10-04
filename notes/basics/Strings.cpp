#include <iostream>
#include <string> 
#include <cmath> 

using namespace std;

int main() {
    // ## String operations

    cout << "\nThis are string operators: " << endl;
    string abc = "abc";
    cout << abc[0] << endl;
    cout << abc.size() << endl;
    cout << abc.substr(1,abc.size()) << endl; // Excludes end

    // ## String modification

    abc[0] = 'c';
    cout << abc << endl;



    return 0;
}