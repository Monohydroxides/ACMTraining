#include <bits/stdc++.h>
using namespace std;

int n;
int a[300];
int dp[300][300];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for(int len = 2; len <= n; ++len) {
        for(int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for(int k = l; k < r; ++k) {
                // cout << dp[l][k] << " " << dp[k + 1][r] << endl;
                if((dp[l][k] == dp[k + 1][r]) && dp[l][k]) {
                    dp[l][r] = dp[l][k] + 1;
                }
                // cout << l << " " << r << " " << k << " " << dp[l][r] << endl;
            }
        }
    }
    int res = 0;
    for(int l = 1; l <= n; ++l) {
        for(int r = l; r <= n; ++r) {
            // cout << l << " " << r << " " << dp[l][r] << endl;
            res = max(res, dp[l][r]);
        }
    }
    cout << res << endl;
    return 0;
}