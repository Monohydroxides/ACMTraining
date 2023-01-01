#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
vector<int> e[N];

int dfn[N], low[N], sz[N], dfncnt;
long long ans[N];

void dfs (int u, int father) {
    dfn[u] = low[u] = ++dfncnt;
    sz[u] = 1;
    ans[u] = n - 1;
    int cut = n - 1;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                ans[u] += (long long) sz[v] * (n - sz[v]);
                cut -= sz[v];
            }
        } else if (v != father) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    ans[u] += (long long) cut * (n - cut);
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v); 
        e[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}