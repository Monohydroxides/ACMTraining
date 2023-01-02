#include <bits/stdc++.h>
using namespace std;

const int N = 610;

int n, m1, m2;
vector<array<int, 2>> e[N];

int dfn[N], low[N], bel[N], dfncnt, scccnt;
bool ins[N];
stack<int> stk;
vector<int> scc[N];

int dst[N][N];

void dfs (int u) {
    dfn[u] = low[u] = ++dfncnt;
    ins[u] = 1;
    stk.push(u);
    for (auto [v, w] : e[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scccnt++;
        while (1) {
            int cur = stk.top();
            stk.pop();
            bel[cur] = scccnt;
            ins[cur] = 0;
            scc[scccnt].push_back(cur);
            if (cur == u) break;
        }
    }
}

int main () {
    cin >> n >> m1 >> m2;
    memset(dst, 0x3f, sizeof dst);
    for (int i = 1; i <= m1; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back({b, 1});
        dst[a][b] = min(dst[a][b], 1);
        e[b].push_back({a, -1});
        dst[b][a] = min(dst[b][a], -1);
    }
    for (int i = 1; i <= m2; i++) {
        int a, b;
        cin >> a >> b;
        e[b].push_back({a, 0});
        dst[b][a] = min(dst[b][a], 0);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dst[i][i] < 0) {
            cout << "NIE\n";
            return 0;
        }
    }

    int ans = 0;
    for (int i = 1; i <= scccnt; i++) {
        int cur = 0;
        for (auto u : scc[i]) {
            for (auto v: scc[i]) {
                if (u == v) {
                    continue;
                }
                cur = max(cur, dst[u][v]);
                // cout << u << " " << v << " " << dst[u][v] << '\n';
            }
        }
        ans += cur + 1;
    }

    cout << ans << '\n';
    return 0;
}