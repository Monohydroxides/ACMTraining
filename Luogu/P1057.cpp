#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[35][35];

int main () {
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = dp[i - 1][j == 0? n - 1: j - 1] + dp[i - 1][j == n - 1? 0: j + 1];
        }
    }
    cout << dp[m][0] << '\n';
    return 0;
}