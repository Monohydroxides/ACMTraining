#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (long long) res * a % mod;
        }
        a = (long long) a * a % mod;
        b >>= 1;
    }
    return res;
}

void work () {
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    int res = 0;
    int las1 = 0, las0 = 0;
    for (int i = 1; i <= n; ++i) {
        if (str[i] == '1') {
            las1 = i;
        } else {
            las0 = i;
        }
        int base = qmi(2, abs(las1 - las0) - 1);
        res = (res + base) % mod;
    }
    cout << res << '\n';
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}
