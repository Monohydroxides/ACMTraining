#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;

int n, m;
vector<int> e[N];

int dfn[N], low[N], dfncnt, sz;
bool cut[N];

void tarjan (int u, int father) {
    dfn[u] = low[u] = ++dfncnt;
    int ch = 0;
    for (auto v: e[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            ch++;
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) cut[u] = 1;
        } else if (v != father) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (u == father && ch <= 1) cut[u] = 0;
    sz += cut[u];
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, i);
        }
    }
    printf("%d\n", sz);
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}