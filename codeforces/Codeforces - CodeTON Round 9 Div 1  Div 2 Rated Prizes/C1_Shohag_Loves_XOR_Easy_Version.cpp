//  C1. Shohag Loves XOR (Easy Version)

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        ll x, m;
        cin >> x >> m;

        ll c = 0;
        for (ll y=1; y<=min(m,2*x); y++) {
            if (x != y && ((x%(x^y)==0)||(y%(x^y)==0))) c++;
        }
        cout << c << "\n";
    }
    return 0;
}
