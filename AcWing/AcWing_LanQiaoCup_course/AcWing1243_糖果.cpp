#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[110];
int dp[(1 << 20)];

int main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= k; ++j) {
            int x;
            cin >> x;
            cur |= (1 << (x - 1));
        }
        a[i] = cur;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int state = 0; state < (1 << m); state++) {
            dp[state | a[i]] = min(dp[state | a[i]], dp[state] + 1);
        }
    }
    if (dp[(1 << m) - 1] == 0x3f3f3f3f) {
        cout << -1 << '\n';
    } else {
        cout << dp[(1 << m) - 1] << '\n';
    }
    return 0;
}