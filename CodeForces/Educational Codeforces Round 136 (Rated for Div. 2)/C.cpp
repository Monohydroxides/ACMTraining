#include <bits/stdc++.h>
using namespace std;

#define int long long

int mod = 998244353;

long long C[61][61];

int Comb (int a, int b) {
    return C[a][b];
}

int calc1 (int x) {
    return Comb(x - 1, x / 2 - 1);
}

int calc2 (int x) {
    return Comb(x - 2, x / 2 - 2);
}

void init () {
    int N = 61;
    for (int i = 0; i < N; i ++ ) {
        for (int j = 0; j <= i; j ++ ) {
            if (!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

void work () {
    int n;
    cin >> n;
    int t = 1;
    long long resa = 0, resb = 0;
    for (int i = n; i >= 2; i -= 2) {
        if (t) {
            resa = (resa + calc1(i)) % mod;
            resb = (resb + calc2(i)) % mod;
        } else {
            resa = (resa + calc2(i)) % mod;
            resb = (resb + calc1(i)) % mod;
        }
        t ^= 1;
    }
    cout << resa << " " << resb << " " << 1 << '\n';
}

signed main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}