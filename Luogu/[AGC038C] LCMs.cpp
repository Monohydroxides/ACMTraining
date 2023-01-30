#include <bits/stdc++.h>
using namespace std;

const int M = 1e6, mod = 998244353;

int n, lim;
int a[200010];
int acnt[M + 10];

int primes[M + 10], cnt;
int mu[M + 10];
bool st[M + 10];
long long f[M + 10];

int qmi (int a, int b) { int res = 1; while (b) {if (b & 1) {res = 1ll * res * a % mod;} a = 1ll * a * a % mod; b >>= 1;} return res; }

void init (int lim) {
    mu[1] = 1;
    for (int i = 2; i <= lim; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; primes[j] * i <= lim; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
            mu[primes[j] * i] = -mu[i];
        }
    }
    for (int i = 1; i <= lim; ++i) {
        for (int j = i; j <= lim; j += i) {
            f[i] = (f[i] + 1ll * j * acnt[j] % mod) % mod;
        }
    }
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        acnt[a[i]]++;
        lim = max(lim, a[i]);
    }
    init(lim);
    // for (int i = 1; i <= lim; ++i) {
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    long long ans = 0;
    for (int d = 1; d <= lim; ++d) {
        long long res = 0;
        for (int k = 1; k <= lim / d; ++k) {
            res = (res + 1ll * mu[k] * f[d * k] % mod * f[d * k] % mod) % mod;
        }
        res = 1ll * res * qmi(d, mod - 2) % mod;
        ans = (ans + res) % mod;
    }
    for (int i = 1; i <= n; ++i) {
        ans = (ans - a[i] + mod) % mod;
    } 
    cout << 1ll * ans * qmi(2, mod - 2) % mod << '\n';
    return 0;
}