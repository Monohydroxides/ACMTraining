#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 1;

int primes[N], cnt;
bool st[N];

void init (int x) {
    for (int i = 2; i <= x; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] * i <= x; ++j) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return;
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    init(n);
    while (q--) {
        int x;
        cin >> x;
        cout << primes[x - 1] << '\n';
    }
    return 0;
}