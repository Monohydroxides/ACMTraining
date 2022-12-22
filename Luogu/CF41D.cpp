#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[110][110];
int dp[110][110][15];

int main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &a[i][j]);
            // cout << a[i][j] << " ";
        }
        // cout << '\n';
    }
    for (int i = 1; i <= m; ++i) {
        dp[n][i][a[n][i] % (k + 1)] = a[n][i]; 
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            for (int r = 0; r <= 11; ++r) {
                if (j - 1 >= 1) {
                    if (dp[i + 1][j - 1][r])
                        dp[i][j][(r + a[i][j]) % (k + 1)] = dp[i + 1][j - 1][r] + a[i][j];
                }
                if (j + 1 <= m) {
                    if (dp[i + 1][j + 1][r])
                        dp[i][j][(r + a[i][j]) % (k + 1)] = max(dp[i][j][(r + a[i][j]) % (k + 1)], dp[i + 1][j + 1][r] + a[i][j]);
                }
                // cout << dp[i][j][(r + a[i][j]) % (k + 1)] << '\n';
            }
        } 
    }
    int res = -1;
    int st, ed;
    stack<char> stk;
    for (int i = 1; i <= m; ++i) {
        if (res < dp[1][i][0]) {
            res = dp[1][i][0];
            ed = i;
        }
    }
    int tmpres = res;
    for (int i = 1; i <= n - 1; ++i) {
        int f = 0;
        if (ed - 1 >= 1) {
            // cout << (tmpres - a[i][ed]) << " " << dp[i + 1][ed - 1][((tmpres - a[i][ed]) % (k + 1) + (k + 1)) % (k + 1)] << '\n';
            if ((tmpres - a[i][ed]) == dp[i + 1][ed - 1][((tmpres - a[i][ed]) % (k + 1) + (k + 1)) % (k + 1)]) {
                stk.push('R');
                tmpres -= a[i][ed];
                ed = ed - 1;
                f = 1;
            }
        }
        if (!f && ed + 1 <= m) {
            // cout << (tmpres - a[i][ed]) << " " << dp[i + 1][ed + 1][((tmpres - a[i][ed]) % (k + 1) + (k + 1)) % (k + 1)] << '\n';
            if ((tmpres - a[i][ed]) == dp[i + 1][ed + 1][((tmpres - a[i][ed]) % (k + 1) + (k + 1)) % (k + 1)]) {
                stk.push('L');
                tmpres -= a[i][ed];
                ed = ed + 1;
                f = 1;
            }
        }
        if (!f) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << res << '\n';
    cout << ed << '\n';
    while (stk.size()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}