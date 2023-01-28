#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int a[200010];

int mu (int x) {
    int cnt = 0;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            cnt++;
            int ret = 0;
            while (x % i == 0) {
                x /= i;
                ret++;
            }
            if (ret > 1) return 0;
        }
    }
    if (x > 1) {
        cnt++;
    }
    return (cnt & 1) ? -1 : 1;
}

void work () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] % a[i]) {
            cout << 0 << '\n';
            return;
        }
    }
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        int x = m / a[i];
        int y = a[i - 1] / a[i];
        long long ans = 0;
        for (int j = 1; j <= y / j; j++) {
            if (y % j == 0) {
                ans = ans + (1ll * mu(j) * (x / j) % mod);
                ans = (ans + mod) % mod;
                if (j * j != y) {
                    int k = y / j;
                    ans = ans + (1ll * mu(k) * (x / k) % mod);
                    ans = (ans + mod) % mod;
                }
            }
        }
        res = res * ans % mod;
    }
    cout << res << '\n';
    return;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}