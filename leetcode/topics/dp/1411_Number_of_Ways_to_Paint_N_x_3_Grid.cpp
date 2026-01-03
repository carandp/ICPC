//  1411. Number of Ways to Paint N × 3 Grid

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
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, 0))));

        for (int p1 = 0; p1 <= 3; p1++)
            for (int p2 = 0; p2 <= 3; p2++)
                for (int p3 = 0; p3 <= 3; p3++)
                    dp[n][p1][p2][p3] = 1;

        for (int i=n-1;i>=0;i--) {
            for (int prev1=0;prev1<=3;prev1++) {
                for (int prev2=0;prev2<=3;prev2++) {
                    for (int prev3=0;prev3<=3;prev3++) {
                        long long res = 0;
                        for (int col1=1;col1<=3; col1++) {
                            if (col1 == prev1) continue;
                            for (int col2=1;col2<=3;col2++) {
                                if (col2==prev2 || col2==col1) continue;
                                for (int col3=1;col3<=3;col3++) {
                                    if (col3==prev3 || col3==col2) continue;
                                    res = (res + dp[i + 1][col1][col2][col3]) % mod;
                                }
                            }
                        }
                        dp[i][prev1][prev2][prev3] = res;
                    }
                }
            }
        }

        return dp[0][0][0][0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vi x = {1, 2, 3, 1};
    // cout << sol.method(x) << nl;
    
}