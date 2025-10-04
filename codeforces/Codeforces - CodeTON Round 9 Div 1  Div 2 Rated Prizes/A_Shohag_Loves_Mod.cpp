//  A. Shohag Loves Mod

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int c = 1;
        while(n--) {
            if (n != 0) cout << c << " ";
            else cout << c << "\n";
            c += 2;
        }
    }
    return 0;
}