#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long a[21], m, res;
int inv[21], n;

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

int Comb (long long a, int b) {
    if (a < 0 || b < 0 || a < b) {
        return 0;
    }
    a %= mod;
    if (!a || !b) {
        return 1;
    }
    int res = 1;
    for (int i = 0; i < b; ++i) {
        res = (long long) res * (a - i) % mod;
    }
    for (int i = 1; i <= b; ++i) {
        res = (long long) res * inv[i] % mod;
    }
    return res;
}

int main () {
    for (int i = 1; i <= 20; ++i) {
        inv[i] = qmi(i, mod - 2);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    res = Comb(n + m - 1, n - 1) % mod;
    for (int state = 1; state < (1 << n); ++state) {
        long long cur = n + m;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((state >> i) & 1) {
                cnt++;
                cur -= a[i + 1];
            }
        }
        cur -= cnt + 1;
        if (cnt & 1) {
            res = (res - Comb(cur, n - 1)) % mod;
        } else {
            res = (res + Comb(cur, n - 1)) % mod;
        }
    }
    cout << (res % mod + mod) % mod << '\n';
}