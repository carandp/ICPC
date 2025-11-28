//  2872. Maximum Number of K-Divisible Components

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
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector<vector<int>> G(n);
        for (vector<int> e: edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }

        vector<int> sum(n,0); // Store sum of component
        for (int i=0;i<n;i++) sum[i] = values[i]%k;

        stack<int> tree;

        stack<int> st;
        vector<bool> visited(n,false);
        vector<int> parent(n,0);
        st.push(0);
        while (!st.empty()) { // DFS to build tree
            int node = st.top();
            st.pop();
            if (visited[node]) continue;
            visited[node] = true;

            tree.push(node);

            int size = G[node].size();
            for (int i=0;i<size;i++) {
                int v = G[node][i];
                if (!visited[v]) {
                    st.push(v);
                    parent[v] = node;
                }
            }
        }

        int res = 0;

        while (!tree.empty()) {
            int node = tree.top();
            tree.pop();
            if (!(sum[node]%k)) res++; // Cut leaf
            else sum[parent[node]] = (sum[parent[node]]+sum[node])%k; // Add leaf to parent
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // int n = 7;
    // vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    // vector<int> values = {3,0,6,1,5,2,1};
    // int k = 3;
    int n = 2;
    vector<vector<int>> edges = {{0,1}};
    vector<int> values = {1,2};
    int k = 1;
    cout << sol.maxKDivisibleComponents(n,edges,values,k) << nl;
    
}
