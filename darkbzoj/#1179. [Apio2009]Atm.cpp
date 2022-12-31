#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
const long long inf = 1ll << 60;

int n, m, csh[N], st, bar, tag[N];
vector<int> e[N];

int dfn[N], low[N], ins[N], bel[N], scctag[N], sccidx, dfnidx;
stack<int> stk;
vector<int> scc[N];

long long dp[N], tot[N];

void tarjan (int u) {
    dfn[u] = low[u] = ++dfnidx;
    stk.push(u);
    ins[u] = 1;
    for (auto v: e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        sccidx++;
        while (1) {
            int cur = stk.top();
            bel[cur] = sccidx;
            ins[cur] = 0;
            scctag[sccidx] |= tag[cur];
            tot[sccidx] += csh[cur];
            scc[sccidx].push_back(cur);
            stk.pop();
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
    for (int i = 1; i <= n; i++) cin >> csh[i];
    cin >> st >> bar;
    for (int i = 1; i <= bar; i++) {
        int x;
        cin >> x;
        tag[x] = 1;
    }

    tarjan(st);

    for (int i = 1; i <= sccidx; i++) {
        dp[i] = -inf;
        for (auto u: scc[i]) {
            for (auto v: e[u]) {
                if (bel[v] == i) {
                    continue;
                }
                dp[i] = max(dp[i], dp[bel[v]]);
            }
        }
        if (scctag[i]) dp[i] = max(dp[i], 0ll);
        dp[i] += tot[i];
    }
    cout << dp[bel[st]] << '\n';
    return 0;
}