//  2257. Count Unguarded Cells in the Grid

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
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<vector<int>> grid(m,vector<int>(n,0)); // Generate grid

        for (int i=0;i<walls.size();i++) { // Add all walls
            vector<int> wall = walls[i];
            grid[wall[0]][wall[1]] = 3;
        }

        for (int i=0;i<guards.size();i++) { // Add all guards
            vector<int> guard = guards[i];
            grid[guard[0]][guard[1]] = 2;
        }

        for (int g=0;g<guards.size();g++) {
            int row = guards[g][0];
            int col = guards[g][1];

            int curr = row+1;
            while (curr < grid.size()) { // Down
                if (!grid[curr][col] || grid[curr][col] == 1) grid[curr][col] = 1;
                else break;
                curr++;
            }
            curr = row-1;
            while (curr >= 0) { // Up
                if (!grid[curr][col] || grid[curr][col] == 1) grid[curr][col] = 1;
                else break;
                curr--;
            }
            curr = col+1;
            while (curr < grid[0].size()) { // Right
                if (!grid[row][curr] || grid[row][curr] == 1) grid[row][curr] = 1;
                else break;
                curr++;
            }
            curr = col-1;
            while (curr >= 0) { // Left
                if (!grid[row][curr] || grid[row][curr] == 1) grid[row][curr] = 1;
                else break;
                curr--;
            }
        }

        int total = 0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (!grid[i][j]) total++;
            }
        }

        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    int m = 4;
    int n = 6;
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    cout << sol.countUnguarded(m,n,guards,walls) << nl;
    
}
