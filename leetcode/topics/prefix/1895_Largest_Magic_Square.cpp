//  1895. Largest Magic Square

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
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> hPreffixSum(n,vector<int>(m+1,0));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                hPreffixSum[i][j+1] = hPreffixSum[i][j] + grid[i][j];
            }
        }
        vector<vector<int>> vPreffixSum(m,vector<int>(n+1,0));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                vPreffixSum[i][j+1] = vPreffixSum[i][j] + grid[j][i];
            }
        }
        int res = min(n,m);
        while (res > 1) {
            for (int i=0;i<n-res+1;i++) {
                for (int j=0;j<m-res+1;j++) {
                    bool valid = true;
                    int rowSum = 0; // Check for row sum
                    for (int r=i;r<i+res;r++) {
                        int curr = hPreffixSum[r][j+res] - hPreffixSum[r][j];
                        if (rowSum == 0) rowSum = curr;
                        if (rowSum != curr) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;

                    int colSum = 0; // Check for col sum
                    for (int c=j;c<j+res;c++) {
                        int curr = vPreffixSum[c][i+res] - vPreffixSum[c][i];
                        if (colSum == 0) colSum = curr;
                        if (colSum != curr) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) continue;
                    if (rowSum != colSum) continue;

                    int d1Sum = 0; // Check for diag sum
                    int d2Sum = 0;
                    int di = i;
                    int dj1 = j;
                    int dj2 = j+res-1;
                    for (int d=0;d<res;d++) {
                        d1Sum += grid[di][dj1];
                        d2Sum += grid[di][dj2];
                        di++;
                        dj1++;
                        dj2--;
                    }

                    if (d1Sum == d2Sum && d1Sum == rowSum) return res;
                }
            }
            res--;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    vvi x = {{1}};
    cout << sol.largestMagicSquare(x) << nl;
    
}
