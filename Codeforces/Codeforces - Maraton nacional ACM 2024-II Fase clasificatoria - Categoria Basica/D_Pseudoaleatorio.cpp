//  D. Pseudoaleatorio

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    while (n != 0) {
        if (k==0) {
            cout << 0 << endl;
        } else {
            ll semillacuad = k * k;
            string sn = to_string(semillacuad);
            while (sn.size() < 2*n) {
                sn = "0" + sn;
            }

            string res = "";
            for (ll i = 0; i < n; i++) {
                res = sn[n-1+n/2-i] + res;
            }

            cout << stoll(res) << endl;
        }

        cin >> n >> k;
    }
    
    return 0;
}
