#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int m;
int primes[N], cnt;
bool st[N];
int mu[N];
int inv[N];

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

void init () {
    mu[1] = 0; // spj
    for (int i = 2; i <= m; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; primes[j] * i <= m; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
            mu[primes[j] * i] = -mu[i]; 
        }
    }
}

int main () {
    cin >> m;
    init();
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        inv[i] = qmi(i, mod - 2);
    }
    for (int d = 2; d <= m; ++d) {
        res = ((res - (long long) mu[d] * (m / d) * inv[m - (m / d)]) % mod + mod) % mod;
    }
    res = (res + 1) % mod;
    cout << res << endl;
    return 0;
}