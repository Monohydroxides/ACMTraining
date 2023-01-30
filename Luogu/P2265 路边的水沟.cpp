#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 10, mod = 1e9 + 7;

int n, m;
int fac[N], invfac[N];

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

int main () {
    cin >> n >> m;
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= n + m; ++i) {
        fac[i] = (ll) fac[i - 1] * i % mod;
    }
    invfac[n + m] = qmi(fac[n + m], mod - 2);
    for (int i = n + m - 1; i >= 1; --i) {
        invfac[i] = (ll) invfac[i + 1] * (i + 1) % mod; 
    }
    cout << (ll) fac[m + n] * invfac[m] % mod * invfac[n] % mod << endl;
    return 0;
}