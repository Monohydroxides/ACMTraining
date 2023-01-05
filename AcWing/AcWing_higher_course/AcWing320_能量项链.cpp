#include <bits/stdc++.h>
using namespace std;

int n;
int a[210];
int dp[210][210];

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int len = 2; len <= n + 1; ++len) {
        for(int l = 1; l + len - 1 <= 2 * n; ++l) {
            int r = l + len - 1;
            for(int k = l + 1; k <= l + len - 2; ++k) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]); 
            }
            // cout << l << " " << r << " " << dp[l][r] << '\n';
        }
    }
    int res = 0;
    for (int l = 1; l <= n; ++l) {
        res = max(dp[l][l + n], res);
    }
    cout << res << '\n';
    return 0;
}