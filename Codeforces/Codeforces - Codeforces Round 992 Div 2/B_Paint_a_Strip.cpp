//  B. Paint a Strip

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) cout << "1\n";
        else if (n == 2) cout << "2\n";
        else {
            int moves = 2;
            int painted = 4;
            while (painted < n) {
                moves++;
                painted++;
                painted*=2;
            }
            cout << moves << '\n';
        }

    }
    
    return 0;
}
