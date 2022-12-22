#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n, m, c;
ll f[410];
int fac[410], invfac[410];

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

void init () {
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 400; ++i) {
        fac[i] = (ll) fac[i - 1] * i % mod;
    }
    invfac[400] = qmi(fac[400], mod - 2);
    for (int i = 399; i >= 0; --i) {
        invfac[i] = (ll) invfac[i + 1] * (i + 1) % mod;
    }
}

int Comb (int a, int b) {
    return (ll) fac[a] * invfac[b] % mod * invfac[a - b] % mod;
}

int add (int a, int b) {
    return (((ll) a + b) % mod + mod) % mod;
}

int sub (int a, int b) {
    return (((ll) a - b) % mod + mod) % mod;
}

int mul (int a, int b) {
    return (((ll) a * b % mod) + mod) % mod;
}

int divm (int a, int b) {
    return (ll) a * qmi(b, mod - 2) % mod;
}

int main () {
    init();
    cin >> n >> m >> c;
    for (int i = 1; i <= c; ++i) {
        for (int j = m, t = 1; j >= 0; --j, t = -t)  {
            f[i] = add(f[i], mul(t, mul(Comb(m, j), qmi(sub(qmi(i + 1, j), 1), n))));
        }
    }
    int res = 0;
    for (int i = 0, t = 1; i <= c; ++i, t = -t) {
        res = add(res, mul(t, mul(Comb(c, i), f[c - i])));
    }
    cout << res << '\n';
    return 0;
}