//  3433. Count Mentions Per User

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
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {


        map<int,vector<string>> message; // <timestamp,tokens>
        map<int,vector<int>> sleep; // <timestamp,ids>
        unordered_map<int,vector<int>> wake; // <timestamp,ids>

        set<int> time; // <timestamps>
        int starter = 0;

        for (int i=0;i<events.size();i++) {
            vector<string> event = events[i];
            string type = event[0];
            int timestamp = stoi(event[1]);
            time.insert(timestamp);
            if (type == "MESSAGE") {
                string msg = event[2];
                if (msg == "ALL") starter++;
                else message[timestamp].push_back(msg);
            } else if (type == "OFFLINE") {
                int id = stoi(event[2]);
                sleep[timestamp].push_back(id);
                wake[timestamp+60].push_back(id);
                time.insert(timestamp+60);
            }
        }

        int totalActive = numberOfUsers;
        vector<bool> active(numberOfUsers,true);
        vector<int> mentions(numberOfUsers,starter);

        for (int t: time) {
            // Wake up users if any
            vector<int> toWake = wake[t];
            if (toWake.size()) {
                for (int id: toWake) {
                    active[id] = true;
                    totalActive++;
                }
            }
            // Sleep down users if any
            vector<int> toSleep = sleep[t];
            if (toSleep.size()) {
                for (int id: toSleep) {
                    active[id] = false;
                    totalActive--;
                }
            }
            // Process any message queries
            vector<string> process = message[t];
            if (process.size()) {
                for (string msg: process) {
                    if (msg == "HERE") {
                        for (int id=0;id<numberOfUsers;id++) {
                            if (active[id]) mentions[id]++;
                        }
                    } else {
                        string curr = "";
                        for (int i=0;i<msg.size();i++) {
                            if (msg[i] == 'i' || msg[i] == 'd') continue;
                            if (msg[i] == ' ') {
                                mentions[stoi(curr)]++;
                                curr = "";
                            } else {
                                curr += msg[i];
                            }
                        }
                        mentions[stoi(curr)]++;
                    }
                }
            }
        }
        return mentions;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solution sol;
    // vi x = {1, 2, 3, 1};
    // cout << sol.method(x) << nl;
    
}
