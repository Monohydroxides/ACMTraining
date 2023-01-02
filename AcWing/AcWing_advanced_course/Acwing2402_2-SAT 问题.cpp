#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int n, m;
int h[N], e[N * 2], ne[N * 2], eid;

int dfn[N], low[N], bel[N], dfncnt, scccnt;
bool ins[N];
stack<int> stk;

void add (int a, int b) {
    e[eid] = b, ne[eid] = h[a], h[a] = eid++;
}

void dfs (int u) {
    dfn[u] = low[u] = ++dfncnt;
    ins[u] = 1;
    stk.push(u);
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scccnt++;
        while (1) {
            int cur = stk.top();
            stk.pop();
            ins[cur] = 0;
            bel[cur] = scccnt;
            if (cur == u) break;
        }
    }
}

int main () {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int p, a, q, b;
        cin >> p >> a >> q >> b;
        p--, q--;
        p = p * 2 + (a == 1);
        q = q * 2 + (b == 1);
        add(p ^ 1, q);
        add(q ^ 1, p);
    }
    for (int i = 0; i < n * 2; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << bel[i * 2] << " " << bel[i * 2 + 1] << '\n';
    // }
    for (int i = 0; i < n; i++) {
        if (bel[i * 2] == bel[i * 2 + 1]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << "POSSIBLE\n";
    for (int i = 0; i < n; i++) {
        if (bel[i * 2] < bel[i * 2 + 1]) {
            cout << 0 << " ";
        } else {
            cout << 1 << " ";
        }
    }
    return 0;
}