//  B. Juego del agua

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    string bottles;

    cin >> bottles;

    bool known[n] = {false};

    for (int i = 0; i < n; i++) {
        if (bottles[i] == 'C' || bottles[i] == 'N') known[i] = true;
    }

    if (n == 1) {
        if (bottles[0] == '-') bottles[0] = '?';
    } else {
        int cif = n-1;
        while(cif > 0 && bottles[cif] != 'C') {
            cif--;
        }
        for (int i=0; i < cif; i++) {
            bottles[i] = 'C';
        }

        int cfi = 0;
        while(cfi < n && bottles[cfi] != 'N') {
            cfi++;
        }
        for (int i=n-1; i > cfi; i--) {
            bottles[i] = 'N';
        }

        for (int i=0; i < n; i++) {
            if (bottles[i] == '-') bottles[i] = '?';
        }
    }

    while (q--) {
        int p;
        cin >> p;
        if (known[p-1]) {
            cout << '!' << endl;
        } else {
            cout << bottles[p-1] << endl;
        }
    }
    
    return 0;
}
