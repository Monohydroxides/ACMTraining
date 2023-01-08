#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int n;
int a[N];
int dp[N][N], rot[N][N];

void dfs (int l, int r) {
    if (l > r) return;
    cout << rot[l][r] << " ";
    dfs(l, rot[l][r] - 1);
    dfs(rot[l][r] + 1, r);
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i][i] = a[i], rot[i][i] = i;
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k <= r; k++) {
                int rs = (k + 1 > r ? 1 : dp[k + 1][r]);
                int ls = (k - 1 < l ? 1 : dp[l][k - 1]);
                if (dp[l][r] < rs * ls + dp[k][k]) {
                    dp[l][r] = rs * ls + dp[k][k];
                    rot[l][r] = k;
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    dfs(1, n);
    return 0;
}