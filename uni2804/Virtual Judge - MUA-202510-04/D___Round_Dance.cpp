//  D - Round Dance

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

// Int vectors
typedef vector<int> vi;
typedef vector<ll> vll;

// Int vectors of vectors
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Defs
#define fori(i, s, n) for(int i = s; i < n; i++)
#define DBG(X) cerr << #X << " = " << X << endl;
#define RAYA cerr << " ========================= " << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) a[i]--;

        int dance_pair = 0;
        int dance_not_pair = 0;

        bool visited[n];
        fill_n(visited,n,false);

        fori(i,0,n) {
            if (visited[i]) continue;

            int current = i;
            map<int, int> chain;

            while (true) {
                chain[current] = chain.size();
                visited[current] = true;
                int next_node = a[current];

                if (chain.count(next_node)) {
                    int cycle_length = chain.size() - chain[next_node];
                    if (cycle_length == 2) dance_pair++;
                    else dance_not_pair++;
                    break;
                }
                if (visited[next_node]) break;
                current = next_node;
            }
        }

        int maximum = dance_pair + dance_not_pair;
        int minimum = dance_not_pair + (dance_pair > 0 ? 1:0);

        cout << minimum << ' ' << maximum << '\n';
    }
    
    return 0;
}