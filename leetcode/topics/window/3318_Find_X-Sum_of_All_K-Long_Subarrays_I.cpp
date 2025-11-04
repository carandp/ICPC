//  3318. Find X-Sum of All K-Long Subarrays I

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
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> xsum(n-k+1,0);

        vector<vector<int>> freq(51,vector<int>(2,0));

        for (int i=0;i<k;i++) { // Build base window frequency
            freq[nums[i]][0]++;
            freq[nums[i]][1] = nums[i];
        }

        vector<vector<int>> base_copy = freq;
        sort(base_copy.begin(),base_copy.end(), greater<vector<int>>());
        for (int i=0;i<x;i++) {
            xsum[0] += base_copy[i][0] * base_copy[i][1];
        }

        for (int i=1;i<n-k+1;i++) {
            freq[nums[i-1]][0]--; // Update window's left
            if (!freq[nums[i-1]][0]) freq[nums[i-1]][1] = 0;

            freq[nums[k+i-1]][0]++; // Update window's right
            freq[nums[k+i-1]][1] = nums[k+i-1];

            vector<vector<int>> copy = freq;
            sort(copy.begin(),copy.end(), greater<vector<int>>());
            for (int j=0;j<x;j++) {
                xsum[i] += copy[j][0] * copy[j][1];
            }
        }

        return xsum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    vi nums = {1,1,2,2,3,4,2,3};
    int k = 6;
    int x = 2;
    print_v(sol.findXSum(nums,k,x));
    
}
