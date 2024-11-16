//  B. Juego del agua

#include<bits/stdc++.h>

using namespace std;

int main() {
    // INCORRECT

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    string estados;

    cin >> estados;

    // Procesar string
    char inicial = '-';
    for (char i: estados) {
        if (i != '-') {
            inicial = i;
            break;
        }
    }
    char final = '-';
    if (inicial == 'N') {
        final = 'C';
    } else if (inicial == 'C') {
        final = 'N';
    }

    bool estaban[n];
    for (int i=0; i<n; i++) {
        estaban[i] = false;
    }

    for (int c0 = 0; c0 < estados.size(); c0++) {
        if (estados[c0] == 'C' || estados[c0] == 'N') estaban[c0] = true;
    }
    int cif = estados.size()-1;
    while(estados[cif] != inicial) {
        cif--;
    }
    int cfi = 0;
    while(estados[cfi] != final) {
        cfi++;
    }

    while (q--) {
        int p;
        cin >> p;

        if (estaban[p-1]) {
            cout << '!' << endl;
        } else if (p-1 < cif) {
            cout << inicial << endl;
        } else if (p-1 > cfi) {
            cout << final << endl;
        } else {
            cout << '?' << endl;
        }
    }
    
    return 0;
}
