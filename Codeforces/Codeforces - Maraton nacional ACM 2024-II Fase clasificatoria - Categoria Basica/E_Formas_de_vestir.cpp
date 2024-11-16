//  E. Formas de vestir

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;

    while (t--) {
        ll n,m;
        cin >> n >> m;
        ll busos[n];
        ll pantalones[m];

        for (ll i=0; i<n;i++) {
            cin >> busos[i];
        }
        for (ll i=0; i<m;i++) {
            cin >> pantalones[i];
        }

        ll res = 0;

        for (ll b=0; b<n; b++) {
            for (ll p=0; p<m; p++) {
                res += busos[b] * pantalones[p] * 2;
            }
        }

        cout << res << endl;

    }
    
    return 0;
}
