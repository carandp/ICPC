//  D. Darius' Wisdom

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(const int n, int c[]) {
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    bool ordered = true;
    for (int i=0; i<n-1; i++) {
        if (c[i] > c[i+1]) {
            ordered = false;
            break;
        }
    }
    if (ordered) {
        cout << 0 << '\n';
        return;
    }

    // Build swapMap and solution
    map<int, set<int>> swapMap;
    swapMap[0] = {};
    swapMap[1] = {};
    swapMap[2] = {};

    int solution[n];
    int solutionCounter = 0;

    for (int i=0; i<n; i++) {
        swapMap[c[i]].insert(i);
    }

    for (int _: swapMap[0]) {
        solution[solutionCounter++] = 0;
    }
    for (int _: swapMap[1]) {
        solution[solutionCounter++] = 1;
    }
    for (int _: swapMap[2]) {
        solution[solutionCounter++] = 2;
    }

    // Start solving
    int moves = 0;
    string solutionString;

    for (int i=0; i<n; i++) {
        while (c[i] != solution[i]) {
            int pillar = c[i];
            int swapIndex = *swapMap[pillar-1].rbegin();

            swapMap[pillar-1].erase(swapIndex);
            swapMap[pillar].erase(i);

            swapMap[pillar].insert(swapIndex);
            swapMap[pillar-1].insert(i);

            c[i] = c[swapIndex];
            c[swapIndex] = pillar;

            solutionString.append(to_string(i+1) + ' ' + to_string(swapIndex+1) + '\n');
            moves++;
        }
    }

    cout << moves << '\n';
    cout << solutionString;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int c[n];
        for (int i=0; i<n; i++) {
            cin >> c[i];
        }
        solve(n,c);
    }
    return 0;
}
