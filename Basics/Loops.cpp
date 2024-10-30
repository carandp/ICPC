#include <iostream>
#include <string> 
#include <cmath> 

using namespace std;

int main() {
    // ## Arrays

    int arr[] {1, 2, 3, 4, 5};
    cout << "This is the size of the array: " << endl;
    cout << size(arr) << endl;

    // ## For loops

    cout << "\nThis is a for loop: " << endl;
    for (int i = 0; i < size(arr); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}