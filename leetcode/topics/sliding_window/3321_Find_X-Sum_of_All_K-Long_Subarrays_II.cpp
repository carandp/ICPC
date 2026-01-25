//  3321. Find X-Sum of All K-Long Subarrays II

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
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> xsum(n-k+1,0);

        set<pair<int,int>> top; // <freq,num>
        set<pair<int,int>> all; // <freq,num>
        unordered_map<int,int> freq; // <num,freq>

        for (int i=0;i<k;i++) { // Build all window
            freq[nums[i]]++;
            if (freq[nums[i]] == 1) all.insert({1,nums[i]});
            else {
                all.erase({freq[nums[i]]-1,nums[i]});
                all.insert({freq[nums[i]],nums[i]});
            }
        }

        long long total = 0;

        int all_size = all.size();
        set<pair<int,int>>::iterator last = prev(all.end());
        for (int i=0;i<min(x,all_size);i++) { // Build top window
            pair<int,int> curr = {last->first, last->second};
            last = prev(last);
            total += 1LL * curr.first * curr.second;
            top.insert(curr);
            all.erase(curr);
        }
        xsum[0] = total;

        for (int i=1;i<n-k+1;i++) {
            pair<int,int> l = {freq[nums[i-1]],nums[i-1]}; // Update window's left
            if (l >= *top.begin()) { // Erase previous l
                total -= 1LL * l.first * l.second;
                top.erase(l);
                if (!all.empty()) {
                    pair<int,int> to_top = *all.rbegin();
                    total += 1LL * to_top.first * to_top.second;
                    top.insert(to_top);
                    all.erase(to_top);
                }
            } else {
                all.erase(l);
            }
            freq[nums[i-1]]--; // Update l's frequency
            l.first--;
            if (freq[nums[i-1]]) { // Insert new l
                if (top.size() < x || l > *top.begin()) {
                    total += 1LL * l.first * l.second;
                    top.insert(l);
                    if (top.size() > x) {
                        pair<int,int> to_all = *top.begin();
                        total -= 1LL * to_all.first * to_all.second;
                        all.insert(to_all);
                        top.erase(to_all);
                    }
                } else {
                    all.insert(l);
                }
            };

            pair<int,int> r = {freq[nums[i+k-1]],nums[i+k-1]}; // Update window's right
            if (r >= *top.begin()) { // Erase previous r
                total -= 1LL * r.first * r.second;
                top.erase(r);
                if (!all.empty()) {
                    pair<int,int> to_top = *all.rbegin();
                    total += 1LL * to_top.first * to_top.second;
                    top.insert(to_top);
                    all.erase(to_top);
                }
            } else {
                all.erase(r);
            }
            freq[nums[i+k-1]]++; // Update r's frequency
            r.first++;
            if (freq[nums[i+k-1]]) { // Insert new r
                if (top.size() < x || r > *top.begin()) {
                    total += 1LL * r.first * r.second;
                    top.insert(r);
                    if (top.size() > x) {
                        pair<int,int> to_all = *top.begin();
                        total -= 1LL * to_all.first * to_all.second;
                        all.insert(to_all);
                        top.erase(to_all);
                    }
                } else {
                    all.insert(r);
                }
            };
            xsum[i] = total;
        }
        return xsum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vi nums = {1,1,2,2,3,4,2,3};
    // int k = 6;
    // int x = 2;
    vi nums = {4,4,4};
    int k = 3;
    int x = 2;
    print_v(sol.findXSum(nums,k,x));
    
}
