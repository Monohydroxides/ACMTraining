#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 5e4 + 10;

int n, m;
int h[N], e[M], ne[M], idx;

int low[N], dfn[N], bel[N], dfncnt, ins[N], sccidx, sz[N];
stack<int> stk;

int outd[N];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan (int u) {
    low[u] = dfn[u] = ++dfncnt;
    stk.push(u);
    ins[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
        
    }
    if (low[u] == dfn[u]) {
        sccidx++;
        while (1) {
            int cur = stk.top();
            bel[cur] = sccidx;
            ins[cur] = 0;
            sz[sccidx]++;
            stk.pop();
            if (cur == u) {
                break;
            }
        }
    }
}

int main () {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (bel[u] != bel[v]) {
                outd[bel[u]]++;
            }
        }
    }
    int ans = 0, cnts = 0;
    for (int i = 1; i <= sccidx; i++) {
        if (outd[i] == 0) {
            ans++;
            cnts += sz[i];
        } 
    }
    if (ans >= 2) {
        cout << 0 << '\n';
    } else {
        cout << cnts << '\n';
    }
    return 0;
}