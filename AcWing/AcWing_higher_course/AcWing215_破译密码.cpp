#include <bits/stdc++.h>
using namespace std;

const int N = 50000;

int primes[N + 10], cnt;
bool st[N + 10];
long long mu[N + 10];

void init () {
    mu[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; primes[j] * i <= N; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= N; ++i) {
        mu[i] = mu[i - 1] + mu[i];
    }
}

void work () {
    int a, b, d;
    cin >> a >> b >> d;
    long long res = 0;
    for (int l = 1, r; l <= min(a / d, b / d); l = r + 1) {
        r = min(a / (a / l), (b / (b / l)));
        res += (long long) (mu[r] - mu[l - 1]) * (a / (d * l)) * (b / (d * l));
    }
    cout << res << '\n';
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
