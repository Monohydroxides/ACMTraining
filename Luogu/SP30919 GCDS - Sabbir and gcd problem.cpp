#include <bits/stdc++.h>
using namespace std;

int n;
int primes[10000010], cnt;
bool st[10000010];
int mp[10000010], low[10000010];

void init () {
    for (int i = 2; i <= 10000000; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            low[i] = i;
        }
        for (int j = 0; (long long) primes[j] * i <= 10000000; j++) {
            st[primes[j] * i] = 1;
            low[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

void work () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        while (x > 1) {
            mp[low[x]] = 1;
            x /= low[x];
        }        
    }
    for (int j = 0; j < cnt; j++) {
        if (!mp[primes[j]]) {
            cout << primes[j] << '\n';
            return;
        }
    }
}

int main () {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(mp, 0, sizeof mp);
        work();
    }
    return 0;
}