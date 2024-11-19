//  C. Gran Suma

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string bigIntegerSum(string str1, string str2)
{

    if (str1.length() > str2.length()) swap(str1, str2);

    string res = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++) {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        res.push_back((sum%10) + '0');
        carry = sum/10;
    }

    for (int i=n1; i<n2; i++) {
        int sum = ((str2[i]-'0')+carry);
        res.push_back((sum%10) + '0');
        carry = sum/10;
    }

    if (carry) res.push_back(carry+'0');

    reverse(res.begin(), res.end());

    string resNo0 = "";
    for (int i=0; i < res.size(); i++) {
        if (resNo0.size() != 0 || res[i] != '0') {
            resNo0.push_back(res[i]);
        }
    }

    if (resNo0.size() == 0) resNo0.push_back('0');

    return resNo0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << bigIntegerSum(a,b) << endl;
    }
    return 0;
}
