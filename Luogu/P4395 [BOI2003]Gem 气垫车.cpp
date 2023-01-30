#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10010][110];
int cnt[110];
vector<int> e[10010];

void dfs (int u, int father) {
    for (int i = 1; i <= 100; i++) {
        dp[u][i] = i;
    }
    for (auto v : e[u]) {
        if (v == father) continue;
        dfs(v, u);
    }
    for (auto v : e[u]) {
        if (v == father) continue;
        for (int i = 1; i <= 100; i++) {
            int cur = 1 << 30;
            for (int j = 1; j <= 100; j++) {
                if (i != j) cur = min(cur, dp[v][j]);
            }
            dp[u][i] += cur;
        }
    }
}

int main () {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1);
    int res = 1 << 30;
    for (int i = 1; i <= 100; i++) {
        res = min(res, dp[1][i]);
    }
    cout << res << '\n';
    return 0;
}