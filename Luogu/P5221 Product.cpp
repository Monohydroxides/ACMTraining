#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 104857601;

int n;
int primes[78500], cnt;
bool st[1000010];
int phi[1000010];

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
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] * i <= n; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = (ll) phi[i] * primes[j] % (mod - 1);
                break;
            }
            phi[i * primes[j]] = (ll) phi[i] * (primes[j] - 1) % (mod - 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        phi[i] = (phi[i] + phi[i - 1]) % (mod - 1);
    }
}

int main () {
    cin >> n;
    init();
    int res1 = 1;
    for (int i = 1; i <= n; ++i) {
        res1 = (ll) res1 * i % mod;
    }
    res1 = qmi(res1, 2 * n);
    int res2 = 1;
    for (int d = 1; d <= n; ++d) {
        res2 = (ll) res2 * qmi(d, (2 * phi[n / d] - 1) % (mod - 1)) % mod;
    }
    cout << (ll) res1 * qmi((int) ((ll) res2 * res2 % mod), mod - 2) % mod << endl;
    return 0;
}