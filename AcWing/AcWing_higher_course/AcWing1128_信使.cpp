#include <bits/stdc++.h>
using namespace std;

int n, m;
int g[105][105];

void floyd () {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main () {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    floyd();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << g[1][i] << '\n';
        ans = max(ans, g[1][i]);
        if (g[1][i] == 0x3f3f3f3f) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}