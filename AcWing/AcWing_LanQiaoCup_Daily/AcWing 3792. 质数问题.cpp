#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int primes[N + 1], cnt;
bool st[N + 1];

void init () {
    for (int i = 2; i <= N; i++) {
        if (!st[i]) {
            primes[++cnt] = i;
        }
        for (int j = 1; primes[j] * i <= N; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main () {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= cnt; i++) {
            if (primes[i] + primes[i + 1] + 1 <= n && !st[primes[i] + primes[i + 1] + 1]) {
                k--;
            }
        }
        if (k <= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}