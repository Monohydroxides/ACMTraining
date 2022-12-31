#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, mod;
vector<int> e[N];

int dfn[N], low[N], ins[N], bel[N], dfncnt, scccnt;
stack<int> stk;
vector<int> scc[N];

int dp[N], way[N], vis[N];

void tarjan (int u) {
    dfn[u] = low[u] = ++dfncnt;
    ins[u] = 1;
    stk.push(u);
    for (auto v: e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scccnt++;
        while (1) {
            int cur = stk.top();
            ins[cur] = 0;
            stk.pop();
            scc[scccnt].push_back(cur);
            bel[cur] = scccnt;
            if (cur == u) break;
        }
    }
}

int main () {
    cin >> n >> m >> mod;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    int ans, w;
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= scccnt; i++) {
        way[i] = 1;
        dp[i] = 0; 
        for (auto u: scc[i]) {
            for (auto v: e[u]) {
                if (!vis[bel[v]] && i != bel[v]) {
                    vis[bel[v]] = 1;
                    if (dp[bel[v]] > dp[i]) {
                        dp[i] = dp[bel[v]], way[i] = 0;
                    }
                    if (dp[bel[v]] == dp[i]) {
                        way[i] = (way[i] + way[bel[v]]) % mod;
                    }
                }
            }
        }
        dp[i] += scc[i].size();
        if (dp[i] > ans) ans = dp[i], w = 0;
        if (dp[i] == ans) w = (w + way[i]) % mod;
        for (auto u: scc[i]) for (auto v: e[u]) vis[bel[v]] = 0;
    }
    cout << ans << "\n" << w << '\n';
    return 0;
}



