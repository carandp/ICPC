//  840. Magic Squares In Grid

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
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3) return 0;
        int res = 0;
        for (int r=1;r<n-1;r++) {
            for (int c=1;c<m-1;c++) {
                bool isValid = true;
                vector<int> sumR(3,0);
                vector<bool> visited(16,false);
                for (int i=r-1;i<r+2;i++) {
                    for (int dx=-1;dx<2;dx++) {
                        if (grid[i][c+dx] > 9 || grid[i][c+dx] < 1) isValid = false;
                        if (visited[grid[i][c+dx]]) isValid = false;
                        visited[grid[i][c+dx]] = true;
                        sumR[dx+1] += grid[i][c+dx];
                    }
                }
                if (!isValid) continue;
                if (sumR[0] != sumR[1] || sumR[1] != sumR[2]) continue;

                vector<int> sumC(3,0);
                for (int j=c-1;j<c+2;j++) {
                    for (int dx=-1;dx<2;dx++) {
                        sumC[dx+1] += grid[r+dx][j];
                    }
                }
                if (sumC[0] != sumC[1] || sumC[1] != sumC[2]) continue;

                int sumD1 = grid[r-1][c-1] + grid[r][c] + grid[r+1][c+1];
                int sumD2 = grid[r+1][c-1] + grid[r][c] + grid[r-1][c+1];
                if (sumR[0] != sumC[0] || sumC[0] != sumD1 || sumD1 != sumD2) continue;

                res++;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    vvi grid = {
        {3,2,9,2,7},
        {6,1,8,4,2},
        {7,5,3,2,7},
        {2,9,4,9,6},
        {4,3,8,2,5}
    };
    cout << sol.numMagicSquaresInside(grid) << nl;
    
}