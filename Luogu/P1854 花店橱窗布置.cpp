#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[110][110];
long long dp[110][110];

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j], dp[i][j] = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= m - n + i; ++j) {
            for (int k = i - 1; k <= j - 1; ++k) {
                if (dp[i][j] < dp[i - 1][k] + a[i][j]) {
                    dp[i][j] = dp[i - 1][k] + a[i][j];
                }
            }
        }
    }
    long long res = -0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= m; ++i) {
        res = max(res, dp[n][i]);
    }
    cout << res << '\n';
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
        for (int tmp = 1; tmp <= m; ++tmp) {
            if (dp[i][tmp] == res) {
                res -= a[i][tmp];
                ans.push_back(tmp);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}