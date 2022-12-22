#include <bits/stdc++.h>
using namespace std;

string orbit (string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res = a;
    for (int i = 0; i < b.size() - 1; ++i) {
        if (b[i] == '1') {
            res[i] = '1';
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

string maxstr (string a, string b) {
    for (int i = 1; i < min(a.size(), b.size()); ++i) {
        if (a[i] != b[i]) {
            if (a[i] == '0') {
                return b;
            } else {
                return a;
            }
        }
    }
    if (a.size() > b.size()) {
        return a;
    } else {
        return b;
    }
}

void work () {
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    string res1 = str;
    string res;
    string tmp1 = " ";
    for (int i = 1; i <= n; ++i) {
        tmp1 = tmp1 + str[i];
        res = maxstr(res, orbit(res1, tmp1));
    }
    int flg = 1;
    int all0 = 0;
    for (int i = 1; i < res.size(); ++i) {
        if (flg && res[i] == '0') {
            if (i == res.size() - 1) {
                all0 = 1;
            }
            continue;
        }
        flg = 0;
        cout << res[i];
    }
    if (all0) {
        cout << 0;
    }
    cout << '\n';
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T = 1;
    while (T--) {
        work();
    }
    return 0;
}