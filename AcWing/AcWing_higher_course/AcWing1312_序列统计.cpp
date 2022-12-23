#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 3;


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

int Comb (int a, int b) {
    if (a < b) return 0;
    int res = 1, div = 1;
    for (int i = 1, j = a; i <= b; ++i, --j) {
        res = (long long) res * j % mod;
        div = (long long) div * i % mod;
    }
    res = (long long) res * qmi(div, mod - 2) % mod;
    return res;
}

int lucas (int a, int b) {
    if (a < mod && b < mod)  return Comb(a, b);
    return (long long) lucas(a / mod, b / mod) * Comb(a % mod, b % mod) % mod;
}

void work () {
    int n, l, r;
    cin >> n >> l >> r;
    cout << (lucas(r - l + n + 1, r - l + 1) - 1 + mod) % mod << '\n';
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}
