//  B. Shohag Loves Strings

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(string& s) {
    if (s.size() == 1) {
        cout << -1 << "\n";
        return;
    }
    for (int i=0; i<s.size()-2; i++) {
        if (s[i] == s[i+1]) {
            cout << s[i] << s[i+1] << "\n";
            return;
        }
        if (s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]) {
            cout << s[i] << s[i+1] << s[i+2] << "\n";
            return;
        }
    }
    if (s[s.size()-2] == s[s.size()-1]) cout << s[s.size()-2] << s[s.size()-1] << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
