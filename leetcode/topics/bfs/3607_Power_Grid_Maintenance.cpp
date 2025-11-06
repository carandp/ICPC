//  3607. Power Grid Maintenance

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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> G(c,vector<int> (0,0));
        for (int i=0; i<connections.size();i++) {
            G[connections[i][0]-1].push_back(connections[i][1]-1);
            G[connections[i][1]-1].push_back(connections[i][0]-1);
        }

        int curr_group = 0;
        vector<set<int>> groups; // Groups of ordered sets
        unordered_map<int,int> inverse_groups;
        vector<int> gvisited(c,0);

        for (int i=0;i<G.size();i++) { // Find all connected components using BFS
            if (!gvisited[i]) {
                queue<int> q;
                q.push(i);
                set<int> s;
                s.insert(i);
                groups.push_back(s);
                inverse_groups[i] = curr_group;
                gvisited[i] = 1;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    if (!gvisited[curr]) {
                        groups[curr_group].insert(curr);
                        inverse_groups[curr] = curr_group;
                    }
                    for (int j=0;j<G[curr].size();j++) {
                        if (!gvisited[G[curr][j]]) {
                            q.push(G[curr][j]);
                            groups[curr_group].insert(G[curr][j]);
                            inverse_groups[G[curr][j]] = curr_group;
                            gvisited[G[curr][j]] = 1;
                        }
                    }
                }
                curr_group++;
            }
        }

        vector<int> active(c,1);
        vector<int> res;
        for (int i=0;i<queries.size();i++) { // For every query
            int qtype = queries[i][0];
            int x = queries[i][1] - 1;
            if (qtype == 2) { // De activate station
                active[x] = 0;
                groups[inverse_groups[x]].erase(x); // Erase station from group
                if (groups[inverse_groups[x]].empty()) {
                    groups[inverse_groups[x]].insert(-2);
                }
            } else {
                if (active[x]) res.push_back(x+1);
                else res.push_back(*groups[inverse_groups[x]].begin()+1);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // int c = 5;
    // vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
    // vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};
    int c = 2;
    vector<vector<int>> connections = {{1,2}};
    vector<vector<int>> queries = {{1,2},{2,2},{1,1},{2,2},{2,1},{1,1}};
    print_v(sol.processQueries(c,connections,queries));
    
}
