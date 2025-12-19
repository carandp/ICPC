//  2092. Find All People With Secret

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

    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[2]<b[2];
    }

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

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DisjointUnionSets dus(n);
        dus.unionSets(0,firstPerson);

        sort(meetings.begin(),meetings.end(),comp);
        meetings.push_back({0,0,(*meetings.rbegin())[2]});

        vector<int> people;
        for (int i=0;i<meetings.size()-1;i++) {
            vector<int> &meeting = meetings[i];
            int x = meeting[0];
            int y = meeting[1];
            dus.unionSets(x,y);
            people.push_back(x);
            people.push_back(y);
            if (meetings[i][2] != meetings[i+1][2]) {
                int root0 = dus.find(0);
                for (int p: people) {
                    if (dus.find(p) != root0) {
                        dus.parent[p] = p;
                        dus.rank[p] = 0;
                    }
                }
                people = {};
            }
        }

        vector<int> res;
        int root0 = dus.find(0);
        for (int i=0;i<n;i++) {
            if (dus.find(i) == root0) res.push_back(i);
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vi x = {1, 2, 3, 1};
    // cout << sol.method(x) << nl;
    
}
