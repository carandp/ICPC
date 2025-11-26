//  2435. Paths in Matrix Whose Sum Is Divisible by K

/**
    @author: carandp
*/

#include<bits/stdc++.h>
using namespace std;

/* types */
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

/* functions */
#define f(i, s, n) for(ll i = s; i < n; i++)
#define rf(i,n,s) for(ll i=n-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define nl "\n"
#define DBG(X) cerr << #X << " = " << X << endl;
#define LINE cerr << " ========================= " << endl;

/* prints */
template <class T>
void print_v(const vector<T> &v) {cout << "{"; f(i, 0, (int)v.size()) { cout << v[i]; if (i + 1 != (int)v.size()) cout << ",";}cout << "}";}
template <class T>
void print_vv(const vector<vector<T>> &vv) { cout << "{\n"; f(i, 0, (int)vv.size()) { cout << "  "; print_v(vv[i]); if (i + 1 != (int)vv.size()) cout << ","; cout << "\n";} cout << "}";}
template <class T, size_t N>
void print_a(const T (&arr)[N]) { cout << "{"; f(i,0,(int)N){ cout << arr[i]; if(i+1!=(int)N) cout << ",";} cout << "}"; }
template <class T, size_t R, size_t C>
void print_aa(const T (&mat)[R][C]) { cout << "{\n"; f(i,0,(int)R){ cout << "  {"; f(j,0,(int)C){ cout << mat[i][j]; if(j+1!=(int)C) cout << ",";} cout << "}"; if(i+1!=(int)R) cout << ","; cout << "\n";} cout << "}"; }

/* utils */
const ll MOD = 1e9 + 7;
ll gcdll(ll a, ll b) { return b == 0 ? a : gcdll(b, a % b); }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }
ll mod_pow(ll a, ll b, ll m = MOD) {ll res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;} return res;}
ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m);}
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a;}
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod = pow(10,9) + 7;
        int m = grid.size();
        int n = grid[0].size();

        // dp(i,j,r) = Number of paths to i,j with residue r
        vector<vector<vector<int>>> dp(m,vector(n,vector(k,0)));

        dp[0][0][grid[0][0]%k]++; // Init 0,0

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (!i && !j) continue;
                for (int r=0;r<k;r++) {
                    if (!i) dp[i][j][(r+grid[i][j])%k] = dp[i][j-1][r]; // Previous col number of paths
                    else if (!j) dp[i][j][(r+grid[i][j])%k] = dp[i-1][j][r]; // Previous row number of paths
                    else dp[i][j][(r+grid[i][j])%k] = (dp[i][j-1][r] + dp[i-1][j][r])%mod; // Previous col + row number of paths % mod
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    // vector<vector<int>> grid = {{0,0,0}};
    vector<vector<int>> grid = {{0},{0},{3}};
    int k = 3;
    cout << sol.numberOfPaths(grid,k) << nl;
    
}
