//  474. Ones and Zeroes

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
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(101,vector<int>(101,0)); // dp(i,j,k) i = pos, j = 0's, k = missing 1's, ret = set size

        for (int i=0;i<strs.size();i++) {
            int numZeros = 0;
            int numOnes = 0;
            for (int c=0;c<strs[i].size();c++) {
                if (strs[i][c] - '0') numOnes++;
                else numZeros++;
            }

            for (int j=m;j>=numZeros;j--) {
                for (int k=n;k>=numOnes;k--) {
                    dp[j][k] = max(dp[j][k],dp[j-numZeros][k-numOnes]+1); // max(size curr subset, size complement subset adding strs[i])
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vector<string> strs = {"10","0001","111001","1","0"};
    // int m = 5;
    // int n = 3;
    // vector<string> strs = {"10","0","1"};
    // int m = 2;
    // int n = 2;
    vector<string> strs = {"0111","110010","1","10","1100001111","0","11110011","1","01000","010100","11101","0","1001","0","00100","01011","10","1","1111110","1","00","00001","110","0"};
    int m = 99;
    int n = 99;
    cout << sol.findMaxForm(strs, m, n) << nl;
    
}
