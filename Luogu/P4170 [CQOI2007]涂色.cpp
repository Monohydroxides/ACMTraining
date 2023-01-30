#include <bits/stdc++.h>
using namespace std;

string str;
int dp[55][55];
int main () {
    cin >> str;
    int n = str.size();
    str = " " + str;
    memset(dp, 0x3f, sizeof dp);
    for (int len = 1; len <= n; ++len) {
        dp[len][len] = 1;
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            if (str[l] == str[r]) {
                dp[l][r] = dp[l][r - 1];
            } else {
                for (int k = l; k < r; ++k) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}