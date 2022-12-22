#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n;
int a[110][110];
int dp[110][110];

int add (int a, int b) {
    return ((a + b) % mod + mod) % mod;
}

int mul (int a, int b) {
    return 1ll * a * b % mod;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = 2 * (a[1][1] != 2);
    for (int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= i; j++ ) {
            int flag = 0;
            for (int k = 1; k <= i; k++ ) {
                if(a[k][i] == 1 && k < j) flag = 1;
                if(a[k][i] == 2 && k >= j) flag = 1;
            }
            if(flag) dp[i][j] = 0;
            dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
            dp[i + 1][i + 1] = add(dp[i + 1][i + 1], dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) { 
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}