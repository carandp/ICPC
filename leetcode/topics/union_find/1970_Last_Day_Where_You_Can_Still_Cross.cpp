//  1970. Last Day Where You Can Still Cross

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
    class DisjointUnionSets {
    public:
        vector<int> rank, parent;

        DisjointUnionSets(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int i) {
            int root = parent[i];
            if (parent[root] != root) {
                return parent[i] = find(root);
            }
            return root;
        }

        void unionSets(int x, int y) {
            int xRoot = find(x);
            int yRoot = find(y);
            if (xRoot == yRoot) return;
            if (rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;
            } else if (rank[yRoot] < rank[xRoot]) {
                parent[yRoot] = xRoot;
            } else {
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }
    };

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row,vector<int>(col,0));
        int n = row*col+2;
        DisjointUnionSets dus(n);
        int res = row*col;

        for (int c=cells.size()-1;c>=0;c--) {
            int i = cells[c][0]-1;
            int j = cells[c][1]-1;
            grid[i][j] = 1;
            res--;
            int k = (i*col)+j+1;
            if (i==0) dus.unionSets(0,k); // Join with top node
            if (i==row-1) dus.unionSets(n-1,k); // Join with bottom node
            if (i-1 >= 0 && grid[i-1][j]) { // Check upper row
                dus.unionSets(k-col,k);
            }
            if (i+1 < row && grid[i+1][j]) { // Check bottom row
                dus.unionSets(k+col,k);
            }
            if (j-1 >= 0 && grid[i][j-1]) { // Check left col
                dus.unionSets(k-1,k);
            }
            if (j+1 < col && grid[i][j+1]) { // Check right col
                dus.unionSets(k+1,k);
            }
            if (dus.find(0) == dus.find(n-1)) return res;
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vi x = {1, 2, 3, 1};
    // cout << sol.method(x) << nl;
    
}