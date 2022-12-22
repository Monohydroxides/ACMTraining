#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int cnt;
bool vis[10000010];

int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (ll) res * a % mod;
        }
        a = (ll) a * a % mod;
        b >>= 1;
    }
    return res;
}

int main () {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            cnt++;
            for (int j = i + i; j <= r; j += i) {
                vis[j] = 1;
            }
        }
    }
    int res = 1;
    for (int i = 1; i <= (r - l + 2); ++i) {
        res = (ll) res * i % mod;
    }
    res = (ll) res * cnt % mod * (ll) qmi(cnt + 1, mod - 2) % mod;
    cout << res << endl;
    return 0;
}