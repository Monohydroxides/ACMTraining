#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
vector<int> e[N];

int dfn[N], low[N], bel[N], ins[N], dfncnt, scccnt;
vector<int> scc[N];
stack<int> stk;

int ind[N];
bool vis[N];

void tarjan (int u) {
    dfn[u] = low[u] = ++dfncnt;
    ins[u] = 1;
    stk.push(u);
    for (auto v : e[u]) {
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= scccnt; i++) {
        memset(vis, 0, sizeof vis);
        for (auto u : scc[i]) 
            for (auto v : e[u]) 
                if (bel[u] != bel[v] && !vis[bel[v]]) 
                    ind[bel[v]]++, vis[bel[v]] = 1;
    }
    int res = 0;
    for (int i = 1; i <= scccnt; i++)
        if (!ind[i])
            res++;
    cout << res << '\n';
    return 0;
}