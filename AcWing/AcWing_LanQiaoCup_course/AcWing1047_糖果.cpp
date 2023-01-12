#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m;
int a[N];
int dp[N][N];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i][j], dp[i - 1][((j - a[i]) % m + m) % m] + a[i]);
        }
    }
    cout << dp[n][0] << '\n';
    return 0;
}