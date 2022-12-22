#include <bits/stdc++.h>
using namespace std;

int mod = 9999973;

int n, m;
int res;
int inv2;
long long dp[101][101][101];

int qmi (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (long long) res * a % mod;
        }
        a = (long long) a * a % mod;
        b >>= 1;
    }
    return res;
}

int add (int a, int b) {
    return ((long long) a + b) % mod;
}

int mul (int a, int b) {
    return ((long long) a * b) % mod;
}

int main () {
    cin >> n >> m;
    inv2 = qmi(2, mod - 2);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= m - j; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= 1) {
                    dp[i][j][k] = add(dp[i][j][k], mul(dp[i - 1][j - 1][k], m - j - k + 1));
                }
                if (j + 1 <= m && k - 1 >= 0) {
                    dp[i][j][k] = add(dp[i][j][k], mul(dp[i - 1][j + 1][k - 1], j + 1));
                }
                if (j >= 2) {
                    dp[i][j][k] = add(dp[i][j][k], mul(dp[i - 1][j - 2][k], (m - j - k + 2) * (m - j - k + 1) / 2));
                }
                if (k >= 1) {
                    dp[i][j][k] = add(dp[i][j][k], mul(dp[i - 1][j][k - 1], j * (m - j - k + 1)));
                }
                if (j + 2 <= m && k - 2 >= 0) {
                    dp[i][j][k] = add(dp[i][j][k], mul(dp[i - 1][j + 2][k - 2], (j + 2) * (j + 1) / 2));
                }
            }
        }
    }
    for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= m; ++k) {
            res = (res + dp[n][j][k]) % mod;
        }
    }
    cout << res << '\n';
    return 0;
}