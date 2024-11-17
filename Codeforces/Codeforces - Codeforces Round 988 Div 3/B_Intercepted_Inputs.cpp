//  B. Intercepted Inputs

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(const vector<ll> & grid, const ll gridSize, const ll k) {
    for (ll i=0; i<gridSize; i++) {
        for (ll j=i+1; j<gridSize; j++) {
            if (grid[i] * grid[j] == k-2) {
                cout << grid[i] << " " << grid[j] << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;

        ll grid[k];
        for (ll i=0; i<k; i++) {
            cin >> grid[i];
        }
        sort(grid, grid + sizeof(grid)/sizeof(grid[0]));

        // Clean to just 2 unique numbers
        vector<ll> gridUnique;
        ll past = -1;
        ll pastc = 0;
        for (ll i=0; i<k; i++) {
            if (grid[i] != past) {
                gridUnique.push_back(grid[i]);
                past = grid[i];
                pastc = 0;
            } else if (pastc < 1) {
                gridUnique.push_back(grid[i]);
                pastc++;
            }
        }

        solve(gridUnique, gridUnique.size(), k);
    }
    
    return 0;
}
