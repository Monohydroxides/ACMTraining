#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 2e6;

int k;
string str;
int fac[N + 10], invfac[N + 10];

int qmi (int a, int b) { int res = 1; while (b) {if (b & 1) res = (long long) res * a % mod; a = (long long) a * a % mod; b >>= 1;} return res;}

int Comb (int a, int b) {
    if (a < b) return 0;
    return (long long) fac[a] * invfac[b] % mod * invfac[a - b] % mod;
}

int main () {
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = (long long) fac[i - 1] * i % mod;
    }
    invfac[N] = qmi(fac[N], mod - 2);
    for (int i = N - 1; i >= 1; i--) {
        invfac[i] = (long long) invfac[i + 1] * (i + 1) % mod;
    }

    cin >> k;
    cin >> str;
    int n = str.size();
    int res = 0;
    for (int i = 0; i <= k; i++) {
        res = (res + (long long) qmi(26, i) * qmi(25, k - i) % mod * Comb(k + n - 1 - i, n - 1) % mod) % mod;
    }
    cout << res << '\n';
    return 0;
}