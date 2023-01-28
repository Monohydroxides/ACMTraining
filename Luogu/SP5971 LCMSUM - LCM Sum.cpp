#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int primes[N + 1], mu[N + 1], cnt;
bool st[N + 1];

long long f[N + 1], g[N + 1];

void init () {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!st[i]) {
            primes[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; primes[j] * i <= N; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
            mu[primes[j] * i] = -mu[i];
        }
    }
    for (long long i = 1; i <= N; i++) {
        for (int j = 1; i * j <= N; j++) {
            f[i * j] += 1ll * mu[i] * i * ((1 + j) * 1ll * j / 2);
        }
    }
    for (long long i = 1; i <= N; i++) {
        for (int j = 1; i * j <= N; j++) {
            g[i * j] += f[j];
        }
    }
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << n * g[n] << '\n';
    }
    return 0;
}