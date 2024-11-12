//  B. Alice's Adventures in Permuting

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, b, c;
    cin >> n >> b >> c;

    if (c >= n) {
        cout << n << endl;
        return;
    }

    if (b == 0) {
        if (c < n-2) {
            cout << "-1" << endl;
        } else {
            cout << n-1 << endl;
        }
    } else if (n == b && b == c){
        cout << n << endl;
    } else {
        cout << n - max(0LL, ((n-c-1)/b+1)) << endl;
    }
}

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}