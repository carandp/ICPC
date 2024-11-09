#include <iostream>
#include <string> 
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

// ## Longest common prefix

// Function prefix uses reference *& to string for speed
string prefix(string& s1, string& s2) {
    string r = "";
    const int n = min(s1.size(), s2.size());
    for (int i=0; i<n; i++) {
        if (s1[i] != s2[i]) {
            break;
        }
        r += s1[i];
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        // Save all words to an array in lowercase
        string arr[n];
        for (int i=0; i<n; i++) {
            string p;
            cin >> p;
            transform(p.begin(), p.end(), p.begin(), ::tolower);
            arr[i] = p;
        }
        string r = arr[0];
        int m = sizeof(arr)/sizeof(arr[0]);
        for (int i=1; i < m; i++) {
            r = prefix(r, arr[i]);
        }
        if (r == "") {
            cout << '*' << endl;
        } else {
            cout << r << endl;
        }
        cin >> n;
    }
    return 0;
}