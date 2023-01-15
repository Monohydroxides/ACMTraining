#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int n, m;
map<int, int> dp[110][110];

int main () {
    cin >> n >> m;
    dp[0][0][2] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i) {
                for (auto it : dp[i - 1][j]) {
                    if (it.first * 2 > m) continue;
                    dp[i][j][it.first * 2] = (dp[i][j][it.first * 2] + it.second) % mod;
                }
            }
            if (j) {
                for (auto it : dp[i][j - 1]) {
                    if (it.first <= 0) continue;
                    dp[i][j][it.first - 1] = (dp[i][j][it.first - 1] + it.second) % mod;
                }
            }
        }
    }
    cout << dp[n][m - 1][1] << '\n';
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// int res;

// void dfs (int sel, int flo, int ret, int st) {
//     if (flo == m && sel == n && !ret) {
//         if (st & 1) return;
//         res++;
//         return;
//     }
//     if (ret > m - flo || ret < 0) return;
//     if (flo < m) {
//         if (ret > 0)
//             dfs(sel, flo + 1, ret - 1, st << 1);
//     } 
//     if (sel < n) {
//         dfs(sel + 1, flo, ret * 2, (st << 1) | 1);
//     }
// }

// int main () {
//     cin >> n >> m;
//     dfs(0, 0, 2, 1);
//     cout << res << '\n';
//     return 0;
// }