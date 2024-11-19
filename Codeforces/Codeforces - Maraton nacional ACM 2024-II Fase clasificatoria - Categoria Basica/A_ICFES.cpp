//  A. ICFES

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;

    while (t--) {
        double long n, k;
        cin >> n >> k;
        double long p = 1/n;
        double long res = 1-pow(1-p,k);
        cout << fixed << setprecision(10) << res << endl;
    }
    return 0;
}
