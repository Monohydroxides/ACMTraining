#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n;
vector<int> e[N];

int dfn[N], low[N], ins[N], bel[N], dfncnt, scccnt;
stack<int> stk;
vector<int> scc[N];

int ind[N], outd[N];

void tarjan (int u) {
    dfn[u] = low[u] = ++dfncnt;
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x, x) {
            e[i].push_back(x);            
        }
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);

    for (int i = 1; i <= scccnt; i++) {
        for (auto u: scc[i]) {
            for (auto v: e[u]) {
                if (bel[v] == i) {
                    continue;
                }
                ind[bel[v]]++;
                outd[i]++;
            }
        }
    }

    if (scccnt == 1) {
        cout << 1 << '\n' << 0 << '\n';
        return 0;
    }

    int S = 0, T = 0;
    for (int i = 1; i <= scccnt; i++) {
        if (!ind[i]) {
            S++;
        }
        if (!outd[i]) {
            T++;
        }
    }
    cout << S << '\n' << max(S, T) << '\n';
    return 0;
}
