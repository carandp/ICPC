//  2536. Increment Submatrices by One

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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        /* Solution with 1D difference array (per row)!

        vector<vector<int>> diff(n,vector<int>(n,0));
        for (int i=0;i<queries.size();i++) { // Build difference 1D arrays
            vector<int> query = queries[i];
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];
            for (int row=row1;row<=row2;row++) {
                if (col2 < n-1) diff[row][col2+1] -= 1;
                diff[row][col1] += 1;
            }
        }
        vector<vector<int>> res(n,vector<int>(n,0));
        for (int i=0;i<n;i++) {
            int curr = 0;
            for (int j=0;j<n;j++) {
                curr += diff[i][j];
                res[i][j] = curr;
            }
        }
        return res;

        */

        /* Optimized version 2D difference array! */

        vector<vector<int>> diff(n,vector<int>(n,0));
        for (int i=0;i<queries.size();i++) { // Build difference 2D array
            vector<int> query = queries[i];
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];
            diff[row1][col1] += 1;
            if (col2+1 < n) diff[row1][col2+1] -= 1;
            if (row2+1 < n) diff[row2+1][col1] -= 1;
            if (row2+1 < n && col2+1 < n) diff[row2+1][col2+1] += 1;
        }

        vector<vector<int>> res(n,vector<int>(n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int above = 0;
                if (i) above = res[i - 1][j];
                int left = 0;
                if (j) left = res[i][j - 1];
                int diag = 0;
                if (i && j) diag = res[i - 1][j - 1];
                res[i][j] += diff[i][j] + above + left - diag;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    vector<vector<int>> queries = {{1,1,2,2},{0,0,1,1}};
    int n = 3;
    sol.rangeAddQueries(n,queries);

}
