#include <bits/stdc++.h>
using namespace std;

const int mod = 19650827;

int n;
int a[2010];
int dp[2010][2010][2];

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i][0] = 1;
    }
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n; i++) {
            int j = i + len;
            if (j > n) break;
			if (a[i] < a[i + 1]) {
                dp[i][j][0] += dp[i + 1][j][0];
            }
			if (a[i] < a[j]) {
                dp[i][j][0] += dp[i + 1][j][1];
            }
			if (a[j] > a[i]) {
                dp[i][j][1] += dp[i][j - 1][0];
            }
			if (a[j] > a[j - 1]) {
                dp[i][j][1] += dp[i][j - 1][1];
            }
			dp[i][j][0] %= mod;
			dp[i][j][1] %= mod;
		}
    }
	cout<< (dp[1][n][0] + dp[1][n][1]) % mod << '\n';
	return 0;
}