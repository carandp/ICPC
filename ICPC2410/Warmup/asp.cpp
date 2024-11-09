#include <iostream>
#include <string> 
#include <cmath> 

using namespace std;

// ## given N symbols 1<N<1000, ret len asp
// asp is a word built from an alphabet of N symbols
// there is no substring of asp more than once within it
// no two consecutive symbols in A are the same
// ex: n = 3, asp = 12 | 13 | 23 | 1, len(asp)=7

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        int resp = 0;
        for (int i = 1; i < n; i++) {
            resp += i;
        }
        cout << resp*2+1 << endl;
        cin >> n;
    }
    return 0;
}