//  C. Ordered Permutations

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        ll maxSp = 0;

        int multiplier = 1;
        for (int i=n; i>0; i--) {
            maxSp += multiplier*i;
            multiplier++;
        }

        vector<ll> pBase;
        for (int i=1; i<n+1; i++) {
            pBase.push_back(i);
        }

        vector<vector<ll>> permutations;
        permutations.push_back(pBase);

        while (next_permutation(pBase.begin(), pBase.end())) {
            permutations.push_back(pBase);
        }
    }
    
    return 0;
}
