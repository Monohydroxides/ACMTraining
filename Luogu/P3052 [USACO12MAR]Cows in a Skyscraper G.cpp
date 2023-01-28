#include <bits/stdc++.h>
using namespace std;

int n, w;
int a[20];
int dp[(1 << 18)];
int lft[(1 << 18)];

int main () {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int state = 0; state < (1 << n); state++) {
        dp[state] = 0x3f3f3f3f;
    }
    dp[0] = 0;
    lft[0] = w;
    for (int state = 0; state < (1 << n); state++) {
        for (int i = 1; i <= n; i++) {
            if ((state >> (i - 1)) & 1) {
                continue;
            }
            if (a[i] <= lft[state]) {
                dp[state | (1 << (i - 1))] = min(dp[state | (1 << (i - 1))], dp[state]);
                lft[state | (1 << (i - 1))] = max(lft[state | (1 << (i - 1))], lft[state] - a[i]);
            } else {
                dp[state | (1 << (i - 1))] = min(dp[state | (1 << (i - 1))], dp[state] + 1);
                lft[state | (1 << (i - 1))] = max(lft[state | (1 << (i - 1))], w - a[i]);
            }
        }
    }
    cout << dp[(1 << n) - 1] + 1 << '\n';
    return 0;
}