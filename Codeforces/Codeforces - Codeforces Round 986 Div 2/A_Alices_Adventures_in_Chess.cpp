//  A. Alice's Adventures in "Chess"

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        string ins;
        cin >> ins;

        int x = 0, y = 0;
        bool found = false;

        if (x == a && y == b) {
            found = true;
            cout << "YES\n";
        }

        for (int j = 0; j < 20; j++) {
            for (char i: ins) {
                if (i == 'N') {
                    y++;
                } else if (i == 'S') {
                    y--;
                } else if (i == 'E') {
                    x++;
                } else {
                    x--;
                }
                if (x == a && y == b) {
                    found = true;
                    cout << "YES\n";
                    break;
                }
            }
            if ((x == 0 && y == 0) || found) {
                break;
            }
        }
        if (!found) {
            cout << "NO\n";
        }
    }
    return 0;
}
