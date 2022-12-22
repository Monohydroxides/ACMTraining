#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10, mod = 1e9 + 7;

int mu[N], primes[N], cnt;
bool st[N];
int fib[N], invfib[N];
int F[N];

int qmi(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)   res = (ll) res * a % mod;
        a = (ll) a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    mu[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0; primes[j] * i < N; ++j) {
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) {
                break;
            }
            mu[primes[j] * i] = -mu[i];
        }
    }
    invfib[1] = invfib[2] = 1;
    fib[1] = fib[2] = 1;
    F[0] = F[1] = F[2] = 1;
    for(int i = 3; i < N; ++i) {
        F[i] = 1;
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        invfib[i] = qmi(fib[i], mod - 2);
    }
    for(int i = 1; i < N; ++i) {
        for(int j = 1; i * j < N; ++j) {
            if(!mu[j])  continue;
            F[i * j] = (ll) F[i * j] * (mu[j] == 1? fib[i]: invfib[i]) % mod;
        }
    }
    for(int i = 2; i < N; ++i) {
        F[i] = (ll) F[i] * F[i - 1] % mod;
    }
}

int main() {
    init();
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int res = 1;
        for(int l = 1, r; l <= min(n, m); l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            res = (ll) res * qmi((ll) F[r] * qmi(F[l - 1], mod - 2) % mod, (ll) (n / l) * (m / l) % (mod - 1)) % mod;
        }
        cout << res << '\n';
    }
    return 0;
}