//  A. Twice

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
        ll box[n];
        for (ll i=0; i<n;i++) {
            cin >> box[i];
        }

        if (n == 1) {
            cout << 0 << endl;
        } else {
            map<ll,ll> m;
            ll visited[n] = {false};
            for (ll i=0; i<n; i++) {
                for (ll j=(i+1); j<n; j++) {
                    if (box[i] == box[j]) {
                        if (!m.contains(box[i])) {
                            m[box[i]] = 2;
                        } else if (visited[i] == false || visited[j] == false) {
                            m[box[i]] += 1;
                        }
                        visited[i] = true;
                        visited[j] = true;
                    }
                }
            }
            ll maxScore = 0;
            if (m.empty()) {
                cout << maxScore << endl;
            } else {
                for (auto & val : m) {
                    maxScore += (val.second)/2;
                }
                cout << maxScore << endl;
            }
        }
    }
    return 0;
}
