#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

int n, m;
vector<pair<int, int>> e[N];

int dfn[N], low[N], ins[N], bel[N], cccnt, dfncnt;
vector<int> cc[N];
stack<int> stk;

void tarjan (int u, int id) {
    dfn[u] = low[u] = ++dfncnt;
    stk.push(u);
    ins[u] = 1;
    for (auto [v, id2]: e[u]) {
        if (!dfn[v]) {
            tarjan(v, id2);
            low[u] = min(low[u], low[v]);
        } else if (id != id2) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        cccnt++;
        while (1) {
            int cur = stk.top();
            ins[cur] = 0;
            bel[cur] = cccnt;
            stk.pop();
            cc[cccnt].push_back(cur);
            if (u == cur) break;
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    tarjan(1, -1);
    int ans = 0;
    for (int i = 1; i <= cccnt; i++) {
        int cnte = 0;
        for (auto u: cc[i]) {
            for (auto [v, id]: e[u]) {
                if (bel[u] != bel[v]) {
                    cnte++;
                }
            }
        }
        ans += (cnte == 1);
    }
    cout << (ans + 1) / 2 << '\n';
    return 0;
}
