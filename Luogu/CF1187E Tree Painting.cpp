#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
int h[N], e[2 * N], ne[2 * N], idx;
int fa[N], sz[N];
long long dp1[N], dp2[N];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1 (int u, int father) {
    sz[u] = 1, fa[u] = father;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) {
            continue;
        }
        dfs1(v, u);
        sz[u] += sz[v];
        dp1[u] += dp1[v];
    }
    dp1[u] += sz[u];
}

void dfs2 (int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == father) {
            continue;
        }
        dp2[v] = dp2[u] - sz[v] + n - sz[v];
        dfs2(v, u);
    }
}

int main () {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs1(1, 0);
    dp2[1] = dp1[1];
    dfs2(1, 0);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, dp2[i]);
    }
    cout << res << '\n';
    return 0;
}