#include <bits/stdc++.h>
using namespace std;

const int N = 2e7 + 10;

unsigned int seed;
inline unsigned int getnext() {
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}

int n;
int primes[N], cnt;
bool st[N];

void init () {
    for (int i = 2; i < N; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] * i < N; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

unsigned int a[N];

int main () {
    cin >> n >> seed;
    for (int i = 1; i <= n; ++i) {
        a[i] = getnext();
    }
    init();
    for (int i = 0; i < cnt; ++i) {
        for (int j = 1; primes[i] * j <= n; ++j) {
            a[primes[i] * j] += a[j];
        }
    }
    unsigned res = 0;
    for (int i = 1; i <= n; ++i) {
        res ^= a[i];
    }
    cout << res << '\n';
    return 0;
}