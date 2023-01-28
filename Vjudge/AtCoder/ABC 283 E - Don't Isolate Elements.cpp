#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;
int a[2][1010][1010];

int dp[1010][2][2];

bool check (int u, int las, int cur, int nxt) {
    for (int j = 1; j <= m; j++) {
        if (a[cur][u][j] == a[cur][u][j + 1] || a[cur][u][j] == a[cur][u][j - 1]) {
            continue;
        }
        if (a[cur][u][j] == a[las][u - 1][j] || a[cur][u][j] == a[nxt][u + 1][j]) {
            continue;
        }
        return false;
    }
    return true;
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[0][i][j];
            a[1][i][j] = 1 - a[0][i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        a[0][i][0] = a[0][i][m + 1] = a[1][i][0] = a[1][i][m + 1] = inf;
    }
    for (int j = 1; j <= m; j++) {
        a[0][0][j] = a[0][n + 1][j] = a[0][0][j] = a[1][n + 1][j] = inf;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int las = 0; las <= 1; las++) {
            for (int cur = 0; cur <= 1; cur++) {
                for (int nxt = 0; nxt <= 1; nxt++) {
                    if (check(i, las, cur, nxt)) {
                        dp[i][cur][nxt] = min(dp[i][cur][nxt], dp[i - 1][las][cur] + cur);
                    }
                }
            }
        }
    }
    int res = min(dp[n][0][0], dp[n][1][0]);
    cout << (res == 0x3f3f3f3f ? -1 : res) << '\n';
    return 0;
}