//  2528. Maximize the Minimum Powered City

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
    long long maxPower(vector<int>& stations, int r, int k) {

        int n = stations.size();

        vector<long long> coverage(n,0);

        long long total = 0;
        for (int i=0;i<r+1;i++) {
            total += stations[i];
        }

        coverage[0] = total;
        long long a = total; // Minimum possible coverage
        long long b = total; // Maximum possible coverage

        for (int i=1;i<n;i++) { // Use window to find station coverage of each city
            if (i-r > 0) total -= stations[i-r-1];
            if (i+r < n) total += stations[i+r];
            coverage[i] = total;
            a = min(a,total);
            b = max(b,total);
        }

        b += k;

        long long res = 0;

        while (a<=b) { // Do binary search for the max minimum
            long long m = a + (b-a)/2;
            vector<long long> diff(n,0); // Interval union
            long long sum = 0;
            long long rem = k;
            bool in_range = true;

            for (int i=0;i<n;i++) {
                sum += diff[i]; // Update sum value
                if (coverage[i] + sum < m) { // Updates interval union
                    long long add = m - coverage[i] - sum;
                    if (rem < add) {
                        in_range = false;
                        break;
                    }
                    rem -= add;
                    sum += add;
                    int end = 2*r+i+1;
                    if (end < n) diff[end] -= add; // Stop after full range
                }
            }
            if (in_range) {
                res = m;
                a = m+1;
            } else b = m-1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vi stations = {1,2,4,5,0};
    // int r = 1;
    // int k = 2;
    // vi stations = {4,4,4,4};
    // int r = 0;
    // int k = 3;
    vi stations = {4,2};
    int r = 1;
    int k = 1;
    cout << sol.maxPower(stations,r,k) << nl;
    
}
