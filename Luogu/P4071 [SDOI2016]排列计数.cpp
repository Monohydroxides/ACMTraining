#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int d[1000010];
int fac[1000010], invfac[1000010];

int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

void init () {
    d[0] = 1;
    fac[0] = 1, invfac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        d[i] = 1ll * i * d[i - 1] % mod + (i & 1 ? -1 : 1);
        d[i] = (d[i] + mod) % mod;
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    invfac[1000000] = qmi(fac[1000000], mod - 2);
    for (int i = 1000000 - 1; i >= 1; i--) {
        invfac[i] = 1ll * invfac[i + 1] * (i + 1) % mod;
    }
}

int comb (int a, int b) {
    return 1ll * fac[a] * invfac[b] % mod * invfac[a - b] % mod;
}

void work () {
    int n, m;
    cin >> n >> m;
    cout << 1ll * comb(n, m) * d[n - m] % mod << '\n';
}

int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}