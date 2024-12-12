//  A. Game of Division

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int n,k;
        cin >> n >> k;

        int a[n];

        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        bool found = false;
        for (int i=0; i<n; i++) {
            bool valid = true;
            for (int j=0; j<n; j++) {
                if (i!=j && abs(a[i]-a[j])%k == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cout << "YES\n";
                cout << i+1 << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << "NO\n";
    }
    return 0;
}
