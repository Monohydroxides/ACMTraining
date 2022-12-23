#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int dp[100010][3];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a[i]);
        dp[i][2] = dp[i - 1][1] + a[i];
    }
    int res = 0;
    res = max(dp[n][0], dp[n][2]);
    cout << res << endl;
    return 0;
}
