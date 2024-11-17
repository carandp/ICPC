//  C. Superultra's Favorite Permutation

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        if (n < 5) {
            cout << "-1" << endl;
        } else {
            if (n%2 == 0) {
                // even
                string res = "";
                for(ll i=2; i<n+1; i+=2) {
                    if (i != 6) {
                        res += to_string(i);
                        res.push_back(' ');
                    }
                }
                res += "6 3 1 ";
                for(ll i=5; i<n+1; i+=2) {
                    res += to_string(i);
                    if (i != n-1) res.push_back(' ');
                }
                cout << res << endl;
            } else {
                // odd
                string res = "";
                for(ll i=1; i<n+1; i+=2) {
                    if (i != 5) {
                        res += to_string(i);
                        res.push_back(' ');
                    }
                }
                res += "5 4 2 ";
                for(ll i=6; i<n+1; i+=2) {
                    res += to_string(i);
                    if (i != n-1) res.push_back(' ');
                }
                cout << res << endl;
            }
        }
    }
    
    return 0;
}
