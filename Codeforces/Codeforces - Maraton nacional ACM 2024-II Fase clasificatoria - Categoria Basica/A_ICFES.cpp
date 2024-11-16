//  A. ICFES

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;

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
