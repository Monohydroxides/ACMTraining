#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
int dst[20][20];
int deg[20];
int dp[1 << 15];
vector<int> ev;

int floyd () {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dst[1][i] >= 0x3f3f3f3f && deg[i]) return -1;
    }
    return 0;
}

int main () {
    cin >> n >> m;
    memset(dst, 0x3f, sizeof dst);
    for (int i = 1; i <= n; i++) dst[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (dst[u][v] > w) dst[u][v] = dst[v][u] = w;
        deg[u]++;
        deg[v]++;
        ans += w;
    }
    if (floyd() == -1) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            ev.push_back(i);
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int p = ev.size();
    for (int state = 0; state < (1 << p); state++) {
        for (int i = 0; i < p; i++) {
            int u = ev[i];
            if ((state >> i) & 1) continue;
            for (int j = 0; j < p; j++) {
                int v = ev[j];
                if (u == v || ((state >> j) & 1)) continue;
                // cout << u << " " << v << '\n';
                dp[state | (1 << i) | (1 << j)] = min(dp[state | (1 << i) | (1 << j)], dp[state] + dst[u][v]);
            }
        }
    }
    cout << ans + dp[(1 << p) - 1] << '\n';
    return 0;
}