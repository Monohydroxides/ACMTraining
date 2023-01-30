#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int fac[2010], invfac[2010];

int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (ll) res * a % mod;
        }
        a = (ll) a * a % mod;
        b >>= 1;
    }
    return res;
}

int Comb (int a, int b) {
    if (b > a) return 0;
    return (ll) fac[a] * invfac[b] % mod * invfac[a - b] % mod;
} 

void init () {
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 2000; ++i) {
        fac[i] = (ll) fac[i - 1] * i % mod;
    }
    invfac[2000] = qmi(fac[2000], mod - 2);
    for (int i = 1999; i >= 0; --i) {
        invfac[i] = (ll) invfac[i + 1] * (i + 1) % mod;
    }
}

void work () {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), g(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        g[i] = Comb(n, i);
        for (int j = 0; j < m; ++j) {
            g[i] = (ll) g[i] * Comb(a[j] + n - i - 1, a[j]) % mod;
        }
    }
    int res = 0;
    for (int i = 0, t = 1; i < n; ++i, t = -t) {
        res = ((res + (t * g[i])) % mod + mod) % mod;
    }
    cout << res << '\n';
}

int main () {
    init();
    work();
    return 0;
}