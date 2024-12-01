//  B. Rakhsh's Revival

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;

        string s;
        cin >> s;

        int timars = 0;
        int numOfWeak = 0;

        for (char i: s) {
            if (!(i-'0')) numOfWeak++;
            else if (numOfWeak < 0) numOfWeak++;
            else numOfWeak = 0;

            if (numOfWeak >= m) {
                numOfWeak = -(k-1);
                timars++;
            }
        }
        cout << timars << '\n';
    }

    return 0;
}
