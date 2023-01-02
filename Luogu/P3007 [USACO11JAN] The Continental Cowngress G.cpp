#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;

int n, m;
vector<int> e[N];

int dfn[N], low[N], bel[N], scccnt, dfncnt;
bool ins[N], vis[N];
stack<int> stk;

void dfs (int u) {
    dfn[u] = low[u] = ++dfncnt;
    ins[u] = 1;
    stk.push(u);
    for (auto v : e[u]) {
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
            ins[cur] = 0;
            bel[cur] = scccnt;
            if (u == cur) break;
        }
    }
}

void dfs2 (int u) {
    vis[u] = 1;
    for (auto v : e[u]) {
        if (!vis[v]) dfs2(v);
    }
}

bool check (int u, int v) {
    memset(vis, 0, sizeof vis);
    dfs2(u);
    return vis[v];
}

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int p, q;
        char op1, op2;
        cin >> p >> op1 >> q >> op2;
        p--, q--;
        p = p * 2 + (op1 == 'Y');
        q = q * 2 + (op2 == 'Y');
        e[p ^ 1].push_back(q);
        e[q ^ 1].push_back(p);
    }
    for (int i = 0; i < 2 * n; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (bel[2 * i] == bel[2 * i + 1]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (check(2 * i, 2 * i + 1)) cout << 'Y';
        else if (check(2 * i + 1, 2 * i))   cout << 'N';
        else cout << '?'; 
    }
    return 0;
}