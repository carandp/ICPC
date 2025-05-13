//  D - How many trees?

/**
    @author: carandp
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

// Int vectors
typedef vector<int> vi;
typedef vector<ll> vll;

// Int vectors of vectors
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Defs
#define fori(i, s, n) for(int i = s; i < n; i++)
#define DBG(X) cerr << #X << " = " << X << endl;
#define RAYA cerr << " ========================= " << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, h;

    cin >> n >> h;

    ll dp[n+1][n+1] = {};

    fori(i,0,n+1) dp[0][i] = 1;

    fori(i,1,n+1) {
        fori(j,1,n+1) {
            fori(k,0,i) {
                dp[i][j] += dp[k][j-1] * dp[i-k-1][j-1];
            }
        }
    }

    cout << (dp[n][n] - dp[n][h - 1]) << '\n';

    return 0;
}