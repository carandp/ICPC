//  A. King Keykhosrow's Mystery

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(int& a, int& b) {
    int m = min(a,b);
    if (m%a == m%b) {
        cout << m << '\n';
        return;
    }
    while (true) {
        m++;
        if (m%a == m%b) {
            cout << m << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a,b;
        cin >> a >> b;

        solve(a,b);
    }
    
    return 0;
}
