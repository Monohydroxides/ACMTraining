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
    int st = 1;
    while (st <= n && str[st] == '0') {
        st++;
    }
    n -= st - 1;
    int j = st;
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }
    for (; j <= n; ++j) {
        if (str[j] == '0') {
            break;
        }
    }
    string res;
    for (int i = st; i <= n + st - 1; ++i) {
        res = res + str[i];
    }
    string tmp = " ";
    int k;
    int cnt = 0;
    for (k = st; cnt < (n - j + st); ++k, ++cnt) {
        tmp = tmp + str[k];
    }
    k--;
    while (k <= n) {
        res = maxstr(res, orbit(str, tmp));
        tmp = tmp + str[k + 1];
        k++;
    }
    int all0 = 0;
    for (int i = 1; i < res.size(); ++i) {
        if (res[i] != '0') {
            break;
        } else if (res[i] == '0') {
            if (i == res.size() - 1) {
                all0 = 1;
            }
        }
    }
    if (all0) {
        cout << 0;
    } else {
        int flg = 1;
        for (int i = 1; i < res.size(); ++i) {
            if (res[i] == '0' && flg) {
                continue;
            }
            flg = 0;
            cout << res[i];
        }
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