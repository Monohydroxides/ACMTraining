#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;

int n;
int arr[1000010];
int f[2101][2101];

void init () {
    f[1][1] = 1;
    for (int i = 2; i <= 2100; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) {
                f[i][j] = 1;
            } else {
                f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
            }
        }
    }
}

int main () {
    init();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] %= mod;
    }
    int q;
    cin >> q;
    int x, y;
    while (q--) {
        cin >> x >> y;
        int res = 0;
        int idx = y;
        for (int i = 1; i <= x + 1; ++i) {
            res = (res + (long long) arr[idx] * f[x + 1][i] % mod) % mod;
            idx = (idx % n) + 1; 
        }
        cout << res << '\n';
    }
    return 0;
}