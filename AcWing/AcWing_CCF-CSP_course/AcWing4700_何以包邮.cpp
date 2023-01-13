#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[35];
int dp[300010];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 300000; j >= 1; j--) {
            if (j < a[i]) {
                dp[j] = min(dp[j], a[i]);
            } else {
                dp[j] = min(dp[j], dp[j - a[i]] + a[i]);
            }
        }
    }
    cout << dp[m] << '\n';
    return 0;
}